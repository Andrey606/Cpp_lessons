#include <QCoreApplication>
#include <QString>
#include <QDebug>
//#include <string.h>
//#include <iostream>
#include "yaml-cpp/yaml.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "cross-compile";

    //std::string var = "string";

    //std::cout << "hello: " << var << std::endl;

    return a.exec();
}
