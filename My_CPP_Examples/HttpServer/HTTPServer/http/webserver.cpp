#include "webserver.h"

#include <QTcpServer>
#include <QDebug>

#include "clientconnection.h"

Webserver::Webserver(QObject *parent) : QObject(parent), m_server(std::make_unique<QTcpServer>())
{
    connect(m_server.get(), &QTcpServer::newConnection, this, &Webserver::newConnection);
}


Webserver::~Webserver() = default;

void Webserver::start()
{
    m_server->listen(QHostAddress::Any, 8080);
}

void Webserver::newConnection()
{
    qDebug() << "newConnection()";

    const auto socket = m_server->nextPendingConnection();
    if(!socket)
        return;

    new ClientConnection(socket);
}
