// Copyright (c) 2025 Zihao Wu
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "tcpserverwidget.h"

TcpServerWidget::TcpServerWidget(QWidget *parent) {
    initUi();
}

TcpServerWidget::~TcpServerWidget() {
    server->close();
}

void TcpServerWidget::initUi() {
    server = new QTcpServer(this);

    QHBoxLayout *configLayout = new QHBoxLayout;
    QLabel *hostAddressLabel = new QLabel(tr("Host Address"));
    hostAddressLineEdit = new QLineEdit;
    QLabel *portLabel = new QLabel(tr("Port"));
    QPushButton *listenButton = new QPushButton(tr("Listen"));
    portLineEdit = new QLineEdit;
    configLayout->addWidget(hostAddressLabel);
    configLayout->addWidget(hostAddressLineEdit);
    configLayout->addWidget(portLabel);
    configLayout->addWidget(portLineEdit);
    configLayout->addWidget(listenButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    commandPlainTextEdit = new QPlainTextEdit;
    mainLayout->addLayout(configLayout);
    mainLayout->addWidget(commandPlainTextEdit);
    setLayout(mainLayout);

    connect(listenButton, &QPushButton::clicked, this, &TcpServerWidget::listenToClient);
    connect(server, &QTcpServer::newConnection, this, &TcpServerWidget::newConnection);

    setWindowTitle(tr("NanonisControllerTcpServerTest"));
    resize(800, 600);
}

void TcpServerWidget::listenToClient() {
    if (!server->isListening()) {
        QHostAddress address = QHostAddress(hostAddressLineEdit->text());
        quint16 port = portLineEdit->text().toUShort();
        if (server->listen(address, port)) {
            hostAddressLineEdit->setEnabled(false);
            portLineEdit->setEnabled(false);
        }
    }
}

void TcpServerWidget::newConnection() {
    socket = server->nextPendingConnection();
    connect(socket, &QTcpSocket::readyRead, this, &TcpServerWidget::read);
}

void TcpServerWidget::read() {
    if (socket->bytesAvailable() != 0) {
        QByteArray data = socket->readAll();
        commandPlainTextEdit->appendPlainText(data.toHex(' '));
    }
}
