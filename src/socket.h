// Copyright (c) 2025 Zihao Wu
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

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
