#include "joystick.h"
#include <QPainter>
#include <QDebug>
#include <cmath>

Joystick::Joystick(QWidget *parent)
    : QWidget(parent) {
    setAttribute(Qt::WA_AcceptTouchEvents);

    String_big_png   = ":/joystick/joystick1.png";
    String_small_png = ":/joystick/joystick2.png";
    //Joystick_Init(); //初始化函数
}

// 通过resizeEvent确保在控件实际尺寸确定后才计算中心位置 避免控件大小尚未确定就将尺寸计算下来
void Joystick::resizeEvent(QResizeEvent* event) {
    QWidget::resizeEvent(event);
    // 每次尺寸变化时重新计算中心位置
    BigCir_xy = rect().center();
    BIG_CIRCLE_RADIUS = width() / 2.0f;
    SMALL_CIRCLE_RADIUS = BIG_CIRCLE_RADIUS * 0.4;
    SmallCir_xy = BigCir_xy;  // 重置小圆位置
    update();
}




void Joystick::Joystick_Init() //设置摇杆大小 和圆心位置
{
    BigCir_xy = rect().center();
    BIG_CIRCLE_RADIUS = this->width()*0.5;
    SMALL_CIRCLE_RADIUS = BIG_CIRCLE_RADIUS * 0.4; //设置为大圆直径多少倍
    // //设置大圆圆心位置
    // centerCir_xy.setX(this->width()*0.5);
    // centerCir_xy.setY(this->height()*0.5);

    //设置小圆圆心位置，与大圆相同
    SmallCir_xy = BigCir_xy ;//= centerCir_xy;

    update();
}


// 获取角度（0-360度）
float Joystick::getAngle() const {
    if (!m_isActive) return -1; //没有触摸摇杆则角度设置为 -1

    QPointF delta = SmallCir_xy - BigCir_xy;  //获得手柄距离中心的 x和 y的距离
    float angle = -std::atan2(delta.y(), delta.x()) * 180 / M_PI;
    return angle < 0 ? angle + 360 : angle;
}

// 获取标准化距离（0-1）
float Joystick::getDistance() const {
    if (!m_isActive) return 0;//没有触摸摇杆则中心距离设置为 0

    QPointF delta = SmallCir_xy - BigCir_xy;  //获得手柄距离中心的 x和 y的距离
    return std::hypot(delta.x(), delta.y()) / BIG_CIRCLE_RADIUS; //  m_radius :摇杆背景半径
}

bool Joystick::isActive() const {
    return m_isActive;
}

int Joystick::activeTouchId() const{
    return m_activeTouchId;
}

/**************************外部接口*****************************/
int Joystick::get_Joystick_Angle(void)
{
    //if (!m_isActive) return -1; //没有触摸摇杆则角度设置为 -1
    return Joystick_Angle;
}
double Joystick::get_Joystick_Long(void)
{
    return Joystick_Long;
}
double Joystick::get_Joystick_X(void)
{
    return Joystick_X;
}
double Joystick::get_Joystick_Y(void)
{
    return Joystick_Y;
}
void Joystick::set_Joystick_Size(int cir_Width,int cir_Height)
{
    this->setFixedSize(cir_Width,cir_Height);
    qDebug()<< cir_Width << "," << cir_Height;
    BIG_CIRCLE_RADIUS = this->width()*0.5;
    SMALL_CIRCLE_RADIUS = BIG_CIRCLE_RADIUS * 0.4;
    //设置大圆圆心位置
    centerCir_xy.setX(this->width()*0.5);
    centerCir_xy.setY(this->height()*0.5);
    //设置小圆圆心位置，与大圆相同
    SmallCir_xy = BigCir_xy = centerCir_xy;
    update();//刷新
}
/**************************外部接口*****************************/


void Joystick::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing); //抗锯齿
    painter.setRenderHints(QPainter::SmoothPixmapTransform);//消锯齿

    //绘制摇杆中的大圆
    QPixmap bigCircle_Pixmap;
    bool ret1 = bigCircle_Pixmap.load(String_big_png);
    if(!ret1)
    {
        QString str = QString("图片 %1 加载失败").arg(String_big_png);
        qDebug() << str;
        return;
    }

    // BigCir_xy = rect().center();
    // BIG_CIRCLE_RADIUS = width() / 2.0f;

    //void QPainter::drawPixmap(int x, int y, int width, int height, const QPixmap &pixmap)
    //参数1,2： 从坐标(x,y)开始画图   参数3,4  所画图的长宽(图可以被拉伸)   参数5  所画图
    painter.drawPixmap(BigCir_xy.x()-BIG_CIRCLE_RADIUS,BigCir_xy.y()-BIG_CIRCLE_RADIUS,\
                                                                                                BIG_CIRCLE_RADIUS*2,BIG_CIRCLE_RADIUS*2,bigCircle_Pixmap);

    //绘制摇杆中的小圆
    QPixmap smallCircle_Pixmap;
    bool ret2 = smallCircle_Pixmap.load(String_small_png);
    if(!ret2)
    {
        QString str = QString("图片 %1 加载失败").arg(String_small_png);
        qDebug() << str;
        return;
    }
    painter.drawPixmap(SmallCir_xy.x()-SMALL_CIRCLE_RADIUS,SmallCir_xy.y()-SMALL_CIRCLE_RADIUS,\
                                                                                                        SMALL_CIRCLE_RADIUS*2,SMALL_CIRCLE_RADIUS*2,smallCircle_Pixmap);


    // 显示 归一化坐标 和 极坐标
    QPointF delta = SmallCir_xy - BigCir_xy;  //获得手柄距离中心的 x和 y的距离
    float angle = -std::atan2(delta.y(), delta.x()) * 180 / M_PI;
    angle =  angle < 0 ? angle + 360 : angle;
    Joystick_Angle = (int)angle;
    Joystick_Long = std::hypot(delta.x(), delta.y()) / BIG_CIRCLE_RADIUS; //  m_radius :摇杆背景半径
    //Joystick_Long = std::sqrt(std::pow(Joystick_X,2)+std::pow(Joystick_Y,2));
    Joystick_X =  (SmallCir_xy.x() - BigCir_xy.x())/ static_cast<double>(BIG_CIRCLE_RADIUS);
    Joystick_Y = -(SmallCir_xy.y() - BigCir_xy.y())/ static_cast<double>(BIG_CIRCLE_RADIUS);
    /*********************数据死区处理*****************************/
    if(Joystick_Long < 0.4)
    {
        Joystick_X = 0;
        Joystick_Y = 0;
        Joystick_Long = 0;
        Joystick_Angle = -1;
    }
    if(Joystick_Long > 0.9)
    {
        Joystick_Long = 1;
    }
    if((Joystick_Angle > 0 && Joystick_Angle < 15) || (Joystick_Angle > 345 && Joystick_Angle < 360))
    {
        Joystick_X = Joystick_Long;
        Joystick_Y = 0;
        Joystick_Angle = 0;
    }
    if((Joystick_Angle > 75 && Joystick_Angle < 105))
    {
        Joystick_X = 0;
        Joystick_Y = Joystick_Long;
        Joystick_Angle = 90;
    }
    if((Joystick_Angle > 165 && Joystick_Angle < 195))
    {
        Joystick_X = -Joystick_Long;
        Joystick_Y = 0;
        Joystick_Angle = 180;
    }
    if((Joystick_Angle > 255 && Joystick_Angle < 285))
    {
        Joystick_X = 0;
        Joystick_Y = -Joystick_Long;
        Joystick_Angle = 270;
    }
    /*********************数据死区处理*****************************/
    emit stateChanged();
}

bool Joystick::event(QEvent *event) {
    switch (event->type()) {
    case QEvent::TouchBegin:
    case QEvent::TouchUpdate:
    case QEvent::TouchEnd:
    {
        //processTouchEvent( ) 职责转移：将具体的触点处理逻辑交给专用方法 // 实现坐标计算、状态更新等核心逻辑
        processTouchEvent(static_cast<QTouchEvent*>(event));// static_cast<QTouchEvent*>(event) 类型转换：将通用 QEvent 转换为具体的 QTouchEvent
        return true;//表示 "该事件已被处理，不需要继续传递"。  若返回 false，事件会继续传递给父控件或其他事件过滤器。
    }
    default:
        return QWidget::event(event);
    }
}

void Joystick::processTouchEvent(QTouchEvent *event) {
    const QList<QEventPoint> points = event->points();

    BigCir_xy = rect().center();
    BIG_CIRCLE_RADIUS = width() / 2.0f;

    // 优先处理已绑定的触点 //作用：确保已绑定的触点优先处理   效果：防止新触点抢夺控制权
    if (m_activeTouchId != -1) {
        // 处理已有触点...

        // 更新或添加触点数据,参数。功能：遍历一个数据范围（如 vector/list），找到第一个满足条件的元素
        auto it = std::find_if(points.begin(), points.end(),
                               [this](const QEventPoint& p){ return p.id() == m_activeTouchId; });

        if (it != points.end()) {
            const QEventPoint& point = *it;
            QPointF localPos = point.position();

            // 关键修复1：持续跟踪即使触点移出控件区域
            // 作用：防止快速移动导致触点丢失
            // 效果：提升摇杆操作顺滑度
            if (point.state() == QEventPoint::Released) {
                m_activeTouchId = -1;
                m_isActive = false;
                SmallCir_xy = BigCir_xy;
                update();
            } else {
                updateHandlePosition(localPos);
            }
        }
        update();
        //emit stateChanged();

        // 提前返回，避免新触点干扰
        return; // 关键修复2：已绑定触点优先处理
    }

    //  下面的这段代码是初次接触摇杆 给触点加ID,后面执行不到这段代码
    // 寻找新触点（仅在无绑定触点时执行）
    for (const QEventPoint &point : points) {
        if (point.state() != QEventPoint::Pressed) continue;

        QPointF localPos = point.position();
        QPointF delta = localPos - BigCir_xy;
        bool inArea = (delta.x() * delta.x() + delta.y() * delta.y())
                      <= (BIG_CIRCLE_RADIUS * BIG_CIRCLE_RADIUS);

        if (inArea && m_activeTouchId == -1) {
            m_activeTouchId = point.id();
            m_isActive = true;
            updateHandlePosition(localPos);
            event->accept(); // 关键修复4：标记事件已处理 :阻止事件继续传播   避免父控件误处理触点事件

            // 作用：确保每个摇杆只绑定一个触点
            // 效果：防止同一摇杆捕获多个触点
            break; // 关键修复5：单触点绑定限制 :一个摇杆只绑定一个触点
        }
    }

    update();
    //emit stateChanged();
}

void Joystick::updateHandlePosition(const QPointF &pos) {
    QPointF delta = pos - BigCir_xy;
    float distance = std::hypot(delta.x(), delta.y());
    // 限制在摇杆范围内
    if (distance > BIG_CIRCLE_RADIUS) {
        delta *= BIG_CIRCLE_RADIUS / distance;
    }
    SmallCir_xy = BigCir_xy + delta;
}

