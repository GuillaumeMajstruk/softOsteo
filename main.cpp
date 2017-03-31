//    softOsteo is the name of the software.
//    This software integrates many functionalities such as patient management, data records, data
//    management, patient consultation, etc..., to help an osteopath in his professional life.
//    Copyright (C) 2017  MAJSTRUK Guillaume.

//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.

//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.

//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <QApplication>
#include <QDebug>

#include "UserInterface/UserInterfaceSourcesFiles/mainwindow.hpp"
#include "UserInterface/ConnectionScreen/connectiondialog.h"
#include "DataBase/database.h"

#include <memory>

int main(int argc, char *argv[])
{
    QApplication *app = new QApplication (argc, argv);    

    // Ajout des caractéristiques système
    app->setOrganizationName("MjkCorp");
    app->setOrganizationDomain("MjkCorp.fr");
    app->setApplicationName("softOsteo");

// WARNING SANS CONNECTION
    // Création puis gestion de la connection à l'application
    //ConnectionDialog *d = new ConnectionDialog(NULL);
    //d->exec();

    MainWindow *mainWindow =  new MainWindow;
    mainWindow ->show();

    return app->exec();
}
