// Copyright (c) 2025 Zihao Wu
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include <QApplication>
#include "command.h"
#include "mainwindow.h"
#include "tclpipe.h"
#include "tclwrapper.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QCoreApplication::setApplicationName("NanonisController");
    QCoreApplication::setApplicationVersion("v1.0");
    QCoreApplication::setOrganizationName("CCM");
    QCoreApplication::setOrganizationDomain("ccm.zju.edu.cn");

    TclPipe tclPipe;
    pTclPipes pipes = tclPipe.getTclPipes();
    TclWrapper tclWrapper(pipes);

    MainWindow window(pipes);
    window.show();
    return app.exec();
}
