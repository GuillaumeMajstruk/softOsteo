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

#include "screen.hpp"

    // Constructeur / destructeur **********************************************

    Screen::Screen(QWidget *parent):
        QWidget(parent)
    {
        qDebug() << "Screen::Screen()";
    }

    Screen::~Screen()
    {
        qDebug() << "Screen::~Screen()";
    }

    // Fonctions publiques ******************************************************

    void Screen::setInterfaceName(const char *name)
    {
           tr(name);
           m_interfaceName = QString::fromUtf8(name);
    }

    void Screen::setInterfaceObjectName(const char *uiName)
    {
        m_objectInterfaceName = uiName;
    }

    void Screen::showThisInterfaceCaracteristics()
    {
        qDebug() <<  "il y a " << thisInterfaceWidgetContainer.size() << " éléments dans cette interface";
        for (int i = 0; i < thisInterfaceWidgetContainer.size(); ++i)
        {
            qDebug() <<"\télément: " << i+1 << " " << thisInterfaceWidgetContainer.at(i)->objectName()
                     << "\ttype de l'objet: " << thisInterfaceWidgetContainer[i]->metaObject()->className();
        }
    }

    // Fonctions protégées *******************************************************

    void Screen::initWidgetList()
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

    QWidget* Screen::getWidget(const QString &widgetName)
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

    bool Screen::hasReturnButton()
    {
        for (int i = 0; i < thisInterfaceWidgetContainer.size(); ++i)
        {
            if (thisInterfaceWidgetContainer[i]->objectName() == "return_PB")
            {
                qDebug() << "TRUE TRUE TRUE";
                return true;
            }
        }
        return false;
    }

    // Fonctions privées *******************************************************

    bool Screen::isCodedWidgetName(const QWidget &aWidget)
    {
        // Itération à travers la liste des "codes"
        for (auto actualWidgetCode: widgetCodes)
        {
            if (aWidget.objectName().contains(actualWidgetCode)) return true;
        }
        return false;
    }
