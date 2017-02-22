#ifndef CONNECTIONDATABASE_HPP
#define CONNECTIONDATABASE_HPP

#include <QSqlQuery>

#include <QString>

#include <QByteArray>
// #include <QCryptographicHash>

#include "database.h"
#include "CryptData/dataencryptor.hpp"

class ConnectionDialog;

class connectionDataBase: public dataBase
{
    // Autorise la classe ConnectionDialog à utiliser les fonctions privées de connectionDataBase
   friend class ConnectionDialog;

public:
    connectionDataBase();
    QSqlDatabase getDataBaseConnection () const { return m_db; }

private:
    // Une fonction pour insérer dans la base de données de connection un nouvel utilisateur et son mot de passe
    void insert (const QString& userName, const QString& password);

    static QString hashWithoutSalt(const QString& strToHash);
    static QString hashWithSalt(const QString& strToHash);
};

#endif // CONNECTIONDATABASE_HPP
