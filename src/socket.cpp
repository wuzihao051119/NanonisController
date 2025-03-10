// Copyright (c) 2025 Zihao Wu
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "socket.h"

Socket::Socket(QObject *parent) : QTcpSocket(parent) {

}

Socket::~Socket() {

}

void Socket::connectToTcpServer(QHostAddress &address, quint16 port) {
    connectToHost(address, port);
}

void Socket::sendData(const QByteArray &data) {
    write(data);
}
