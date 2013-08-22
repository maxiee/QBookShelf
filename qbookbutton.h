#ifndef QBOOKBUTTON_H
#define QBOOKBUTTON_H

#include <QAbstractButton>
#include <QFileDialog>
#include <QFileInfo>

class QBookButton : public QAbstractButton
{
    Q_OBJECT
public:
    explicit QBookButton(QWidget *parent = 0);
    explicit QBookButton(QWidget *parent = 0, const QString &name = "", const QString &addr = "");
signals:
    
public slots:
    void bookPressed();
protected:
    void paintEvent ( QPaintEvent * e );
private:
    bool processBookName(QString &str);
    QString *bookAddr;
    QStringList *bookName;
    QString *address;
    
};

#endif // QBOOKBUTTON_H
