// Copyright (c) 2025 Zihao Wu
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QPushButton>

#include "command.h"
#include "function.h"
#include "socket.h"
#include "tclpipe.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(pTclPipes pipes, QWidget *parent = nullptr);
    ~MainWindow();
    
signals:
    void socketConnect(QHostAddress &address, quint16 port);
    void socketSendData(const QByteArray &data);

private slots:
    void getHostAddress();
    void invokeCommand();
    void getResponse();

private:
    void initUi();
    void initCommand();
    
private:
    std::ostringstream m_oss;
    Function *m_function;
    Command *m_command;
    Socket *m_socket;
    pTclPipes m_pipes;

    QLineEdit *hostAddressLineEdit;
    QLineEdit *portLineEdit;
};

#endif // MAINWINDOW_H
