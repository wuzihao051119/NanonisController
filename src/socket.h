// Copyright (c) 2025 Zihao Wu
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef SOCKET_H
#define SOCKET_H

#include <QTcpSocket>

class Socket : public QTcpSocket {
    Q_OBJECT

public:
    Socket(QObject *parnet = nullptr);
    ~Socket();

public:
    QByteArray m_receiveData;

public slots:
    void connectToTcpServer(QHostAddress &address, quint16 port);
    void sendData(const QByteArray &data);
    void receiveData();

signals:
    void dataAvailable(const QByteArray &data);
};

#endif // SOCKET_H
