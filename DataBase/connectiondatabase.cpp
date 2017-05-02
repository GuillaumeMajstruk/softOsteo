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

#include "connectiondatabase.hpp"


// Constructeur / destructeur ********************************************************************************
connectionDataBase::connectionDataBase()
{

#ifdef Q_OS_WIN
    getDatabaseConnection().setDatabaseName("F:/Programmes/Programme_Alisson/ConnectionDataBase/connection.db");
#else
    m_db.setDatabaseName("/Users/Guillaume/softOsteo/ConnectionDataBase/connectionDB.db");
#endif

    // vérification que la connection à pue être établie
    checkConnectionToDatabase();

    QSqlQuery query(getDatabaseConnection());



    execStatement(Statement::connectionDatabase::createTableStatement);

    insert("Guillaume", "030893Guigui");
    insert("Tatiana", "jesuistata");
}

// Fonctions privées ********************************************************************************

void connectionDataBase::insert(const string &userName, const string &password)
{
    // Insère dans la base de donnée ce qui à été hashé pour les stocker
    execStatement(string(Statement::connectionDatabase::insertStatement).arg(hashWithoutSalt(userName), hashWithSalt(password)));
}

string connectionDataBase::hashWithoutSalt(const string &strToHash)
{
    return dataEncryptor::hashIt_SHA256(strToHash);
}

string connectionDataBase::hashWithSalt(const string &strToHash)
{
    return string ( dataEncryptor::hashIt_MD5(SALT_BEFORE) +
                     dataEncryptor::hashIt_SHA256(strToHash) +
                     dataEncryptor::hashIt_MD5(SALT_AFTER));
}
