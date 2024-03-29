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
    m_newPatientButton = loadWidget<pushButton>("newPatientButton_PB");
    m_returnButton = loadWidget<pushButton>("returnButton_PB");
    m_validateSelectionButton = loadWidget<pushButton>("validateSelectionButton_PB");
    m_searchButton = loadWidget<pushButton>("searchButton_PB");

    m_searchPatientLineEdit = loadWidget<lineEdit>("searchPatientLineEdit_LE");

    m_patientList = loadWidget<listWidget>("patientList_LST");


    // / Connection signaux/slots ///////////////////////////////////////////////////////
    connect (m_newPatientButton, &pushButton::clicked, this, &SelectPatientScreen::newPatientButton_clicked);
    connect (m_returnButton, &pushButton::clicked, this, &SelectPatientScreen::returnButton_clicked);
    connect (m_validateSelectionButton, &pushButton::clicked, this, &SelectPatientScreen::validateSelectionButton_clicked);
    connect (m_searchButton, &pushButton::clicked, this, &SelectPatientScreen::searchButton_clicked);

    connect (m_searchPatientLineEdit, &QLineEdit::textChanged,
             this, &SelectPatientScreen::searchPatientLineEdit_textEdited);
    // //////////////////////////////////////////////////////////////////////////////////

    printNumOfElemts();
}

SelectPatientScreen::~SelectPatientScreen()
{
    qDebug() << "SelectPatientScreen::~SelectPatientScreen()";
}
