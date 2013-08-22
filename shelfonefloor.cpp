#include "shelfonefloor.h"
#include<Qdir>
#include<QFileInfo>
#include<QDebug>

shelfOneFloor::shelfOneFloor(QWidget *parent) :
    QWidget(parent)
{
    this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    //QBookButton *btn1 = new QBookButton(this);
    //QBookButton *btn2 = new QBookButton(this);
    //QBookButton *btn3 = new QBookButton(this);
    //QHBoxLayout *layout = new QHBoxLayout(this);
    //打开固定文件夹，获取里面的内容，存到一张表里面去
    QDir *dir = new QDir("E://书库//test");
    bookNameList = new QList<QFileInfo>(dir->entryInfoList());
    QGridLayout *layout = new QGridLayout(this);
    int row,column;
    int count=0;
    for(int i=0;i<bookNameList->count();i++)
    {
        row = count/3;
        column = count%3;
        QString *str = new QString(bookNameList->at(i).fileName());
        QString *str2 = new QString(bookNameList->at(i).absoluteFilePath());
        if(str == QString(".")||str == QString(".."))
            continue;
        count++;
        qDebug()<<row<<","<<column;
        layout->addWidget(new QBookButton(this,*str,*str2),row,column);
    }
    //layout->addWidget(btn1);
    //layout->addWidget(btn2);
    //layout->addWidget(btn3);
    this->setLayout(layout);
    this->resize(500,70*bookNameList->count());
}

void shelfOneFloor::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setWindow(this->geometry());
    painter.setBrush(QBrush(QColor(168,130,81)));
    painter.drawRect(this->geometry());
}
