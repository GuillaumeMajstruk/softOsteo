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

#ifndef CREATENEWDATE_HPP
#define CREATENEWDATE_HPP

#include <QWidget>
#include <QDebug>

#include "UserInterface/userinterfaceloader.hpp"
#include "typedefs.hpp"

class CreateNewDate: public Screen
{
    Q_OBJECT

public: // Constructeur et destructeur
    explicit CreateNewDate(Screen * parent = 0);
    virtual ~CreateNewDate();

private: // Attributs privés
    // Éléments de GUI
    pushButton * m_cancel = nullptr;
    pushButton * m_saveNewDate = nullptr;
    pushButton * m_search = nullptr;

    lineEdit * m_searchPatient = nullptr;

    listWidget * m_patientList = nullptr;
    calendar * m_calendar = nullptr;
};

#endif // CREATENEWDATE_HPP
