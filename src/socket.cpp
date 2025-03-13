// Copyright (c) 2025 Zihao Wu
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "socket.h"

Socket::Socket(QObject *parent) : QTcpSocket(parent) {
    connect(this, &Socket::readyRead, this, &Socket::receiveData);
}

Socket::~Socket() {
    this->close();
}

void Socket::connectToTcpServer(QHostAddress &address, quint16 port) {
    connectToHost(address, port);
}

void Socket::sendData(const QByteArray &data) {
    write(data);
}

void Socket::receiveData() {
    if (bytesAvailable() != 0) {
        m_receiveData = readAll();
        emit dataAvailable(m_receiveData);
    }
}
