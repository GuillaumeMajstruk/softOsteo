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


#include "welcomescreen.hpp"


// ///////////////////////////////////////////////////////////////////////////////
// /                       CONSTRUCTEUR/DESTRUCTEUR                             //
// ///////////////////////////////////////////////////////////////////////////////
WelcomeScreen::WelcomeScreen(Screen *parent):
    Screen(parent)
{
    qDebug() << "WelcomeScreen::WelcomeScreen()";

    // / définition du nom de l'interface
    setInterfaceName(SharedVar::InterfaceName::WelcomeScreen_name);

    // / définition du nom de l'objet interface
    setInterfaceObjectName(SharedVar::InterfaceObjectName::WelcomeScreen_obj_name);

    // / chargement de l'interface graphique
    m_interface = userInterfaceLoader(DYNAMIC).loadUi<WelcomeScreen>(m_objectInterfaceName + ".ui");

    // / on cherche les boutons correspondants
        m_billButton = loadWidget<pushButton>("billButton");
        m_managementButton = loadWidget<pushButton> ("managementButton");
        m_newConsultationButton = loadWidget<pushButton> ("newConsultationButton");
        m_newMeetingButton = loadWidget<pushButton> ("newMeetingButton");
        m_patientsFolderButton = loadWidget<pushButton> ("patientsFolderButton");


    // / connection des signaux/slots des boutons de cette interface
    connect (m_billButton, &pushButton::clicked, this, &WelcomeScreen::billButton_clicked);
    connect (m_managementButton, &pushButton::clicked, this, &WelcomeScreen::managementButton_clicked);
    connect (m_newConsultationButton, &pushButton::clicked, this, &WelcomeScreen::newConsultationButton_clicked);
    connect (m_newMeetingButton, &pushButton::clicked, this, &WelcomeScreen::newMeetingButton_clicked);
    connect (m_patientsFolderButton, &pushButton::clicked, this, &WelcomeScreen::patientsFolderButton_clicked);

    printNumOfElemts();

}

WelcomeScreen::~WelcomeScreen()
{
    qDebug() << "WelcomeScreen::~WelcomeScreen()";
}

// ///////////////////////////////////////////////////////////////////////////////


// ///////////////////////////////////////////////////////////////////////////////
// /                              SLOTS                                         //
// ///////////////////////////////////////////////////////////////////////////////

void WelcomeScreen::billButton_clicked()
{
    qDebug() << "billButton_clicked";
    emit billButton_HasBeenClicked();
}

void WelcomeScreen::managementButton_clicked()
{
    qDebug() << "managementButton_clicked";
    emit managementButton_HasBeenClicked();
}

void WelcomeScreen::newConsultationButton_clicked()
{
    qDebug() << "newConsultationButton_clicked";
    emit newConsultationButton_HasBeenClicked();
}

void WelcomeScreen::newMeetingButton_clicked()
{
    qDebug() << "newMeetingButton_clicked";
    emit newMeetingButton_HasBeenClicked();
}

void WelcomeScreen::patientsFolderButton_clicked()
{
    qDebug() << "patientsFolderButton_clicked";
    emit patientsFolderButton_HasBeenClicked();
}

// ///////////////////////////////////////////////////////////////////////////////
