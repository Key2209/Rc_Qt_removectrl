
#ifndef MYSCROLLER_HORIZ_H
#define MYSCROLLER_HORIZ_H

#include <QWidget>
#include <QScrollBar>
#include <QSpinBox>
#include <QBoxLayout>
#include <QTouchEvent>


namespace Ui {
class MyScroller_Horiz;
}

class MyScroller_Horiz : public QWidget
{
    Q_OBJECT

public:
    explicit MyScroller_Horiz(QWidget *parent = nullptr);
    ~MyScroller_Horiz();

    // 外部接口
    void setRange(float min, float max);          // 设置数值范围
    void setSingleStep(float step);             // 设置步进值（QSlider默认没有，但此处保留）
    void setvalue(int value);                 // 设置当前值
    float getValue(){return current_value;};  // 获取当前值


private:
    Ui::MyScroller_Horiz *ui;

signals:
    void scrollerValueChanged(int value); // 值变化时发射信号

protected:
    // 重写触摸事件处理
    void touchEvent(QTouchEvent *event);
    bool event(QEvent *event) override;

private slots:
    void on_pushButton_up_clicked();
    void on_pushButton_dowm_clicked();

private:
    // 布局和区域管理（虽然在当前文件中未实现，但保留定义）
    void setupLayout();                       // 初始化布局
    void updateTouchArea();                   // 更新触摸区域

    // --- 数据模型 ---
    float min_value = 0.0;
    float max_value = 100.0;
    float current_value = 0.0;



    QRect m_touchArea;                        // 有效触摸区域（在touchEvent中未使用，但保留）


    bool m_isDragging = false; // 【新增】跟踪手指是否正在拖动滑块
    int m_activeTouchId = -1;  // 【新增】跟踪当前激活的触点 ID
};

#endif // MYSCROLLER_HORIZ_H
