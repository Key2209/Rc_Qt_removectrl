/********************************************************************************
** Form generated from reading UI file 'myscroller_horiz.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYSCROLLER_HORIZ_H
#define UI_MYSCROLLER_HORIZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyScroller_Horiz
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *value_label;
    QSlider *horizontalSlider;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_dowm;
    QPushButton *pushButton_up;

    void setupUi(QWidget *MyScroller_Horiz)
    {
        if (MyScroller_Horiz->objectName().isEmpty())
            MyScroller_Horiz->setObjectName("MyScroller_Horiz");
        MyScroller_Horiz->resize(490, 72);
        MyScroller_Horiz->setStyleSheet(QString::fromUtf8("background-color: #1E1E20;"));
        gridLayout = new QGridLayout(MyScroller_Horiz);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        value_label = new QLabel(MyScroller_Horiz);
        value_label->setObjectName("value_label");
        value_label->setMinimumSize(QSize(50, 50));
        value_label->setMaximumSize(QSize(50, 50));
        value_label->setStyleSheet(QString::fromUtf8("QLabel#value_label {\n"
"    /* \346\240\270\345\277\203\345\244\226\350\247\202 */\n"
"    background-color: #FAFAFA;\n"
"    color: black;             /* \346\267\261\347\201\260\350\211\262\346\226\207\345\255\227 */\n"
"    font-family: \"Segoe UI\", \"Helvetica\", sans-serif;\n"
"    font-weight: bold;\n"
"\n"
"    /* \350\276\271\346\241\206\345\222\214\345\234\206\350\247\222 */\n"
"    border: 1px solid #CCCCCC;  /* \347\273\206\345\276\256\347\232\204\350\276\271\346\241\206 */\n"
"    border-radius: 8px;         /* \346\237\224\345\222\214\347\232\204\345\234\206\350\247\222 */\n"
"    \n"
"    /* \351\230\264\345\275\261\346\225\210\346\236\234 (\345\217\257\351\200\211\357\274\214\344\275\206\346\216\250\350\215\220\357\274\214\346\250\241\346\213\237\346\267\261\345\272\246) */\n"
"    box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1); \n"
"    \n"
"    /* \345\261\205\344\270\255\346\230\276\347\244\272 */\n"
"    qproperty-alignment: AlignCenter; \n"
"}"));

        horizontalLayout_2->addWidget(value_label);

        horizontalSlider = new QSlider(MyScroller_Horiz);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setMinimumSize(QSize(50, 50));
        horizontalSlider->setMaximumSize(QSize(16777215, 50));
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
"    background: #D8D8D8; /* \346\265\205\347\201\260\350\211\262 */\n"
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
"    width: 4px; \n"
"    \n"
"    /* \351\253\230\345\272\246\357\274\232\344\270\216\346\273\221\346\247\275\351\253\230\345\272\246\347\233\270\345\220\214\357\274\214\345\256\236\347\216\260\345\236\202\347\233\264\345\257\271\351\275\220 */\n"
"    height: 50px; \n"
"    \n"
"    /* \346\266\210\351\231\244 handle \347\232\204\351\273\230\350\256\244\347\252\201\345\207\272\350\276\271\350\267\235\357\274\214\344\275\277\345\256\203\345\256\214\345\205\250\345\257\271\351\275\220\346\273\221\346\247\275\344\270\212\344\270\213\350\276\271\347\274"
                        "\230 */\n"
"    margin: 0px 0px 0px 0px; \n"
"    \n"
"    /* \351\242\234\350\211\262\357\274\232\350\256\276\347\275\256\344\270\200\344\270\252\345\217\257\350\247\201\350\211\262\357\274\214\344\275\234\344\270\272\346\213\226\345\212\250\346\240\207\350\256\260 */\n"
"    background: white; \n"
"    \n"
"    /* \350\276\271\346\241\206\357\274\232\347\250\215\345\276\256\345\242\236\345\212\240\344\270\200\347\202\271\345\214\272\345\210\206\345\272\246 */\n"
"    border: 1px solid #333333; \n"
"    border-radius: 1px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:hover {\n"
"    /* 10. \346\202\254\345\201\234\346\227\266\345\242\236\345\212\240\351\230\264\345\275\261\346\210\226\351\253\230\344\272\256 */\n"
"    background: #FFFFFF;\n"
"    border: 1px solid #1E90FF;\n"
"}"));
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_2->addWidget(horizontalSlider);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, -1, 0, -1);
        pushButton_dowm = new QPushButton(MyScroller_Horiz);
        pushButton_dowm->setObjectName("pushButton_dowm");
        pushButton_dowm->setMinimumSize(QSize(50, 50));
        pushButton_dowm->setMaximumSize(QSize(50, 50));
        pushButton_dowm->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \346\240\270\345\277\203\345\244\226\350\247\202 */\n"
"    background-color: #6D6D6D;    /* \351\273\230\350\256\244\350\203\214\346\231\257\350\211\262\357\274\232\346\267\261\350\223\235\350\211\262 */\n"
"    color: black;                 /* \347\231\275\350\211\262\346\226\207\345\255\227 */\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    font-size: 14pt;\n"
"    border: none;                 /* \347\247\273\351\231\244\350\276\271\346\241\206\357\274\214\346\211\201\345\271\263\345\214\226 */\n"
"    border-radius: 12px;          /* \345\244\247\345\234\206\350\247\222\357\274\214\346\233\264\351\200\202\345\220\210\350\247\246\346\216\247 */\n"
"\n"
"    /* \346\237\224\345\222\214\350\277\207\346\270\241\357\274\214\345\242\236\345\274\272\344\272\244\344\272\222\344\275\223\351\252\214 */\n"
"    transition: all 0.2s ease-out; \n"
"}"));

        horizontalLayout->addWidget(pushButton_dowm);

        pushButton_up = new QPushButton(MyScroller_Horiz);
        pushButton_up->setObjectName("pushButton_up");
        pushButton_up->setMinimumSize(QSize(50, 50));
        pushButton_up->setMaximumSize(QSize(50, 50));
        pushButton_up->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \346\240\270\345\277\203\345\244\226\350\247\202 */\n"
"    background-color: #6D6D6D;    /* \351\273\230\350\256\244\350\203\214\346\231\257\350\211\262\357\274\232\346\267\261\350\223\235\350\211\262 */\n"
"    color: black;                 /* \347\231\275\350\211\262\346\226\207\345\255\227 */\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    font-size: 14pt;\n"
"    border: none;                 /* \347\247\273\351\231\244\350\276\271\346\241\206\357\274\214\346\211\201\345\271\263\345\214\226 */\n"
"    border-radius: 12px;          /* \345\244\247\345\234\206\350\247\222\357\274\214\346\233\264\351\200\202\345\220\210\350\247\246\346\216\247 */\n"
"\n"
"    /* \346\237\224\345\222\214\350\277\207\346\270\241\357\274\214\345\242\236\345\274\272\344\272\244\344\272\222\344\275\223\351\252\214 */\n"
"    transition: all 0.2s ease-out; \n"
"}"));

        horizontalLayout->addWidget(pushButton_up);


        horizontalLayout_2->addLayout(horizontalLayout);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        retranslateUi(MyScroller_Horiz);

        QMetaObject::connectSlotsByName(MyScroller_Horiz);
    } // setupUi

    void retranslateUi(QWidget *MyScroller_Horiz)
    {
        MyScroller_Horiz->setWindowTitle(QCoreApplication::translate("MyScroller_Horiz", "Form", nullptr));
        value_label->setText(QCoreApplication::translate("MyScroller_Horiz", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700;\">0</span></p></body></html>", nullptr));
        pushButton_dowm->setText(QCoreApplication::translate("MyScroller_Horiz", "-", nullptr));
        pushButton_up->setText(QCoreApplication::translate("MyScroller_Horiz", "+", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyScroller_Horiz: public Ui_MyScroller_Horiz {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYSCROLLER_HORIZ_H
