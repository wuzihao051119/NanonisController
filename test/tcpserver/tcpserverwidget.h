// Copyright (c) 2025 Zihao Wu
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef TCPSERVERWIDGET_H
#define TCPSERVERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QTcpServer>
#include <QTcpSocket>

class TcpServerWidget : public QWidget {
    Q_OBJECT

public:
    TcpServerWidget(QWidget *parent = nullptr);
    ~TcpServerWidget();

public slots:
    void newConnection();
    void read();

private slots:
    void listenToClient();

private:
    void initUi();
    
private:
    QTcpServer *server;
    QTcpSocket *socket;
    QLineEdit *hostAddressLineEdit;
    QLineEdit *portLineEdit;
    QPushButton *listenButton;
    QPlainTextEdit *commandPlainTextEdit;
};

#endif // TCPSERVERWIDGET_H
