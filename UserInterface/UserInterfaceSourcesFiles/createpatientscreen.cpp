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

#include "createpatientscreen.h"

CreatePatientScreen::CreatePatientScreen(Screen *parent):
    Screen(parent)
{
    qDebug() << "CreatePatientScreen::CreatePatientScreen()";
    // Met à jour le nom de l'interface
    setInterfaceName(SharedVar::InterfaceName::CreatePatientScreen_name);

    // Met à jour le nom d'objet de l'interface
    setInterfaceObjectName(SharedVar::InterfaceObjectName::CreatePatientScreen_obj_name);


    // Charge l'interface depuis le fichier .ui grâce à userInterfaceLoader
    m_interface = userInterfaceLoader(DYNAMIC).loadUi<CreatePatientScreen>(m_objectInterfaceName += ".ui");


    // Initialisation des éléments de l'interface

    // QPushButton
    m_savePatientFolder = loadWidget<pushButton>("savePatientFolder_PB");
    m_returnButton = loadWidget<pushButton>("return_PB");

    // QlineEdit
    m_patientName = loadWidget<lineEdit>("patientName_LE");
    m_patientSurname = loadWidget<lineEdit>("patientSurname_LE");
    m_patientJob = loadWidget<lineEdit>("patientJob_LE");
    m_cityNameAdress = loadWidget<lineEdit>("cityNameAdress_LE");
    m_postalCodeAdress = loadWidget<lineEdit>("postalCodeAdress_LE");
    m_streetAndNumAdress = loadWidget<lineEdit>("streetAndNumAdress_LE");
    m_patientCurrentMedic = loadWidget<lineEdit>("patientCurrentMedic_LE");
    m_patientEmail = loadWidget<lineEdit>("patientEmail_LE");
    m_patientPhoneNumber = loadWidget<lineEdit>("patientPhoneNumber_LE");
    m_patientHobbies = loadWidget<lineEdit>("patientHobbies_LE");

    // QComboBox
    m_patientSex = loadWidget<comboBox>("patientSex_CB");
    m_patientFamilialStatus = loadWidget<comboBox>("patientFamilialStatus_CB");

    // QSpinBox
    m_patientChildNumber = loadWidget<spinBox>("patientChildNumber_SB");

    // QPlainTextEdit
    m_cardioPneumo = loadWidget<plainTextEdit>("cardioPneumo_PTE");
    m_uroGyneco = loadWidget<plainTextEdit>("uroGyneco_PTE");
    m_endocrino = loadWidget<plainTextEdit>("endocrino_PTE");
    m_digest = loadWidget<plainTextEdit>("digest_PTE");
    m_orl = loadWidget<plainTextEdit>("orl_PTE");
    m_neuro = loadWidget<plainTextEdit>("neuro_PTE");
    m_psycho = loadWidget<plainTextEdit>("psycho_PTE");
    m_allergoDermato = loadWidget<plainTextEdit>("allergoDermato_PTE");
    m_ophtalmo = loadWidget<plainTextEdit>("ophtalmo_PTE");
    m_occlusal = loadWidget<plainTextEdit>("occlusal_PTE");
    m_orthoTraumatoRhumato = loadWidget<plainTextEdit>("orthoTraumatoRhumato_PTE");
    m_currentMedCure = loadWidget<plainTextEdit>("currentMedCure_PTE");
    m_patientFamilialAntecedents = loadWidget<plainTextEdit>("patientFamilialAntecedents_PTE");
    m_conclusion = loadWidget<plainTextEdit>("conclusion_PTE");


    connect (m_patientName, &lineEdit::textEdited, this, &CreatePatientScreen::updateSaveInformationText);
    connect (m_patientSurname, &lineEdit::textEdited, this, &CreatePatientScreen::updateSaveInformationText);

    // debug
    printNumOfElemts();
}

CreatePatientScreen::~CreatePatientScreen()
{
    qDebug() << "CreatePatientScreen::~CreatePatientScreen()";
}

void CreatePatientScreen::updateSaveInformationText()
{
    if (!m_savePatientFolder->isEnabled())
        m_savePatientFolder->setEnabled(true);
    m_savePatientFolder->setText("Enregistrer le dossier de " + m_patientName->text() + " " + m_patientSurname->text());
}
