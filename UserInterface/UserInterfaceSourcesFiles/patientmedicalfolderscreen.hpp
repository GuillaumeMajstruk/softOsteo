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

#ifndef PATIENTMEDICALFOLDERSCREEN_HPP
#define PATIENTMEDICALFOLDERSCREEN_HPP

#include <QWidget>

#include "UserInterface/userinterfaceloader.hpp"
#include "typedefs.hpp"

// Dans cette interface, les informations d'un patient sont chargés depuis la base de donnée
// et sont interprétés en tant que labels

class PatientMedicalFolderScreen : public Screen
{
    Q_OBJECT

public: // Constructeur / destructeur ***********************

    explicit PatientMedicalFolderScreen(Screen * parent = 0);
    virtual ~PatientMedicalFolderScreen();

};

#endif // PATIENTMEDICALFOLDERSCREEN_HPP
