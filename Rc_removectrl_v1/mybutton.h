#ifndef MYBUTTON_H
#define MYBUTTON_H
#include <QPushButton>
#include <QMouseEvent>

class MyButton : public QPushButton
{
    Q_OBJECT

    // ⭐ 关键: 暴露 ButtonMode 属性给 Qt Designer
    // DESIGNABLE true 允许在 Designer 的属性编辑器中看到并修改此属性
    Q_PROPERTY(ButtonMode buttonMode READ getButtonMode WRITE setButtonMode DESIGNABLE true)

public:
    // 按钮模式枚举
    enum ButtonMode {
        MomentaryMode, // 模式 1: 按下保持，释放回弹 (例如: 加速/刹车)
        ToggleMode     // 模式 2: 按下一次打开，再按一次关闭 (例如: 灯光开关)
    };
    Q_ENUM(ButtonMode) // 启用 Qt 元对象系统识别枚举


    // ⭐ 默认构造函数：供 Qt Designer 或提升的 Widget 使用
    explicit MyButton(QWidget *parent = nullptr);
    // 构造函数：接收按钮文本、模式和父对象
    explicit MyButton(const QString &text, ButtonMode mode, QWidget *parent = nullptr);


    // ⭐ 关键修正 1: Q_PROPERTY 的 Getter 方法 (READ)
    ButtonMode getButtonMode() const { return m_mode; }

    // Q_PROPERTY 的 Setter 方法 (WRITE)
    // 负责在 Designer 中设置属性后，重新配置按钮模式
    void setButtonMode(ButtonMode mode);

    int get_ButtonState(){ return m_state; }



signals:


protected:
    // 重写鼠标按下事件，用于处理触摸输入
    void mousePressEvent(QMouseEvent *event) override
    {
        // 屏蔽鼠标事件以避免与触摸冲突
        event->ignore();
    }
    void mouseReleaseEvent(QMouseEvent *event) override
    {
        event->ignore();
    }


private slots:
    // 模式 1 逻辑槽函数：处理 QPushButton::pressed
    void handlePressed();
    // 模式 1 逻辑槽函数：处理 QPushButton::released
    void handleReleased();

    // 模式 2 逻辑槽函数：处理 QPushButton::toggled
    void handleToggle(bool checked);

private:
    // 统一的初始化逻辑：设置模式、连接信号和样式
    void setupButton(ButtonMode mode);
    ButtonMode m_mode; // 当前按钮的模式，与 Q_PROPERTY 保持一致

    int m_state = 0; // 按钮状态变量 (0: OFF, 1: ON)

    bool event(QEvent *event) override;
};

#endif // MYBUTTON_H
