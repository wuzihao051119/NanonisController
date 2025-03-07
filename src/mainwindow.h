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

class MainWindow : public QMainWindow
{
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void initUi();
    void initTclInterp();
    void initCommand();

private:
    Tcl_Interp *interp;
    std::ostringstream oss;
    Function *m_function;
    Command *m_command;
};

#endif // MAINWINDOW_H
