#ifndef SHELFONEFLOOR_H
#define SHELFONEFLOOR_H

#include <QWidget>
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
signals:
    
public slots:
    
};

#endif // SHELFONEFLOOR_H
