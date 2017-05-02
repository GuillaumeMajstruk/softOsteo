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

#include "typedefs.hpp"
#include <QString>

enum class Familial_Status
{
    Married, // = 0
    Single,  // = 1
    Divorced // = 2
};

enum class Patient_Sex
{
    Male,  // = 0
    Female // = 1
};

class Patient
{
public: // Constructeur / destructeur ****************************************************
    Patient(string, string, string, string, string, string, string, string, string, string, string, Familial_Status, Patient_Sex, int);

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

    Familial_Status getFamilialStatus ()    const { return p_FamilialStatus; }
    Patient_Sex getSex()                    const { return p_Sex; }

    int getChildrenNumber()                 const { return p_ChildrenNumber; }

    int getID ()                            const { return p_ID; }

public: // Fonctions *********************************************************************

private: // Fonctions ********************************************************************

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

Familial_Status p_FamilialStatus;
Patient_Sex p_Sex;

int p_ChildrenNumber;

int p_ID;
};

#endif // PATIENT_HPP
