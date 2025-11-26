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
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *wifiName;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *domain_ip;
    QPushButton *pushButton_connect;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *ConnectWidget)
    {
        if (ConnectWidget->objectName().isEmpty())
            ConnectWidget->setObjectName("ConnectWidget");
        ConnectWidget->resize(716, 433);
        gridLayout = new QGridLayout(ConnectWidget);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer_2 = new QSpacerItem(20, 161, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(204, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(ConnectWidget);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        wifiName = new QLineEdit(ConnectWidget);
        wifiName->setObjectName("wifiName");

        horizontalLayout_2->addWidget(wifiName);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_3 = new QLabel(ConnectWidget);
        label_3->setObjectName("label_3");

        horizontalLayout->addWidget(label_3);

        domain_ip = new QLineEdit(ConnectWidget);
        domain_ip->setObjectName("domain_ip");

        horizontalLayout->addWidget(domain_ip);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        pushButton_connect = new QPushButton(ConnectWidget);
        pushButton_connect->setObjectName("pushButton_connect");

        verticalLayout_2->addWidget(pushButton_connect);


        gridLayout->addLayout(verticalLayout_2, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(204, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 161, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);


        retranslateUi(ConnectWidget);

        QMetaObject::connectSlotsByName(ConnectWidget);
    } // setupUi

    void retranslateUi(QWidget *ConnectWidget)
    {
        ConnectWidget->setWindowTitle(QCoreApplication::translate("ConnectWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("ConnectWidget", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700;\">WIFI:</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("ConnectWidget", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700;\">IP/DOMAIN</span></p></body></html>", nullptr));
        pushButton_connect->setText(QCoreApplication::translate("ConnectWidget", "\350\277\236\346\216\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConnectWidget: public Ui_ConnectWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTWIDGET_H
