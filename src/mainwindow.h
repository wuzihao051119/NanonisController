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

#include <tcl.h>

#include "command.h"
#include "function.h"
#include "socket.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void initUi();
    void initTclInterp();
    void initCommand();

signals:
    void socketConnect(QHostAddress &address, quint16 port);
    void socketSendData(const QByteArray &data);

private slots:
    void getHostAddress();
    void invokeCommand();

private:
    Tcl_Interp *m_interp;
    std::ostringstream m_oss;
    Function *m_function;
    Command *m_command;
    Socket *m_socket;

    QLineEdit *hostAddressLineEdit;
    QLineEdit *portLineEdit;
};

#endif // MAINWINDOW_H
