#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QVBoxLayout>
#include"shelfonefloor.h"
class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
private:
    void paintEvent(QPaintEvent *e);

};

#endif // WIDGET_H
