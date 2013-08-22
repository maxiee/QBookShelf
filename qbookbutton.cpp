#include "qbookbutton.h"
#include <QPainter>
#include<QProcess>

QBookButton::QBookButton(QWidget *parent) :
    QAbstractButton(parent)
{
    this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    //bookAddr = new QString(QFileDialog::getOpenFileName(this,tr("Open Book"), "/"));
    qDebug(bookAddr->toAscii());
    processBookName(*bookAddr);
    connect(this,SIGNAL(clicked()),this,SLOT(bookPressed()));
}

QBookButton::QBookButton(QWidget *parent, const QString &name, const QString &addr) :
    QAbstractButton(parent)
{
    this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    bookAddr = new QString(name);
    qDebug(bookAddr->toAscii());
    processBookName(*bookAddr);
    address = new QString(addr);
    connect(this,SIGNAL(clicked()),this,SLOT(bookPressed()));
    //this->resize(70,140);
}

void QBookButton::paintEvent(QPaintEvent *e)
{
    //this->setText(QString("[C.GUI.Qt.4编程(第二版)]（加）布兰切特，（英）萨默菲尔德.扫描版.pdf"));
    QPainter painter(this);
    painter.setWindow(QRect(0,0,340,480));
    //绘制图书背景
    painter.setPen(Qt::NoPen);
    QLinearGradient bookGradient(170,0,170,480);
    bookGradient.setColorAt(0.3,QColor(239,200,135));
    bookGradient.setColorAt(1.0,QColor(249,234,208));
    painter.setBrush(bookGradient);
    painter.drawRect(0,0,340,480);
    //绘制图书标题
    painter.setPen(QPen(Qt::black,3,Qt::SolidLine));
    QFont font("Tiems",26,QFont::Bold);
    int i=0,currentY=80,bookNameCount;
    bookNameCount = bookName->at(0).count();
    qDebug(QString::number(bookNameCount,10).toAscii());
    painter.setFont(font);
    //绘制大标题
    while(bookNameCount > 0 )
    {
        painter.drawText(0,currentY,340,40,Qt::AlignCenter,bookName->at(0).mid(10*i,10+10*i));
        i++;
        currentY += 60;
        bookNameCount -= 10;
    }
    painter.drawText(0,currentY,340,40,Qt::AlignCenter,bookName->at(0).mid(10*i,10+10*i));
    //绘制小标题
    font.setPixelSize(18);
    painter.setFont(font);
    for(i=1;i<bookName->count();i++)
    {
        painter.drawText(0,currentY,340,40,Qt::AlignCenter,bookName->at(i));
        currentY += 30;
    }
}

bool QBookButton::processBookName(QString &str)
{
    QFileInfo fi;
    fi = QFileInfo(str);
    str = fi.fileName();
    qDebug(str.toAscii());
    if(str.at(0)!='[')
        return false;
    int i=str.indexOf(']');
    if(i==-1)
        return false;
    bookName = new QStringList();
    bookName->append(str.mid(1,i-1));
    str.remove(0,i+1);
    bookName->append(str.split("."));
    return true;
}

void QBookButton::bookPressed()
{
    QString cmd("\"D:\\软件\\Foxit Reader\\Foxit Reader.exe\" ");
    cmd.append(address);
    qDebug(cmd.toAscii());
    //system(cmd.toAscii());
    QProcess p;
    p.execute(cmd);
}
