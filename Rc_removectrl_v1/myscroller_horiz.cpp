
#include "myscroller_horiz.h"
#include "ui_myscroller_horiz.h"
#include <QTouchEvent>
#include <QDebug>
#include <QCoreApplication>


MyScroller_Horiz::MyScroller_Horiz(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyScroller_Horiz)
{
    // 【关键】必须显式开启触摸事件支持
    setAttribute(Qt::WA_AcceptTouchEvents);
    ui->setupUi(this);

    // QSlider的范围固定为 0-100，用于标准化
    ui->horizontalSlider->setRange(0,100);


    setRange(-20,80);

    connect(ui->horizontalSlider, &QSlider::valueChanged, this, [this](int value){
        // QSlider value (0-100)
        double normalized = value / 100.0;

        // 1. 计算映射后的 current_value (这部分必须每次都执行)
        if (min_value < 0 && max_value > 0)
        {
            float negative_part= -min_value/(max_value - min_value); // 负数部分占比
            float div= negative_part*100.0f; // 分界点位置 (0-100)
            if (value < div)
            {
                // 左半边: 0% -> min_value, div% -> 0
                double ratio_left = value / div;
                current_value = (1-ratio_left) * min_value; // 0~div 映射到 min_value~0
            }
            else
            {
                // 右半边: div% -> 0, 100% -> max_value
                double ratio_right = (value - div) / (100.0 - div);
                current_value = ratio_right * max_value; // 0~(100-div) 映射到 0~max_value
            }
        }
        else
        {
            // 正常范围 (全正或全负)
            current_value = normalized * (max_value - min_value) + min_value;
        }



            ui->value_label->setText(QString::number(current_value, 'f', 2));


    });
}


MyScroller_Horiz::~MyScroller_Horiz()
{
    delete ui;
}


// 设置数值范围（min:最小值，max:最大值）
void MyScroller_Horiz::setRange(float min, float max) {
    min_value = static_cast<float>(min);
    max_value = static_cast<float>(max);

}


void MyScroller_Horiz::setvalue(int value)
{
    // 这里传入的是 QSlider 的 0-100 范围的值
    ui->horizontalSlider->setValue(value);
}


// 事件处理入口 (简化版，只处理触摸事件)
bool MyScroller_Horiz::event(QEvent *event) {
    switch (event->type()) {
    case QEvent::TouchBegin:
    case QEvent::TouchUpdate:
    case QEvent::TouchEnd:
        // 直接将事件转发给 touchEvent 处理
        touchEvent(static_cast<QTouchEvent*>(event));
        // 注意：返回 false 或 QWidget::event(event) 允许 QSlider 内部接收 Mouse Events
        // 但由于 touchEvent 中已设置 setValue，返回 true 更安全
        return true;
    case QEvent::Resize:
        updateTouchArea(); // 如果需要根据大小调整触摸区域
    default:
        break;
    }
    return QWidget::event(event);
}

// 核心触摸处理逻辑 (处理多指，将触摸位置映射到 QSlider 的值)
void MyScroller_Horiz::touchEvent(QTouchEvent *event) {
    // 检查当前事件是否包含任何活跃的触点
    if (event->points().isEmpty()) {
        event->ignore();
        return;
    }

    // 遍历所有触点
    for (const QEventPoint &point : event->points()) {

        QPointF localPos = point.position();

        // --- 逻辑分支 1: 启动拖动 (TouchBegin) ---
        if (point.state() == QEventPoint::Pressed) {
            // 只有当新的触点在滑条区域内时，才开始拖动
            if (ui->horizontalSlider->geometry().contains(localPos.toPoint())) {
                m_isDragging = true;
                m_activeTouchId = point.id();
            }
        }

        // --- 逻辑分支 2: 正在拖动 (TouchUpdate) ---
        // 如果当前是激活触点且处于拖动状态，执行滑动逻辑
        if (m_isDragging && point.id() == m_activeTouchId &&
            (point.state() == QEventPoint::Updated || point.state() == QEventPoint::Pressed)) {

            // 【关键修改】：不再检查 localPos 是否在滑条的垂直/水平边界内。
            // 只要手指在拖动，就基于其水平位置计算滑条的值。

            // 计算触摸点在 QSlider 内部的相对位置
            double slider_x = localPos.x() - ui->horizontalSlider->x();

            // 计算标准化位置 (0.0 ~ 1.0)
            // 注意：qBound(0.0, ..., 1.0) 确保即使手指超出滑条左右边界，normalized 也不会超过 0 或 1。
            double normalized = qBound(0.0, slider_x / ui->horizontalSlider->width(), 1.0);

            // 将标准化位置映射回 QSlider 的值域 (0-100)
            int min = ui->horizontalSlider->minimum();
            int max = ui->horizontalSlider->maximum();

            // 使用 qRound 解决精度问题
            int newValue = min + qRound(normalized * (max - min));

            // 边界约束
            newValue = qBound(min, newValue, max);

            // 更新 QSlider 的值 (这会触发 valueChanged 信号)
            ui->horizontalSlider->setValue(newValue);

            // 标记事件已被处理
            event->accept();
            return;
        }

        // --- 逻辑分支 3: 结束拖动 (TouchEnd / Released) ---
        if (point.state() == QEventPoint::Released) {
            // 如果释放的触点是激活触点，则停止拖动
            if (point.id() == m_activeTouchId) {
                m_isDragging = false;
                m_activeTouchId = -1;
            }
        }
    }

    // 如果事件包含触点，但没有触点触发拖动，则忽略
    if (m_isDragging) {
        // 如果正在拖动，则接受事件以防止其被父控件抢占
        event->accept();
    } else {
        event->ignore();
    }
}


void MyScroller_Horiz::on_pushButton_up_clicked()
{
    ui->horizontalSlider->setValue(ui->horizontalSlider->value()+1);

}


void MyScroller_Horiz::on_pushButton_dowm_clicked()
{
    ui->horizontalSlider->setValue(ui->horizontalSlider->value()-1);
}

void MyScroller_Horiz::updateTouchArea()
{
    m_touchArea = ui->horizontalSlider->geometry().adjusted(-20,-20,20,20);
}

