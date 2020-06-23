#include <QCoreApplication>
#include <QtCore>

#include "webserver.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Webserver webserver;
    webserver.start();

    return a.exec();
}
