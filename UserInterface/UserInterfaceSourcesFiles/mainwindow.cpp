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


#include "mainwindow.hpp"
#include "ui_mainwindow.h"

using SharedVar::Debug::log_d;

// Constructeur / Destructeur *********************************************************

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    // Chargement de la base de données patients
    p_db = std::unique_ptr<patientDatabase> (new patientDatabase);

    // instanciation du chargeur d'interface
    m_uiLoader = new userInterfaceLoader(STATIC);

    //   défini la taille minimum de 800x600 (px)
    setMinimumSize(*m_windowSize);

    // connexion les actions de la barre de menu
    connect(ui->actionQuitter, &QAction::triggered, this, &MainWindow::quitValidating);
    connect(ui->actionPlein_cran, &QAction::triggered, this, &MainWindow::changeWindowMode);

    // Initialisation du StackedWidget
    initStackedInterfaces();

    // Mise à jour de l'interface actuelle et gestion de la connection / déconnexion des widgets des interfaces
    setNewInterface(SharedVar::InterfaceObjectName::WelcomeScreen_obj_name);

    // Définition du nom de l'utilisateur actuel
    QSettings settings(QSettings::IniFormat, QSettings::UserScope, qApp->organizationName(), qApp->applicationName());
    m_currentUserName = settings.value("connection/UserId").toString();

    // Affiche le message de bienvenue pendant 5 secondes
    showStatusBarMessage(string(Message::StatusBar::statusBarWelcome).arg(m_currentUserName,
                                                                           QDate::currentDate().toString(Qt::SystemLocaleLongDate)),
                         5000 );
}

MainWindow::~MainWindow()
{
    delete m_uiLoader;
    delete m_windowSize;
    delete allInterfaces;
    delete ui;
}

// Fonctions privés *******************************************************************************

void MainWindow::initStackedInterfaces()
{
    // définition de allInterfaces
    allInterfaces = new QStackedWidget(this);

    // Remplissage d
    for (auto widget: m_uiLoader->m_allInterfaceVector)
    {
        allInterfaces->addWidget(as<Screen*>(widget)->getInterfaceWidget());
    }
}

// Met à jour l'interface actuelle et connecte ses éléments
// Enregistre l'interface précédente et déconnecte ses éléments
void MainWindow::setNewInterface(const string& requiredInterfaceName)
{
    // S'il n'y a pas de widget central, on met à jour
    // le widget central en utilisant "allInterfaces" (QStackedWidget)
    setCentralWidget(allInterfaces);

    // Déconnection de l'ancienne interface

    disconnectCurrentInterface(getActualInterfaceObjectName());

    // On cherche à obtenir l'index de l'interface demandée
    int index = getInterfaceIndex(requiredInterfaceName);

    if (index == -1) // L'index retourné est -1 => l'interface n'est pas trouvée
        throw std::exception();


    // Mise à jour de l'index actuel dans le QStackedWidget
    allInterfaces->setCurrentIndex(index);

    // Mise à jour du nom de l'interface actuelle
    setWindowTitle(getActualInterfaceName());

    // Connection des éléments de l'interface actuelle
    connectCurrentInterface(requiredInterfaceName);

    showElementsOfInterface();
}

void MainWindow::changeWindowModeText()
{
    ui->actionPlein_cran->text() == Message::QActionText::QA_maximizedMode ?
                ui->actionPlein_cran->setText(Message::QActionText::QA_windowedMode) :
                ui->actionPlein_cran->setText(Message::QActionText::QA_maximizedMode);

    return;
}

void MainWindow::showStatusBarMessage(const string &message, int duration)
{
    this->ui->statusbar->showMessage(message, duration);
}

// Retourne l'index du widget en fonction de son nom
// Ou retourne -1 si le widget n'est pas trouvé
int MainWindow::getInterfaceIndex(const string &queriedInterfaceName)
{
    // On parcours le stackedWidget
    for (int i = 0; i < allInterfaces->count(); ++i)
    {
        // Si le nom du widget actuel correspond, on retourne son index
        if (allInterfaces->widget(i)->objectName() == queriedInterfaceName)
            return i;
    }
    return -1;
}

void MainWindow::connectCurrentInterface(const string &interfaceName)
{
    qDebug() << "calling Connection for " << interfaceName;

    // Connexion des éléments de l'interface WelcomeScreen
    if (interfaceName == SharedVar::InterfaceObjectName::WelcomeScreen_obj_name)
    {
        // Enregistrer un nouveau rendez-vous
        connect (getActualInterface_Screen<WelcomeScreen>(),
                &WelcomeScreen::newDateButton_HasBeenClicked,
                this, &MainWindow::on_newDateClick);

        // Effectuer une nouvelle consultation
        connect (getActualInterface_Screen<WelcomeScreen>(),
                 &WelcomeScreen::newConsultationButton_HasBeenClicked,
                 this, &MainWindow::on_newConsultationClick);

        // Consulter le dossier d'un patient
        connect (getActualInterface_Screen<WelcomeScreen>(),
                 &WelcomeScreen::patientsFolderButton_HasBeenClicked,
                 this, &MainWindow::on_patientsFolderClick);
    }

    // Connexion des éléments de l'interface SelectPatientScreen
    else if (interfaceName == SharedVar::InterfaceObjectName::SelectPatientScreen_obj_name)
    {
        // Créer/Enregistrer un nouveau patient dans la base de données patient
        connect (getActualInterface_Screen<SelectPatientScreen>(),
                 &SelectPatientScreen::newPatientButton_hasBeenClicked,
                 this, &MainWindow::on_newPatientClick);
    }

    // Connexion des éléments de l'interface CreatePatientScreen
    else if (interfaceName == SharedVar::InterfaceObjectName::CreatePatientScreen_obj_name)
    {
        // Créer/Enregistrer un nouveau patient dans la base de données patient
        connect (getActualInterface_Screen<CreatePatientScreen>(),
                 &CreatePatientScreen::savePatientFolder_hasBeenClicked,
                 this, &MainWindow::on_saveNewPatientClick);
    }

    // Connection du bouton "retour" de l'interface
    if (getActualInterface_Screen<Screen>()->hasReturnButton())
    {
        qDebug() << "Connection of return button because this interface has one";
        connect (getActualInterface_Screen<Screen>(),
                 &Screen::returnButtonClicked,
                 this, &MainWindow::on_returnButtonClick);
    }

    // Connection du chargement de la liste des patients depuis la base de données
    // si l'interface à connecter à un élément de liste à charger
    if ( getActualInterface_Screen<Screen>()->hasListWidget() )
    {
        qDebug() << "Connection of patient List";
        dataBaseManipulation::getPatientList(p_db.get(), getActualInterface_Widget()->findChild<QListWidget*>("patientList_LST"));
        connect(getActualInterface_Widget()->findChild<QListWidget*>("patientList_LST"),
                &QListWidget::itemDoubleClicked,
                this,
                &MainWindow::getPatientIndexFromList);
    }

    return;
}

void MainWindow::disconnectCurrentInterface(const string &interfaceName)
{
    qDebug() << "calling Disconnection of " << interfaceName;

    // Déconnexion des éléments de l'interface WelcomeScreen
    if (interfaceName == SharedVar::InterfaceObjectName::WelcomeScreen_obj_name)
    {
        disconnect (getActualInterface_Screen<WelcomeScreen>(),
                &WelcomeScreen::newDateButton_HasBeenClicked,
                this, &MainWindow::on_newDateClick);
        disconnect (getActualInterface_Screen<WelcomeScreen>(),
                 &WelcomeScreen::newConsultationButton_HasBeenClicked,
                 this, &MainWindow::on_newConsultationClick);
        disconnect (getActualInterface_Screen<WelcomeScreen>(),
                 &WelcomeScreen::patientsFolderButton_HasBeenClicked,
                 this, &MainWindow::on_patientsFolderClick);
    }

    // Déconnexion des éléments de l'interface SelectPatientScreen
    else if (interfaceName == SharedVar::InterfaceObjectName::SelectPatientScreen_obj_name)
    {
        disconnect (getActualInterface_Screen<SelectPatientScreen>(),
                 &SelectPatientScreen::newPatientButton_hasBeenClicked,
                 this, &MainWindow::on_saveNewPatientClick);
    }

    // Déconnexion des éléments de l'interface CreatePatientScreen
    else if (interfaceName == SharedVar::InterfaceObjectName::CreatePatientScreen_obj_name)
    {
        // Créer/Enregistrer un nouveau patient dans la base de données patient
        disconnect (getActualInterface_Screen<CreatePatientScreen>(),
                 &CreatePatientScreen::savePatientFolder_hasBeenClicked,
                 this, &MainWindow::on_saveNewPatientClick);
    }

    // Déconnection du bouton "retour" de l'interface
    if (getActualInterface_Screen<Screen>()->hasReturnButton())
    {
        qDebug() << "Disonnection of return button because this interface HAD one";
        disconnect (getActualInterface_Screen<Screen>(),
                 &Screen::returnButtonClicked,
                 this, &MainWindow::on_returnButtonClick);
    }

    // Déconnection du chargement de la liste des patients depuis la base de données
    // si l'interface à connecter à un élément de liste à charger
    if ( getActualInterface_Screen<Screen>()->hasListWidget() )
    {
        qDebug() << "Disconnection of patient List";
        dataBaseManipulation::getPatientList(p_db.get(), getActualInterface_Widget()->findChild<QListWidget*>("patientList_LST"));
        disconnect(getActualInterface_Widget()->findChild<QListWidget*>("patientList_LST"),
                &QListWidget::itemDoubleClicked,
                this,
                &MainWindow::getPatientIndexFromList);
    }

    return;
}

// Fonctions protégées ****************************************************************************

//Demande à la fermeture de la fenêtre si l'utilisateur est sûr de vouloir quitter ?
void MainWindow::closeEvent(QCloseEvent *event)
{
    int ret = msgBox::question(     this,
                                    trUtf8(Message::MsgBoxTitle::title_Quit),
                                    trUtf8(Message::Question::msg_sureToQuit),
                                    msgBox::Yes | msgBox::No
                                    );
     switch (ret)
     {
     case msgBox::Yes:
         event->accept();
         break;
     default:
         event->ignore();
         break;
     }
}

// Slots privés ***********************************************************************************

void MainWindow::changeWindowMode()
{
    switch(windowState())
    {
    case Qt::WindowMaximized:
        changeWindowModeText();
        setWindowState(Qt::WindowNoState);
        break;
    case Qt::WindowNoState:
        changeWindowModeText();
        setWindowState(Qt::WindowMaximized);
        break;
    }
    return;
}

void MainWindow::quitValidating()
{
    int ret = msgBox::question  (
                                    this,
                                    trUtf8(Message::MsgBoxTitle::title_Quit),
                                    trUtf8(Message::Question::msg_sureToQuit)
                                );
    switch (ret)
    {
        case msgBox::Yes:
            qApp->quit();
        break;
        default:
        break;
    }
}

int MainWindow::getPatientIndexFromList(QListWidgetItem * an_item)
{
    // L'index du patient à trouver dans la base de données en fonction de
    // son nom ou de son prénom tels qu'ils sont stockés
    int indexOfPatient = 0;

    // La requête
    QSqlQuery index (as<patientDatabase*>(p_db.get())->getDatabaseConnection());

    // La requête est-elle éxécutée correctement ?
    if (!index.exec(string(Statement::patientDatabase::getPatientIndex_byName).arg(an_item->text().split(" ").at(0))))
    {
        // Non ...
        msgBox::warning(NULL, "treatment error", index.lastError().text());
        // Mauvais index (négatif impossible ...)
        indexOfPatient = -1;
    }
    else // oui ...
    {
        if (index.first())
        {
            msgBox::information(NULL, "item", "item selected: " + an_item->text() + ", ID in database: " + index.value(0).toString());
            // Mise à jour de l'index
            indexOfPatient = index.value(0).toInt();
        }
    }
    // La fonction retourne le bon index
    return indexOfPatient;
}

// Slots d'interraction avec l'utilisateur ************************************************************

    // WelcomeScreen **********************************************************************************

        // clique sur 'patientsFolder_PB'
        void MainWindow::on_patientsFolderClick()
        {
            // Changement de l'interface
            setNewInterface(SharedVar::InterfaceObjectName::PatientMedicalFolder_obj_name);
        }

        // Clique sur 'newConsultation_PB'
        void MainWindow::on_newConsultationClick()
        {
            // Changement de l'interface
            setNewInterface(SharedVar::InterfaceObjectName::SelectPatientScreen_obj_name);
        }

        // Clique sur 'newDate_PB'
        void MainWindow::on_newDateClick()
        {
            setNewInterface(SharedVar::InterfaceObjectName::CreateNewDate_obj_name);
        }

        // Clique sur 'returnButton'
        void MainWindow::on_returnButtonClick()
        {
            // on change l'interface
            setNewInterface(SharedVar::InterfaceObjectName::WelcomeScreen_obj_name);
        }

    // END WelcomeScreen ******************************************************************************

    // SelectPatientScreen ****************************************************************************

        void MainWindow::on_newPatientClick()
        {
            // Changement d'interface
            setNewInterface(SharedVar::InterfaceObjectName::CreatePatientScreen_obj_name);
        }

    // END SelectPatientScreen ************************************************************************

    // CreatePatientScreen ****************************************************************************

        // FIXME
        void MainWindow::on_saveNewPatientClick()
        {            
            // Changement d'interface
            qDebug() << "saving new patient !";

            // Création des variables temporaires pour traiter les données saisies
            Screen * tempScreenInstance = getActualInterface_Screen<Screen>();
            if (!tempScreenInstance)
            {
                msgBox::critical(NULL, "error", "error creating instance of Screen");
            }
            // Obtention des données des éléments
            string pName (as <lineEdit*>(tempScreenInstance->getWidget("patientName_LE"))->text());
            string pSurname (as <lineEdit*>(tempScreenInstance->getWidget("patientSurname_LE"))->text());
            string pJob (as <lineEdit*>(tempScreenInstance->getWidget("patientJob_LE"))->text());
            string pPhoneNumber (as <lineEdit*>(tempScreenInstance->getWidget("patientPhoneNumber_LE"))->text());
            string pEmail (as <lineEdit*>(tempScreenInstance->getWidget("patientEmail_LE"))->text());
            string pCurrentMedic (as <lineEdit*>(tempScreenInstance->getWidget("patientCurrentMedic_LE"))->text());
            string pHobbies (as <lineEdit*>(tempScreenInstance->getWidget("patientHobbies_LE"))->text());
            string pPostalCodeAdress (as <lineEdit*>(tempScreenInstance->getWidget("postalCodeAdress_LE"))->text());
            string pCityNameAdress (as <lineEdit*>(tempScreenInstance->getWidget("cityNameAdress_LE"))->text());
            string pStreetAndNumAdress (as <lineEdit*>(tempScreenInstance->getWidget("streetAndNumAdress_LE"))->text());
            string pSocialSecurityNumber (as <lineEdit*>(tempScreenInstance->getWidget("patientSocialSecurityNumber_LE"))->text());

            QSqlQuery insertion (as <patientDatabase*>(p_db.get())->getDatabaseConnection());

            // FIXME réaranger la fonction d'insertion !!!!!!
            insertion.prepare   (
                                    "INSERT INTO general_infos (patientName, patientSurname, patientAdress_street_and_number ,patientAdress_postalCode"
                                    ",patientAdress_cityName, patientPhoneNumber ,patientEmail, patientJob, patientMedic, patientHobbies"
                                    ", patientSocialSecurityNumber)"
                                    "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)"
                                );

            insertion.bindValue(0, pName);
            insertion.bindValue(1, pSurname);
            insertion.bindValue(2, pStreetAndNumAdress);
            insertion.bindValue(3, pPostalCodeAdress);
            insertion.bindValue(4, pCityNameAdress);
            insertion.bindValue(5, pPhoneNumber);
            insertion.bindValue(6, pEmail);
            insertion.bindValue(7, pJob);
            insertion.bindValue(8, pCurrentMedic);
            insertion.bindValue(9, pHobbies);
            insertion.bindValue(10, pSocialSecurityNumber);

            if (!insertion.exec())
                msgBox::warning(NULL, "insertion error", insertion.lastError().text());
            return;
        }

    // END CreatePatientScreen ************************************************************************
