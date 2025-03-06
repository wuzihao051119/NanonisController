#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) {
    initUi();
    initTclInterp();
    initCommand();
}

MainWindow::~MainWindow() {
    Tcl_DeleteInterp(interp);
    delete m_function;
    delete m_command;
}

void MainWindow::initUi() {
    QWidget *centralWidget = new QWidget;

    QVBoxLayout *configLayout = new QVBoxLayout;
    QLabel *hostAddressLabel = new QLabel(tr("Host Address"));
    QLineEdit *hostAddressLineEdit = new QLineEdit;
    QLabel *portLabel = new QLabel(tr("Port"));
    QLineEdit *portLineEdit = new QLineEdit;
    QPushButton *connectButton = new QPushButton(tr("Connect"));
    configLayout->addWidget(hostAddressLabel);
    configLayout->addWidget(hostAddressLineEdit);
    configLayout->addWidget(portLabel);
    configLayout->addWidget(portLineEdit);
    configLayout->addWidget(connectButton);
    configLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    QPlainTextEdit *commandTextEdit = new QPlainTextEdit;
    mainLayout->addLayout(configLayout);
    mainLayout->addWidget(commandTextEdit);

    centralWidget->setLayout(mainLayout);

    setCentralWidget(centralWidget);
    setWindowTitle(tr("NanonisController"));
    resize(800, 600);
}

void MainWindow::initTclInterp() {
    interp = Tcl_CreateInterp();

    Tcl_CreateObjCommand(interp, "Bias.Get", NULL, NULL, NULL);
    Tcl_Eval(interp, "Bias.Get");
}

void MainWindow::initCommand() {
    m_function = new Function(oss);
    m_command = new Command(*m_function);
}
