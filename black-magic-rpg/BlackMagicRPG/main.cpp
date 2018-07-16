#include "game.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    game gameLogic;
    w.show();
    return a.exec();
}
