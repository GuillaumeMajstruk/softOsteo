#include <QtGui>


#include "mainwindow.hpp"
#include "ui_mainwindow.h"

using SharedVar::Debug::log_d;

// ///////////////////////////////////////////////////////////////////////////////
// /                       CONSTRUCTEUR/DESTRUCTEUR                             //
// ///////////////////////////////////////////////////////////////////////////////
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    // / instanciation du userInterfaceLoader
    m_uiLoader = new userInterfaceLoader(STATIC);

    ///  défini la taille minimum de 800x600 (px)
    setMinimumSize(*m_windowSize);

    // / connecte les éléments activables de la fenêtre principale à leurs slots respectifs
    connect(ui->actionQuitter, &QAction::triggered, this, &MainWindow::quitValidating);
    connect(ui->actionPlein_cran, &QAction::triggered, this, &MainWindow::changeWindowMode);

    // / initialisation de l'interface actuelle
    setCurrentInterface("", SharedVar::InterfaceObjectName::WelcomeScreen_obj_name);
    connect(dynamic_cast<WelcomeScreen*> (m_currentInterface),
            &WelcomeScreen::managementButton_HasBeenClicked,
            this, &MainWindow::printMessage);

    // Récupération du nom de l'utilisateur actuel
    // TODO: test des settings !!!!
    QSettings settings(QSettings::IniFormat, QSettings::UserScope, qApp->organizationName(), qApp->applicationName());
    m_currentUserName = settings.value("connection/UserId").toString();


    ui->statusbar->showMessage(QString("Bienvenue " + m_currentUserName + ", "
                                       "nous sommes le %1").arg(QDate::currentDate().toString(Qt::SystemLocaleLongDate)), 5000);
}

MainWindow::~MainWindow()
{
    delete m_uiLoader;
    delete m_windowSize;
    delete m_currentInterface;
    delete ui;
}
// ///////////////////////////////////////////////////////////////////////////////


// ///////////////////////////////////////////////////////////////////////////////
// /                              SLOTS                                         //
// ///////////////////////////////////////////////////////////////////////////////

void MainWindow::changeWindowModeText()
{
    ui->actionPlein_cran->text() == Message::QActionText::QA_maximizedMode ?
                ui->actionPlein_cran->setText(Message::QActionText::QA_windowedMode) :
                ui->actionPlein_cran->setText(Message::QActionText::QA_maximizedMode);

    return;
}

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
    int ret = QMessageBox::question  (
                                            this,
                                            trUtf8(Message::MsgBoxTitle::title_Quit),
                                            trUtf8(Message::Question::msg_sureToQuit),
                                            QMessageBox::Yes | QMessageBox::No,
                                            QMessageBox::Yes
                                        );

    switch (ret)
    {
        case QMessageBox::Yes:
            qApp->quit();
        break;
        default:
        break;
    }
}

void MainWindow::printMessage()
{
    log_d(QVariant("Signal Received").toString());
    setCurrentInterface(SharedVar::InterfaceObjectName::WelcomeScreen_obj_name,
                        SharedVar::InterfaceObjectName::CreatePatientScreen_obj_name);
}

// ///////////////////////////////////////////////////////////////////////////////


// / demande à la fermeture de la fenêtre si l'utilisateur est sûr de vouloir quitter ?
void MainWindow::closeEvent(QCloseEvent *event)
{
    int ret = QMessageBox::question(this,
                                    trUtf8(Message::MsgBoxTitle::title_Quit),
                                    trUtf8(Message::Question::msg_sureToQuit),
                                    QMessageBox::Yes
                                    | QMessageBox::No
                                    );
     switch (ret)
     {
     case QMessageBox::Yes:
         event->accept();
         break;
     default:
         event->ignore();
         break;
     }
}

void MainWindow::setCurrentInterface(const QString &currentInterface, const QString &neededInterface)
{
    if (neededInterface.isEmpty())

    if (!m_uiLoader->m_allInterface.contains(neededInterface))
        qDebug() << "nullWidget";

    // / Si currentInterface == empty -> il n'y a pas d'interface précédente
    if (!currentInterface.isEmpty())
    {
        // / l'interface précédente prend la valeur de l'interface actuelle
        m_previousInterface = m_uiLoader->m_allInterface [currentInterface];
        qDebug() << "previous interface: " << m_previousInterface->getInterfaceName();
    }

    // / l'interface actuelle devient l'interface qu'il y a dans la liste des interface
    m_currentInterface = m_uiLoader->m_allInterface [neededInterface];

    // / l'interface devient l'objet central de la fenêtre principale
    setCentralWidget(m_currentInterface->getWidget());

    // / met à jour le nom de l'interface actuelle
    setWindowTitle(getActualInterfaceName());

    qDebug() << "current interface: " << m_currentInterface->getInterfaceName();
    return;
}
