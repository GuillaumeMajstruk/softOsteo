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


// Appelle automatiquement le constructeur de dataBase()
connectionDataBase::connectionDataBase()
{
    // Connection à la base de donnée de connection
    m_db = QSqlDatabase::addDatabase("QSQLITE");

#ifdef Q_OS_WIN
    m_db.setDatabaseName("F:/Programmes/Programme_Alisson/ConnectionDataBase/connectionDB.db");
#else
    m_db.setDatabaseName("/Users/Guillaume/softOsteo/ConnectionDataBase/connectionDB.db");
#endif

    m_db.setPassword("1234");


    // vérification que la connection à pue être établie
    checkConnectionToDatabase();

    QSqlQuery query(m_db);

    if (!query.exec("CREATE TABLE IF NOT EXISTS 'users' ('Username' TEXT PRIMARY KEY, 'Password' TEXT )"))
        QMessageBox::warning(NULL, "error", query.lastError().text());

    insert("Guillaume", "030893Guigui");
    insert("Tatiana", "jesuistata");
}

QString connectionDataBase::hashWithoutSalt(const QString &strToHash)
{
    return dataEncryptor::hashIt_SHA256(strToHash);
}

QString connectionDataBase::hashWithSalt(const QString &strToHash)
{
    return QString ( dataEncryptor::hashIt_MD5(SALT_BEFORE) +
                     dataEncryptor::hashIt_SHA256(strToHash) +
                     dataEncryptor::hashIt_MD5(SALT_AFTER));
}


void connectionDataBase::insert(const QString &userName, const QString &password)
{
    QSqlQuery query (m_db);


    // Insère dans la base de donnée ce qui à été hashé pour les stocker
    if (!query.exec("INSERT INTO users (Username, Password)"
                       "VALUES  ( "
                            " '" + hashWithoutSalt(userName) + "',"
                            " '" + hashWithSalt(password) + "'"
                                ")"))
        QMessageBox::warning(NULL, "error", query.lastError().text());
}
