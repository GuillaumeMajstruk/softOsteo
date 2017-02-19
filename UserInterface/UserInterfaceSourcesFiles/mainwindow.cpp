#include <QtGui>


#include "mainwindow.hpp"
#include "ui_mainwindow.h"

using Global::Debug::log_d;

/////////////////////////////////////////////////////////////////////////////////
///                       CONSTRUCTEUR/DESTRUCTEUR                             //
/////////////////////////////////////////////////////////////////////////////////
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    /// instanciation du userInterfaceLoader
    m_uiLoader = new userInterfaceLoader(STATIC);

    /// défini la taille minimum de 800x600 (px)
    setMinimumSize(*m_windowSize);

    /// connecte les éléments activables de la fenêtre principale à leurs slots respectifs
    connect(ui->actionQuitter, &QAction::triggered, this, &MainWindow::quitValidating);
    connect(ui->actionPlein_cran, &QAction::triggered, this, &MainWindow::setFullScreen);

    /// initialisation de l'interface actuelle
    setCurrentInterface("", Global::InterfaceObjectName::WelcomeScreen_obj_name);
    connect(dynamic_cast<WelcomeScreen*> (m_currentInterface),
            &WelcomeScreen::managementButton_HasBeenClicked,
            this, &MainWindow::printMessage);

    ui->statusbar->showMessage(QString("Bienvenue Guillaume, "
                                       "nous sommes le %1").arg(QDate::currentDate().toString(Qt::SystemLocaleLongDate)), 5000);
}

MainWindow::~MainWindow()
{
    delete m_uiLoader;
    delete m_windowSize;
    delete m_currentInterface;
    delete ui;
}
/////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////
///                              SLOTS                                         //
/////////////////////////////////////////////////////////////////////////////////
void MainWindow::setFullScreen()
{
    disconnect(ui->actionPlein_cran, SIGNAL(triggered()), this, SLOT(setFullScreen()));

    /// met à jour la nouvelle taille de fenêtre en fonction de
    /// l'écran principale
    m_windowSize = new QSize    (
                                    QDesktopWidget().width(),
                                    QDesktopWidget().height()
                                );

    ///applique la taille à l'écran
//    this->resize(*m_windowSize);
    this->setGeometry(0,0, QDesktopWidget().width(), QDesktopWidget().height());

    ui->actionPlein_cran->setText(trUtf8("Mode &fenêtré"));
    connect(ui->actionPlein_cran, SIGNAL(triggered()), this, SLOT(setWindowed()));
}

void MainWindow::setWindowed()
{
    ///déconnection pour éviter le conflit entre les signaux
    disconnect(ui->actionPlein_cran, &QAction::triggered, this, &MainWindow::setWindowed);

    /// met à jour la nouvelle taille de fenêtre
    /// en fonction de l'écran sur lequel le programme fonctionne
    m_windowSize = new QSize    (
                                    Global::Screen::defaultScreenSizeWindowed().widht,
                                    Global::Screen::defaultScreenSizeWindowed().height
                                );

    /// applique la taille à l'écran
    this->resize(*m_windowSize);

    ui->actionPlein_cran->setText(trUtf8("Mode Pl&ein Écran"));
    connect(ui->actionPlein_cran, &QAction::triggered, this, &MainWindow::setFullScreen);
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
    setCurrentInterface(Global::InterfaceObjectName::WelcomeScreen_obj_name,
                        Global::InterfaceObjectName::CreatePatientScreen_obj_name);
}

/////////////////////////////////////////////////////////////////////////////////


/// demande à la fermeture de la fenêtre si l'utilisateur est sûr de vouloir quitter ?
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

    /// Si currentInterface == empty -> il n'y a pas d'interface précédente
    if (!currentInterface.isEmpty())
    {
        /// l'interface précédente prend la valeur de l'interface actuelle
        m_previousInterface = m_uiLoader->m_allInterface [currentInterface];
        qDebug() << "previous interface: " << m_previousInterface->getInterfaceName();
    }

    /// l'interface actuelle devient l'interface qu'il y a dans la liste des interface
    m_currentInterface = m_uiLoader->m_allInterface [neededInterface];

    /// l'interface devient l'objet central de la fenêtre principale
    setCentralWidget(m_currentInterface->getWidget());

    /// met à jour le nom de l'interface actuelle
    setWindowTitle(getActualInterfaceName());

    qDebug() << "current interface: " << m_currentInterface->getInterfaceName();
    return;
}
