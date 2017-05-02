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
                 Familial_Status fStatus, Patient_Sex sex, int childNum):
    p_Name(name),
    p_Surname (surname),
    p_Job (job),
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

}

bool Patient::checkInput()
{
    return false;
}
