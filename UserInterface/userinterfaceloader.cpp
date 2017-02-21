#include <QtGui>
#include "userinterfaceloader.hpp"

//
// \brief userInterfaceLoader::userInterfaceLoader
// \param staticOrDynamic
// Si staticOrDynamic = "true" on instancie statiquement l'objet
// en initialisant la QMap
// Si staticOrDynamic = "false" on instancie dynamiquement l'objet
// sans initialiser la QMap, ceci ayant pour but d'uniquement accéder à une fonction de la classe

userInterfaceLoader::userInterfaceLoader(bool staticOrDynamic)
{
    if (staticOrDynamic)
    {
        qDebug() << "userInterfaceLoader::userInterfaceLoader(STATIC)";

        // CRÉATION D'UNE INSTANCE DU CONTENEUR D'INTERFACES
        // -> à l'initialisation d'une instance "statique" de
        // la classe userInterfaceLoader on définie un conteneur
        // de type (QMAP) qui contiendra une instance "unique" de
        // chaque interface (unique_ptr)
        m_allInterface = QMap<QString, Screen*>();

        // Création d'instances unique de toutes les interfaces du programme
        static std::unique_ptr<WelcomeScreen> UiLoaderInstance_WelcomeScreen (new WelcomeScreen);
        static std::unique_ptr<SelectPatientScreen> UiLoaderInstance_SelectPatientScreen (new SelectPatientScreen);
        static std::unique_ptr<CreatePatientScreen> UiLoaderInstance_CreatePatientScreen (new CreatePatientScreen);

        m_allInterface.insert(Global::InterfaceObjectName::WelcomeScreen_obj_name,
                              UiLoaderInstance_WelcomeScreen.get());

        m_allInterface.insert(Global::InterfaceObjectName::SelectPatientScreen_obj_name,
                              UiLoaderInstance_SelectPatientScreen.get());

        m_allInterface.insert(Global::InterfaceObjectName::CreatePatientScreen_obj_name,
                              UiLoaderInstance_CreatePatientScreen.get());

    }
    qDebug() << "userInterfaceLoader::userInterfaceLoader(DYNAMIC)";
}
