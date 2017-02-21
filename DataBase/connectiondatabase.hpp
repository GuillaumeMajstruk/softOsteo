#ifndef CONNECTIONDATABASE_HPP
#define CONNECTIONDATABASE_HPP

#include "database.h"
#include <QSqlQuery>

class connectionDataBase: public dataBase
{
public:
    connectionDataBase();
    QSqlDatabase getDataBaseConnection () const { return m_db; }
};

#endif // CONNECTIONDATABASE_HPP
