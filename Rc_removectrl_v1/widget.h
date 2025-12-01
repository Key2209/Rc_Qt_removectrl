#ifndef WIDGET_H
#define WIDGET_H

#include "UdpService.h"
#include "joystick.h"
#include "rcwidget.h"
#include <QWidget>
#include <QTimer>
#include <QEvent>
#include "androidinfoprovider.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

#include "datastruct.h"
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_start_clicked();

    void on_pushButton_test_clicked();


    void on_pushButton_connect_clicked();

    void on_pushButton_connect_2_clicked();

    void onStackedWidgetPageChanged(int index);
private:
    Ui::Widget *ui;
    UdpService *m_udpService=nullptr;//UDP服务类
    UiDataStruct m_Uidata;//UI数据结构体
    QString m_IpAddress_Domain;//IP地址或域名

    QTimer *m_sendDataTimer=nullptr;//发送数据定时器
    void handleBackAction(QWidget *senderWidget);

    void updateControlValues();
    UiDataStruct getControlValues(){updateControlValues();return m_Uidata;}
    void sendDataTimerTimeout();

    AndroidInfoProvider *m_androidInfoProvider=nullptr;


    Joystick* joystick1=nullptr;
    Joystick* joystick2=nullptr;
    float scroller_horiz1_value=0.0;
    float scroller_vertical1_value=0.0;
    int *button_group1_states=nullptr;
signals:


protected:
    // ⭐ 重写 eventFilter，用于集中处理所有子 Widget 的事件
    bool eventFilter(QObject *watched, QEvent *event) override;
};
#endif // WIDGET_H
