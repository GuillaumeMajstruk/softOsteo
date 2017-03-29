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

#ifndef CREATEPATIENTSCREEN_H
#define CREATEPATIENTSCREEN_H

#include <QWidget>
#include <QTabWidget>
#include <QPushButton>
#include <QLineEdit>

#include <QList>
#include <exception>

#include "UserInterface/userinterfaceloader.hpp"
#include "typedefs.hpp"


class CreatePatientScreen: public Screen
{
    Q_OBJECT

public: // Constructeur / destructeur **********************

    explicit CreatePatientScreen(Screen *parent = 0);
    virtual ~CreatePatientScreen();

private slots: // Slots privés *****************************

    // Mise à jour du texte du bouton "enregistrer le dossier"
    void updateSaveInformationText();
};

#endif // CREATEPATIENTSCREEN_H
