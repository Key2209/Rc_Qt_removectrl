#include "rcwidget.h"
#include "ui_rcwidget.h"



RcWidget::RcWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RcWidget)
{
    ui->setupUi(this);

    ui->pushButton_7->setButtonMode(MyButton::ToggleMode);
    ui->pushButton_8->setButtonMode(MyButton::ToggleMode);
    ui->pushButton_9->setButtonMode(MyButton::ToggleMode);


    // // 1. 实例化 UdpService
    // m_udpService = new UdpService(4210, this); // 端口 4210

    // // 2. ⭐ 核心：设置回调函数 (依赖注入)
    // // 每次 UdpService::controlTimerTimeout 触发时，都会调用 MainWindow::getControlValues()
    // m_udpService->setControlValueGetter(
    //     std::bind(&RcWidget::getControlValues, this)
    //     );

    // // 3. 配置目标地址 (假设从 UI 界面获取)
    // m_udpService->set_targetMdnsHost("esp32-robot.local");

    // 4. 连接 UI 事件到槽函数 (假设有一个 Connect 按钮)
    // connect(connectButton, &QPushButton::clicked, this, &MainWindow::onConnectClicked);

    // 5. 连接摇杆信号到槽函数
    // connect(m_joystickWidget, &JoystickWidget::valuesChanged,
    //         this, &MainWindow::onJoystickValuesChanged);



}

RcWidget::~RcWidget()
{
    delete ui;
}



