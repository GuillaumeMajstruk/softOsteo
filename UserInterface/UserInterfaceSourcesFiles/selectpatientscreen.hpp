#ifndef SELECTPATIENTSCREEN_HPP
#define SELECTPATIENTSCREEN_HPP

#include <QWidget>
#include <QtGui>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>

#include "UserInterface/userinterfaceloader.hpp"



class SelectPatientScreen : public Screen
{
    Q_OBJECT
public:
    explicit SelectPatientScreen(Screen *parent = 0);
    virtual ~SelectPatientScreen();

private:
    // ///////////////////////////////////////////////////////////////////////////////
    // /                    METHODES/ACCESSEURS/ATTRIBUTS                           //
    // ///////////////////////////////////////////////////////////////////////////////

    QPushButton * m_newPatientButton = nullptr;
    QPushButton * m_returnButton = nullptr;
    QPushButton * m_validateSelectionButton = nullptr;
    QPushButton * m_searchButton = nullptr;

    QLabel * m_searchPatientLabel = nullptr;

    QLineEdit * m_searchPatientLineEdit = nullptr;

    QListWidget * m_patientList = nullptr;

    // ///////////////////////////////////////////////////////////////////////////////

    // ///////////////////////////////////////////////////////////////////////////////
    // /                              SIGNALS                                       //
    // ///////////////////////////////////////////////////////////////////////////////
signals:
    void newPatientButton_hasBeenClicked();
    void returnButton_hasBeenClicked();
    void validateSelectionButton_hasBeenClicked();
    void searchButton_hasBeenClicked();

    void searchPatientLineEdit_textHasBeenEdited(const QString&);

    // ///////////////////////////////////////////////////////////////////////////////

    // ///////////////////////////////////////////////////////////////////////////////
    // /                              SLOTS                                         //
    // ///////////////////////////////////////////////////////////////////////////////
private slots:
    void newPatientButton_clicked()
    {
        qDebug() << "newPatientButton_clicked()";
        emit newPatientButton_hasBeenClicked();
    }

    void returnButton_clicked()
    {
        qDebug() << "returnButton_clicked()";
        emit returnButton_hasBeenClicked();
    }

    void validateSelectionButton_clicked()
    {
        qDebug() << "validateSelectionButton_clicked()";
        emit validateSelectionButton_hasBeenClicked();
    }

    void searchButton_clicked()
    {
        qDebug() << "searchButton_clicked()";
        emit validateSelectionButton_hasBeenClicked();
    }

    void searchPatientLineEdit_textEdited(const QString&)
    {
        qDebug() << "searchPatientLineEdit_clicked()";
        emit searchPatientLineEdit_textHasBeenEdited(m_searchPatientLineEdit->text());
    }

    // ///////////////////////////////////////////////////////////////////////////////
};

#endif // SELECTPATIENTSCREEN_HPP
