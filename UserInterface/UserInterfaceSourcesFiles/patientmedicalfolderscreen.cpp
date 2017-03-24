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

#include "patientmedicalfolderscreen.hpp"

PatientMedicalFolderScreen::PatientMedicalFolderScreen(Screen *parent):
    Screen(parent)
{
    qDebug() << "PatientMedicalFolderScreen::PatientMedicalFolderScreen()";

    // Mise à jour du nom de l'interface visuelle
    setInterfaceName(SharedVar::InterfaceName::PatientMedicalFolder_name);

    // Mise à jour du nom de l'objet interface
    setInterfaceObjectName(SharedVar::InterfaceObjectName::PatientMedicalFolder_obj_name);

    // Chargement de l'interface depuis le fichier de configuration
    m_interface = userInterfaceLoader(DYNAMIC).loadUi<PatientMedicalFolderScreen>(m_objectInterfaceName);

    // Définitions de tous les éléments de cette interface
    m_patientSexInfo = loadWidget<comboBox>("patientSex_CB");
    m_patientFamilialStatusInfo = loadWidget<comboBox>("patientFamilialStatus_CB");

    // Partie générale
    m_patientNameInfo = loadWidget<label>("patientName_INFO");
    m_patientSurnameInfo = loadWidget<label>("patientSurname_INFO");
    m_streetAndNumAdressInfo = loadWidget<label>("streetAndNumAdress_INFO");
    m_postalCodeAdressInfo = loadWidget<label>("postalCodeAdress_INFO");
    m_cityNameAdressInfo = loadWidget<label>("cityNameAdress_INFO");
    m_patientPhoneNumberInfo = loadWidget<label>("patientPhoneNumber_INFO");
    m_patientEmailInfo = loadWidget<label>("patientEmail_INFO");
    m_patientJobInfo = loadWidget<label>("patientJob_INFO");
    m_patientHobbies = loadWidget<label>("patientHobbies_INFO");

    // Antécédents médicaux
    m_patientIsSmokerInfo = loadWidget<label>("patientIsSmoker_INFO");
    m_cardioPneumoInfo = loadWidget<label>("cardioPneumo_INFO");
    m_uroGynecoInfo = loadWidget<label>("uroGyneco_INFO");
    m_endocrinoInfo = loadWidget<label>("endocrino_INFO");
    m_digestInfo = loadWidget<label>("digest_INFO");
    m_orlInfo = loadWidget<label>("orl_INFO");
    m_neuroInfo = loadWidget<label>("neuro_INFO");
    m_psychoInfo = loadWidget<label>("psycho_INFO");
    m_allergoDermatoInfo = loadWidget<label>("allergoDermato_INFO");
    m_ophtalmoInfo = loadWidget<label>("ophtalmo_INFO");
    m_occlusalInfo = loadWidget<label>("occlusal_INFO");
    m_orthoTraumatoRhumatoInfo = loadWidget<label>("orthoTraumatoRhumato_INFO");

    // Partie conclusion
    m_currentMedCureInfo = loadWidget<label>("currentMedCure_INFO");
    m_patientFamilialAntecedentsInfo = loadWidget<label>("patientFamilialAntecedents_INFO");

    // Partie "boite à outils"
    m_oldConsultations = loadWidget<pushButton>("oldConsultations_PB");
    m_newConsultation = loadWidget<pushButton>("newConsultation_PB");
    m_bills  = loadWidget<pushButton>("bills_PB");
    m_saveNewDate = loadWidget<pushButton>("saveNewDate_PB");
    m_addOldReport = loadWidget<pushButton>("addOldReports_PB");
    m_addPatientAppendices = loadWidget<pushButton>("addPatientAppendices_PB");
    m_patientAppendices = loadWidget<pushButton>("patientAppendices_PB");

    m_return = loadWidget<pushButton>("return_PB");

    printNumOfElemts();

}

PatientMedicalFolderScreen::~PatientMedicalFolderScreen()
{
    qDebug() << "PatientMedicalFolderScreen::~PatientMedicalFolderScreen()";
}
