#include "qmainwindow.h"
#include <QApplication>
#include<QTextCodec>
#include<QScrollArea>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QMainWindow w;
    w.show();

    return a.exec();
}
