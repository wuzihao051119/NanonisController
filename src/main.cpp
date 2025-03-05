#include <QApplication>
#include "mainwindow.h"
#include "command.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Command command;
    MainWindow window;
    window.show();
    app.exec();
}
