#ifndef CONNECTIONDATABASE_HPP
#define CONNECTIONDATABASE_HPP

#include "database.h"
#include <QSqlQuery>

#include <QString>

#include <QByteArray>
#include <QCryptographicHash>

class connectionDataBase: public dataBase
{
public:
    connectionDataBase();
    QSqlDatabase getDataBaseConnection () const { return m_db; }

private:
    void insert (const QString& userName, const QString& password);
};

#endif // CONNECTIONDATABASE_HPP
