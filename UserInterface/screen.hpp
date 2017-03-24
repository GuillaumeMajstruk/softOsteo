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

#include <assert.h>

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

    // Affiche le nombre d'éléments actionnables dans l'interface
    virtual void showThisInterfaceCaracteristics()
    {
        qDebug() << "il y a " << thisInterfaceWidgetContainer.size() << " éléments dans cette interface";
        for (int i = 1; i < thisInterfaceWidgetContainer.size(); ++i)
        {
            qDebug() << "\télément: " << i << " " << thisInterfaceWidgetContainer[i]->objectName()
                     << "\ttype de l'objet: " << thisInterfaceWidgetContainer[i]->metaObject()->className();
        }
    }

protected:

    // / Widget -> interface
    QWidget * m_interface = nullptr;

    // / Nom de l'interface
    QString m_interfaceName;

    // / Nom de l'objet interface
    QString m_objectInterfaceName;

    // Liste qui contient tous les widgets graphiques et utilisables d'une interface
    // C'est cette liste que je vais remplir avec les éléments utilisables
    QList<QWidget*> m_thisInterfaceWidgets;

    // Liste qui contient tous les noms des widgets d'une interface
    QStringList m_allWidgetNames;


// TESTS ////////////////////////////////////////////////////////////////////////////////////////
private:

    const QStringList widgetCodes
    {
        "PB", // pushButton
        "LE", // lineEdit
        "PTE", // plainTextEdit
        "INFO", // les labels qui représentent une information à afficher sous forme de texte
        "LST", // listWidgets
        "CB", // comboBox
        "SB", // spinBox
        "CKB", // checkBox
        "CALENDAR" // calendarWidget
    };

    // Une fonction pour vérifier si le nom du widget
    // passé en argument est "codé" ou non ?
    // -> Return true si le nom est un nom "codé"
    // -> Return false si le nom est un nom "non-codé"
    bool isCodedWidgetName (const QWidget& aWidget)
    {
        // Itération à travers la liste des "codes"
        for (auto actualWidgetCode: widgetCodes)
        {
            if (aWidget.objectName().contains(actualWidgetCode)) return true;
        }
        return false;
    }


protected:

    QVector<QWidget*> thisInterfaceWidgetContainer;

    // Ajoute à la liste des éléments de l'interface les widgets "utilisables"
    // par l'utilisateur dans le container de l'interface dont elle est appellée
    virtual void initWidgetList ()
    {
        QList<QWidget*> widList = m_interface->findChildren<QWidget*>();
        for (auto widget: widList)
        {
            if (isCodedWidgetName(*widget))
            {
                // Le widget est un widget "codé" ?
                // Oui ? -> Ajoute le widget au container
                thisInterfaceWidgetContainer.push_back(widget);
            }
        }
    }

    // Permet d'acceder à un widget de la liste des widget
    // de l'interface depuis laquelle elle est appellée
    virtual QWidget * getWidget (const QString& widgetName)
    {
        QWidget* tempWidget = new QWidget;
        for (int i = 0; i < thisInterfaceWidgetContainer.size(); ++i)
        {
            if (thisInterfaceWidgetContainer[i]->objectName() == widgetName)
                tempWidget = thisInterfaceWidgetContainer[i];
        }
        assert(tempWidget);
        return tempWidget;
    }

// //////////////////////////////////////////////////////////////////////////////////////
};

#endif // / SCREEN_HPP
