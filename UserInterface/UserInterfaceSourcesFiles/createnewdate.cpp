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

#include "createnewdate.hpp"

CreateNewDate::CreateNewDate(Screen *parent):
    Screen(parent)
{
    // debug
    qDebug() << "CreateNewDate::CreateNewDate()";

    // Mise à jour du nom de l'interface visuelle
    setInterfaceName(SharedVar::InterfaceName::CreateNewDate_name);

    // Mise à jour du nom de l'objet interface
    setInterfaceObjectName(SharedVar::InterfaceObjectName::CreateNewDate_obj_name);

    // Chargement de l'interface depuis le fichier de configuration
    m_interface = userInterfaceLoader(DYNAMIC).loadUi<CreateNewDate>(m_objectInterfaceName);

    // Initialisation des éléments de l'interface
    initWidgetList();

    // Connection du bouton "retour"
    if (hasReturnButton())
        connect (dynamic_cast<pushButton*>(getWidget("return_PB")), &pushButton::clicked, this, &Screen::returnButtonClicked);

    // debug
    showThisInterfaceCaracteristics();
}

CreateNewDate::~CreateNewDate()
{
    qDebug() << "CreateNewDate::~CreateNewDate()";
}
