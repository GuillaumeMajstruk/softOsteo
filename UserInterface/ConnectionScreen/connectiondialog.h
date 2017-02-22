#ifndef CONNECTIONDIALOG_H
#define CONNECTIONDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QString>
#include <QInputEvent>
#include <QDir>
#include <QSettings>

#include <QSqlQuery>

#include "Messages/messages.hpp"
#include "DataBase/connectiondatabase.hpp"

// ConnectionDialog est une classe qui est chargée de gérer l'accès
// à l'application en fonction depar l'utilisation d'un mot de passe et
// d'un nom d'utilisateur.

namespace Ui {
class ConnectionDialog;
}

class ConnectionDialog : public QDialog
{
    Q_OBJECT

public: /// Constructeur et destructeur

    explicit ConnectionDialog(QWidget *parent = 0);
    ~ConnectionDialog();

private: /// Attributs
    Ui::ConnectionDialog *ui;

    // Provisoire: base de donnée de connection
    connectionDataBase *connection_db = Q_NULLPTR;

    /// Correspond à ce qu'il y a dans UsernameTexte.
    QString enteredUsername;
    ///Correspond à ce qu'il y a dans PasswordTexte.
    QString enteredPass;


    /// Si la fonction 'compareEnteredIds' revoie vrai => isConnected = true.
    bool isConnected = false;

private: ///functions
    /// Quand l'utilisateur clique sur le bouton Ok de la page de connection
    /// les variables enteredUsername et enteredPass sont mises à jour en fonction
    /// de ce qui est dans les lineEdits correpondant.
    void updateEnteredIds();


    /// Compare les identifiants entrés à ceux stockés pour l'instant dans une variable
    /// TODO: pouvoir comparer les identifiants rentrés à des identifiants stockés.
    /// dans une base de donnée !
    bool compareEnteredIds();

protected:
    /// Surchargé pour ignorer un appuie sur les touches échape et entrer
    /// De base pour un QDialog, 'entrer' et 'échape' ferment la fenêtre.
    void keyPressEvent(QKeyEvent *);

    /// Surchargé pour éviter d'accéder à l'application sans avoir à entrer
    /// les identifiants de connexion et quitte l'application entièrement
    /// si besoin est.
    void closeEvent(QCloseEvent *);

private slots:
    /// Appelle les fonctions membres 'updateEnteredIds' et 'compareEnteredIds'
    /// puis met à jour le status de l'application en fonction du résultat de
    /// la connection
    void checkConnectionIds ();

    /// Quitte l'application entièrement.
    void Quit();
};

#endif // CONNECTIONDIALOG_H
