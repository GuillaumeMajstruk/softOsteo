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

#ifndef USERINTERFACELOADER_HPP
#define USERINTERFACELOADER_HPP

#include <QtUiTools>
#include <QDir>
#include <QDebug>
#include <QScreen>
#include <QDebug>
#include <QFile>
#include <QMap>
#include <QVector>

#include "interfaceGlobal.hpp"
#include "screen.hpp"
#include "UserInterface/UserInterfaceSourcesFiles/welcomescreen.hpp"
#include "UserInterface/UserInterfaceSourcesFiles/selectpatientscreen.hpp"
#include "UserInterface/UserInterfaceSourcesFiles/createpatientscreen.h"
#include "userinterface/UserInterfaceSourcesFiles/createnewdate.hpp"
#include "UserInterface/UserInterfaceSourcesFiles/patientmedicalfolderscreen.hpp"




class userInterfaceLoader: public QUiLoader
{

public: // Constructeur / destructeur ************************************************************************

    userInterfaceLoader(bool /* true: static, false: dynamic*/);

public: // Fonctions publiques *******************************************************************************

    template <typename T>
    T * loadUi(const string& uiToLoadName)
    {
        // Est-ce que le nom d'interface correspond bien à un fichier d'interface .ui ?
            QFile _interface (SharedVar::Path::resourcesUiFilesRoot + uiToLoadName + ".ui");

            // peut-on ouvrir le fichier en lecture ?
            if (!_interface.open(QFile::ReadOnly)) qDebug() << "erreur à l'ouverture du fichier de configuration"
                                                           << uiToLoadName;

            // création du widget interface "ui" en fonction du fichier *.ui
            QWidget * loadedInterface = load(&_interface);
            T * castedInterface = as<T*>(loadedInterface);

            // le fichier est-il chargé correctement ?
            if (!castedInterface)
            {
                qDebug() << "le fichier d'interface n'est pas chargé ";
                return NULL;
            }

            // retourne l'interface qui a été chargée depuis le fichier *.ui
            return castedInterface;
    }


    // Retourne l'interface actuelle (descendante de Screen)
    // castée dans le type voulue
    template <typename T>
    T * getCurrentStackedScreen (const int& currentIndex)
    {
        return as<T*>(m_allInterfaceVector[currentIndex]);
    }

public: // Attributs publiques *******************************************************************************

    // Contient un "unique_ptr" vers chaque interface du logiciel
    QVector<Screen*> m_allInterfaceVector;

};

#endif // USERINTERFACELOADER_HPP
