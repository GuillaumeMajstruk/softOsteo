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

#ifndef CONNECTIONDATABASE_HPP
#define CONNECTIONDATABASE_HPP

#include <QSqlQuery>
#include <QString>
#include <QByteArray>

#include "database.h"
#include "CryptData/dataencryptor.hpp"

class ConnectionDialog;

class connectionDataBase: public dataBase
{
    // Autorise la classe ConnectionDialog à utiliser les fonctions privées de connectionDataBase
   friend class ConnectionDialog;

public: // Constructeur / destructeur *************************************************************************

    connectionDataBase();

public: // Fonctions publiques ********************************************************************************

    // Retourne la connection à la base de données
    QSqlDatabase getDataBaseConnection () const { return m_db; }

private: // Fonctions privées *********************************************************************************

    // Une fonction pour insérer dans la base de données de connection un nouvel utilisateur et son mot de passe
    void insert (const QString& userName, const QString& password);

    // Fonction de hashage sans sel
    static QString hashWithoutSalt(const QString& strToHash);

    // Fonction de hashage avec sel
    static QString hashWithSalt(const QString& strToHash);
};

#endif // CONNECTIONDATABASE_HPP
