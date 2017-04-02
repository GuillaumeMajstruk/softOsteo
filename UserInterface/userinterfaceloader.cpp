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

#include "userinterfaceloader.hpp"

// /
// / \brief userInterfaceLoader::userInterfaceLoader
// / \param staticOrDynamic
// / Si staticOrDynamic = "true" on instancie statiquement l'objet
// / en initialisant la QMap
// / Si staticOrDynamic = "false" on instancie dynamiquement l'objet
// / sans initialiser la QMap, ceci ayant pour but d'uniquement accéder à une fonction de la classe


// Constructeur / destructeur *******************************************************************************
userInterfaceLoader::userInterfaceLoader(bool staticOrDynamic)
{
    if (staticOrDynamic)
    {
        qDebug() << "userInterfaceLoader::userInterfaceLoader(STATIC)";

        // CRÉATION D'UNE INSTANCE DU CONTENEUR D'INTERFACES
        // -> à l'initialisation d'une instance "statique" de
        // la classe userInterfaceLoader on définie un conteneur
        // de type (QVector) qui contiendra une instance "unique" de
        // chaque interface (unique_ptr)
        m_allInterfaceVector = QVector<Screen*>();

        // Création d'instances unique de toutes les interfaces du programme
        static std::unique_ptr<WelcomeScreen> UiLoaderInstance_WelcomeScreen (new WelcomeScreen);
        static std::unique_ptr<SelectPatientScreen> UiLoaderInstance_SelectPatientScreen (new SelectPatientScreen);
        static std::unique_ptr<CreatePatientScreen> UiLoaderInstance_CreatePatientScreen (new CreatePatientScreen);
        static std::unique_ptr<CreateNewDate> UiLoaderInstance_CreateNewDate (new CreateNewDate);
        static std::unique_ptr<PatientMedicalFolderScreen> UiLoaderInstance_PatientMedicalFolderScreen (new PatientMedicalFolderScreen);

        // On place les instances dans le conteneur d'interfaces
        m_allInterfaceVector.push_back(UiLoaderInstance_WelcomeScreen.get());
        m_allInterfaceVector.push_back(UiLoaderInstance_SelectPatientScreen.get());
        m_allInterfaceVector.push_back(UiLoaderInstance_CreatePatientScreen.get());
        m_allInterfaceVector.push_back(UiLoaderInstance_CreateNewDate.get());
        m_allInterfaceVector.push_back(UiLoaderInstance_PatientMedicalFolderScreen.get());

    }

    qDebug() << "userInterfaceLoader::userInterfaceLoader(DYNAMIC)";
}
