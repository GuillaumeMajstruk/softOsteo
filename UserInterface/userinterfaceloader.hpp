#ifndef USERINTERFACELOADER_HPP
#define USERINTERFACELOADER_HPP

#include <QtUiTools>
#include <QDir>
#include <QDebug>
#include <QScreen>
#include <QDebug>
#include <QFile>
#include <QMap>

#include "interfaceGlobal.hpp"
#include "screen.hpp"
#include "UserInterface/UserInterfaceSourcesFiles/welcomescreen.hpp"
#include "UserInterface/UserInterfaceSourcesFiles/selectpatientscreen.hpp"
#include "UserInterface/UserInterfaceSourcesFiles/createpatientscreen.h"




class userInterfaceLoader: public QUiLoader
{

public:
    // / Constructeur par défaut
    userInterfaceLoader(bool /* true: static, false: dynamic*/);


    template <typename T>
    T * loadUi(const QString& uiToLoadName)
    {
        // / Est-ce que le nom d'interface correspond bien à un fichier d'interface .ui ?
            QFile _interface (SharedVar::Path::resourcesUiFilesRoot + uiToLoadName);

            // / peut-on ouvrir le fichier en lecture ?
            if (!_interface.open(QFile::ReadOnly)) qDebug() << "erreur à l'ouverture du fichier de configuration"
                                                           << uiToLoadName;

            // / création du widget interface "ui" en fonction du fichier *.ui
            QWidget * loadedInterface = load(&_interface);
            T * castedInterface = static_cast<T*>(loadedInterface);

            // / le fichier est-il chargé correctement ?
            if (!castedInterface)
            {
                qDebug() << "le fichier d'interface n'est pas chargé ";
                return NULL;
            }

            // / retourne l'interface qui a été chargée depuis le fichier *.ui
            return castedInterface;
    }

    // / Contient toutes les interfaces du programme
    // / !!! DÉFINIE UNIQUEMENT SI INSTANCE STATIQUE DÉCLARÉE !!!
    QMap<QString, Screen*> m_allInterface;

};

#endif // / USERINTERFACELOADER_HPP
