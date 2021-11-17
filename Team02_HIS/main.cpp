#include "informations.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Informations w;
    w.show();
    return a.exec();
}
