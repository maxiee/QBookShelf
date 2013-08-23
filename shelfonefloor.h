#ifndef SHELFONEFLOOR_H
#define SHELFONEFLOOR_H

#include <QScrollArea>
//#include<QHBoxLayout>
#include<QPainter>
#include"qbookbutton.h"
#include<QGridLayout>

class shelfOneFloor : public QWidget
{
    Q_OBJECT
public:
    explicit shelfOneFloor(QWidget *parent = 0);
private:
    void paintEvent(QPaintEvent *e);
    int bookCount;
    QList<QFileInfo> *bookNameList;
signals:
    
public slots:
    
};

#endif // SHELFONEFLOOR_H
