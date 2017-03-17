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
    // Met à jour le nom de l'interface
    setInterfaceName(SharedVar::InterfaceName::CreatePatientScreen_name);

    // Met à jour le nom d'objet de l'interface
    setInterfaceObjectName(SharedVar::InterfaceObjectName::CreatePatientScreen_obj_name);


    // Charge l'interface depuis le fichier .ui grâce à userInterfaceLoader
    m_interface = userInterfaceLoader(DYNAMIC).loadUi<CreatePatientScreen>(m_objectInterfaceName += ".ui");


    // Initialisation des boutons de l'interface
    m_savePatientFolder = m_interface->findChild<QPushButton*>("savePatientFolders_PB");
    m_returnButton = m_interface->findChild<QPushButton*>("return_PB");



}

void CreatePatientScreen::updateSaveInformationText(const QString & text)
{
    if (!text.isEmpty());
//        m_savePatientFolder->setText(m_savePatientFolder->text().arg(/* TEXT DES LINES-EDITS NOM ET PRENOM */));
}
