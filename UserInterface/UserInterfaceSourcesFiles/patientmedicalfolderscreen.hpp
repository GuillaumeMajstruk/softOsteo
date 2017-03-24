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

#ifndef PATIENTMEDICALFOLDERSCREEN_HPP
#define PATIENTMEDICALFOLDERSCREEN_HPP

#include <QWidget>

#include "UserInterface/userinterfaceloader.hpp"
#include "typedefs.hpp"

// Dans cette interface, les informations d'un patient sont chargés depuis la base de donnée
// et sont interprétés en tant que labels

class PatientMedicalFolderScreen : public Screen
{
    Q_OBJECT
public: // Constructeur / destructeur
    explicit PatientMedicalFolderScreen(Screen * parent = 0);
    virtual ~PatientMedicalFolderScreen();

private: // Attributs privés

    // Éléments de l'interface (qui contiennent les informations chargées depuis la base de donnée
    // QComboBox
    comboBox * m_patientSexInfo = nullptr;
    comboBox * m_patientFamilialStatusInfo = nullptr;

    // QLabels qui concernent les renseignements généraux du patient
    label * m_patientNameInfo = nullptr;
    label * m_patientSurnameInfo = nullptr;
    label * m_streetAndNumAdressInfo = nullptr;
    label * m_postalCodeAdressInfo = nullptr;
    label * m_cityNameAdressInfo = nullptr;
    label * m_patientPhoneNumberInfo = nullptr;
    label * m_patientEmailInfo = nullptr;
    label * m_patientJobInfo = nullptr;
    label * m_patientHobbies = nullptr;

    // QLabels qui concernent les antécédents médicaux
    label * m_patientIsSmokerInfo = nullptr;
    label * m_cardioPneumoInfo = nullptr;
    label * m_uroGynecoInfo = nullptr;
    label * m_endocrinoInfo = nullptr;
    label * m_digestInfo = nullptr;
    label * m_orlInfo = nullptr;
    label * m_neuroInfo = nullptr;
    label * m_psychoInfo = nullptr;
    label * m_allergoDermatoInfo = nullptr;
    label * m_ophtalmoInfo = nullptr;
    label * m_occlusalInfo = nullptr;
    label * m_orthoTraumatoRhumatoInfo = nullptr;

    // QLabels qui concernent les éléments de conclusion
    label * m_currentMedCureInfo = nullptr;
    label * m_patientFamilialAntecedentsInfo = nullptr;

    // Elements cliquables de l'interface
    pushButton * m_oldConsultations = nullptr;
    pushButton * m_newConsultation = nullptr;
    pushButton * m_bills = nullptr;
    pushButton * m_saveNewDate = nullptr;
    pushButton * m_addOldReport = nullptr;
    pushButton * m_addPatientAppendices = nullptr;
    pushButton * m_patientAppendices = nullptr;

    pushButton * m_return = nullptr;
};

#endif // PATIENTMEDICALFOLDERSCREEN_HPP
