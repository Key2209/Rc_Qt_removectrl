#ifndef RCWIDGET_H
#define RCWIDGET_H

#include <QWidget>
#include "myscroller_horiz.h"
#include "myscroller_vertical.h"
#include "ui_rcwidget.h"
#include "mybutton.h"
namespace Ui {
class RcWidget;
}

class RcWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RcWidget(QWidget *parent = nullptr);
    ~RcWidget();
    JoystickDataStruct getValue_joystick1(){
       return ui->Joystick_widget1->get_Joystick_ALLData();
    };
    JoystickDataStruct getValue_joystick2(){
        return ui->Joystick_widget2->get_Joystick_ALLData();
    }

    float getValue_scroller_horiz1(){
        return ui->myScroller_Horiz_widget1->getValue();
    };
    float getValue_scroller_vertical1(){
        return ui->myScroller_vertical_widget1->getValue();
    };

    int* getValue_button_group1(){
        static int button_states[9];
        button_states[0]=ui->pushButton->get_ButtonState();
        button_states[1]=ui->pushButton_2->get_ButtonState();
        button_states[2]=ui->pushButton_3->get_ButtonState();
        button_states[3]=ui->pushButton_4->get_ButtonState();
        button_states[4]=ui->pushButton_5->get_ButtonState();
        button_states[5]=ui->pushButton_6->get_ButtonState();
        button_states[6]=ui->pushButton_7->get_ButtonState();
        button_states[7]=ui->pushButton_8->get_ButtonState();
        button_states[8]=ui->pushButton_9->get_ButtonState();
        return button_states;
    };

private:
    Ui::RcWidget *ui;





};

#endif // RCWIDGET_H
