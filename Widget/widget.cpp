#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    mouse_press(false),
    ui(new Ui::Widget)
{
    //设置窗体标题栏隐藏并设置位于顶层
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    //可获取鼠标跟踪效果
    setMouseTracking(true);
    // 不继承父组件的背景色
    setAutoFillBackground(true);
    // 使用 Highlight 作为背景色
    //setBackgroundRole(QPalette::Highlight);
    background = new QLabel(this);
    //设置标签的背景色为蓝色
    background->setStyleSheet("background-color:blue");

    //设置图片充满整个标签
    background->setScaledContents(true);

    //构建最小化、最大化、关闭按钮
    minButton = new QToolButton(this);
    closeButton = new QToolButton(this);
    maxButton = new QToolButton(this);

    //获取最小化、关闭按钮图标
    QPixmap minPix  = style()->standardPixmap(QStyle::SP_TitleBarMinButton);
    QPixmap closePix = style()->standardPixmap(QStyle::SP_TitleBarCloseButton);
    QPixmap maxPix = style()->standardPixmap(QStyle::SP_TitleBarMaxButton);

    //设置最小化、关闭按钮图标
    minButton->setIcon(minPix);
    closeButton->setIcon(closePix);
    maxButton->setIcon(maxPix);

    //设置鼠标移至按钮上的提示信息
    minButton->setToolTip(tr("最小化"));
    maxButton->setToolTip(tr("最大化"));
    closeButton->setToolTip(tr("关闭"));

    //设置最小化、关闭按钮的样式
    minButton->setStyleSheet("background-color:transparent;");
    closeButton->setStyleSheet("background-color:transparent;");
    maxButton->setStyleSheet("background-color:transparent;");

    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        mouse_press = true;
        //鼠标相对于窗体的位置（或者使用event->globalPos() - this->pos()）
        move_point = event->pos();;
    }
}
void Widget::mouseMoveEvent(QMouseEvent *event)
{
    //若鼠标左键被按下
    if(mouse_press)
    {
        //鼠标相对于屏幕的位置
        QPoint move_pos = event->globalPos();

        //移动主窗体位置
        this->move(move_pos - move_point);
    }
}
void Widget::mouseReleaseEvent(QMouseEvent *)
{
    //设置鼠标为未被按下
    mouse_press = false;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    wid = this->width();

    //设置背景标签的位置大小
    background->setGeometry(0, 0, this->width(), this->height());
    //设置标签的显示图片
    background->setPixmap(QPixmap(":/images/bg"));
    //设置背景图片的位置大小
    background->setGeometry(0, 0, this->width(), this->height()/3);

    //设置最小化、关闭按钮在界面的位置
    minButton->setGeometry(wid-66,5,20,20);
    maxButton->setGeometry(wid-46,5,20,20);
    closeButton->setGeometry(wid-25,5,20,20);
}
