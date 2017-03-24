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
#include <QList>
#include <QString>
#include <QStringList>
#include <QMap>
#include <exception>
#include <QDebug>

class Screen : public QWidget
{
    Q_OBJECT
public:

    Screen(QWidget *parent = 0):
        QWidget(parent)
    {
        qDebug() << "Screen::Screen()";
    }

    virtual ~Screen ()
    {
        qDebug() << "Screen::~Screen()";
    }

    // / Retourne le widget qui correspond à l'interface
    virtual QWidget* getWidget() const { return m_interface; }

    // / Retourne le nom de l'interface
    virtual QString  getInterfaceName() const { return m_interfaceName; }

    // / Retourne le nom de l'objet interface
    virtual QString getInterfaceObjectName() const { return m_objectInterfaceName; }

    // / Défini le nom de l'interface
    virtual void setInterfaceName (const char* name) {
        tr(name);
        m_interfaceName = QString::fromUtf8(name);
    }

    // /  Défini le nom de l'objet interface
    virtual void setInterfaceObjectName (const char* uiName)
    {
        m_objectInterfaceName = uiName;
    }

    // Fonction qui initialise un objet de type QWidget* en fonction
    // de son type et du nom de l'objet trouvé dans le parent
    template <typename T>
    T* loadWidget (const QString& widgetName)
    {
        // Trouve le widget correspondant dans le parent
        T * tempWidget = m_interface->findChild<T*>(widgetName);

        // Ajoute à la liste qui contient tous les widgets de cette
        // interface
        m_thisInterfaceWidgets.push_back(tempWidget);

        // On vérifie que le widget est correctement chargé
        if (!tempWidget)
        {
            qDebug() << "WIDGET NON INITIALISÉ -> " << widgetName;
        }

        // Retourne le widget chargé
        return tempWidget;
    }

    // Affiche le nombre d'éléments actionnables dans l'interface
    virtual void printNumOfElemts ()
    {
        qDebug() << "il y a " << m_thisInterfaceWidgets.size() << " éléments dans cette interface";
    }

protected:

    // / Widget -> interface
    QWidget * m_interface = nullptr;

    // / Nom de l'interface
    QString m_interfaceName;

    // / Nom de l'objet interface
    QString m_objectInterfaceName;

    // Liste qui contient tous les widgets graphiques d'une interface
    QList<QWidget*> m_thisInterfaceWidgets;

    // Liste qui contient tous les noms des widgets d'une interface
    QStringList m_allWidgetNames;


// TEST ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Contient les codes qui déterminent le type à charger, le code de chaque widget étant dans le nom de l'objet
    // exemple: patientList_LST => "LST" est le code pour ListWidget
//    const QStringList m_widgetCodes
//    {
//        "LST",          // ListWidget
//        "LE",           // LineEdit
//        "PB",           //PushButton
//        "PTE",          //PlainTextEdit
//        "INFO",         // Labels jouand le rôle de texte (ex: information générale -> nom du patient)
//        "CB",           // ComboBox
//        "SB",           // SpinBox
//        "CKB",          // CheckBox
//        "CALENDAR"      // CalendarWidget
//    };

//    // Retourne vrai si le nom contient un code
//    // Retourn faux si non
//    bool isCodedWidgetName (const QString& widgetName)
//    {
//        for (auto code: m_widgetCodes)
//        {
//            if (widgetName.contains(code))
//                return true;
//        }
//        return false;
//    }

//    // Retourne le code du widget pour savoir quel type d'initialisation
//    // il faut utiliser
//    QString getWidgetCode (const QString& widgetName)
//    {
//        for (auto code: m_widgetCodes)
//        {
//            if (widgetName.contains(code))
//                return code;
//        }
//        return QString("code non trouvé");
//    }

//    // Ajoute les widgets utilisable à la liste de cette interface
//    void addUsableWidgetToList ()
//    {
//        // Pour chaque widget de l'interface ...
//        for (auto widget: m_interface->findChildren<QWidget*>())
//        {
//            // Si le nom du widget contient un code (widgetCodes) ...
//            if (isCodedWidgetName(widget->objectName()))
//            {
//                // On l'ajoute à la liste des widgets utilisables
//                m_thisInterfaceWidgets.append(widget);
//                qDebug() << "added widget: " << widget->objectName();
//            }
//        }
//        return;
//    }

//    virtual void initInterfaceWidgets(QWidget * an_interface)
//    {
//        addUsableWidgetToList();
//        for (auto widget: m_thisInterfaceWidgets)
//        {

//        }
//    }

// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
};

#endif // / SCREEN_HPP
