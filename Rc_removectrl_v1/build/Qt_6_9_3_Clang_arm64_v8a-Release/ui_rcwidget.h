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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <joystick.h>
#include <mybutton.h>
#include <myscroller_horiz.h>
#include <myscroller_vertical.h>

QT_BEGIN_NAMESPACE

class Ui_RcWidget
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    MyButton *pushButton;
    MyButton *pushButton_2;
    MyButton *pushButton_3;
    QVBoxLayout *verticalLayout_2;
    MyButton *pushButton_4;
    MyButton *pushButton_5;
    MyButton *pushButton_6;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *textEdit;
    MyScroller_Horiz *myScroller_Horiz_widget1;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    MyButton *pushButton_7;
    MyButton *pushButton_8;
    MyButton *pushButton_9;
    MyScroller_vertical *myScroller_vertical_widget1;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    Joystick *Joystick_widget1;
    QSpacerItem *horizontalSpacer;
    Joystick *Joystick_widget2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *RcWidget)
    {
        if (RcWidget->objectName().isEmpty())
            RcWidget->setObjectName("RcWidget");
        RcWidget->resize(902, 544);
        RcWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 31, 32);"));
        gridLayout = new QGridLayout(RcWidget);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer = new QSpacerItem(20, 44, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(68, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        pushButton = new MyButton(RcWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(80, 50));
        pushButton->setMaximumSize(QSize(80, 50));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new MyButton(RcWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(80, 50));
        pushButton_2->setMaximumSize(QSize(80, 50));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new MyButton(RcWidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setMinimumSize(QSize(80, 50));
        pushButton_3->setMaximumSize(QSize(80, 50));

        verticalLayout->addWidget(pushButton_3);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        pushButton_4 = new MyButton(RcWidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setMinimumSize(QSize(80, 50));
        pushButton_4->setMaximumSize(QSize(80, 50));

        verticalLayout_2->addWidget(pushButton_4);

        pushButton_5 = new MyButton(RcWidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setMinimumSize(QSize(80, 50));
        pushButton_5->setMaximumSize(QSize(80, 50));

        verticalLayout_2->addWidget(pushButton_5);

        pushButton_6 = new MyButton(RcWidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setMinimumSize(QSize(80, 50));
        pushButton_6->setMaximumSize(QSize(80, 50));

        verticalLayout_2->addWidget(pushButton_6);


        horizontalLayout_2->addLayout(verticalLayout_2);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        textEdit = new QTextEdit(RcWidget);
        textEdit->setObjectName("textEdit");
        textEdit->setMinimumSize(QSize(500, 150));
        textEdit->setMaximumSize(QSize(300, 150));

        verticalLayout_3->addWidget(textEdit);

        myScroller_Horiz_widget1 = new MyScroller_Horiz(RcWidget);
        myScroller_Horiz_widget1->setObjectName("myScroller_Horiz_widget1");
        myScroller_Horiz_widget1->setMinimumSize(QSize(500, 60));
        myScroller_Horiz_widget1->setMaximumSize(QSize(300, 60));

        verticalLayout_3->addWidget(myScroller_Horiz_widget1);


        horizontalLayout_4->addLayout(verticalLayout_3);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        pushButton_7 = new MyButton(RcWidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setMinimumSize(QSize(80, 50));
        pushButton_7->setMaximumSize(QSize(80, 50));

        verticalLayout_4->addWidget(pushButton_7);

        pushButton_8 = new MyButton(RcWidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setMinimumSize(QSize(80, 50));
        pushButton_8->setMaximumSize(QSize(80, 50));

        verticalLayout_4->addWidget(pushButton_8);

        pushButton_9 = new MyButton(RcWidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setMinimumSize(QSize(80, 50));
        pushButton_9->setMaximumSize(QSize(80, 50));

        verticalLayout_4->addWidget(pushButton_9);


        horizontalLayout_3->addLayout(verticalLayout_4);

        myScroller_vertical_widget1 = new MyScroller_vertical(RcWidget);
        myScroller_vertical_widget1->setObjectName("myScroller_vertical_widget1");
        myScroller_vertical_widget1->setMinimumSize(QSize(80, 180));
        myScroller_vertical_widget1->setMaximumSize(QSize(80, 180));

        horizontalLayout_3->addWidget(myScroller_vertical_widget1);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        Joystick_widget1 = new Joystick(RcWidget);
        Joystick_widget1->setObjectName("Joystick_widget1");
        Joystick_widget1->setMinimumSize(QSize(150, 150));
        Joystick_widget1->setMaximumSize(QSize(150, 150));

        horizontalLayout->addWidget(Joystick_widget1);

        horizontalSpacer = new QSpacerItem(285, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        Joystick_widget2 = new Joystick(RcWidget);
        Joystick_widget2->setObjectName("Joystick_widget2");
        Joystick_widget2->setMinimumSize(QSize(150, 150));
        Joystick_widget2->setMaximumSize(QSize(150, 150));

        horizontalLayout->addWidget(Joystick_widget2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout_5->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout_5, 1, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(67, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 44, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);


        retranslateUi(RcWidget);

        QMetaObject::connectSlotsByName(RcWidget);
    } // setupUi

    void retranslateUi(QWidget *RcWidget)
    {
        RcWidget->setWindowTitle(QCoreApplication::translate("RcWidget", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("RcWidget", "A", nullptr));
        pushButton_2->setText(QCoreApplication::translate("RcWidget", "B", nullptr));
        pushButton_3->setText(QCoreApplication::translate("RcWidget", "C", nullptr));
        pushButton_4->setText(QCoreApplication::translate("RcWidget", "D", nullptr));
        pushButton_5->setText(QCoreApplication::translate("RcWidget", "E", nullptr));
        pushButton_6->setText(QCoreApplication::translate("RcWidget", "F", nullptr));
        pushButton_7->setText(QCoreApplication::translate("RcWidget", "1", nullptr));
        pushButton_8->setText(QCoreApplication::translate("RcWidget", "2", nullptr));
        pushButton_9->setText(QCoreApplication::translate("RcWidget", "3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RcWidget: public Ui_RcWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RCWIDGET_H
