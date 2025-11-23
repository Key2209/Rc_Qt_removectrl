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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConnectWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLabel *label_4;
    QLineEdit *lineEdit_2;

    void setupUi(QWidget *ConnectWidget)
    {
        if (ConnectWidget->objectName().isEmpty())
            ConnectWidget->setObjectName("ConnectWidget");
        ConnectWidget->resize(400, 300);
        gridLayout = new QGridLayout(ConnectWidget);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(ConnectWidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(ConnectWidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_3 = new QLabel(ConnectWidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        lineEdit = new QLineEdit(ConnectWidget);
        lineEdit->setObjectName("lineEdit");

        gridLayout->addWidget(lineEdit, 1, 1, 1, 1);

        label_4 = new QLabel(ConnectWidget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        lineEdit_2 = new QLineEdit(ConnectWidget);
        lineEdit_2->setObjectName("lineEdit_2");

        gridLayout->addWidget(lineEdit_2, 2, 1, 1, 1);


        retranslateUi(ConnectWidget);

        QMetaObject::connectSlotsByName(ConnectWidget);
    } // setupUi

    void retranslateUi(QWidget *ConnectWidget)
    {
        ConnectWidget->setWindowTitle(QCoreApplication::translate("ConnectWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("ConnectWidget", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700;\">WIFI:</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("ConnectWidget", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700;\">WIFI:</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("ConnectWidget", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700;\">WIFI:</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("ConnectWidget", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700;\">WIFI:</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConnectWidget: public Ui_ConnectWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTWIDGET_H
