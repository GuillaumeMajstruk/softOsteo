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

#ifndef PATIENT_HPP
#define PATIENT_HPP

#include <QString>
#include <QMessageBox>

#include "patientdatabase.hpp"
#include "typedefs.hpp"

class Patient
{
public: // Constructeur / destructeur ****************************************************

    // Création d'un nouveau patient "à la main"
    Patient(string, string, string, string, string, string, string, string, string, string, string, string, string, string);

    // Création d'un nouveau patient depuis une base de données (automatique)
    Patient(patientDatabase a_Pdb);

public: // Fonctions (ACCESSEURS) ********************************************************

    string getName()                        const { return p_Name; }
    string getSurname()                     const { return p_Surname; }
    string getJob()                         const { return p_Job; }
    string getPhoneNumber()                 const { return p_PhoneNumber; }
    string getEmail()                       const { return p_Email; }
    string getMedic()                       const { return p_CurrentMedic; }
    string getHobbies()                     const { return p_Hobbies; }
    string getPostalCode()                  const { return p_PostalCodeAddr; }
    string getCityName()                    const { return p_CityNameAddr; }
    string getStreetAndNum ()               const { return p_StreetAndNumAddr; }
    string getSocialSecurityNumber()        const { return p_SocialSecurityNumber; }

    string getFamilialStatus ()             const { return p_FamilialStatus; }
    string getSex()                         const { return p_Sex; }

    string getChildrenNumber()                 const { return p_ChildrenNumber; }

    int getID ()                            const { return p_ID; }

public: // Fonctions *********************************************************************

    // Affiche un résumé du patient dans un msgBox
    void resume();

private: // Fonctions ********************************************************************

    // Vérifie que les champs obligatoires ne sont pas vides
    bool checkInput ();

private: // Attributs privés *************************************************************

string p_Name;
string p_Surname;
string p_Job;
string p_PhoneNumber;
string p_Email;
string p_CurrentMedic;
string p_Hobbies;
string p_PostalCodeAddr;
string p_CityNameAddr;
string p_StreetAndNumAddr;
string p_SocialSecurityNumber;
string p_FamilialStatus;
string p_Sex;
string p_ChildrenNumber;

int p_ID;
};

#endif // PATIENT_HPP
