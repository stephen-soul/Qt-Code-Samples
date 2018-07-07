#include <QCoreApplication>
#include "logic.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    logic programLogic;
    programLogic.returnHello();
    return a.exec();
}
