#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->page_main);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_start_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_rc);
}


void Widget::on_pushButton_connect_clicked()
{
 ui->stackedWidget->setCurrentWidget(ui->page_connect);
}

