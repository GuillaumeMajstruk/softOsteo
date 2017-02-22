#include "connectiondatabase.hpp"


// Appelle automatiquement le constructeur de dataBase()
connectionDataBase::connectionDataBase()
{
    // Connection à la base de donnée de connection
    m_db = QSqlDatabase::addDatabase("QSQLITE");

    m_db.setDatabaseName("/Users/Guillaume/softOsteo/ConnectionDataBase/connectionDB.db");


    // vérification que la connection à pue être établie
    checkConnectionToDatabase();

    QSqlQuery query(m_db);

    if (!query.exec("CREATE TABLE IF NOT EXISTS 'users' ('Username' TEXT PRIMARY KEY, 'Password' TEXT )"))
        QMessageBox::warning(NULL, "error", query.lastError().text());

    insert("Guillaume", "030893Guigui");
}


void connectionDataBase::insert(const QString &userName, const QString &password)
{
    // Transforme en tableau de bits les chaines de caractères
    QByteArray userBa = userName.toUtf8();
    QByteArray passBa = password.toUtf8();

    // Hash les tableau binaires
    QString usernameHash = QCryptographicHash::hash(userBa, QCryptographicHash::Sha256).toHex();
    QString passwordHash = QCryptographicHash::hash(passBa, QCryptographicHash::Sha256).toHex();

    QSqlQuery query(m_db);

    // Insère dans la base de donnée ce qui à été hashé pour les stocker
    if (!query.exec("INSERT INTO users (Username, Password)"
               "VALUES ( '" + usernameHash + "', '" + passwordHash + "')"))
        QMessageBox::warning(NULL, "error", query.lastError().text());
}
