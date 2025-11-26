#include "connectwidget.h"
#include "ui_connectwidget.h"

#include <QKeyEvent>

ConnectWidget::ConnectWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::ConnectWidget)
{
    ui->setupUi(this);


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
    emit ConnectWidget_connectClicked(ui->domain_ip->text());
}


