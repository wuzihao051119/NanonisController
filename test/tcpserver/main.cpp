// Copyright (c) 2025 Zihao Wu
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include <QApplication>
#include "tcpserverwidget.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    TcpServerWidget widget;
    widget.show();
    return app.exec();
}
