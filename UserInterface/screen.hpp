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

#ifndef SCREEN_HPP
#define SCREEN_HPP

// ////////////////////////////////////////////////////////////////
// /     représente le concepte "d'écran" (qui sont des widgets ///
// /     en réalité) à afficher dans la MainWindow.             ///
// /     class abstraite                                        ///
// ////////////////////////////////////////////////////////////////

#include <QWidget>
#include <QTabWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QListWidget>
#include <QPalette>

#include <QList>
#include <QMap>

#include <exception>
#include <iomanip>
#include <assert.h>

#include "typedefs.hpp"

#include <QDebug>

class MainWindow;


class Screen : public QWidget
{

    Q_OBJECT

    friend class MainWindow;

public: // Constructeur / Destructeur *********************************************

    Screen(QWidget *parent = 0);

    virtual ~Screen ();

public: // Fonction publiques *****************************************************

    // Retourne le widget qui correspond à l'interface
    virtual QWidget* getInterfaceWidget() const { return m_interface; }

    // Retourne le nom de l'interface
    virtual string  getInterfaceName() const { return m_interfaceName; }

    // Retourne le nom de l'objet interface
    virtual string getInterfaceObjectName() const { return m_objectInterfaceName; }

    // Défini le nom de l'interface
    virtual void setInterfaceName (const char* name);

    // Défini le nom de l'objet interface
    virtual void setInterfaceObjectName (const char* uiName);

    // Affiche le nombre d'éléments actionnables dans l'interface
    virtual void showThisInterfaceCaracteristics();

protected: // Attributs protégés ***************************************************

    // L'interface à proprement parlé interprétée en tant que pointeur sur QWidget
    QWidget * m_interface = nullptr;

    // Nom de l'interface
    string m_interfaceName;

    // Nom de l'objet interface
    string m_objectInterfaceName;

    // Le conteneur de tous mes éléments graphiques
    // actionnable par l'utilisateur (ex: QPushButton ...)
    QVector<QWidget*> thisInterfaceWidgetContainer;

protected: // Fonctions protégées ***********************************************

    // Ajoute à la liste des éléments de l'interface les widgets "utilisables"
    // par l'utilisateur dans le container de l'interface dont elle est appellée
    virtual void initWidgetList ();

    // Permet d'acceder à un widget de la liste des widget
    // de l'interface depuis laquelle elle est appellée
    virtual QWidget * getWidget (const string& widgetName);

    // Fonction pour vérifier que cette interface contient un bouton "retour"
    bool hasReturnButton ();

    // Fonction pour vérifier que cette interface contient une liste des
    // patients à charger depuis la base de données patient
    bool hasListWidget();

private: // Attributs privés *****************************************************************

    const stringList widgetCodes
    {
        "PB",           // pushButton
        "LE",           // lineEdit
        "PTE",          // plainTextEdit
        "INFO",         // les labels qui représentent une information à afficher sous forme de texte
        "LST",          // listWidgets
        "CB",           // comboBox
        "SB",           // spinBox
        "CKB",          // checkBox
        "CALENDAR"      // calendarWidget
    };

private: // Fonction privées *****************************************************************

    // Une fonction pour vérifier si le nom du widget
    // passé en argument est "codé" ou non ?
    // -> Return true si le nom est un nom "codé"
    // -> Return false si le nom est un nom "non-codé"
    bool isCodedWidgetName (const QWidget& aWidget);

signals:
    void returnButtonClicked();
};

#endif // / SCREEN_HPP
