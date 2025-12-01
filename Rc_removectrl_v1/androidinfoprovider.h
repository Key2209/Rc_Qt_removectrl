#pragma once
#include <QJniObject>
#include <QObject>

class AndroidInfoProvider : public QObject
{
    Q_OBJECT
public:
    explicit AndroidInfoProvider(QObject *parent = nullptr);

    QString getWifiSsid();
    QString getDeviceInfo();
    QString getIpAddress();

    QString getConnectedWifiName();
    int getWifiSignalStrength();
    // 权限申请（ACCESS_FINE_LOCATION）
    void requestLocationPermission();
private:
    QJniObject getActivity();
};



// 定义 Toast 持续时间的枚举
enum ToastDuration {
    SHORT = 0, // 约 2 秒
    LONG = 1   // 约 3.5 秒
};

void showAndroidToast(const QString &message, ToastDuration duration = SHORT);
