#include "widget.h"

Widget::Widget(QWidget *parent) :
    QScrollArea(parent)
{
    shelfOneFloor *one = new shelfOneFloor;
    shelfOneFloor *two = new shelfOneFloor;
    shelfOneFloor *three = new shelfOneFloor;

    QVBoxLayout *layout = new QVBoxLayout(this);
    QWidget *wid = new QWidget(this);
    layout->addWidget(one);
    layout->addWidget(two);
    layout->addWidget(three);

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    wid->setLayout(layout);
    wid->resize(400,600);
    wid->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    this->setWidget(wid);
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
