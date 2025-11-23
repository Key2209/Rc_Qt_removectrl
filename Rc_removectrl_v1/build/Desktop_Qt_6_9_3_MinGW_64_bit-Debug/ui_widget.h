/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <connectwidget.h>
#include <rcwidget.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_2;
    QStackedWidget *stackedWidget;
    ConnectWidget *page_connect;
    RcWidget *page_rc;
    QWidget *page_main;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_start;
    QPushButton *pushButton_connect;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(647, 467);
        gridLayout_2 = new QGridLayout(Widget);
        gridLayout_2->setObjectName("gridLayout_2");
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName("stackedWidget");
        page_connect = new ConnectWidget();
        page_connect->setObjectName("page_connect");
        stackedWidget->addWidget(page_connect);
        page_rc = new RcWidget();
        page_rc->setObjectName("page_rc");
        stackedWidget->addWidget(page_rc);
        page_main = new QWidget();
        page_main->setObjectName("page_main");
        gridLayout = new QGridLayout(page_main);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        pushButton_start = new QPushButton(page_main);
        pushButton_start->setObjectName("pushButton_start");
        pushButton_start->setMinimumSize(QSize(150, 50));
        pushButton_start->setMaximumSize(QSize(150, 50));

        verticalLayout->addWidget(pushButton_start);

        pushButton_connect = new QPushButton(page_main);
        pushButton_connect->setObjectName("pushButton_connect");
        pushButton_connect->setMinimumSize(QSize(150, 50));
        pushButton_connect->setMaximumSize(QSize(150, 50));

        verticalLayout->addWidget(pushButton_connect);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        stackedWidget->addWidget(page_main);

        gridLayout_2->addWidget(stackedWidget, 0, 0, 1, 1);


        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton_start->setText(QCoreApplication::translate("Widget", "\345\274\200\345\247\213", nullptr));
        pushButton_connect->setText(QCoreApplication::translate("Widget", "\350\277\236\346\216\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
