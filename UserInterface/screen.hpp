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
    T* loadWidget (const char* widgetName)
    {
        // Trouve le widget correspondant dans le parent
        T * tempWidget = m_interface->findChild<T*>(widgetName);

        // Ajoute à la liste qui contient tous les widgets de cette
        // interface
        m_allWidgets.push_back(tempWidget);

        // On vérifie que le widget est correctement chargé
        if (!tempWidget)
        {
            qDebug() << "widget non initialisé -> " << widgetName;
        }

        // Retourne le widget chargé
        return tempWidget;
    }

    // Affiche le nombre d'éléments actionnables dans l'interface
    virtual void printNumOfElemts ()
    {
        qDebug() << "il y a " << m_allWidgets.size() << " éléments dans cette interface";
    }

protected:

    // / Widget -> interface
    QWidget * m_interface = nullptr;

    // / Nom de l'interface
    QString m_interfaceName;

    // / Nom de l'objet interface
    QString m_objectInterfaceName;

    // TEST
    // Liste qui contient tous les widgets graphiques d'une interface
    QList<QWidget*> m_allWidgets;
};

#endif // / SCREEN_HPP
