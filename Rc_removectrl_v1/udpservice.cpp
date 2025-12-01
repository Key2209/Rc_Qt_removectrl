#include "UdpService.h"
#include <QHostInfo>
#include <QJsonArray>
#include "androidinfoprovider.h"
// --- 构造函数与析构函数 ---

UdpService::UdpService(quint16 targetPort, QObject *parent)
    : QObject(parent),
    m_targetPort(targetPort),
    m_isConnected(false)
{
    // 1. 初始化 UDP Socket
    m_udpSocket = new QUdpSocket(this);

    // 绑定到任意端口和地址，用于发送和接收
    if (!m_udpSocket->bind(QHostAddress::AnyIPv4, 0)) {
        //emit errorOccurred("Failed to bind UDP socket.");
        qDebug() << "Failed to bind UDP socket.";
    }

    // 2. 连接数据接收信号槽
    connect(m_udpSocket, &QUdpSocket::readyRead, this, &UdpService::readPendingDatagrams);

    // 3. 初始化连接定时器
    m_connectionTimer = new QTimer(this);

    // 每隔 1 秒尝试发送一次连接请求
    m_connectionTimer->setInterval(1000);
    m_connectionTimer->stop();// 初始时停止定时器
    connect(m_connectionTimer, &QTimer::timeout, this, &UdpService::connectionTimerTimeout);



    // m_sendDataTimer = new QTimer(this);
    // m_sendDataTimer->setInterval(20); // 20次/秒，高频发送
    // m_sendDataTimer->stop(); // 初始停止
    // connect(m_sendDataTimer, &QTimer::timeout, this, &UdpService::sendDataTimerTimeout);
}

UdpService::~UdpService()
{
    // 停止定时器
    m_connectionTimer->stop();
    m_sendDataTimer->stop(); // 初始停止
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
    // m_isConnected = false;
    // emit connectionStatusChanged(false);
    if(m_targetAddress.isNull())
    {
        //m_targetAddress=QHostAddress(m_targetMdnsHost);
        qDebug()<< "Target address was null, attempting to resolve using MDNS host:" << m_targetMdnsHost;
        return;
    }
    //立即发送第一个连接请求，然后启动定时器
    connectionTimerTimeout();
    m_connectionTimer->start();
    qDebug() << "Connection timer started.";
}



void UdpService::sendData(const UiDataStruct &data)
{
    if (!m_isConnected) {
        qWarning() << "Cannot send data: Not connected.";
        return;
    }

    QJsonObject json;
    json["cmd"] = "ctrl";

    // --- Joystick1 ---
    json["x1"] = data.joystick1.x;
    json["y1"] = data.joystick1.y;

    // --- Joystick2 ---
    json["x2"] = data.joystick2.x;
    json["y2"] = data.joystick2.y;

    // --- Scrollers ---
    json["sc_h1"] = data.scroller_horiz1;
    json["sc_v1"] = data.scroller_vertical1;

    // --- Button Group 1 ---
    QJsonArray btnGroup1;
    for (int i = 0; i < 10; i++)
        btnGroup1.append(data.button_group1[i]);
    json["btn_g1"] = btnGroup1;

    // // --- Button Group 2 ---
    // QJsonArray btnGroup2;
    // btnGroup2.reserve(10);
    // for (int i = 0; i < 10; i++)
    //     btnGroup2.append(data.button_group2[i]);
    // json["btn_g2"] = btnGroup2;

    // 最终发送
    sendJson(json);
}

void UdpService::set_targetMdnsHost(QString &MdnsHost)
{

    qDebug() << "Starting connection attempt...";
    if (!MdnsHost.isEmpty()) {
        // 如果没有 QZeroConf，尝试普通的 hostname -> IP 解析（QHostInfo）
        MdnsHost=MdnsHost+".local";
        qDebug() << "Resolving host via QHostInfo:" << MdnsHost;
        QHostInfo::lookupHost(MdnsHost, this, SLOT(onHostLookupFinished(QHostInfo)));

    } else {
        qWarning() << "No target host specified";
    }
}

// --- 私有辅助方法 ---

/**
 * @brief 将 QJsonObject 转换为 JSON 字节流并发送。
 */
void UdpService::sendJson(const QJsonObject& jsonObject)
{
    QJsonDocument doc(jsonObject);
    QByteArray datagram = doc.toJson(QJsonDocument::Compact); // 紧凑格式，节省带宽
    // 使用已解析的目标地址进行发送
    if(m_targetAddress.isNull())
    {
        m_targetAddress=QHostAddress(m_targetMdnsHost);
        qDebug()<< "Target address was null, attempting to resolve using MDNS host:" << m_targetMdnsHost;
    }
    qint64 bytes = m_udpSocket->writeDatagram(datagram, m_targetAddress, m_targetPort);

    if (bytes == -1) {
        emit errorOccurred(QString("Failed to send datagram: %1").arg(m_udpSocket->errorString()));
    } else {
        qDebug() << "Sent datagram:" << datagram << "to" << m_targetAddress.toString() << ":" << m_targetPort;
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
    json["device"]= m_deviceName;
    qDebug() << "connectionTimerTimeout Sending connection request...";
    sendJson(json);


}

void UdpService::sendDataTimerTimeout()
{

}

void UdpService::onHostLookupFinished(const QHostInfo &info)
{
    if (info.error() != QHostInfo::NoError) {

        qDebug() << "Failed to resolve host:" << info.hostName();

        qWarning() << "Host lookup failed:" << info.errorString();
        qDebug()<<"ip:"<<info.addresses();
        return;
    }

    // 找到第一个 IPv4 地址作为目标
    for (const QHostAddress &addr : info.addresses()) {
        if (addr.protocol() == QAbstractSocket::IPv4Protocol) {
            m_targetAddress = addr;
            emit sendIPAddress(addr.toString());//发送解析后的IP地址)
            qDebug() << "Resolved host" << info.hostName() << "->" << addr.toString();
            return;
        }
    }

    qWarning() << "No IPv4 address found for host" << info.hostName();
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

        if(sender.toString() != QHostAddress(m_targetAddress).toString())// 忽略非目标地址的消息
        {
            qDebug() << "Ignoring datagram from unknown sender:" << sender.toString();
            qDebug()<< "Expected sender:" << QHostAddress(m_targetMdnsHost).toString();
            qDebug()<< "Expected sender IP:" << m_targetAddress.toString();
            continue;
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
    if (!m_isConnected && obj.contains("status") && obj["status"].toString() == "ok") {
        m_isConnected = true;
        m_connectionTimer->stop();
        emit connectionStatusChanged(true);

        //开启不断发送
        //m_sendDataTimer->start(); // 初始停止
        qDebug() << "✅ Successfully connected to robot!";
        return;
    }

    if (obj.contains("status")&&obj["status"].toString() == "connection failed") {
        qDebug() << "❌ Connection to robot failed.";

        showAndroidToast(obj["device"].toString(),ToastDuration::SHORT);
        return;
    }


    // // 检查是否是 ESP32 发送的状态/其他信息
    // if (obj.contains("status")) {
    //     // 例如：{"status": "low_battery"}
    //     qDebug() << "Robot Status Update:" << obj["status"].toString();
    //     emit messageReceived(obj);
    //     return;
    // }

    // // 转发其他任何消息
    // emit messageReceived(obj);
}
