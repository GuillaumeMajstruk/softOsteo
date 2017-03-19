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

class dataBase;
class connectionDataBase;

// Un objet pour stocker les données de connection à la base de donnée
typedef struct dataBaseConnectionOptions
{

    dataBaseConnectionOptions() {}

   // Nom de la base de donnée
    QString m_dbName;

    // Nom de connection de l'utilisateur à la base de donnée
    QString m_dbUserName;

    // Mot de passe de connection à la base de donnée
    QString m_dbPass;


    // Vérifie que les informations de la base de donnée soient toutes remplies
    bool isEmptyConnectionOption()
    {
        return (m_dbName.isEmpty()
                && m_dbUserName.isEmpty()
                && m_dbPass.isEmpty());
    }

    void setConnectionOptionsToDataBase (dataBase * a_dataBase);

    QString getConnectionInformations() const { return QString ( m_dbName + " " + m_dbUserName + " " + m_dbPass); }

}dbConnectionOptions;


class dataBase
{
    friend struct dataBaseConnectionOptions;
    friend class connectionDataBase;

public:
    // constructeur par défaut
    dataBase();

    // Constructeurs surchargé
    dataBase (const QString &dataBaseName, const QString &dataBaseUserName, const QString &dataBasePassword = "");

    // Destructeur
    ~dataBase() { m_db.close(); }

private: // FUNCTIONS
    bool checkConnectionToDatabase();


private: // ATRIBUTES
    // Connection à une base de donnée.
    QSqlDatabase m_db;

    // Pour stocker les options de connection à la base de donnée
    dbConnectionOptions m_dbConnectionOptions;

    // Quand la base de donnée est connecté => isConnected est passé à "true"
    bool isConnected = false;
};

#endif // DATABASE_H
