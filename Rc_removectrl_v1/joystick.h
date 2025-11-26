#ifndef JOYSTICK_H
#define JOYSTICK_H
/*
该类来自东莞理工行者战队
*/

#pragma once
#include <QWidget>
#include <QTouchEvent>
#include <QPointF>

typedef struct JoystickDataStruct
{
    float x;
    float y;
    double long_value;
    int angle;
}JoystickDataStruct;


class Joystick : public QWidget {
    Q_OBJECT
public:
    // explicit Joystick(QWidget *parent = nullptr, bool isLeft = true);
    explicit Joystick(QWidget *parent = nullptr);

    // 获取摇杆状态
    float getAngle() const;    // 角度（0-360度）
    float getDistance() const; // 距离中心的比例（0-1）
    bool isActive() const;     // 是否被激活
    int activeTouchId() const; // 获得id


    /**************************外部接口*****************************/
    int get_Joystick_Angle(void);
    double get_Joystick_Long(void);
    double get_Joystick_X(void);
    double get_Joystick_Y(void);
    JoystickDataStruct get_Joystick_ALLData(void){
        return joystickData;
    }
    void set_Joystick_Size(int cir_Width,int cir_Height);
    /**************************外部接口*****************************/


signals:
    void stateChanged(); // 状态变化信号
    //void joystick_Order(); // 状态变化信号

protected:
    void paintEvent(QPaintEvent* event) override;
    bool event(QEvent *event) override;

    void resizeEvent(QResizeEvent* event);


private:
    QPointF centerCir_xy;//窗口圆心
    QPointF BigCir_xy;   //大圆圆心坐标
    QPointF SmallCir_xy; //小圆圆心坐标

    int SMALL_CIRCLE_RADIUS;
    int BIG_CIRCLE_RADIUS;

    QString String_big_png;
    QString String_small_png;


    // 状态参数
    int m_activeTouchId = -1; // 当前绑定的触点ID
    bool m_isActive = false;

    //发送的参数
    double Joystick_X = 0;
    double Joystick_Y = 0;
    double Joystick_Long = 0;
    int Joystick_Angle = 0;
    JoystickDataStruct joystickData;
    void Joystick_Init();
    void processTouchEvent(QTouchEvent *event);
    void updateHandlePosition(const QPointF &pos);
};

#endif // JOYSTICK_H


