#include "widget.h"

Widget::Widget(QWidget *parent) :
    QScrollArea(parent)
{
    shelfOneFloor *one = new shelfOneFloor(this);

    //one->resize(500,700);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    this->setWidget(one);
    this->setWindowTitle("QBookShelf");
    this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    this->resize(one->width()+20,500);
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setWindow(this->geometry());
    painter.setBrush(QBrush(QColor(212,173,114)));
    painter.drawRect(this->geometry());
}

Widget::~Widget()
{
}
