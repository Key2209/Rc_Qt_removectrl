#ifndef CONNECTWIDGET_H
#define CONNECTWIDGET_H

#include <QSettings>
#include <QWidget>
#include "ui_connectwidget.h"

namespace Ui {
class ConnectWidget;
}

class ConnectWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ConnectWidget(QWidget *parent = nullptr);
    ~ConnectWidget();

    QString getIpAddress() const
    {

        return ui->domain->text();
    }
    void setConnectIpAddress(const QString &ipAddress)
    {
        qDebug() << "设置连接IP地址为：" << ipAddress;
        ui->ip_address->setText(ipAddress);

    }
    void setWifiName(QString ssid)
    {
        // 1. 设置文本内容
        ui->lbl_wifi_status->setText("局域网:"+ssid.remove(QChar('"')));


        ui->lbl_wifi_status->setAlignment(Qt::AlignCenter);
        // 2. 使用 setStyleSheet 设置文本格式
        ui->lbl_wifi_status->setStyleSheet(
            "QLabel {"
            "   color: black;           /* 文字颜色：亮蓝色 */"
            "   font-size: 20pt;          /* 字体大小：18磅 */"
            "   font-weight: bold;        /* 字体粗细：加粗 */"
            "   font-family: 'Arial';     /* 字体类型 */"
            "   text-align: center;       /* 【关键】设置文本水平居中 */"
            "}"
            );
    }
    void setIpAddress(QString ipAddress)
    {


        ui->phone_ip->setText("本机IP地址:"+ipAddress.remove(QChar('"')));
        // 2. 使用 setStyleSheet 设置文本格式
        ui->phone_ip->setAlignment(Qt::AlignCenter);
        ui->phone_ip->setStyleSheet(
            "QLabel {"
            "   font-size: 20pt;          /* 字体大小：18磅 */"
            "   font-family: 'Arial';     /* 字体类型 */"
            "   text-align: center;       /* 【关键】设置文本水平居中 */"
            "   font-weight: bold;        /* 字体粗细：加粗 */"
            "   color: #8E8E93; "
            "   font-size: 11pt;"
            "   font-weight: 400;"
            "}"
            );
    }


signals:
    void ConnectWidget_connectClicked(QString ipAddress);

    void ConnectWidget_domainClicked(QString ipAddress);




private slots:
    void on_pushButton_connect_clicked();

    void on_pushButton_domain_clicked();

private:
    Ui::ConnectWidget *ui;

    QSettings *m_settings;
protected:
    // ⭐ 保护方法：重写按键事件处理函数
    //void keyPressEvent(QKeyEvent *event) override;



};

#endif // CONNECTWIDGET_H
