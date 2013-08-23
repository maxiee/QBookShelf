#ifndef WIDGET_H
#define WIDGET_H

#include <QScrollArea>
#include<QVBoxLayout>
#include <QTabBar>
#include"shelfonefloor.h"
class Widget : public QScrollArea
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
private:
    void paintEvent(QPaintEvent *e);

};

#endif // WIDGET_H
