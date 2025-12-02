#include "anaekran.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AnaEkran w;
    w.show();
    return a.exec();
}
