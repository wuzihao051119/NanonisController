#ifndef SOCKET_H
#define SOCKET_H

#include <QTcpSocket>

class Socket : public QTcpSocket
{
public:
    Socket(QWidget *parnet = nullptr);
    ~Socket();
};

#endif // SOCKET_H
