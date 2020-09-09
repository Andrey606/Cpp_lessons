#include <QCoreApplication>
#include <QString>
#include <QDebug>
#include <QFile>
#include <QSettings>
#include <string.h>
#include <iostream>
#include <fstream>
#include "yaml-cpp/yaml.h"


#define PATH_TO_YAML_FILE   "/usr/config/"
#define NAME_OF_YAML_FILE   "immortal_omo_devices.yaml"

void upload_immortal_devices(void)
{
    char file_path[50] = {0}; strcat(file_path, PATH_TO_YAML_FILE); strcat(file_path, NAME_OF_YAML_FILE);

    std::ifstream fin(file_path);
    YAML::Node doc = YAML::Load(fin);

    QSettings *setting = new QSettings("/usr/config/ZinaSettings_work_embed.conf",QSettings::NativeFormat);

    // проверка наличие файла
    if (!QFile(file_path).exists())
    {
        // ERROR opening yaml file
        qDebug() << "Can't open file \'"+ QString(file_path) + "\'";
        exit(228);
    }

    if(!doc.IsNull() && setting->value("ALL/REJOIN").toString() == "ENABLE")
    {
        qInfo().noquote() << endl << " rejoin are enabled" << endl;
        for(unsigned i=0;i<doc.size();i++)
        {
            qInfo() << "loaded";
        }
    }
    else
    {
        qInfo().noquote() << endl << " rejoin are disabled" << endl;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "cross-compile";

    std::string var = "string";

    std::cout << "hello: " << var << std::endl;

    upload_immortal_devices();

    return a.exec();
}
