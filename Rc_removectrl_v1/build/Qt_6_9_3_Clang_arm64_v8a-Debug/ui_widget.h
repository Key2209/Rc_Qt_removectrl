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
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <connectwidget.h>
#include <myscroller_horiz.h>
#include <myscroller_vertical.h>
#include <rcwidget.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_2;
    QStackedWidget *stackedWidget;
    ConnectWidget *page_connect;
    RcWidget *page_rc;
    QWidget *page_test;
    MyScroller_Horiz *widget;
    QSlider *horizontalSlider;
    QSlider *horizontalSlider_2;
    MyScroller_vertical *widget_2;
    QWidget *page_main;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_start;
    QPushButton *pushButton_test;
    QPushButton *pushButton_connect;
    QPushButton *pushButton_connect_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(647, 467);
        Widget->setStyleSheet(QString::fromUtf8("background-color: #EFEFEF;"));
        gridLayout_2 = new QGridLayout(Widget);
        gridLayout_2->setObjectName("gridLayout_2");
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: #EFEFEF;"));
        page_connect = new ConnectWidget();
        page_connect->setObjectName("page_connect");
        stackedWidget->addWidget(page_connect);
        page_rc = new RcWidget();
        page_rc->setObjectName("page_rc");
        stackedWidget->addWidget(page_rc);
        page_test = new QWidget();
        page_test->setObjectName("page_test");
        widget = new MyScroller_Horiz(page_test);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 90, 451, 81));
        widget->setStyleSheet(QString::fromUtf8("background-color: #1E1E20;"));
        horizontalSlider = new QSlider(page_test);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(20, 240, 421, 61));
        horizontalSlider->setStyleSheet(QString::fromUtf8("QSlider {\n"
"    /* 1. \346\266\210\351\231\244\345\244\226\350\276\271\350\267\235\357\274\214\350\256\251\346\273\221\346\235\241\345\215\240\346\215\256\346\225\264\344\270\252\346\216\247\344\273\266\345\214\272\345\237\237 */\n"
"    padding: 0px;\n"
"    margin: 0px;\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"    /* 2. \346\273\221\346\247\275\345\216\232\345\272\246\344\270\216\346\216\247\344\273\266\351\253\230\345\272\246\344\270\200\350\207\264 */\n"
"    height: 50px;\n"
"    \n"
"    /* 3. \350\256\276\347\275\256\346\234\252\345\241\253\345\205\205\345\214\272\345\237\237\347\232\204\350\203\214\346\231\257\350\211\262\357\274\210\345\215\263\347\237\251\345\275\242\345\217\263\344\276\247\347\232\204\351\242\234\350\211\262\357\274\211 */\n"
"    background: #E0E0E0; /* \346\265\205\347\201\260\350\211\262 */\n"
"    \n"
"    /* 4. \346\266\210\351\231\244\350\276\271\346\241\206\357\274\214\344\275\277\345\205\266\347\234\213\350\265\267\346\235\245\345\203\217\344\270\200\344\270\252\347"
                        "\272\257\347\237\251\345\275\242 */\n"
"    border: 1px solid #C0C0C0; \n"
"    \n"
"    /* 5. \346\266\210\351\231\244\345\234\206\350\247\222 */\n"
"    border-radius: 0px; \n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"    /* 6. \350\256\276\347\275\256\345\267\262\345\241\253\345\205\205\345\214\272\345\237\237\347\232\204\350\203\214\346\231\257\350\211\262\357\274\210\345\215\263\347\237\251\345\275\242\345\267\246\344\276\247\347\232\204\351\242\234\350\211\262\357\274\211 */\n"
"    background: #1E90FF; /* \344\272\256\350\223\235\350\211\262 */\n"
"    \n"
"    /* 7. \347\241\256\344\277\235 sub-page \345\220\214\346\240\267\346\230\257\347\233\264\350\247\222 */\n"
"    border-radius: 0px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"    /* 8. \347\241\256\344\277\235 add-page \347\273\247\346\211\277 groove \347\232\204\346\240\267\345\274\217\357\274\210\345\215\263\346\234\252\345\241\253\345\205\205\345\214\272\345\237\237\347\232\204\351\242\234\350\211\262\357\274\211 */\n"
"    backgr"
                        "ound: #E0E0E0;\n"
"    border-radius: 0px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    /* 9. \345\260\206\346\273\221\345\235\227\350\256\276\350\256\241\346\210\220\344\270\200\344\270\252\344\270\215\347\240\264\345\235\217\347\237\251\345\275\242\347\272\277\346\235\241\347\232\204\347\273\206\351\225\277\347\253\226\347\272\277 */\n"
"    \n"
"    /* \345\256\275\345\272\246\357\274\232\351\235\236\345\270\270\347\273\206\347\232\204\347\272\277 */\n"
"    width: 0px; \n"
"    \n"
"    /* \351\253\230\345\272\246\357\274\232\344\270\216\346\273\221\346\247\275\351\253\230\345\272\246\347\233\270\345\220\214\357\274\214\345\256\236\347\216\260\345\236\202\347\233\264\345\257\271\351\275\220 */\n"
"    height: 0px; \n"
"    \n"
"    /* \346\266\210\351\231\244 handle \347\232\204\351\273\230\350\256\244\347\252\201\345\207\272\350\276\271\350\267\235\357\274\214\344\275\277\345\256\203\345\256\214\345\205\250\345\257\271\351\275\220\346\273\221\346\247\275\344\270\212\344\270\213\350\276\271\347\274\230"
                        " */\n"
"    margin: 0px 0px 0px 0px; \n"
"    \n"
"    /* \351\242\234\350\211\262\357\274\232\350\256\276\347\275\256\344\270\200\344\270\252\345\217\257\350\247\201\350\211\262\357\274\214\344\275\234\344\270\272\346\213\226\345\212\250\346\240\207\350\256\260 */\n"
"    background: none; \n"
"    \n"
"    /* \350\276\271\346\241\206\357\274\232\347\250\215\345\276\256\345\242\236\345\212\240\344\270\200\347\202\271\345\214\272\345\210\206\345\272\246 */\n"
"    border: 0px solid #333333; \n"
"    border-radius: 0px;\n"
"}\n"
"\n"
""));
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);
        horizontalSlider_2 = new QSlider(page_test);
        horizontalSlider_2->setObjectName("horizontalSlider_2");
        horizontalSlider_2->setGeometry(QRect(20, 30, 371, 41));
        horizontalSlider_2->setOrientation(Qt::Orientation::Horizontal);
        widget_2 = new MyScroller_vertical(page_test);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(510, 50, 81, 291));
        stackedWidget->addWidget(page_test);
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

        pushButton_test = new QPushButton(page_main);
        pushButton_test->setObjectName("pushButton_test");
        pushButton_test->setMinimumSize(QSize(150, 50));
        pushButton_test->setMaximumSize(QSize(150, 50));

        verticalLayout->addWidget(pushButton_test);

        pushButton_connect = new QPushButton(page_main);
        pushButton_connect->setObjectName("pushButton_connect");
        pushButton_connect->setMinimumSize(QSize(150, 50));
        pushButton_connect->setMaximumSize(QSize(150, 50));

        verticalLayout->addWidget(pushButton_connect);

        pushButton_connect_2 = new QPushButton(page_main);
        pushButton_connect_2->setObjectName("pushButton_connect_2");
        pushButton_connect_2->setMinimumSize(QSize(150, 50));
        pushButton_connect_2->setMaximumSize(QSize(150, 50));

        verticalLayout->addWidget(pushButton_connect_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        stackedWidget->addWidget(page_main);

        gridLayout_2->addWidget(stackedWidget, 0, 0, 1, 1);


        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton_start->setText(QCoreApplication::translate("Widget", "\345\274\200\345\247\213", nullptr));
        pushButton_test->setText(QCoreApplication::translate("Widget", "Test", nullptr));
        pushButton_connect->setText(QCoreApplication::translate("Widget", "\350\277\236\346\216\245", nullptr));
        pushButton_connect_2->setText(QCoreApplication::translate("Widget", "\350\277\236\346\216\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
