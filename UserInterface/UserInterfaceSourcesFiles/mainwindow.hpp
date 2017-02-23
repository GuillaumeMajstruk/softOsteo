#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <memory>
#include <QDesktopWidget>
#include <QMessageBox>
#include <QString>
#include <QWidget>
#include <QSize>
#include <QSettings>


#include "UserInterface/UserInterfaceSourcesFiles/selectpatientscreen.hpp"
#include "UserInterface/interfaceGlobal.hpp"
#include "UserInterface/UserInterfaceSourcesFiles/welcomescreen.hpp"
#include "UserInterface/userinterfaceloader.hpp"
#include "UserInterface/screen.hpp"

#include "Messages/messages.hpp"

namespace Ui {
class MainWindow;
}



// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// / la classe MainWindow est la fenêtre qui contiendra les interfaces (QWidget) représentants les différentes fenêtres du programme ///
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class  MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    // ///////////////////////////////////////////////////////////////////////////////
    // /                       CONSTRUCTEUR/DESTRUCTEUR                             //
    // ///////////////////////////////////////////////////////////////////////////////
    // / constructeur
    explicit MainWindow(QWidget *parent = 0);

    // / destructeur
    virtual ~MainWindow();

    // ///////////////////////////////////////////////////////////////////////////////


    // ///////////////////////////////////////////////////////////////////////////////
    // /                              METHODES/ACCESSEURS                           //
    // ///////////////////////////////////////////////////////////////////////////////
    // / retourne le nom de l'interface actuelle
    QString getActualInterfaceName() const
    {
        return { m_currentInterface->getInterfaceName() };
    }

    //  retourne l'objet interface acuelle (m_currentInterface)
    QWidget* getActualInterface() const { return m_currentInterface->getWidget(); }

    /////////////////////////////////////////////////////////////////////////////////

private:

    // ///////////////////////////////////////////////////////////////////////////////
    // /                              METHODES:ATTRIBUTS                            //
    // ///////////////////////////////////////////////////////////////////////////////
    // / interface utilisateur
    Ui::MainWindow *ui;

    // / Utilisateur actuel du programme
    QString m_currentUserName;

    // / Chargeur d'interface
    userInterfaceLoader * m_uiLoader = nullptr;

    // / Taille par défaut de l'interface utilisateur (-> mode fenêtré)
    QSize *m_windowSize = new QSize     (
                                            Global::Screen::defaultScreenSizeWindowed().widht,
                                            Global::Screen::defaultScreenSizeWindowed().height
                                        );

    // / interface utilisateur actuelle (utilisée en tant que widget dans la fenêtre principale)
    // /appelle le constructeur de Qwidget->Screen->WelcomeScreen
    Screen * m_currentInterface = nullptr;

    // / quand l'interface change, on garde en mémoire l'interface précédente pour pouvoir faire un
    // / retour
    Screen * m_previousInterface = nullptr;

    // ///////////////////////////////////////////////////////////////////////////////

    // / Défini l'interface utilisateur actuellement utilisée
    void setCurrentInterface (const QString& currentInterface, const QString& neededInterface);

    // / change le message de l'action de mode de fenêtre
    void changeWindowModeText();

protected:
    void closeEvent(QCloseEvent * event);


    // ///////////////////////////////////////////////////////////////////////////////
    // /                              SLOTS                                         //
    // ///////////////////////////////////////////////////////////////////////////////
private slots:

    // / Gère la mise à l'échelle de l'écran (plein écran / fenêtré)
    void changeWindowMode();

    // / demande à l'utilisateur s'il veut vraiment quitter ?
    void quitValidating ();

    // / test pour le slot
    void printMessage ();

    // ///////////////////////////////////////////////////////////////////////////////

    // ///////////////////////////////////////////////////////////////////////////////
    // /                              SIGNALS                                       //
    // ///////////////////////////////////////////////////////////////////////////////
signals:
    // /...
};

#endif // / MAINWINDOW_HPP
