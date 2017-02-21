#include "connectiondatabase.hpp"


// Appelle automatiquement le constructeur de dataBase()
connectionDataBase::connectionDataBase()
{
    // Connection à la base de donnée de connection
    m_db = QSqlDatabase::addDatabase("QSQLITE");

    m_db.setDatabaseName("/Users/Guillaume/softOsteo/ConnectionDataBase/connectionDB.db");
    // vérification que la connection à pue être établie
    checkConnectionToDatabase();
}
