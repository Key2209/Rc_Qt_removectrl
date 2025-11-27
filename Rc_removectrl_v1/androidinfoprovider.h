// #ifndef ANDROIDINFOPROVIDER_H
// #define ANDROIDINFOPROVIDER_H

// #include <QObject>
// #include <QString>
// #include <QDebug>
// #include <QCoreApplication> // 必须包含，因为权限 API 提升到了 QCoreApplication 实例

// #ifdef Q_OS_ANDROID
// #include <QJniObject>      // 用于 JNI 桥接
// #include <QNativeInterface> // 用于获取 Android Context
// #endif

// class AndroidInfoProvider : public QObject
// {
//     Q_OBJECT
// public:
//     explicit AndroidInfoProvider(QObject *parent = nullptr);

//     // Q_INVOKABLE 允许在 QML 或其他地方调用
//     Q_INVOKABLE QString getLocalIpAddress() const;
//     Q_INVOKABLE QString getDeviceModel() const;
//     Q_INVOKABLE QString getWifiSsid();

// public slots:
//     // 请求运行时权限（SSID 需要 ACCESS_FINE_LOCATION）
//     void requestLocationPermission();

// signals:
//     // 权限请求完成后发送信号
//     void permissionGranted();
//     void permissionDenied();

// private:
// #ifdef Q_OS_ANDROID
//     // Android 权限请求结果的回调函数。
//     // 在 Qt 6.9 中，它用于连接 QCoreApplication::checkPermissionResult 信号。
//     void handlePermissionResult(int requestCode, const QStringList &permissions, const QList<bool> &grantResults);
// #endif
// };

// #endif // ANDROIDINFOPROVIDER_H
