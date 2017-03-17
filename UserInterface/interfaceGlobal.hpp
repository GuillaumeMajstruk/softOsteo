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

#ifndef INTERFACEGLOBAL_HPP
#define INTERFACEGLOBAL_HPP

#include <QtGui>
#include <QString>
#include <QSize>

#include <memory>


// /////////////
// / DEFINES ///
// /////////////

#define STATIC true
#define DYNAMIC false

// /////////////


// ////////////////////////////////////////////////////////////////////////////
// /                             GLOBALES:                                  ///
// / contient des namespaces pour déclarer/définir des variables globales   ///
// ////////////////////////////////////////////////////////////////////////////
namespace SharedVar
{

    // / Contient les chemins d'accés de certaines ressources
    namespace Path
    {
        static const QString resourcesUiFilesRoot = ":/form/UserInterface/ui_Files/";
    }

    // / Contient les noms des différentes objets interfaces
    namespace InterfaceObjectName
    {
        static const char* WelcomeScreen_obj_name       = "WelcomeScreen";
        static const char* SelectPatientScreen_obj_name = "SelectPatientScreen";
        static const char* CreatePatientScreen_obj_name = "CreatePatientScreen";
    }

    // /  Contient les noms d'interfaces utilisateurs
    namespace InterfaceName
    {
        static const char * WelcomeScreen_name = "Écran d'accueil";
        static const char * SelectPatientScreen_name = "Séléction d'un patient";
        static const char * CreatePatientScreen_name = "Enregistrement d'un nouveau patient";
    }

    // /  Contient des éléments utiles au débogage
    namespace Debug
    {

        inline void log_d(const QVariant& dataToDebugStream)
        {
            qDebug() << dataToDebugStream;
        }

    }

    // / Contient les éléments relatifs à l'écran
    namespace Screen {

        struct defaultScreenSizeWindowed
        {
            static const int widht = 800;
            static const int height = 600;
        };
    }
}
// ////////////////////////////////////////////////////////////////////////////
#endif // / INTERFACEGLOBAL_HPP
