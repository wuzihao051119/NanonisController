// Copyright (c) 2025 Zihao Wu
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "mainwindow.h"

MainWindow::MainWindow(std::ostringstream &oss, Command &command, TclWrapper& tclWrapper, QWidget *parent) :
    m_oss(oss),
    m_command(command),
    m_tclWrapper(tclWrapper),
    QMainWindow(parent) {
    initUi();
}

MainWindow::~MainWindow() {

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
    commandTextEdit = new QPlainTextEdit;
    
    QHBoxLayout *submitLayout = new QHBoxLayout;
    commandLineEdit = new QLineEdit;
    QPushButton *submitButton = new QPushButton(tr("Submit"));
    submitLayout->addWidget(commandLineEdit);
    submitLayout->addWidget(submitButton);

    mainLayout->addLayout(configLayout);
    mainLayout->addWidget(commandTextEdit);
    mainLayout->addLayout(submitLayout);

    centralWidget->setLayout(mainLayout);

    connect(connectButton, &QPushButton::clicked, this, &MainWindow::getHostAddress);
    connect(this, &MainWindow::socketConnect, m_socket, &Socket::connectToTcpServer);
    connect(submitButton, &QPushButton::clicked, this, &MainWindow::invokeCommand);
    connect(&m_command, &Command::socketSend, m_socket, &Socket::sendData);
    connect(m_socket, &Socket::dataAvailable, this, &MainWindow::getResponse);

    setCentralWidget(centralWidget);
    setWindowTitle(tr("NanonisController"));
    resize(800, 600);
}

void MainWindow::getHostAddress() {
    QString address = hostAddressLineEdit->text();
    quint16 port = portLineEdit->text().toUShort();
    QHostAddress hostAddress = QHostAddress(address);
    emit socketConnect(hostAddress, port);
}

void MainWindow::invokeCommand() {
    m_tclWrapper.eval(commandLineEdit->text().toLatin1());
    commandTextEdit->appendPlainText(m_tclWrapper.getResult());
}

void MainWindow::getResponse(const QByteArray &data) {
    const std::string response = m_command.dump(data.toStdString());
    commandTextEdit->appendPlainText(QString::fromStdString(response));
}
