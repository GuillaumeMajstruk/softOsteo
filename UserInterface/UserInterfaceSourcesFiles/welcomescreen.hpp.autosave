#ifndef WELCOMESCREEN_HPP
#define WELCOMESCREEN_HPP

#include <QWidget>
#include <QPushButton>
#include <QString>
#include <QPalette>
#include <QDebug>

#include "UserInterface/userinterfaceloader.hpp"
#include "UserInterface/screen.hpp"


class WelcomeScreen : public Screen
{
    Q_OBJECT
public:

    // ///////////////////////////////////////////////////////////////////////////////
    // /                       CONSTRUCTEUR/DESTRUCTEUR                             //
    // ///////////////////////////////////////////////////////////////////////////////

    WelcomeScreen(Screen * parent = 0);
    virtual ~WelcomeScreen();

    // ///////////////////////////////////////////////////////////////////////////////

private:

    // ///////////////////////////////////////////////////////////////////////////////
    // /                    METHODES/ACCESSEURS/ATTRIBUTS                           //
    // ///////////////////////////////////////////////////////////////////////////////



    QPushButton *m_billButton = nullptr;
    QPushButton *m_managementButton = nullptr;
    QPushButton *m_newConsultationButton = nullptr;
    QPushButton *m_newMeetingButton = nullptr;
    QPushButton *m_patientsFolderButton = nullptr;

    // ///////////////////////////////////////////////////////////////////////////////

    // ///////////////////////////////////////////////////////////////////////////////
    // /                              SIGNALS                                       //
    // ///////////////////////////////////////////////////////////////////////////////
signals:
    void billButton_HasBeenClicked();
    void managementButton_HasBeenClicked();
    void newConsultationButton_HasBeenClicked();
    void newMeetingButton_HasBeenClicked();
    void patientsFolderButton_HasBeenClicked();

    // ///////////////////////////////////////////////////////////////////////////////

    // ///////////////////////////////////////////////////////////////////////////////
    // /                              SLOTS                                         //
    // ///////////////////////////////////////////////////////////////////////////////

private slots:
    void billButton_clicked();
    void managementButton_clicked();
    void newConsultationButton_clicked();
    void newMeetingButton_clicked();
    void patientsFolderButton_clicked();

    // ///////////////////////////////////////////////////////////////////////////////
};

#endif // WELCOMESCREEN_HPP
