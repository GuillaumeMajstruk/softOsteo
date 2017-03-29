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

    // / instanciation du chargeur d'interface
    m_uiLoader = new userInterfaceLoader(STATIC);

    //   défini la taille minimum de 800x600 (px)
    setMinimumSize(*m_windowSize);

    // / connexion les actions de la barre de menu
    connect(ui->actionQuitter, &QAction::triggered, this, &MainWindow::quitValidating);
    connect(ui->actionPlein_cran, &QAction::triggered, this, &MainWindow::changeWindowMode);


    // TODO REVOIR IMPLEMENTATION ***********************************************************************
    allInterfaces = new QStackedWidget();
    for (int i = 0; i < m_uiLoader->m_allInterfaceVector.size(); ++i)
    {
        allInterfaces->addWidget(m_uiLoader->m_allInterfaceVector[i]->getInterfaceWidget());
    }

    setCentralWidget(allInterfaces);
    // Connections des éléments utilisables de l'interface
    connect(dynamic_cast<WelcomeScreen*>(m_uiLoader->m_allInterfaceVector[allInterfaces->currentIndex()]),
            &WelcomeScreen::newDateButton_HasBeenClicked,
            this, &MainWindow::on_newDateClick);
    // ***************************************************************************************************

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
    delete m_currentInterface;
    delete ui;
}

// Fonctions privés *******************************************************************************

// TODO modification complète => QStackedWidget
void MainWindow::setCurrentInterface(const QString &currentInterface, const QString &neededInterface)
{
    return;
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

// Slots d'interaction avec l'utilisateur ****************************************

// clique sur 'patientsFolder_PB'
void MainWindow::on_patientsFolderClick()
{
    // Changement de l'interface
    setCurrentInterface(getActualInterfaceObjectName(),
                        SharedVar::InterfaceObjectName::SelectPatientScreen_obj_name);
}

// Clique sur 'newConsultation_PB'
void MainWindow::on_newConsultationClick()
{
    // Changement de l'interface
    setCurrentInterface(getActualInterfaceObjectName(),
                        SharedVar::InterfaceObjectName::SelectPatientScreen_obj_name);
}

// Clique sur 'newDate_PB'
void MainWindow::on_newDateClick()
{
    qDebug() << "signal signal";
    allInterfaces->setCurrentIndex(1);
    connect(dynamic_cast<SelectPatientScreen*>(m_uiLoader->m_allInterfaceVector[allInterfaces->currentIndex()]),
            &SelectPatientScreen::returnButton_hasBeenClicked,
            this, &MainWindow::goBack);
}

// Clique sur 'returnButton'
void MainWindow::on_returnButtonClick()
{
    // on change l'interface
    setCurrentInterface(getActualInterfaceObjectName(),
                        SharedVar::InterfaceObjectName::WelcomeScreen_obj_name);

}

// test
void MainWindow::goBack()
{
    allInterfaces->setCurrentIndex(0);
}
