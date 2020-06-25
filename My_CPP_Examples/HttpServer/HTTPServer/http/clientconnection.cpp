#include "clientconnection.h"

#include <QTcpSocket>
#include <QDebug>
#include <QFile>
#include <QVector>

ClientConnection::ClientConnection(QTcpSocket *socket, QObject *parent) : QObject(parent), m_socket(socket)
{
    connect(m_socket.get(), &QAbstractSocket::disconnected, this, &QObject::deleteLater);
    connect(m_socket.get(), &QIODevice::readyRead, this, &ClientConnection::readyRead);
}

void ClientConnection::readyRead()
{
    while(m_socket->canReadLine())
    {
        const auto line = m_socket->readLine();

        qDebug() << line;

        if(line == "\r\n")
        {
            m_socket->write("HTTP/1.1 200 OK\r\n");
            m_socket->write("Connection: keep-alive\r\n");
            m_socket->write("Connect-Length: 4\r\n");
            m_socket->write("\r\n");
/*
            m_socket->write("<!doctype html>");
            m_socket->write("<html>");
            m_socket->write("<head>");
            m_socket->write("</head>");
            m_socket->write("<body>");
            m_socket->write("<h1 style=\"text-align: center;font-family: 'Open Sans', sans-serif;\">Press Space to start</h1>");

            m_socket->write("<img id=\"offline-resources-1x\" src=\"./100-error-offline.png\">");*/
            QString path = "/home/andrew/Documents/Cpp_lessons/My_CPP_Examples/HttpServer/HTTPServer/http/t-rex-runner/";

            QVector<QString> files;
            files = {"index.html"/*, "assets/default_100_percent/100-offline-sprite.png", "assets/default_200_percent/200-offline-sprite.png"*/};

            for(int i=0; i<files.length(); i++)
            {
                qDebug() << path+files[i];
                QFile inputFile(path+files[i]);
                QByteArray read ;
                inputFile.open(QIODevice::ReadOnly);
                while(1)
                {
                    read.clear();
                    read = inputFile.read(inputFile.size());
                    qDebug() << "Read : " << read.size();
                    if(read.size()==0)
                         break;
                    qDebug() << "Written : " << m_socket->write(read);
                    m_socket->waitForBytesWritten();
                    read.clear();
                }
            }

            /*m_socket->write("</body>");
            m_socket->write("<script>");
            m_socket->write("</script>");
            m_socket->write("</html>");
*/

            m_socket->close();
        }
    }
}

ClientConnection::~ClientConnection() = default;
