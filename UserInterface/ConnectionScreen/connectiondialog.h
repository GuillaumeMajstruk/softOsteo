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

#ifndef CONNECTIONDIALOG_H
#define CONNECTIONDIALOG_H

#include <string>
#include <QInputEvent>
#include <QDir>
#include <QSettings>

#include <QSqlQuery>

#include "Messages/messages.hpp"
#include "DataBase/connectiondatabase.hpp"
#include "typedefs.hpp"

// ConnectionDialog est une classe qui est chargée de gérer l'accès
// à l'application en fonction depar l'utilisation d'un mot de passe et
// d'un nom d'utilisateur.

namespace Ui {
class ConnectionDialog;
}

class ConnectionDialog : public QDialog
{
    Q_OBJECT
public: // Constructeur et destructeur ***************************************

    explicit ConnectionDialog(QWidget *parent = 0);
    ~ConnectionDialog();

private: // Attributs privés *************************************************
    Ui::ConnectionDialog *ui;

    // Provisoire: base de donnée de connection
    connectionDataBase *connection_db = Q_NULLPTR;

    // Correspond à ce qu'il y a dans UsernameTexte.
    string enteredUsername;
    // Correspond à ce qu'il y a dans PasswordTexte.
    string enteredPass;


    // Si la fonction 'compareEnteredIds' revoie vrai => isConnected = true.
    bool isConnected = false;

private: // Fonctions privées ***********************************************

    // Quand l'utilisateur clique sur le bouton Ok de la page de connection
    // les variables enteredUsername et enteredPass sont mises à jour en fonction
    // de ce qui est dans les lineEdits correpondant.
    void updateEnteredIds();


    // Compare les identifiants entrés à ceux stockés pour l'instant dans une variable
    bool compareEnteredIds();

protected: // Fonctions protégées ***************************************

    // Surchargé pour ignorer un appuie sur les touches échape et entrer
    // De base pour un QDialog, 'entrer' et 'échape' ferment la fenêtre.
    void keyPressEvent(QKeyEvent *);

    // Surchargé pour éviter d'accéder à l'application sans avoir à entrer
    // les identifiants de connexion et quitte l'application entièrement
    // si besoin est.
    void closeEvent(QCloseEvent *);

private slots: // Slots privés *******************************************

    // Appelle les fonctions membres 'updateEnteredIds' et 'compareEnteredIds'
    // puis met à jour le status de l'application en fonction du résultat de
    // la connection
    void checkConnectionIds ();

    // Quitte l'application entièrement.
    void Quit();
};

#endif // CONNECTIONDIALOG_H
