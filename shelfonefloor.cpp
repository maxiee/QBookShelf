#include "shelfonefloor.h"

shelfOneFloor::shelfOneFloor(QWidget *parent) :
    QWidget(parent)
{
    this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    QBookButton *btn1 = new QBookButton(this);
    QBookButton *btn2 = new QBookButton(this);
    QBookButton *btn3 = new QBookButton(this);
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(btn1);
    layout->addWidget(btn2);
    layout->addWidget(btn3);
    this->setLayout(layout);
}

void shelfOneFloor::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setWindow(this->geometry());
    painter.setBrush(QBrush(QColor(168,130,81)));
    painter.drawRect(this->geometry());
}
