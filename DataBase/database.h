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

#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QMessageBox>
#include <QTextStream>

#include "Messages/messages.hpp"
#include "UserInterface/interfaceGlobal.hpp"
#include "typedefs.hpp"

class connectionDataBase;
class patientDatabase;

class dataBase
{
    friend struct dataBaseConnectionOptions;

public: // Constructeur / destructeur ***************************************************************************
    // constructeur par défaut
    dataBase();

    ~dataBase() { m_db.close(); }

public: // Fonctions publiques ***********************************************************************************

    // Retourne la connection à la base de données
    virtual QSqlDatabase& getDatabaseConnection() { return m_db; }

    // Vérifie que la base de données est bien connectée
    bool checkConnectionToDatabase();


private: // Attributs privés *************************************************************************************

    // Connection à une base de donnée.
    QSqlDatabase m_db;

    // Quand la base de donnée est connecté => isConnected est passé à "true"
    bool isConnected = false;
};

#endif // DATABASE_H
