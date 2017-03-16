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
