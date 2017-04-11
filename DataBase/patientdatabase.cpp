#include "patientdatabase.hpp"

patientDatabase::patientDatabase()
{
//    m_db = QSqlDatabase::addDatabase("QSQLITE");

    getDatabaseConnection().setDatabaseName("F:/Programmes/Programme_Alisson/PatientDataBase/patients.db");
    getDatabaseConnection().setPassword("1234");


    checkConnectionToDatabase();
    QSqlQuery query (getDatabaseConnection());

    // Test
//    loadPatientsIdentity_fromDB();

    qDebug() << "name at index is " << getNameAt(3);
}


void patientDatabase::loadPatientsIdentity_fromDB()
{
    QSqlQuery query (getDatabaseConnection());

    m_patientList = new QList<QString>;

    if (!query.exec("SELECT patientName, patientSurname FROM patient_general_informations"))
        msgBox::warning(NULL, "error loading patient list from database", query.lastError().text());

    else
    {
        while (query.next())
        {
            QString name = query.value(0).toString();
            QString surname = query.value(1).toString();

            m_patientList->append(QString(name + ", " + surname));
            qDebug() << QString(name + ", " + surname);
        }
        msgBox::information(NULL, "patient list loaded successfully", "patient list loaded successfully from Database");
    }

}

QString patientDatabase::getNameAt(int index)
{
    QSqlQuery query (getDatabaseConnection());

    QString id;

    if (!query.exec(QString("SELECT patientName, patientSurname FROM patient_general_informations WHERE (patientID = %1)").arg(index)))
        msgBox::warning(NULL, "error loading patient list from database", query.lastError().text());
    while (query.next())
    {
        QString name = query.value(0).toString();
        QString surname = query.value(1).toString();

        id = name + ", " + surname;
    }
    return id;
}
