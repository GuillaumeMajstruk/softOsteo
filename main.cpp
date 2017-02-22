#include <QApplication>

#include "UserInterface/UserInterfaceSourcesFiles/mainwindow.hpp"
#include "UserInterface/ConnectionScreen/connectiondialog.h"
#include "DataBase/database.h"

#include <QPlainTextEdit>
#include <QSettings>

int main(int argc, char *argv[])
{
    QApplication *app = new QApplication (argc, argv);

    // Ajout des caractéristiques système
    app->setOrganizationName("MjkCorp");
    app->setOrganizationDomain("MjkCorp.fr");
    app->setApplicationName("softOsteo");

    ConnectionDialog *d = new ConnectionDialog(NULL);
    d->exec();

    MainWindow *mainWindow =  new MainWindow;
    mainWindow ->show();

    return app->exec();
}
