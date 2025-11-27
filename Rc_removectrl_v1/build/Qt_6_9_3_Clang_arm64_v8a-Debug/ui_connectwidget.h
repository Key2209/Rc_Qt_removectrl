/********************************************************************************
** Form generated from reading UI file 'connectwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTWIDGET_H
#define UI_CONNECTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConnectWidget
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *lbl_wifi_status;
    QLabel *phone_ip;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *domain;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLineEdit *ip_address;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_domain;
    QPushButton *pushButton_connect;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *ConnectWidget)
    {
        if (ConnectWidget->objectName().isEmpty())
            ConnectWidget->setObjectName("ConnectWidget");
        ConnectWidget->resize(781, 506);
        ConnectWidget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #FFFFFF;\n"
"	color:#FFFFFF;\n"
"    border-radius: 15px;\n"
"}\n"
""));
        gridLayout = new QGridLayout(ConnectWidget);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(60, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        lbl_wifi_status = new QLabel(ConnectWidget);
        lbl_wifi_status->setObjectName("lbl_wifi_status");
        lbl_wifi_status->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background: transparent;"));

        verticalLayout_4->addWidget(lbl_wifi_status);

        phone_ip = new QLabel(ConnectWidget);
        phone_ip->setObjectName("phone_ip");
        phone_ip->setStyleSheet(QString::fromUtf8("color: #8E8E93; font-size: 11pt; font-weight: 400;"));

        verticalLayout_4->addWidget(phone_ip);

        verticalLayout_4->setStretch(0, 3);
        verticalLayout_4->setStretch(1, 2);

        verticalLayout_5->addLayout(verticalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_4 = new QLabel(ConnectWidget);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(100, 50));
        label_4->setMaximumSize(QSize(100, 50));
        label_4->setStyleSheet(QString::fromUtf8("    background-color: #E3E3E3;\n"
"    color: black;\n"
"    border-radius: 12px;\n"
"    font-size: 15px;\n"
"    font-weight: bold;"));

        horizontalLayout_5->addWidget(label_4);

        domain = new QLineEdit(ConnectWidget);
        domain->setObjectName("domain");
        domain->setMinimumSize(QSize(250, 50));
        domain->setMaximumSize(QSize(250, 50));
        domain->setStyleSheet(QString::fromUtf8("background-color: #E3E3E3;\n"
"border-raidus:2px;"));

        horizontalLayout_5->addWidget(domain);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_5 = new QLabel(ConnectWidget);
        label_5->setObjectName("label_5");
        label_5->setMinimumSize(QSize(100, 50));
        label_5->setMaximumSize(QSize(100, 50));
        label_5->setStyleSheet(QString::fromUtf8("    background-color: #E3E3E3;\n"
"    color: black;\n"
"    border-radius: 12px;\n"
"    font-size: 15px;\n"
"    font-weight: bold;"));

        horizontalLayout_6->addWidget(label_5);

        ip_address = new QLineEdit(ConnectWidget);
        ip_address->setObjectName("ip_address");
        ip_address->setMinimumSize(QSize(250, 50));
        ip_address->setMaximumSize(QSize(250, 50));
        ip_address->setStyleSheet(QString::fromUtf8("background-color: #E3E3E3;\n"
"border-raidus:2px;"));

        horizontalLayout_6->addWidget(ip_address);


        verticalLayout->addLayout(horizontalLayout_6);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        pushButton_domain = new QPushButton(ConnectWidget);
        pushButton_domain->setObjectName("pushButton_domain");
        pushButton_domain->setMinimumSize(QSize(80, 40));
        pushButton_domain->setMaximumSize(QSize(80, 40));
        pushButton_domain->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: transparent; /* \347\241\256\344\277\235\345\256\271\345\231\250\344\271\237\346\230\257\351\200\217\346\230\216\347\232\204 */\n"
"    color: black;\n"
"	border-color:#F2F2F2;\n"
"	border: 1px solid black; /* \347\256\200\345\206\231\357\274\232\345\220\214\346\227\266\350\256\276\347\275\256\347\262\227\347\273\206\343\200\201\346\240\267\345\274\217\345\222\214\351\242\234\350\211\262 */\n"
"    border-radius: 2px;\n"
"    padding: 6px 15px;\n"
"}"));

        verticalLayout_2->addWidget(pushButton_domain);

        pushButton_connect = new QPushButton(ConnectWidget);
        pushButton_connect->setObjectName("pushButton_connect");
        pushButton_connect->setMinimumSize(QSize(80, 40));
        pushButton_connect->setMaximumSize(QSize(80, 40));
        pushButton_connect->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2ECC71;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 3px;\n"
"    padding: 8px 15px;\n"
"}\n"
""));

        verticalLayout_2->addWidget(pushButton_connect);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(-1, 5, -1, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        checkBox = new QCheckBox(ConnectWidget);
        checkBox->setObjectName("checkBox");
        checkBox->setMinimumSize(QSize(110, 50));
        checkBox->setMaximumSize(QSize(150, 50));
        checkBox->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"    /* 1. \346\226\207\346\234\254\351\242\234\350\211\262\343\200\201\345\255\227\345\217\267\345\222\214\351\227\264\350\267\235\350\246\201\346\261\202 */\n"
"    color: #1C1C1E; \n"
"    font-size: 12pt;\n"
"    spacing: 5px; /* \346\214\207\347\244\272\345\231\250\344\270\216\346\226\207\346\234\254\344\271\213\351\227\264\347\232\204\350\267\235\347\246\273 */\n"
"    \n"
"    /* \351\242\235\345\244\226\347\232\204\345\241\253\345\205\205\357\274\214\347\241\256\344\277\235\347\202\271\345\207\273\345\214\272\345\237\237\350\210\222\351\200\202 */\n"
"    padding: 5px 0px; \n"
"}\n"
"\n"
"/* ================= \346\214\207\347\244\272\345\231\250 (\346\226\271\346\241\206/\345\234\206\345\234\210) \346\240\267\345\274\217 ================= */\n"
"\n"
"QCheckBox::indicator {\n"
"    /* \342\255\220 \350\256\276\347\275\256\346\214\207\347\244\272\345\231\250\347\232\204\345\260\272\345\257\270 (\345\256\236\347\216\260\346\224\276\345\244\247\346\225\210\346\236\234) \342\255\220 */\n"
"  "
                        "  width: 24px;\n"
"    height: 24px; \n"
"    \n"
"    /* \350\276\271\346\241\206\345\222\214\350\203\214\346\231\257\357\274\214\345\210\233\345\273\272\346\234\252\351\200\211\344\270\255\347\232\204\345\244\226\350\247\202 */\n"
"    border-radius: 6px; /* \346\237\224\345\222\214\347\232\204\345\234\206\350\247\222\357\274\214\344\271\237\345\217\257\344\273\245\346\224\271\344\270\272 12px \345\256\236\347\216\260\345\234\206\345\275\242 */\n"
"    border: 1px solid #C7C7CC; /* \346\265\205\347\201\260\350\211\262\350\276\271\346\241\206 */\n"
"    background-color: white; \n"
"}\n"
"\n"
"/* \346\234\252\351\200\211\344\270\255\347\212\266\346\200\201 */\n"
"QCheckBox::indicator:unchecked {\n"
"    background-color: white; \n"
"}\n"
"\n"
"/* \351\200\211\344\270\255\347\212\266\346\200\201 */\n"
"QCheckBox::indicator:checked {\n"
"    /* iOS \347\273\277\350\211\262\345\241\253\345\205\205 */\n"
"    background-color: #34C759; \n"
"\n"
"    \n"
"}"));

        horizontalLayout->addWidget(checkBox);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 1);

        horizontalLayout_2->addLayout(verticalLayout_3);


        verticalLayout_5->addLayout(horizontalLayout_2);

        verticalLayout_5->setStretch(0, 5);
        verticalLayout_5->setStretch(1, 4);

        gridLayout->addLayout(verticalLayout_5, 1, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(60, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 110, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 15);
        gridLayout->setRowStretch(2, 5);
        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 10);
        gridLayout->setColumnStretch(2, 1);

        retranslateUi(ConnectWidget);

        QMetaObject::connectSlotsByName(ConnectWidget);
    } // setupUi

    void retranslateUi(QWidget *ConnectWidget)
    {
        ConnectWidget->setWindowTitle(QCoreApplication::translate("ConnectWidget", "Form", nullptr));
        lbl_wifi_status->setText(QCoreApplication::translate("ConnectWidget", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; font-weight:700;\">WIFI\351\205\215\347\275\256</span></p></body></html>", nullptr));
        phone_ip->setText(QCoreApplication::translate("ConnectWidget", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700;\">\346\234\254\346\234\272IP\345\234\260\345\235\200:192.168....</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("ConnectWidget", "<html><head/><body><p align=\"center\">\350\256\276\345\244\207\345\220\215\347\247\260\357\274\232</p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("ConnectWidget", "<html><head/><body><p align=\"center\">\350\256\276\345\244\207IP\357\274\232</p></body></html>", nullptr));
        pushButton_domain->setText(QCoreApplication::translate("ConnectWidget", "\346\237\245\346\211\276IP", nullptr));
        pushButton_connect->setText(QCoreApplication::translate("ConnectWidget", "\350\277\236\346\216\245", nullptr));
        checkBox->setText(QCoreApplication::translate("ConnectWidget", "\344\270\213\346\254\241\350\207\252\345\212\250\350\277\236\346\216\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConnectWidget: public Ui_ConnectWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTWIDGET_H
