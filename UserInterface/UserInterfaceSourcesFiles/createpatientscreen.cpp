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


// Constructeur / destructeur ******************************************************************

CreatePatientScreen::CreatePatientScreen(Screen *parent):
    Screen(parent)
{
    qDebug() << "CreatePatientScreen::CreatePatientScreen()";

    // Met à jour le nom de l'interface
    setInterfaceName(SharedVar::InterfaceName::CreatePatientScreen_name);

    // Met à jour le nom d'objet de l'interface
    setInterfaceObjectName(SharedVar::InterfaceObjectName::CreatePatientScreen_obj_name);

    // Charge l'interface depuis le fichier .ui grâce à userInterfaceLoader
    m_interface = userInterfaceLoader(DYNAMIC).loadUi<CreatePatientScreen>(m_objectInterfaceName);

    // Initialisation des éléments de l'interface
    initWidgetList();

    // Connection des éléments de l'interface
    connect (dynamic_cast<lineEdit*>(getWidget("patientName_LE")), &lineEdit::textEdited, this, &CreatePatientScreen::updateSaveInformationText);
    connect (dynamic_cast<lineEdit*>(getWidget("patientSurname_LE")), &lineEdit::textEdited, this, &CreatePatientScreen::updateSaveInformationText);

    // debug
    showThisInterfaceCaracteristics();
}

CreatePatientScreen::~CreatePatientScreen()
{
    qDebug() << "CreatePatientScreen::~CreatePatientScreen()";
}


// Slots privés ***************************************************************************************************

void CreatePatientScreen::updateSaveInformationText()
{
    if (!dynamic_cast<pushButton*>(getWidget("savePatientFolder_PB"))->isEnabled())
        dynamic_cast<pushButton*>(getWidget("savePatientFolder_PB"))->setEnabled(true);
    dynamic_cast<pushButton*>(getWidget("savePatientFolder_PB"))->setText("Enregistrer le dossier de " +
                                                                          dynamic_cast<lineEdit*>(getWidget("patientName_LE"))->text() +
                                                                          " " +
                                                                          dynamic_cast<lineEdit*>(getWidget("patientSurname_LE"))->text());
}
