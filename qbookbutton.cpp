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
    painter.setWindow(QRect(0,0,340,480));
    painter.setPen(Qt::NoPen);
    QLinearGradient bookGradient(170,0,170,480);
    bookGradient.setColorAt(0.3,QColor(239,200,135));
    bookGradient.setColorAt(1.0,QColor(249,234,208));
    painter.setBrush(bookGradient);
    painter.drawRect(0,0,340,480);
    painter.setPen(QPen(Qt::black,3,Qt::SolidLine));
    QString *str = new QString;
    str->append(text());
    processBookName(str);
    //painter.drawPixmap(0,0,170,240,QPixmap("classic.jpg"));
    QFont font("Tiems",26,QFont::Bold);
    int i=0;
    painter.setFont(font);
    if(bookName->at(0).count()>10)
    {
        painter.drawText(0,80,340,40,Qt::AlignCenter,bookName->at(i).mid(0,10));
        painter.drawText(0,140,340,40,Qt::AlignCenter,bookName->at(i).mid(10,10));
    }
    else
        painter.drawText(0,80,340,40,Qt::AlignCenter,bookName->at(i));
    font.setPixelSize(18);
    painter.setFont(font);
    painter.drawText(0,220,340,40,Qt::AlignCenter,bookName->at(1));
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
