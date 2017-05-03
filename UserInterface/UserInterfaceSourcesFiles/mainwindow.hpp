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

#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QDesktopWidget>
#include <QMessageBox>
#include <string>
#include <QWidget>
#include <QSize>
#include <QSettings>
#include <QStackedWidget>
#include <QComboBox>
#include <QSpinBox>

#include <memory>

#include "DataBase/patient/patient.hpp"

#include "DataBase/patient/patientdatabase.hpp"
#include "UserInterface/UserInterfaceSourcesFiles/selectpatientscreen.hpp"
#include "UserInterface/interfaceGlobal.hpp"
#include "UserInterface/UserInterfaceSourcesFiles/welcomescreen.hpp"
#include "UserInterface/userinterfaceloader.hpp"
#include "UserInterface/screen.hpp"
#include "Messages/messages.hpp"

namespace Ui {
class MainWindow;
}

class  MainWindow : public QMainWindow
{
    Q_OBJECT
    friend class Screen;

public: // Constructeur / destructeur ***********************************************
    explicit MainWindow(QWidget *parent = 0);

    // Fonctions publiques **********************************************************

    // retourne le nom de l'interface actuelle
    string getActualInterfaceName() const { return m_uiLoader->getCurrentStackedScreen<Screen>(allInterfaces->currentIndex())->getInterfaceName(); }

    // retourne le nom de l'objet interface actuel
    string getActualInterfaceObjectName() const { return m_uiLoader->getCurrentStackedScreen<Screen>(allInterfaces->currentIndex())->getInterfaceObjectName(); }

    //  retourne l'objet interface acuelle (m_currentInterface)
    QWidget* getActualInterface_Widget() const { return m_uiLoader->getCurrentStackedScreen<Screen>(allInterfaces->currentIndex())->getInterfaceWidget(); }

    // retourne l'objet de type "screen"
    template <class T>
    T* getActualInterface_Screen() const { return m_uiLoader->getCurrentStackedScreen<T>(allInterfaces->currentIndex()); }

public: // Attributs publiques **************************************************************************

    std::unique_ptr<patientDatabase> p_db;

private: // Attributs privées ***************************************************************************

    // Interface utilisateur
    Ui::MainWindow *ui;

    // Utilisateur actuel du programme
    string m_currentUserName;

    // Chargeur d'interface
    userInterfaceLoader * m_uiLoader = nullptr;

    // Taille par défaut de l'interface utilisateur (-> mode fenêtré)
    QSize *m_windowSize = new QSize     (
                                            SharedVar::Screen::defaultScreenSizeWindowed().widht,
                                            SharedVar::Screen::defaultScreenSizeWindowed().height
                                        );

    // Toutes les interfaces sont dans un stacked widget de telle sorte que l'on puisse changer
    // d'interface directement depuis cet objet
    QStackedWidget * allInterfaces = nullptr;

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // ~Debug~
    listWidget * debugList = nullptr;
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

private: // Fonctions privées *****************************************************************

    // Initialisation des interfaces dans le QStackedWidget
    void initStackedInterfaces ();

    // Défini l'interface utilisateur actuellement utilisée
    void setNewInterface (const string& requiredInterfaceName);

    // change le message de l'action de mode de fenêtre
    void changeWindowModeText();

    // affiche un message dans la barre de status ('message', pendant 'duration')
    void showStatusBarMessage (const string& message, int duration);

    // Retourne l'index d'une interface en fonction de son nom
    int getInterfaceIndex (const string& interfaceName);

    // Connecte les éléments de l'interface graphique voulue
    // en fonction de son nom
    void connectCurrentInterface (const string& interfaceName);

    // Déconnecte les éléments de l'interface précédente
    void disconnectCurrentInterface (const string& interfaceName);

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // ~Debug~ Liste les éléments "importants" de l'interface actuelle
    inline void showElementsOfInterface()
    {

        if (!debugList)
        {
            debugList = new listWidget();
        }
        else debugList->clear();

        debugList->setWindowTitle(string("Elements of %1").arg(getActualInterfaceName()));

        for (auto wid: getActualInterface_Widget()->findChildren<Widget*>())
        {
            if (getActualInterface_Screen<Screen>()->isCodedWidgetName(*wid))
            {
                debugList->addItem(wid->objectName());
            }
        }
        debugList->show();
    }
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

protected: // Fonctions protégées ************************************************************

    // Redéfinition de l'évenement "closeEvent" pour qu'il convienne au contexte du programme
    void closeEvent(QCloseEvent * event);

private slots: // Slots privés ***************************************************************

    // Gère la mise à l'échelle de l'écran (plein écran / fenêtré)
    void changeWindowMode();

    // demande à l'utilisateur s'il veut vraiment quitter ?
    void quitValidating ();

    // retourne l'index du patient séléctionné dans la liste des patients
    // Ou un nombre négatif si le patients n'est pas trouvé;
    int getPatientIndexFromList (QListWidgetItem*);

private slots: // Slots de dialogue entre cette classe (MainWindow) et les autres interfaces

    // WelcomeScreen **************************************************
        // Redirige vers l'interface "dossiers des patients"
        void on_patientsFolderClick();

        // Redirige vers l'interface "Nouvelle consultation"
        void on_newConsultationClick();

    //      TODO: a créer ************************
    //    void on_managementClick();
    //    void on_billClick();
    // *******************************************

        // Redirige vers  l'interface "Nouveau rendez-vous"
        void on_newDateClick();

        // Fonction de retour valable pour toutes les interfaces
        // qui ont un bouton "retour" -> fonction (hasReturnButton())f
        void on_returnButtonClick();

    // END WelcomeScreen **********************************************

    // SelectPatientScreen ********************************************
        // Redirige vers l'interface de création d'un nouveau dossier patient
        void on_newPatientClick();


    // END SelectPatientScreen ****************************************

    // CreatePatientScreen ********************************************
        // FIXME version primitive d'enregistrement dans la base de donnée patients
        void on_saveNewPatientClick();


    // END CreatePatientScreen ****************************************




signals: // Signaux *********************************************************
    // ...
};

#endif // / MAINWINDOW_HPP
