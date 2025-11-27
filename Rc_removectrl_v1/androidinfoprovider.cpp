// #include "androidinfoprovider.h"
// #include <QNetworkInterface>
// #include <QHostAddress>
// #include <QCoreApplication> // 用于 qApp 和权限管理
// #include <QGuiApplication>   // 用于 QGuiApplication::instance()

// // --- AndroidInfoProvider 类的实现 ---

// AndroidInfoProvider::AndroidInfoProvider(QObject *parent) : QObject(parent)
// {
//     // 在构造函数中连接权限请求的结果信号
// #ifdef Q_OS_ANDROID
//     // Qt 6.9 中，权限结果信号在 QCoreApplication/QGuiApplication 实例上。
//     // qApp 宏代表 QCoreApplication::instance() 或 QGuiApplication::instance()。
//     QObject::connect(qApp, &QCoreApplication::checkPermissionResult,
//                      this, &AndroidInfoProvider::handlePermissionResult);
// #endif
// }

// // --- 1. 获取 IP 地址 (纯 Qt API) ---
// QString AndroidInfoProvider::getLocalIpAddress() const
// {
//     QString ipAddress;
//     QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();

//     // 遍历所有 IP 地址，找到第一个非回环的 IPv4 地址
//     for (const QHostAddress &entry : ipAddressesList) {
//         if (entry != QHostAddress::LocalHost && entry.protocol() == QAbstractSocket::IPv4Protocol) {
//             ipAddress = entry.toString();
//             break;
//         }
//     }
//     // 如果没有找到有效地址，返回回环地址
//     return ipAddress.isEmpty() ? "127.0.0.1" : ipAddress;
// }

// // --- 2. 获取设备型号 (Qt 6 JNI) ---
// QString AndroidInfoProvider::getDeviceModel() const
// {
// #ifdef Q_OS_ANDROID
//     // 使用 QJniObject 读取 Android 系统属性 android.os.Build.MODEL
//     QJniObject model = QJniObject::getStaticObjectField("android/os/Build", "MODEL", "Ljava/lang/String;");
//     // 读取制造商属性
//     QJniObject manufacturer = QJniObject::getStaticObjectField("android/os/Build", "MANUFACTURER", "Ljava/lang/String;");

//     QString modelName = model.isValid() ? model.toString() : "Unknown Model";

//     if (manufacturer.isValid()) {
//         // 格式化输出：MANUFACTURER MODEL
//         return manufacturer.toString().toUpper() + " " + modelName;
//     }
//     return modelName;
// #else
//     return "Unknown Device";
// #endif
// }

// // --- 3. 获取 Wi-Fi SSID (Qt 6 JNI，需要权限) ---
// QString AndroidInfoProvider::getWifiSsid()
// {
// #ifdef Q_OS_ANDROID
//     // 权限检查应该在调用此函数前完成

//     // 1. 获取 Android Context
//     QJniObject context = QNativeInterface::QAndroidApplication::context();
//     if (!context.isValid()) return "Error: No Context";

//     // 2. 获取 WifiManager 服务 (getSystemService("wifi"))
//     QJniObject serviceName = QJniObject::fromString("wifi");
//     QJniObject wifiService = context.callObjectMethod(
//         "getSystemService",
//         "(Ljava/lang/String;)Ljava/lang/Object;", // JNI 方法签名
//         serviceName.object<jstring>());

//     if (!wifiService.isValid()) return "Error: No Wifi Service";

//     // 3. 调用 getConnectionInfo() 获取 WifiInfo 对象
//     QJniObject connectionInfo = wifiService.callObjectMethod(
//         "getConnectionInfo",
//         "()Landroid/net/wifi/WifiInfo;");

//     if (!connectionInfo.isValid()) return "Error: No Connection Info";

//     // 4. 调用 getSSID() 获取 SSID 字符串
//     QJniObject ssidObject = connectionInfo.callObjectMethod("getSSID", "()Ljava/lang/String;");

//     if (ssidObject.isValid()) {
//         QString rawSsid = ssidObject.toString();
//         // 移除 Android 通常添加的双引号
//         if (rawSsid.startsWith("\"") && rawSsid.endsWith("\"")) {
//             return rawSsid.mid(1, rawSsid.length() - 2);
//         }
//         return rawSsid;
//     }
//     return "SSID Not Found/Permission Denied";
// #else
//     return "Not Applicable";
// #endif
// }

// // --- 4. 权限请求 (Qt 6 JNI) ---
// void AndroidInfoProvider::requestLocationPermission()
// {
// #ifdef Q_OS_ANDROID
//     // 修正: 权限函数在 Qt 6.9 中是 QCoreApplication 的非静态成员，需通过实例 (qApp) 调用。
//     auto check = qApp->checkPermission("android.permission.ACCESS_FINE_LOCATION");

//     // Qt::PermissionStatus::Granted 是 Qt 6 中正确的权限枚举类型
//     if (check == Qt::PermissionStatus::Granted) {
//         qDebug() << "Location Permission already granted.";
//         emit permissionGranted();
//         return;
//     }

//     qDebug() << "Requesting Location Permission...";
//     // 修正: 使用实例 (qApp) 调用 requestPermissions
//     qApp->requestPermissions(QStringList("android.permission.ACCESS_FINE_LOCATION"), 100);

// #else
//     qDebug() << "Permission management not needed on this platform.";
//     emit permissionGranted();
// #endif
// }

// // --- 5. 权限请求结果处理 (Qt 6 JNI Callback) ---
// void AndroidInfoProvider::handlePermissionResult(int requestCode, const QStringList &permissions, const QList<bool> &grantResults)
// {
//     // 检查是否是我们请求的权限 (请求码 100)
//     if (requestCode == 100 && !permissions.isEmpty() && permissions.contains("android.permission.ACCESS_FINE_LOCATION")) {
//         // 检查结果列表是否非空，并且第一个结果是否为 true (允许)
//         if (!grantResults.isEmpty() && grantResults.first()) {
//             qDebug() << "Location Permission GRANTED!";
//             emit permissionGranted();
//         } else {
//             qDebug() << "Location Permission DENIED!";
//             emit permissionDenied();
//         }
//     }
// }
