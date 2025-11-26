#ifndef CONNECTWIDGET_H
#define CONNECTWIDGET_H

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

        return ui->domain_ip->text();
    }

signals:
    void ConnectWidget_connectClicked(QString ipAddress);






private slots:
    void on_pushButton_connect_clicked();

private:
    Ui::ConnectWidget *ui;


protected:
    // ⭐ 保护方法：重写按键事件处理函数
    //void keyPressEvent(QKeyEvent *event) override;



};

#endif // CONNECTWIDGET_H
