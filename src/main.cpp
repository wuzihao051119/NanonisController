#include <QApplication>
#include "mainwindow.h"
#include "command.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    app.exec();
}
