#ifndef QBOOKBUTTON_H
#define QBOOKBUTTON_H

#include <QAbstractButton>

class QBookButton : public QAbstractButton
{
    Q_OBJECT
public:
    explicit QBookButton(QWidget *parent = 0);
    
signals:
    
public slots:

protected:
    void paintEvent ( QPaintEvent * e );
private:
    bool processBookName(QString *str);
    QString *bookAddr;
    QStringList *bookName;
    
};

#endif // QBOOKBUTTON_H
