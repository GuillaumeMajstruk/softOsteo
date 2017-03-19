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
public:
    explicit CreatePatientScreen(Screen *parent = 0);
    virtual ~CreatePatientScreen();

private: //Attributs privés

    // Eléments de l'interface
    // QPushButton
    pushButton * m_savePatientFolder = nullptr;
    pushButton * m_returnButton = nullptr;

    // QLineEdit
    lineEdit * m_patientName = nullptr;
    lineEdit * m_patientSurname = nullptr;
    lineEdit * m_patientJob = nullptr;
    lineEdit * m_cityNameAdress = nullptr;
    lineEdit * m_postalCodeAdress = nullptr;
    lineEdit * m_streetAndNumAdress = nullptr;
    lineEdit * m_patientCurrentMedic = nullptr;
    lineEdit * m_patientEmail = nullptr;
    lineEdit * m_patientPhoneNumber = nullptr;
    lineEdit * m_patientHobbies = nullptr;

    // QComboBox
    comboBox * m_patientSex = nullptr;
    comboBox * m_patientFamilialStatus = nullptr;

    // QSpinBox
    spinBox * m_patientChildNumber = nullptr;

    // QCheckBox
    checkBox * m_patientIsSmoker = nullptr;

    // QPlainTextEdit
    plainTextEdit * m_cardioPneumo = nullptr;
    plainTextEdit * m_uroGyneco = nullptr;
    plainTextEdit * m_endocrino = nullptr;
    plainTextEdit * m_digest = nullptr;
    plainTextEdit * m_orl = nullptr;
    plainTextEdit * m_neuro = nullptr;
    plainTextEdit * m_psycho = nullptr;
    plainTextEdit * m_allergoDermato = nullptr;
    plainTextEdit * m_ophtalmo = nullptr;
    plainTextEdit * m_occlusal = nullptr;
    plainTextEdit * m_orthoTraumatoRhumato = nullptr;
    plainTextEdit * m_currentMedCure = nullptr;
    plainTextEdit * m_patientFamilialAntecedents = nullptr;
    plainTextEdit * m_conclusion = nullptr;




private slots:
    void updateSaveInformationText();
};

#endif // CREATEPATIENTSCREEN_H
