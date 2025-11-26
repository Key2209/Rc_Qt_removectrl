#include "mybutton.h"
#include <QDebug>
#include <QStyle>

// 默认构造函数：供 Qt Designer 或提升的 Widget 使用
MyButton::MyButton(QWidget *parent)
    : QPushButton(parent) // 调用基类构造函数
{
    setAttribute(Qt::WA_AcceptTouchEvents);
    setAttribute(Qt::WA_TouchPadAcceptSingleTouchEvents);
    // ⭐ 关键：设置默认模式。Designer 随后会调用 setButtonMode 覆盖此设置。
    setupButton(MomentaryMode);
}
// =========================================================================
// 2. Q_PROPERTY Setter
// =========================================================================

// Q_PROPERTY 的 Setter 方法 (WRITE)：在 Designer 中设置属性时会被调用
void MyButton::setButtonMode(ButtonMode mode)
{

    // 只有模式变化时才重新配置
    if (m_mode != mode) {
        setupButton(mode);
    }
}

// =========================================================================
// 3. 统一初始化逻辑
// =========================================================================

// 统一的初始化逻辑：设置公共属性和模式特定连接
void MyButton::setupButton(ButtonMode mode)
{
    // 1. 更新模式成员变量
    m_mode = mode;


    // // 2. ⭐ 关键：清除旧连接，防止 setButtonMode 重复连接信号
    // disconnect(this, &QPushButton::toggled, this, &MyButton::handleToggle);
    // disconnect(this, &QPushButton::pressed, this, &MyButton::handlePressed);
    // disconnect(this, &QPushButton::released, this, &MyButton::handleReleased);

    // 3. 设置通用属性和样式
    setFocusPolicy(Qt::StrongFocus);
    //setMinimumSize(120, 80);

    // 应用自定义样式
    setStyleSheet(R"(
QPushButton {
        background-color: #4CAF50;
        color: white;
        border: 2px solid #4CAF50;
        border-radius: 12px;
        font-size: 18px;
        font-weight: 500;
        padding: 10px;
    }

    QPushButton[pressed="true"] {
        background-color: #388E3C;

    }

    QPushButton[checked="true"] {
        background-color: #2196F3;
        border-color: #1976D2;
    }
    )");

    // 4. 根据模式配置 checkable 状态和信号连接
    if (m_mode == ToggleMode) {
        // 模式 2: 开关状态
        setCheckable(true);
        m_state = isChecked() ? 1 : 0; // 同步内部状态

        // 连接 QPushButton::toggled 信号
        //connect(this, &QPushButton::toggled, this, &MyButton::handleToggle);
    } else {
        // 模式 1: 自动回弹
        setCheckable(false); // 必须禁用 checkable
        m_state = 0; // 默认状态为 0

        // // 连接 QPushButton::pressed 和 released 信号
        // connect(this, &QPushButton::pressed, this, &MyButton::handlePressed);
        // connect(this, &QPushButton::released, this, &MyButton::handleReleased);
    }
}

bool MyButton::event(QEvent *event)
{
    switch (event->type())
    {
    case QEvent::TouchBegin:
        if (m_mode == MomentaryMode) handlePressed();
        if (m_mode == ToggleMode) handleToggle(!m_state);
        return true;

    case QEvent::TouchEnd:
        if (m_mode == MomentaryMode) handleReleased();
        return true;

    default:
        break;
    }

    return QPushButton::event(event);
}




MyButton::MyButton(const QString &text, ButtonMode mode, QWidget *parent)
    : QPushButton(text, parent),
    m_mode(mode)
{
    setAttribute(Qt::WA_AcceptTouchEvents);
    setAttribute(Qt::WA_TouchPadAcceptSingleTouchEvents);
    setupButton(mode);
}



// 模式 1 (自动回弹) 按下处理
void MyButton::handlePressed()
{
    qDebug() << text() << " (Momentary) Pressed.";
    m_state=1;
    setProperty("pressed", true);
    style()->polish(this);
}

// 模式 1 (自动回弹) 释放处理
void MyButton::handleReleased()
{
    qDebug() << text() << " (Momentary) Released.";

    m_state=0;
    setProperty("pressed", false);
    style()->polish(this);
}

// 模式 2 (开关状态) 切换处理
void MyButton::handleToggle(bool checked)
{
    // 确保样式更新 (setProperty用于QSS选择器 [checked="true"])
    setProperty("checked", checked);
    style()->polish(this); // 强制应用新的样式

    qDebug() << text() << " (Toggle) State Changed to:" << (checked ? "ON" : "OFF");
    if(checked)
    {
        m_state=1;
    }
    else
    {
        m_state=0;
    }

}
