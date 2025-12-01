#include "connectwidget.h"
#include "ui_connectwidget.h"

#include <QKeyEvent>
#include <QTimer>




ConnectWidget::ConnectWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::ConnectWidget)
{
    ui->setupUi(this);
    ui->checkBox->hide();//懒得写了直接默认吧
    m_settings = new QSettings;
    QString savedIp = m_settings->value("ip", "").toString();
    QString savedDomain = m_settings->value("domain", "").toString();
    if(!savedIp.isEmpty()&&!savedDomain.isEmpty()){
        qDebug() << "加载保存的IP地址：" << savedIp;
        ui->ip_address->setText(savedIp);
        ui->domain->setText(savedDomain);
        // ⭐ 关键修改：使用 singleShot 延迟执行连接
        // 延迟 0 毫秒执行，这意味着它将在所有构造和事件设置完成后立即执行。
        QTimer::singleShot(0, this, [this]() {
            // 在 Lambda 函数中调用您的连接槽函数
            on_pushButton_connect_clicked();
        });
    }


    // ⭐ 确保 Widget 可以接收键盘焦点，从而接收 QKeyEvent
    setFocusPolicy(Qt::StrongFocus);
    // ⭐ 不需要重写 keyPressEvent

}

ConnectWidget::~ConnectWidget()
{
    delete ui;
}

void ConnectWidget::on_pushButton_connect_clicked()
{

    emit ConnectWidget_connectClicked(ui->ip_address->text());
    m_settings->setValue("ip", ui->ip_address->text()); // 保存IP地址
    m_settings->setValue("domain",ui->domain->text()); // 保存域名
}



void ConnectWidget::on_pushButton_domain_clicked()
{
    emit ConnectWidget_domainClicked(ui->domain->text());
}

