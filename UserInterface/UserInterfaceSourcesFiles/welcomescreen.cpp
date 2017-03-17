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

#include <QtGui>

#include "welcomescreen.hpp"

//#define DEBUG


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

#ifdef DEBUG
    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::blue);
    m_interface->setAutoFillBackground(true);
    m_interface->setPalette(pal);
#endif //DEBUG

    // / on cherche les boutons correspondants
        m_billButton = m_interface->findChild<QPushButton*>("billButton");
        m_managementButton = m_interface->findChild<QPushButton*> ("managementButton");
        m_newConsultationButton = m_interface->findChild<QPushButton*> ("newConsultationButton");
        m_newMeetingButton = m_interface->findChild<QPushButton*> ("newMeetingButton");
        m_patientsFolderButton = m_interface->findChild<QPushButton*> ("patientsFolderButton");

    // / sont-ils TOUS correctement initialisés ?
    if (        !m_billButton
            ||  !m_managementButton
            ||  !m_newConsultationButton
            ||  !m_newMeetingButton
            ||  !m_patientsFolderButton ) throw std::exception {};


    // / connection des signaux/slots des boutons de cette interface
    connect (m_billButton, &QPushButton::clicked, this, &WelcomeScreen::billButton_clicked);
    connect (m_managementButton, &QPushButton::clicked, this, &WelcomeScreen::managementButton_clicked);
    connect (m_newConsultationButton, &QPushButton::clicked, this, &WelcomeScreen::newConsultationButton_clicked);
    connect (m_newMeetingButton, &QPushButton::clicked, this, &WelcomeScreen::newMeetingButton_clicked);
    connect (m_patientsFolderButton, &QPushButton::clicked, this, &WelcomeScreen::patientsFolderButton_clicked);

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
