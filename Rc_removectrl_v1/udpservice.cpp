#include "UdpService.h"

// --- 构造函数与析构函数 ---

UdpService::UdpService(const QString& targetMdnsHost, quint16 targetPort, QObject *parent)
    : QObject(parent),
    m_targetMdnsHost(targetMdnsHost),
    m_targetPort(targetPort),
    m_isConnected(false)
{
    // 1. 初始化 UDP Socket
    m_udpSocket = new QUdpSocket(this);

    // 绑定到任意端口和地址，用于发送和接收
    if (!m_udpSocket->bind(QHostAddress::AnyIPv4, 0)) {
        emit errorOccurred("Failed to bind UDP socket.");
    }

    // 2. 连接数据接收信号槽
    connect(m_udpSocket, &QUdpSocket::readyRead, this, &UdpService::readPendingDatagrams);

    // 3. 初始化连接定时器
    m_connectionTimer = new QTimer(this);
    // 每隔 1 秒尝试发送一次连接请求
    m_connectionTimer->setInterval(1000);
    connect(m_connectionTimer, &QTimer::timeout, this, &UdpService::connectionTimerTimeout);

    // 尝试将 MDNS 域名解析为 IP 地址
    // QHostAddress 的构造函数支持域名解析，但 `.local` 域名在某些系统上可能有问题。
    m_targetAddress = QHostAddress(m_targetMdnsHost);

    if (m_targetAddress.isNull()) {
        qWarning() << "MDNS Hostname could not be immediately resolved. Will rely on network services.";
        // 即使解析失败，我们仍然使用 QHostAddress(m_targetMdnsHost) 作为发送目标，
        // 期望 QUdpSocket 内部能处理，但最好是有一个已解析的 IP。
    }
}

UdpService::~UdpService()
{
    // 停止定时器
    m_connectionTimer->stop();
    // 释放 Socket 资源
    m_udpSocket->close();
}

// --- 公共方法 ---

/**
 * @brief 开始连接尝试过程。
 * 停止现有连接，设置状态为断开，并启动定时器开始发送 {"cmd": "connect"}。
 */
void UdpService::startConnectionAttempt()
{
    qDebug() << "Starting connection attempt...";
    m_isConnected = false;
    emit connectionStatusChanged(false);

    //立即发送第一个连接请求，然后启动定时器
    connectionTimerTimeout();
    m_connectionTimer->start();
}

/**
 * @brief 发送控制命令 {"cmd": "ctrl", "t": throttle, "s": steer}
 * @param throttle 油门/速度 (-100 to 100)
 * @param steer 转向 (-100 to 100)
 */
void UdpService::sendControlCommand(int throttle, int steer)
{
    if (!m_isConnected) {
        qWarning() << "Cannot send control command: Not connected.";
        return;
    }

    QJsonObject json;
    json["cmd"] = "ctrl";
    json["t"] = throttle; // 对应 't' (throttle)
    json["s"] = steer;    // 对应 's' (steer)

    sendJson(json);
}

// --- 私有辅助方法 ---

/**
 * @brief 将 QJsonObject 转换为 JSON 字节流并发送。
 */
void UdpService::sendJson(const QJsonObject& jsonObject)
{
    QJsonDocument doc(jsonObject);
    QByteArray datagram = doc.toJson(QJsonDocument::Compact); // 紧凑格式，节省带宽

    // 使用主机名作为地址进行发送 (期望系统能解析)
    QHostAddress targetAddr(m_targetMdnsHost);
    if (targetAddr.isNull()) {
        // 如果无法解析，则使用之前解析的 IP 或默认回环地址作为警告
        targetAddr = m_targetAddress.isNull() ? QHostAddress("127.0.0.1") : m_targetAddress;
    }

    qint64 bytes = m_udpSocket->writeDatagram(datagram, targetAddr, m_targetPort);

    if (bytes == -1) {
        emit errorOccurred(QString("Failed to send datagram: %1").arg(m_udpSocket->errorString()));
    } else {
        qDebug() << "Sent datagram:" << datagram << "to" << targetAddr.toString() << ":" << m_targetPort;
    }
}

/**
 * @brief 定时器超时槽，发送连接请求。
 */
void UdpService::connectionTimerTimeout()
{
    if (m_isConnected) {
        // 如果已经连接，则停止定时器
        m_connectionTimer->stop();
        return;
    }

    // 发送连接请求
    QJsonObject json;
    json["cmd"] = "connect";
    sendJson(json);

    qDebug() << "Sending connection request...";
}

// --- 槽函数：数据接收 ---

/**
 * @brief 处理 QUdpSocket 接收到的数据报。
 */
void UdpService::readPendingDatagrams()
{
    while (m_udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(static_cast<int>(m_udpSocket->pendingDatagramSize()));

        QHostAddress sender;
        quint16 senderPort;

        m_udpSocket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);

        qDebug() << "Received datagram from:" << sender.toString() << ":" << senderPort << "Data:" << datagram;

        // 如果是首次连接，并且发送方是 ESP32，则记录其 IP
        if (!m_isConnected && (sender.toString() == QHostAddress(m_targetMdnsHost).toString() || m_targetAddress.isNull())) {
            m_targetAddress = sender;
            qDebug() << "Target address resolved/confirmed to:" << m_targetAddress.toString();
        }

        processIncomingMessage(datagram);
    }
}

/**
 * @brief 解析接收到的 JSON 消息并执行相应操作。
 */
void UdpService::processIncomingMessage(const QByteArray& data)
{
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(data, &error);

    if (error.error != QJsonParseError::NoError) {
        qWarning() << "Failed to parse JSON:" << error.errorString();
        return;
    }

    if (!doc.isObject()) {
        qWarning() << "Received JSON is not an object.";
        return;
    }

    QJsonObject obj = doc.object();

    // 检查是否是连接成功的回复
    if (!m_isConnected && obj.contains("cmd") && obj["cmd"].toString() == "connected") {
        m_isConnected = true;
        m_connectionTimer->stop();
        emit connectionStatusChanged(true);
        qDebug() << "✅ Successfully connected to robot!";
        return;
    }

    // 检查是否是 ESP32 发送的状态/其他信息
    if (obj.contains("status")) {
        // 例如：{"status": "low_battery"}
        qDebug() << "Robot Status Update:" << obj["status"].toString();
        emit messageReceived(obj);
        return;
    }

    // 转发其他任何消息
    emit messageReceived(obj);
}
