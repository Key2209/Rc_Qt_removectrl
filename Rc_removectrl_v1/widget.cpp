#include "widget.h"
#include "ui_widget.h"
#include "connectwidget.h"
#include "androidinfoprovider.h"



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->page_main);


    // 为子页面安装事件过滤器
    ui->page_connect->installEventFilter(this);
    ui->page_rc->installEventFilter(this);
    ui->page_test->installEventFilter(this);

    // 创建 UDP 服务实例
    m_udpService = new UdpService(3333, this); // 端口

    //获取安卓设备信息类
    m_androidInfoProvider=new AndroidInfoProvider;
    m_udpService->setDeviceName(m_androidInfoProvider->getDeviceInfo());

    //发送数据定时器
    m_sendDataTimer = new QTimer(this);
    m_sendDataTimer->setInterval(20); // 20次/秒，高频发送
    m_sendDataTimer->stop(); // 初始停止
    connect(m_sendDataTimer, &QTimer::timeout, this, &Widget::sendDataTimerTimeout);



    //解析到的IP地址信号
    connect(m_udpService,&UdpService::sendIPAddress,this,[this](QString ipAddress){
        qDebug()<<"你好你好解析到的IP地址:"<<ipAddress;
        ui->page_connect->setConnectIpAddress(ipAddress);
    });


    // 监听 stackedWidget 页面切换信号
    connect(ui->stackedWidget,&QStackedWidget::currentChanged,this,&Widget::onStackedWidgetPageChanged);


    connect(ui->page_connect,&ConnectWidget::ConnectWidget_domainClicked,this,[this](QString ipAddress)
        {
            m_udpService->set_targetMdnsHost(ipAddress);
        });

    //点击连接按钮信号
    // connect(ui->page_connect,&ConnectWidget::ConnectWidget_connectClicked,this,[this](QString ipAddress){

    //     if(ipAddress.isEmpty()||m_IpAddress_Domain==ipAddress){
    //         return;
    //         qDebug()<<"IP地址为空或未更改，跳过连接";
    //     }

    //     if(m_udpService!=nullptr)
    //     {
    //         delete m_udpService;
    //         //disconnect()
    //     }

    //     //m_udpService = new UdpService(3333, this); // 端口
    //     //m_IpAddress_Domain=ipAddress;
    //     if(m_udpService){

    //         qDebug()<<"m_IpAddress_Domain:"<<m_IpAddress_Domain;
    //         //m_udpService->set_targetMdnsHost(m_IpAddress_Domain);
    //         //m_udpService->startConnectionAttempt();
    //         qDebug()<<"Connecting to "<<m_IpAddress_Domain;
    //         qDebug()<<"UDP服务已创建";


    //         // //连接状态变化信号
    //         // connect(m_udpService, &UdpService::connectionStatusChanged, this, [this](bool isConnected){
    //         //     if(isConnected){
    //         //         qDebug() << "连接成功，切换到遥控界面";
    //         //         ui->stackedWidget->setCurrentWidget(ui->page_rc);
    //         //         m_sendDataTimer->start();
    //         //     }else{
    //         //         //ui->stackedWidget->setCurrentWidget(ui->page_connect);
    //         //         m_sendDataTimer->stop();
    //         //     }

    //         // });


    //     }
    // });



    connect(ui->page_connect,&ConnectWidget::ConnectWidget_connectClicked,this,[this](QString ipAddress){

        m_udpService->set_targetAddress(ipAddress);
        m_udpService->startConnectionAttempt();

    });

    //连接状态变化信号
    connect(m_udpService, &UdpService::connectionStatusChanged, this, [this](bool isConnected){
        if(isConnected){
            qDebug() << "连接成功，切换到遥控界面";
            ui->stackedWidget->setCurrentWidget(ui->page_rc);
            showAndroidToast("连接成功",ToastDuration::SHORT);
            m_sendDataTimer->start();
        }else{
            ui->stackedWidget->setCurrentWidget(ui->page_connect);
            showAndroidToast("连接断开",ToastDuration::SHORT);
            m_sendDataTimer->stop();
        }
    });



}



Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_start_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_rc);

    qDebug() << "遥控界面";
}




void Widget::handleBackAction(QWidget *senderWidget)
{
    if (!senderWidget) return;

    // 获取当前的页面指针
    QWidget *currentPage = ui->stackedWidget->currentWidget();

    // 检查当前页面是否为 Connect, RC 或 Test 页面
    if (currentPage == ui->page_rc ||
        currentPage == ui->page_connect ||
        currentPage == ui->page_test)
    {
        // 如果是从子页面返回，则切换回主页面
        qDebug() << "Handling back from" << currentPage->objectName() << ". Switching to page_main.";
        ui->stackedWidget->setCurrentWidget(ui->page_main);

        // 【关键】如果是从 RC 界面返回，确保停止发送数据的定时器
        if (currentPage == ui->page_rc) {
            m_sendDataTimer->stop();
        }
    }
    // 如果当前已经是主页面，或者无法识别的页面，则执行退出操作
    else if (currentPage == ui->page_main)
    {
        qDebug() << "Handling back from page_main. Quitting application.";
        QApplication::quit();
    }
    // C. 默认处理
    // else
    // {
    //     // 默认行为：例如退出应用
    //     QApplication::quit();
    // }
}

void Widget::updateControlValues()
{


    m_Uidata.joystick1 = ui->page_rc->getValue_joystick1();
    m_Uidata.joystick2 = ui->page_rc->getValue_joystick2();
    m_Uidata.scroller_horiz1 = ui->page_rc->getValue_scroller_horiz1();
    m_Uidata.scroller_vertical1 = ui->page_rc->getValue_scroller_vertical1();


    for (int i = 0; i < 9; ++i) {
        m_Uidata.button_group1[i]=ui->page_rc->getValue_button_group1()[i];
    }

}

bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    // 1. 检查事件类型是否为按键按下事件
    if (event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);

        // 2. 检查按下的键是否为返回键
        if (keyEvent->key() == Qt::Key_Back)
        {
            // 3. 执行统一的处理逻辑
            handleBackAction(qobject_cast<QWidget*>(watched));

            // 4. 阻止事件继续传播到子 Widget 或父 Widget
            return true; // 表示事件已处理
        }
    }

    // 对于其他事件或按键，让它们正常处理
    return QWidget::eventFilter(watched, event);
}


void Widget::sendDataTimerTimeout()
{
    updateControlValues();
    m_udpService->sendData(m_Uidata);
    //qDebug() << "Sending data:" << "X:" << m_Uidata.joystick1.x << "Y:" << m_Uidata.joystick1.y;
}


void Widget::on_pushButton_test_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_test);
}




void Widget::on_pushButton_connect_clicked()
{

    qDebug() << "连接界面";
}


void Widget::on_pushButton_connect_2_clicked()
{

    ui->stackedWidget->setCurrentWidget(ui->page_connect);
    qDebug() << "连接界面";
}

void Widget::onStackedWidgetPageChanged(int index)
{
    if (index == ui->stackedWidget->indexOf(ui->page_main))
    {


    }
    else if (index == ui->stackedWidget->indexOf(ui->page_connect))
    {
        qDebug() << "已切换到 page_connect";

        QString ipAddress = m_androidInfoProvider->getIpAddress();
        QString wifiSsid = m_androidInfoProvider->getWifiSsid();
        ui->page_connect->setWifiName(wifiSsid);
        ui->page_connect->setIpAddress(ipAddress);



    }
    else if (index == ui->stackedWidget->indexOf(ui->page_rc))
    {
        qDebug() << "已切换到 page_rc";
    }
    else if (index == ui->stackedWidget->indexOf(ui->page_test))
    {
        qDebug() << "已切换到 page_test";
    }


}

