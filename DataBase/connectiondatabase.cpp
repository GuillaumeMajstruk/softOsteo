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

    // vérification que la connection à pue être établie
    checkConnectionToDatabase();

    QSqlQuery query(m_db);

    if (!query.exec("CREATE TABLE IF NOT EXISTS 'users' ('Username' TEXT PRIMARY KEY, 'Password' TEXT )"))
        QMessageBox::warning(NULL, "error", query.lastError().text());

    insert("Guillaume", "030893Guigui");
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
