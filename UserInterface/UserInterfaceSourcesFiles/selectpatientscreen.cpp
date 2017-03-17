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

    m_interface = userInterfaceLoader(DYNAMIC).loadUi<SelectPatientScreen>(m_objectInterfaceName + ".ui");

    // / Initialisation des Widgets de l'interfaces ////////////////////////////////////
    m_newPatientButton = m_interface->findChild<QPushButton*>("newPatientButton");
    m_returnButton = m_interface->findChild<QPushButton*>("returnButton");
    m_validateSelectionButton = m_interface->findChild<QPushButton*>("validateSelectionButton");
    m_searchButton = m_interface->findChild<QPushButton*>("searchButton");

    m_searchPatientLineEdit = m_interface->findChild<QLineEdit*>("searchPatientLineEdit");

    m_searchPatientLabel = m_interface->findChild<QLabel*>("searchPatientLabel");
    m_searchPatientLabel->setBuddy(m_searchPatientLineEdit);

    m_patientList = m_interface->findChild<QListWidget*>("patientList");
    // //////////////////////////////////////////////////////////////////////////////////

    // / Connection signaux/slots ///////////////////////////////////////////////////////
    connect (m_newPatientButton, &QPushButton::clicked, this, &SelectPatientScreen::newPatientButton_clicked);
    connect (m_returnButton, &QPushButton::clicked, this, &SelectPatientScreen::returnButton_clicked);
    connect (m_validateSelectionButton, &QPushButton::clicked, this, &SelectPatientScreen::validateSelectionButton_clicked);
    connect (m_searchButton, &QPushButton::clicked, this, &SelectPatientScreen::searchButton_clicked);

    connect (m_searchPatientLineEdit, &QLineEdit::textChanged,
             this, &SelectPatientScreen::searchPatientLineEdit_textEdited);
    // //////////////////////////////////////////////////////////////////////////////////
}

SelectPatientScreen::~SelectPatientScreen()
{
    qDebug() << "SelectPatientScreen::~SelectPatientScreen()";
}
