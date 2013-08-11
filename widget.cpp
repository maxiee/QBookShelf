#include "widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    shelfOneFloor *one = new shelfOneFloor;
    shelfOneFloor *two = new shelfOneFloor;
    shelfOneFloor *three = new shelfOneFloor;
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(one);
    layout->addWidget(two);
    layout->addWidget(three);
    this->setLayout(layout);
}

Widget::~Widget()
{
}
