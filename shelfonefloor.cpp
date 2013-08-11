#include "shelfonefloor.h"

shelfOneFloor::shelfOneFloor(QWidget *parent) :
    QWidget(parent)
{
    this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    QBookButton *btn1 = new QBookButton(this);
    QBookButton *btn2 = new QBookButton(this);
    QBookButton *btn3 = new QBookButton(this);
    QBookButton *btn4 = new QBookButton(this);
    QBookButton *btn5 = new QBookButton(this);
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(btn1);
    layout->addWidget(btn2);
    layout->addWidget(btn3);
    layout->addWidget(btn4);
    layout->addWidget(btn5);
    this->setLayout(layout);
}

void shelfOneFloor::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setWindow(this->geometry());
    painter.setBrush(QBrush(Qt::black,Qt::SolidPattern));
    painter.drawRect(this->geometry());
}
