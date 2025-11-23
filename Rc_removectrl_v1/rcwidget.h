#ifndef RCWIDGET_H
#define RCWIDGET_H

#include <QWidget>

namespace Ui {
class RcWidget;
}

class RcWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RcWidget(QWidget *parent = nullptr);
    ~RcWidget();

private:
    Ui::RcWidget *ui;
};

#endif // RCWIDGET_H
