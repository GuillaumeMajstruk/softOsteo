#include "database.h"

using Global::Debug::log_d;

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


bool dataBase::checkConnectionToDatabase()
{
    // Impossibilité à se connecter à la base de donnée
    if (!m_db.open())
    {
        QMessageBox::warning(NULL,
                             Message::MsgBoxTitle::Error_Msg::title_Error,
                             Message::MsgBoxContent::content_DatabaseConnectionError,
                             QMessageBox::Ok);
        isConnected = false;
    }
    // Connection à la base de donnée établie avec succés !
    else
    {
        QMessageBox::information(NULL,
                                  Message::MsgBoxTitle::title_ConnectionToDataBase_Ok,
                                  Message::MsgBoxContent::content_DatabaseConnectionOk);
        isConnected = true;
    }
    log_d(static_cast<int>(isConnected));
    return isConnected;
}

void dataBaseConnectionOptions::setConnectionOptionsToDataBase(dataBase *a_dataBase)
{
    a_dataBase->m_db.setDatabaseName(m_dbName);
    a_dataBase->m_db.setUserName(m_dbUserName);
    a_dataBase->m_db.setPassword(m_dbPass);
}
