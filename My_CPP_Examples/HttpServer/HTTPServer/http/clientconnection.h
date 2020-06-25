#pragma once

#include <QObject>

#include <memory>

class QTcpSocket;

class ClientConnection : public QObject
{
    Q_OBJECT
public:
    explicit ClientConnection(QTcpSocket *socket, QObject *parent = nullptr);
    ~ClientConnection() override;

private:
    void readyRead();

private:
    const std::shared_ptr<QTcpSocket> m_socket;
};
