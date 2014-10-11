#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QLabel>
#include <QToolButton>
#include <QBitmap>
#include <QPainter>
#include <qDebug>

namespace Ui {
class Widget;
}

class QToolButton;
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
private:
    Ui::Widget *ui;
    QPoint move_point;
    QToolButton *minButton;
    QToolButton *closeButton;
    QToolButton *maxButton;

    bool mouse_press;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *);
public:
    int wid;
    QLabel *background;
};

#endif // WIDGET_H
