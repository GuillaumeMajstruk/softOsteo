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

#ifndef PATIENTDATABASE_HPP
#define PATIENTDATABASE_HPP

#include <QList>
#include <QListWidget>

#include "../database.h"
#include "typedefs.hpp"

class patientDatabase: public dataBase
{
public: // Constructeur / Destructeur **************************************************************

    // Constructeur
    explicit patientDatabase();

public: // Fonctions publiques *********************************************************************

private: // Fonctions privées **********************************************************************

private: // Attributs privés ***********************************************************************

};

namespace dataBaseManipulation
{
    // Charge la liste de tous les patients enregistrés dans la base de données
    void getPatientList (patientDatabase *a_db, listWidget *a_listWidget);

    // Retourne l'index dans la base de donnée d'un patient séléctionné dans la liste
    int getIndexByName (const patientDatabase& a_db, QListWidget *a_listWidget);
}

#endif // PATIENTDATABASE_HPP
