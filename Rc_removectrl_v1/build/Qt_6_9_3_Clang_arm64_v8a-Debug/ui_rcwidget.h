/********************************************************************************
** Form generated from reading UI file 'rcwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RCWIDGET_H
#define UI_RCWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RcWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;

    void setupUi(QWidget *RcWidget)
    {
        if (RcWidget->objectName().isEmpty())
            RcWidget->setObjectName("RcWidget");
        RcWidget->resize(400, 300);
        gridLayout = new QGridLayout(RcWidget);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(RcWidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(RcWidget);

        QMetaObject::connectSlotsByName(RcWidget);
    } // setupUi

    void retranslateUi(QWidget *RcWidget)
    {
        RcWidget->setWindowTitle(QCoreApplication::translate("RcWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("RcWidget", "\351\201\245\346\216\247\345\231\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RcWidget: public Ui_RcWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RCWIDGET_H
