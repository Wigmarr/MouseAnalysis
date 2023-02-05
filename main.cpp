#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("MySoft");
    QCoreApplication::setOrganizationDomain("127.0.0.1");
    QCoreApplication::setApplicationName("Mouse Analyser");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
