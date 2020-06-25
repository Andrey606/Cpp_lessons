#pragma once

#include <QObject>

#include <memory>

class QTcpServer;

class Webserver : public QObject
{
    Q_OBJECT
public:
    explicit Webserver(QObject *parent = nullptr);
    ~Webserver() override;

    void start();

private slots:
    void newConnection();

private:
    const std::shared_ptr<QTcpServer> m_server;

};
