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

    // instanciation du chargeur d'interface
    m_uiLoader = new userInterfaceLoader(STATIC);

    //   défini la taille minimum de 800x600 (px)
    setMinimumSize(*m_windowSize);

    // connexion les actions de la barre de menu
    connect(ui->actionQuitter, &QAction::triggered, this, &MainWindow::quitValidating);
    connect(ui->actionPlein_cran, &QAction::triggered, this, &MainWindow::changeWindowMode);


    // FIXME REVOIR IMPLEMENTATION ***********************************************************************
    // Initialisation du StackedWidget
    initStackedInterfaces();

    // Mise à jour de l'interface actuelle et gestion de la connection / déconnexion des widgets des interfaces
    setNewtInterface(SharedVar::InterfaceObjectName::WelcomeScreen_obj_name);

    // Définition du nom de l'utilisateur actuel
    QSettings settings(QSettings::IniFormat, QSettings::UserScope, qApp->organizationName(), qApp->applicationName());
    m_currentUserName = settings.value("connection/UserId").toString();

    // Affiche le message de bienvenue pendant 5 secondes
    showStatusBarMessage(QString(Message::StatusBar::statusBarWelcome).arg(m_currentUserName,
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
        allInterfaces->addWidget(static_cast<Screen*>(widget)->getInterfaceWidget());
    }
}

// FIXME modification complète => utilisation d'un QStackedWidget
// Met à jour l'interface actuelle et connecte ses éléments
// Enregistre l'interface précédente et déconnecte ses éléments
void MainWindow::setNewtInterface(const QString& requiredInterfaceName)
{
    // S'il n'y a pas de widget central, on met à jour
    // le widget central en utilisant "allInterfaces" (QStackedWidget)
    setCentralWidget(allInterfaces);

    // Déconnection de l'ancienne interface

    disconnectCurrentInterface(getActualInterfaceObjectName());

    // On cherche à obtenir l'index de l'interface demandée
    int index = getInterfaceIndex(requiredInterfaceName);

    if (index == -1) // L'index retourné est -1 => l'interface n'est pas trouvée
        throw std::exception("erreur de chargement d'interface", 9);


    // Mise à jour de l'index actuel dans le QStackedWidget
    allInterfaces->setCurrentIndex(index);

    // Mise à jour du nom de l'interface actuelle
    setWindowTitle(getActualInterfaceName());

    // Connection des éléments de l'interface actuelle
    connectCurrentInterface(requiredInterfaceName);
}

void MainWindow::changeWindowModeText()
{
    ui->actionPlein_cran->text() == Message::QActionText::QA_maximizedMode ?
                ui->actionPlein_cran->setText(Message::QActionText::QA_windowedMode) :
                ui->actionPlein_cran->setText(Message::QActionText::QA_maximizedMode);

    return;
}

void MainWindow::showStatusBarMessage(const QString &message, int duration)
{
    this->ui->statusbar->showMessage(message, duration);
}

// Retourne l'index du widget en fonction de son nom
// Ou retourne -1 si le widget n'est pas trouvé
int MainWindow::getInterfaceIndex(const QString &queriedInterfaceName)
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

void MainWindow::connectCurrentInterface(const QString &interfaceName)
{
    qDebug() << "calling Connection for " << interfaceName;
    if (interfaceName == SharedVar::InterfaceObjectName::WelcomeScreen_obj_name)
    {
        connect (getActualInterface_Screen<WelcomeScreen>(),
                &WelcomeScreen::newDateButton_HasBeenClicked,
                this, &MainWindow::on_newDateClick);
        connect (getActualInterface_Screen<WelcomeScreen>(),
                 &WelcomeScreen::newConsultationButton_HasBeenClicked,
                 this, &MainWindow::on_newConsultationClick);
        connect (getActualInterface_Screen<WelcomeScreen>(),
                 &WelcomeScreen::patientsFolderButton_HasBeenClicked,
                 this, &MainWindow::on_patientsFolderClick);
    }

    // Connection du bouton "retour" de l'interface
    if (getActualInterface_Screen<Screen>()->hasReturnButton())
    {
        qDebug() << "Connection of return button because this interface has one";
        connect (getActualInterface_Screen<Screen>(),
                 &Screen::returnButtonClicked,
                 this, &MainWindow::on_returnButtonClick);
    }
    return;
}

void MainWindow::disconnectCurrentInterface(const QString &interfaceName)
{
    qDebug() << "calling Disconnection of " << interfaceName;
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
    // Connection du bouton "retour" de l'interface
    if (getActualInterface_Screen<Screen>()->hasReturnButton())
    {
        qDebug() << "Disonnection of return button because this interface HAD one";
        disconnect (getActualInterface_Screen<Screen>(),
                 &Screen::returnButtonClicked,
                 this, &MainWindow::on_returnButtonClick);
    }
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

// Slots d'interraction avec l'utilisateur ****************************************

// clique sur 'patientsFolder_PB'
void MainWindow::on_patientsFolderClick()
{
    // Changement de l'interface
    setNewtInterface(SharedVar::InterfaceObjectName::PatientMedicalFolder_obj_name);
}

// Clique sur 'newConsultation_PB'
void MainWindow::on_newConsultationClick()
{
    // Changement de l'interface
    setNewtInterface(SharedVar::InterfaceObjectName::SelectPatientScreen_obj_name);
}

// Clique sur 'newDate_PB'
void MainWindow::on_newDateClick()
{
    setNewtInterface(SharedVar::InterfaceObjectName::CreateNewDate_obj_name);
}

// Clique sur 'returnButton'
void MainWindow::on_returnButtonClick()
{
    // on change l'interface
    setNewtInterface(SharedVar::InterfaceObjectName::WelcomeScreen_obj_name);
}
