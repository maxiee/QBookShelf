#include "widget.h"
#include<QFileDialog>
#include<QDir>
#include<QHBoxLayout>

Widget::Widget(QWidget *parent) :
    QScrollArea(parent)
{
    shelfOneFloor *one = new shelfOneFloor(this);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    this->setWidget(one);
    this->resize(one->width(),one->height());
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
