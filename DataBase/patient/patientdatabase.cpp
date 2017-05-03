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

#include "patientdatabase.hpp"

patientDatabase::patientDatabase()
{

    // Mise à jour du chemin de la base de données à utiliser
    getDatabaseConnection().setDatabaseName("F:/Programmes/Programme_Alisson/PatientDataBase/patients.db");

    // Vérifie que la connexion est possible et si oui, décrypte la base de données
    checkConnectionToDatabase();
}

void dataBaseManipulation::getPatientList(patientDatabase *a_db, listWidget *a_listWidget)
{
    a_listWidget->clear();

    QSqlQuery selectEverything (a_db->getDatabaseConnection());

    selectEverything.exec("SELECT name, surname FROM general_infos");

    while (selectEverything.next())
    {
        string currentItem = selectEverything.value(0).toString() + " " + selectEverything.value(1).toString();

        listItem * an_item = new listItem(a_listWidget);
        an_item ->setData(0, currentItem);
    }
    return;
}

int dataBaseManipulation::getIndexByName(const patientDatabase &a_db, listWidget *a_listWidget)
{
    return 1;
}
