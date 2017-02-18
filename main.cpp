#include <QApplication>


#include "UserInterface/UserInterfaceSourcesFiles/mainwindow.hpp"
#include "UserInterface/ConnectionScreen/connectiondialog.h"
#include "DataBase/database.h"

#include <QPlainTextEdit>


int main(int argc, char *argv[])
{
    QApplication *app = new QApplication (argc, argv);

    ConnectionDialog *d = new ConnectionDialog(0);
    d->exec();

    MainWindow *mainWindow =  new MainWindow;
    mainWindow ->show();

    return app->exec();
}
