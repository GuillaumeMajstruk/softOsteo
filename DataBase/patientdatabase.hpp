#ifndef PATIENTDATABASE_HPP
#define PATIENTDATABASE_HPP

#include <QList>

#include "database.h"
#include "typedefs.hpp"

class patientDatabase: public dataBase
{
public: // Constructeur / Destructeur **************************************************************

    // Constructeur
    explicit patientDatabase();

public: // Fonctions publiques *********************************************************************

private: // Fonctions privées **********************************************************************

    // Charge la liste de tous les patients enregistrés dans la base de données
    void loadPatientsIdentity_fromDB();

    // Retourne le nom à l'index indiqué
    QString getNameAt (int index);

private: // Attributs privés ***********************************************************************

    // La liste de tous les patients enregistrés dans la base de données
    QList<QString> * m_patientList = nullptr;

};

#endif // PATIENTDATABASE_HPP
