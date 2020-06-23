#include "clientconnection.h"

#include <QTcpSocket>
#include <QDebug>

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

            m_socket->close();
        }
    }
}

ClientConnection::~ClientConnection() = default;
