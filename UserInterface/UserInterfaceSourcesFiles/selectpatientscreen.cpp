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

#include "selectpatientscreen.hpp"

SelectPatientScreen::SelectPatientScreen(Screen *parent) :
    Screen(parent)
{
    qDebug() << "SelectPatientScreen::SelectPatientScreen()";

    // / Définition du nom visuel de l'interface
    setInterfaceName(SharedVar::InterfaceName::SelectPatientScreen_name);

    // / Déclaration du nom de l'objet d'interface
    setInterfaceObjectName(SharedVar::InterfaceObjectName::SelectPatientScreen_obj_name);

    // Chargement de l'interface suivant le fichier de configuration
    m_interface = userInterfaceLoader(DYNAMIC).loadUi<SelectPatientScreen>(m_objectInterfaceName);

    // / Initialisation des Widgets de l'interfaces
    initWidgetList();


    // / Connection signaux/slots ///////////////////////////////////////////////////////
    connect (dynamic_cast<pushButton*>(getWidget("newPatientButton_PB")), &pushButton::clicked, this, &SelectPatientScreen::newPatientButton_clicked);
    connect (dynamic_cast<pushButton*>(getWidget("returnButton_PB")), &pushButton::clicked, this, &SelectPatientScreen::returnButton_clicked);
    connect (dynamic_cast<pushButton*>(getWidget("validateSelectionButton_PB")), &pushButton::clicked, this, &SelectPatientScreen::validateSelectionButton_clicked);
    connect (dynamic_cast<pushButton*>(getWidget("searchButton_PB")), &pushButton::clicked, this, &SelectPatientScreen::searchButton_clicked);

    connect (dynamic_cast<lineEdit*>(getWidget("searchPatientLineEdit_LE")), &QLineEdit::textChanged,
             this, &SelectPatientScreen::searchPatientLineEdit_textEdited);
    // //////////////////////////////////////////////////////////////////////////////////

    showThisInterfaceCaracteristics();
}

SelectPatientScreen::~SelectPatientScreen()
{
    qDebug() << "SelectPatientScreen::~SelectPatientScreen()";
}
