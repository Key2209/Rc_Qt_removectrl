#include "androidinfoprovider.h"
#include <QJniObject>
#include <QNetworkInterface>
#include <QDebug>

#ifdef Q_OS_ANDROID
#include <QtCore/qjniobject.h>
#endif


AndroidInfoProvider::AndroidInfoProvider(QObject *parent)
    : QObject(parent)
{


#ifdef Q_OS_ANDROID
    // 自动申请权限
    requestLocationPermission();
#endif

}

QJniObject AndroidInfoProvider::getActivity()
{
    return QJniObject::callStaticObjectMethod(
        "org/qtproject/qt/android/QtNative",
        "activity",
        "()Landroid/app/Activity;"
        );
}

QString AndroidInfoProvider::getWifiSsid()
{
#ifdef Q_OS_ANDROID
    QJniObject activity = getActivity();
    if (!activity.isValid()) return "Activity invalid";

    QJniObject wifiService = activity.callObjectMethod(
        "getSystemService",
        "(Ljava/lang/String;)Ljava/lang/Object;",
        QJniObject::fromString("wifi").object()
        );
    if (!wifiService.isValid()) return "WifiManager invalid";

    QJniObject info =
        wifiService.callObjectMethod("getConnectionInfo",
                                     "()Landroid/net/wifi/WifiInfo;");
    if (!info.isValid()) return "WifiInfo invalid";

    return info.callObjectMethod("getSSID",
                                 "()Ljava/lang/String;").toString();
#else
    return "Not Android";
#endif
}

QString AndroidInfoProvider::getDeviceInfo()
{
#ifdef Q_OS_ANDROID
    QString brand = QJniObject::getStaticObjectField<jstring>(
                        "android/os/Build",
                        "BRAND").toString();
    QString model = QJniObject::getStaticObjectField<jstring>(
                        "android/os/Build",
                        "MODEL").toString();
    return brand + " " + model;
#else
    return "Not Android";
#endif
}

QString AndroidInfoProvider::getIpAddress()
{
    for (auto &iface : QNetworkInterface::allInterfaces()) {
        for (auto &e : iface.addressEntries()) {
            if (e.ip().protocol() == QAbstractSocket::IPv4Protocol &&
                e.ip().toString() != "127.0.0.1")
                return e.ip().toString();
        }
    }
    return "Unknown";
}



// ------------------ 获取当前连接 WiFi 名称 ------------------
QString AndroidInfoProvider::getConnectedWifiName()
{
#ifdef Q_OS_ANDROID
    QJniObject activity = getActivity();
    if (!activity.isValid()) {
        qDebug() << "Activity invalid";
        return "Activity invalid";
    }

    // 获取系统 WifiManager
    QJniObject wifiService = activity.callObjectMethod(
        "getSystemService",
        "(Ljava/lang/String;)Ljava/lang/Object;",
        QJniObject::fromString("wifi").object()
        );
    if (!wifiService.isValid()) {
        qDebug() << "WifiManager invalid";
        return "WifiManager invalid";
    }

    // 获取 WifiInfo 对象
    QJniObject info = wifiService.callObjectMethod(
        "getConnectionInfo",
        "()Landroid/net/wifi/WifiInfo;"
        );
    if (!info.isValid()) {
        qDebug() << "WifiInfo invalid";
        return "WifiInfo invalid";
    }

    // 获取 SSID 并去掉返回字符串中的双引号
    QString ssid = info.callObjectMethod("getSSID", "()Ljava/lang/String;").toString();
    qDebug() << "Raw SSID:" << ssid;
    ssid = ssid.remove('\"'); // Android 有时返回 "SSID"，去掉引号
    qDebug()<< "Processed SSID:" << ssid;
    return ssid;
#else
    return "Not Android";
#endif
}

// ------------------ 获取当前连接 WiFi 信号强度 ------------------
int AndroidInfoProvider::getWifiSignalStrength()
{
#ifdef Q_OS_ANDROID
    QJniObject activity = getActivity();
    if (!activity.isValid()) {
        qDebug() << "Activity invalid";
        return -1;
    }

    // 获取系统 WifiManager
    QJniObject wifiService = activity.callObjectMethod(
        "getSystemService",
        "(Ljava/lang/String;)Ljava/lang/Object;",
        QJniObject::fromString("wifi").object()
        );
    if (!wifiService.isValid()) {
        qDebug() << "WifiManager invalid";
        return -1;
    }

    // 获取 WifiInfo 对象
    QJniObject info = wifiService.callObjectMethod(
        "getConnectionInfo",
        "()Landroid/net/wifi/WifiInfo;"
        );
    if (!info.isValid()) {
        qDebug() << "WifiInfo invalid";
        return -1;
    }

    // 获取 RSSI（信号强度），单位 dBm
    int rssi = info.callMethod<jint>("getRssi", "()I");
    return rssi;
#else
    return -1; // 非 Android 平台
#endif
}
void AndroidInfoProvider::requestLocationPermission()
{
#ifdef Q_OS_ANDROID
    QJniObject activity = getActivity();
    if (!activity.isValid()) return;

    QJniEnvironment env;

    // 创建权限字符串数组
    jclass stringClass = env->FindClass("java/lang/String");
    jobjectArray permissionsArray = env->NewObjectArray(
        1,
        stringClass,
        env->NewStringUTF("android.permission.ACCESS_FINE_LOCATION")
        );

    // 获取 Activity.requestPermissions 方法
    jmethodID methodID = env->GetMethodID(
        env->GetObjectClass(activity.object<jobject>()),
        "requestPermissions",
        "([Ljava/lang/String;I)V"
        );

    if (!methodID) {
        qDebug() << "requestPermissions method not found!";
        return;
    }

    // 调用权限申请
    env->CallVoidMethod(activity.object<jobject>(), methodID, permissionsArray, 1);

    // 清理 JNI 局部引用
    env->DeleteLocalRef(permissionsArray);
    env->DeleteLocalRef(stringClass);

    // 注意：用户拒绝权限的回调需要在 Java 端 Activity.onRequestPermissionsResult，
    // 这里 Qt 无法直接捕获，需要在 Java 层通知 C++，或者简单处理：
    // 如果获取 SSID 返回 "<unknown ssid>"，则判定用户拒绝权限
#endif
}


#include <QCoreApplication>
#include <QJniObject>
#include <QDebug>


/**
 * @brief 在 Android 主 UI 线程上显示原生的 Toast 通知。
 * @param message 要显示的消息文本。
 * @param duration 持续时间（SHORT 或 LONG）。
 */
void showAndroidToast(const QString &message, ToastDuration duration)
{
#ifdef Q_OS_ANDROID
    QNativeInterface::QAndroidApplication::runOnAndroidMainThread([message, duration] {
        QJniEnvironment env;

        // 1. 获取 Context JNI 对象
        QJniObject contextObject = QNativeInterface::QAndroidApplication::context();

        if (!contextObject.isValid()) {
            qWarning() << "Failed to get Android Context.";
            return;
        }

        // 2. 将 Context 对象的原生句柄 (jobject) 提取出来
        jobject contextHandle = contextObject.object<jobject>(); // <--- 关键修正

        // 3. 将 QString 转换为 Java 字符串
        QJniObject javaString = QJniObject::fromString(message);

        // 4. 调用 android.widget.Toast.makeText(...) 静态方法
        QJniObject toast = QJniObject::callStaticObjectMethod(
            "android/widget/Toast",
            "makeText",
            "(Landroid/content/Context;Ljava/lang/CharSequence;I)Landroid/widget/Toast;",
            contextHandle,                                   // <--- 传递原生句柄
            javaString.object(),
            jint(duration)
            );

        if (toast.isValid()) {
            // 5. 调用 Toast 对象的 show() 方法显示通知
            toast.callMethod<void>("show");
        } else {
            qWarning() << "Failed to create Android Toast object.";
        }
    });
#else
    Q_UNUSED(duration);
    qDebug() << "Toast (Simulation):" << message;
#endif
}


