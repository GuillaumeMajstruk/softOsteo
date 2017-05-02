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

#ifndef WELCOMESCREEN_HPP
#define WELCOMESCREEN_HPP

#include "UserInterface/userinterfaceloader.hpp"
#include "UserInterface/screen.hpp"

#include "typedefs.hpp"


class WelcomeScreen : public Screen
{
    Q_OBJECT
public: // Constructeur / destructeur ***********************************************

    WelcomeScreen(Screen * parent = 0);
    virtual ~WelcomeScreen();

signals: // Signals *****************************************************************

    void billButton_HasBeenClicked();
    void managementButton_HasBeenClicked();
    void newConsultationButton_HasBeenClicked();
    void newDateButton_HasBeenClicked();
    void patientsFolderButton_HasBeenClicked();

private slots: // Slots privés ******************************************************

    void billButton_clicked();
    void managementButton_clicked();
    void newConsultationButton_clicked();
    void newDateButton_clicked();
    void patientsFolderButton_clicked();

};

#endif // / WELCOMESCREEN_HPP
