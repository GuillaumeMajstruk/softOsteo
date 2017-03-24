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

#ifndef SELECTPATIENTSCREEN_HPP
#define SELECTPATIENTSCREEN_HPP

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>

#include "UserInterface/userinterfaceloader.hpp"
#include "typedefs.hpp"



class SelectPatientScreen : public Screen
{
    Q_OBJECT
public:
    explicit SelectPatientScreen(Screen *parent = 0);
    virtual ~SelectPatientScreen();

private:
    // ///////////////////////////////////////////////////////////////////////////////
    // /                    METHODES/ACCESSEURS/ATTRIBUTS                           //
    // ///////////////////////////////////////////////////////////////////////////////

    pushButton * m_newPatientButton = nullptr;
    pushButton * m_returnButton = nullptr;
    pushButton * m_validateSelectionButton = nullptr;
    pushButton * m_searchButton = nullptr;

    lineEdit * m_searchPatientLineEdit = nullptr;

    listWidget * m_patientList = nullptr;

    // ///////////////////////////////////////////////////////////////////////////////

    // ///////////////////////////////////////////////////////////////////////////////
    // /                              SIGNALS                                       //
    // ///////////////////////////////////////////////////////////////////////////////
signals:
    void newPatientButton_hasBeenClicked();
    void returnButton_hasBeenClicked();
    void validateSelectionButton_hasBeenClicked();
    void searchButton_hasBeenClicked();

    void searchPatientLineEdit_textHasBeenEdited(const QString&);

    // ///////////////////////////////////////////////////////////////////////////////

    // ///////////////////////////////////////////////////////////////////////////////
    // /                              SLOTS                                         //
    // ///////////////////////////////////////////////////////////////////////////////
private slots:
    void newPatientButton_clicked()
    {
        qDebug() << "newPatientButton_clicked()";
        emit newPatientButton_hasBeenClicked();
    }

    void returnButton_clicked()
    {
        qDebug() << "returnButton_clicked()";
        emit returnButton_hasBeenClicked();
    }

    void validateSelectionButton_clicked()
    {
        qDebug() << "validateSelectionButton_clicked()";
        emit validateSelectionButton_hasBeenClicked();
    }

    void searchButton_clicked()
    {
        qDebug() << "searchButton_clicked()";
        emit validateSelectionButton_hasBeenClicked();
    }

    void searchPatientLineEdit_textEdited(const QString&)
    {
        qDebug() << "searchPatientLineEdit_clicked()";
        emit searchPatientLineEdit_textHasBeenEdited(m_searchPatientLineEdit->text());
    }

    // ///////////////////////////////////////////////////////////////////////////////
};

#endif // / SELECTPATIENTSCREEN_HPP
