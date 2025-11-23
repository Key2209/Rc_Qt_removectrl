#ifndef UDPSERVICE_H
#define UDPSERVICE_H

#include <QObject>
#include <QUdpSocket>
#include <QHostAddress>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
#include <QTimer>

class UdpService : public QObject
{
    Q_OBJECT
public:
    // 构造函数：需要指定目标（ESP32）的 MDNS 域名和端口
    explicit UdpService(const QString& targetMdnsHost, quint16 targetPort, QObject *parent = nullptr);
    ~UdpService();

    // 公共方法
    void startConnectionAttempt();
    void sendControlCommand(int throttle, int steer);

signals:
    // 信号：通知 UI 连接状态
    void connectionStatusChanged(bool isConnected);
    // 信号：当接收到特定回复时
    void messageReceived(const QJsonObject& data);
    // 信号：通知 UI 发生了错误
    void errorOccurred(const QString& message);

private slots:
    // 槽：处理 QUdpSocket 的数据接收
    void readPendingDatagrams();
    // 槽：用于处理连接尝试的定时器，定期发送连接请求
    void connectionTimerTimeout();

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

    // 目标地址 (解析 MDNS 后的 IP 地址)
    QHostAddress m_targetAddress;

    // 私有辅助方法
    void sendJson(const QJsonObject& jsonObject);
    void processIncomingMessage(const QByteArray& data);

    // 由于 QUdpSocket 不支持直接用 MDNS 域名发送，
    // 在 Android/Qt 层面需要先解析。这里简化处理，假设
    // MDNS 解析后的 IP 地址可以直接发送，或者在初次通信时广播/硬编码。
    // 为了简化和聚焦 UDP 通信，我们暂时**假设**在实际应用中
    // MDNS 域名 **"esp32-robot.local"** 可以被系统网络层自动解析为 IP 地址。
    // 在实际的 Android/Qt 应用中，你可能需要额外的库或系统调用来完成 MDNS 解析，
    // 但在 C++/Qt 层面，我们先用 `m_targetMdnsHost` 作为发送地址。

    // **重要提示：** Qt 的 `QUdpSocket::writeDatagram` 接受 `QHostAddress`。
    // 虽然它可以解析主机名，但在某些平台和配置下，对 `.local` 地址的解析可能需要额外配置。
    // 简化起见，我们将先用 `QHostAddress(m_targetMdnsHost)` 尝试，如果失败，则需要外部解析。
};

#endif // UDPSERVICE_H

