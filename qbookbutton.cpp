#include "qbookbutton.h"
#include <QPainter>

QBookButton::QBookButton(QWidget *parent) :
    QAbstractButton(parent)
{
    this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
}

void QBookButton::paintEvent(QPaintEvent *e)
{
    this->setText(QString("[C.GUI.Qt.4编程(第二版)]（加）布兰切特，（英）萨默菲尔德.扫描版.pdf"));

    QPainter painter(this);
    painter.setWindow(QRect(0,0,170,240));
    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(Qt::cyan,Qt::SolidPattern));
    painter.drawRect(0,0,170,240);
    painter.setPen(QPen(Qt::black,3,Qt::SolidLine));
    QString *str = new QString;
    str->append(text());
    processBookName(str);
    int i=0;
    for(i=0;i<bookName->size();i++)
        painter.drawText(0,60+20*i,bookName->at(i));

}

bool QBookButton::processBookName(QString *str)
{
    if(str->at(0)!='[')
        return false;
    int i=str->indexOf(']');
    if(i==-1)
        return false;
    bookName = new QStringList();
    bookName->append(str->mid(1,i-1));
    str->remove(0,i+1);
    bookName->append(str->split("."));
    return true;
}
