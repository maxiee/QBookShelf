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

Widget::~Widget()
{
}
