// Copyright (c) 2025 Zihao Wu
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "mainwindow.h"

MainWindow::MainWindow(pTclPipes pipes, QWidget *parent) : m_pipes(pipes), QMainWindow(parent) {
    initUi();
    initCommand();
}

MainWindow::~MainWindow() {
    delete m_function;
    delete m_command;
}

void MainWindow::initUi() {
    m_socket = new Socket;

    QWidget *centralWidget = new QWidget;

    QHBoxLayout *configLayout = new QHBoxLayout;
    QLabel *hostAddressLabel = new QLabel(tr("Host Address"));
    hostAddressLineEdit = new QLineEdit;
    QLabel *portLabel = new QLabel(tr("Port"));
    portLineEdit = new QLineEdit;
    QPushButton *connectButton = new QPushButton(tr("Connect"));
    configLayout->addWidget(hostAddressLabel);
    configLayout->addWidget(hostAddressLineEdit);
    configLayout->addWidget(portLabel);
    configLayout->addWidget(portLineEdit);
    configLayout->addWidget(connectButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    QPlainTextEdit *commandTextEdit = new QPlainTextEdit;
    
    QHBoxLayout *submitLayout = new QHBoxLayout;
    QLineEdit *commandlineEdit = new QLineEdit;
    QPushButton *submitButton = new QPushButton(tr("Submit"));
    submitLayout->addWidget(commandlineEdit);
    submitLayout->addWidget(submitButton);

    mainLayout->addLayout(configLayout);
    mainLayout->addWidget(commandTextEdit);
    mainLayout->addLayout(submitLayout);

    centralWidget->setLayout(mainLayout);

    connect(connectButton, &QPushButton::clicked, this, &MainWindow::getHostAddress);
    connect(this, &MainWindow::socketConnect, m_socket, &Socket::connectToTcpServer);
    connect(submitButton, &QPushButton::clicked, this, &MainWindow::invokeCommand);
    connect(this, &MainWindow::socketSendData, m_socket, &Socket::sendData);
    connect(m_socket, &Socket::dataAvailable, this, &MainWindow::getResponse);

    setCentralWidget(centralWidget);
    setWindowTitle(tr("NanonisController"));
    resize(800, 600);
}

void MainWindow::initCommand() {
    m_function = new Function(m_oss);
    m_command = new Command(*m_function, m_oss);
}

void MainWindow::getHostAddress() {
    QString address = hostAddressLineEdit->text();
    quint16 port = portLineEdit->text().toUShort();
    QHostAddress hostAddress = QHostAddress(address);
    emit socketConnect(hostAddress, port);
}

void MainWindow::invokeCommand() {
    std::vector<std::string> args;
    args.emplace_back("0.000000005");
    m_command->invoke("Bias.Set", args);
    emit socketSendData(QByteArray::fromStdString(m_oss.str()));
}

void MainWindow::getResponse() {
    QByteArray &data = m_socket->m_receiveData;
    qDebug() << data;
}
