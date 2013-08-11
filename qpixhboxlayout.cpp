#include "qpixhboxlayout.h"

QPixHBoxLayout::QPixHBoxLayout(QWidget *parent)
{
    QPainter *painter = new QPainter(parent);
    painter->setBrush(QBrush(Qt::cyan,Qt::SolidPattern));
    painter->drawRect(this->geometry());
}
