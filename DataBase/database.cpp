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

#include "database.h"

using SharedVar::Debug::log_d;

// Constructeur / destructeur ***************************************************************************

dataBase::dataBase() {}

dataBase::dataBase(const QString &dataBaseName, const QString &dataBaseUserName, const QString &dataBasePassword)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_dbConnectionOptions = dbConnectionOptions();
    m_dbConnectionOptions.m_dbUserName = dataBaseUserName;
    m_dbConnectionOptions.m_dbName =  dataBaseName;
    m_dbConnectionOptions.m_dbPass = dataBasePassword;

    m_dbConnectionOptions.setConnectionOptionsToDataBase(this);

    log_d (m_dbConnectionOptions.getConnectionInformations());

    checkConnectionToDatabase();
}

// Fonctions privées ************************************************************************************

bool dataBase::checkConnectionToDatabase()
{
    // / Impossibilité à se connecter à la base de donnée
    if (!m_db.open())
    {
        msgBox::warning(NULL,
                             Message::MsgBoxTitle::Error_Msg::title_Error,
                             Message::MsgBoxContent::content_DatabaseConnectionError,
                             QMessageBox::Ok);
        isConnected = false;
    }
    // / Connection à la base de donnée établie avec succés !
    else
    {
        msgBox::information(NULL,
                                  Message::MsgBoxTitle::title_ConnectionToDataBase_Ok,
                                  Message::MsgBoxContent::content_DatabaseConnectionOk);
        isConnected = true;
    }
    log_d(static_cast<int>(isConnected));
    return isConnected;
}


// databaseConnectionOptions struct function definition *************************************************

void dataBaseConnectionOptions::setConnectionOptionsToDataBase(dataBase *a_dataBase)
{
    a_dataBase->m_db.setDatabaseName(m_dbName);
    a_dataBase->m_db.setUserName(m_dbUserName);
    a_dataBase->m_db.setPassword(m_dbPass);
}
