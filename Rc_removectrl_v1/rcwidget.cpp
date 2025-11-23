#include "rcwidget.h"
#include "ui_rcwidget.h"

RcWidget::RcWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RcWidget)
{
    ui->setupUi(this);
}

RcWidget::~RcWidget()
{
    delete ui;
}
