#include "widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    shelfOneFloor *one = new shelfOneFloor;
    shelfOneFloor *two = new shelfOneFloor;
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(one);
    layout->addWidget(two);
    this->setLayout(layout);
    this->resize(800,600);
    this->setWindowTitle("QBookShelf");
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
