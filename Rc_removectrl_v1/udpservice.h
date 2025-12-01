#ifndef UDPSERVICE_H
#define UDPSERVICE_H

#include <QObject>
#include <QUdpSocket>
#include <QHostAddress>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
#include <QTimer>
#include <QHostInfo>
#include "androidinfoprovider.h"
#include "datastruct.h"
using ControlValueGetter = std::function<UiDataStruct()>;
class UdpService : public QObject
{
    Q_OBJECT
public:
    // 构造函数：需要指定目标（ESP32）的 MDNS 域名和端口
    explicit UdpService(quint16 targetPort, QObject *parent = nullptr);
    ~UdpService();

    // 公共方法
    void startConnectionAttempt();//连接


    void sendData(const UiDataStruct &data);//发送控制数据

    void set_targetMdnsHost(QString &MdnsHost);//设置MDNS地址,并且解析
    //设置ip地址
    void set_targetAddress(const QString &address){

        m_targetAddress=QHostAddress(address);
        if (m_targetAddress.isNull()) {

            qWarning() << "MDNS Hostname could not be immediately resolved. Will rely on network services.";
        }
    }//手动设置IP地址
    void setDeviceName(const QString &deviceName){
        m_deviceName=deviceName;
    }//设置设备名称
    void setControlValueGetter(ControlValueGetter getter) { m_controlValueGetter = std::move(getter); }
signals:
    // 信号：通知 UI 连接状态
    void connectionStatusChanged(bool isConnected);
    // 信号：当接收到特定回复时
    void messageReceived(const QJsonObject& data);
    // 信号：通知 UI 发生了错误
    void errorOccurred(const QString& message);

    void sendIPAddress(const QString ipAddress);//发送解析后的IP地址
private slots:
    // 槽：处理 QUdpSocket 的数据接收
    void readPendingDatagrams();
    // 槽：用于处理连接尝试的定时器，定期发送连接请求
    void connectionTimerTimeout();

    void sendDataTimerTimeout();//用于周期性发送控制命令

    void onHostLookupFinished(const QHostInfo &info);
private:
    // 核心网络组件
    QUdpSocket *m_udpSocket;

    // 目标 ESP32 信息
    QString m_targetMdnsHost; // ESP32 的 MDNS 域名 (例如 "esp32-robot.local")
    quint16 m_targetPort;     // ESP32 监听的端口号

    // 连接状态
    bool m_isConnected;

    // 连接尝试定时器
    QTimer *m_connectionTimer;
    QTimer *m_sendDataTimer; //用于周期性发送控制命令
    // 目标地址 (解析 MDNS 后的 IP 地址)
    QHostAddress m_targetAddress;

    QString m_deviceName="unkonwn_device";//设备名称";
    // 私有辅助方法
    void sendJson(const QJsonObject& jsonObject);
    void processIncomingMessage(const QByteArray& data);



    ControlValueGetter m_controlValueGetter;

};

#endif // UDPSERVICE_H

