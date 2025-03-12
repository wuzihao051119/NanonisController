// Copyright (c) 2025 Zihao Wu
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QBoxLayout>
#include <QFile>
#include <QLabel>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QPushButton>

#include "command.h"
#include "function.h"
#include "socket.h"
#include "tclwrapper.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(std::ostringstream &oss, Command& command, TclWrapper &tclWrapper, QWidget *parent = nullptr);
    ~MainWindow();
    
signals:
    void socketConnect(QHostAddress &address, quint16 port);
    void socketSendData(const QByteArray &data);

private slots:
    void getHostAddress();
    void invokeCommand();

private:
    void initUi();
    
private:
    std::ostringstream &m_oss;
    Command &m_command;
    TclWrapper &m_tclWrapper;
    Socket *m_socket;

    QLineEdit *hostAddressLineEdit;
    QLineEdit *portLineEdit;
    QPlainTextEdit* commandTextEdit;
    QLineEdit* commandLineEdit;
};

#endif // MAINWINDOW_H
