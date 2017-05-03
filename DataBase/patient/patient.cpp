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

#include "patient.hpp"

Patient::Patient(string name, string surname, string job, string phone, string email, string currentMedic, string hobbies, string postalCode, string cityName, string streetAndNum, string socialSecurityNum,
                 string fStatus, string sex, string childNum):
    p_Name(name),
    p_Surname (surname),
    p_Job (job),
    p_PhoneNumber (phone),
    p_Email (email),
    p_CurrentMedic (currentMedic),
    p_Hobbies (hobbies),
    p_PostalCodeAddr (postalCode),
    p_CityNameAddr (cityName),
    p_StreetAndNumAddr (streetAndNum),
    p_SocialSecurityNumber (socialSecurityNum),
    p_FamilialStatus (fStatus),
    p_Sex (sex),
    p_ChildrenNumber (childNum)
{
    if (!checkInput())
        msgBox::critical(NULL, "Error !", "Erreur à la création du patient, pensez à remplir tous les champs obligatoires !");
}

bool Patient::checkInput()
{
    return !( p_Name.isEmpty() ||
              p_Surname.isEmpty() ||
              p_StreetAndNumAddr.isEmpty() ||
              p_PostalCodeAddr.isEmpty() ||
              p_CityNameAddr.isEmpty() ||
              p_PhoneNumber.isEmpty() ||
              p_SocialSecurityNumber.isEmpty() );
}

void Patient::resume()
{
    string _resume (
                    "Sexe: " + p_Sex + "\n" +
                    "Nom: " + p_Name + "\n" +
                    "Prénom: " + p_Surname + "\n" +
                    "Adresse: " + p_StreetAndNumAddr + ", " + p_PostalCodeAddr + ", " + p_CityNameAddr + "\n" +
                    "Numéro de téléphone: " + p_PhoneNumber + "\n" +
                    "Email: " + p_Email + "\n" +
                    "Status familiale: " + p_FamilialStatus + "\n" +
                    "Nombre d'enfant(s): " + p_ChildrenNumber + "\n" +
                    "Métier: " + p_Job + "\n" +
                    "Médecin traitant: " + p_CurrentMedic + "\n" +
                    "Passes temps/ Loisirs: " + p_Hobbies + "\n" +
                    "Numéro de sécurité sociale: " + p_SocialSecurityNumber + "\n"
                    );

    msgBox::information(
                NULL,
                "Patient",
                _resume
                );
}
