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

#include "connectiondialog.h"
#include "ui_connectiondialog.h"

ConnectionDialog::ConnectionDialog(QWidget *parent) :
    dialog(parent),
    ui(new Ui::ConnectionDialog)
{
    // / Mise à jour de l'interface
    ui->setupUi(this);

    // / Définition de la taille fixe de la fenêtre de connection
    setFixedSize(250, 150);
    this->setWindowState(Qt::WindowActive);

    // / Mise à jour des Tooltips
    ui->UsernameTexte->setToolTip(Message::ToolTips::tt_Connection_UserName);
    ui->PasswordTexte->setToolTip(Message::ToolTips::tt_Connection_Password);

    // / Mise à jour du mode de remplissage de QLineEdit "PasswordText"
    ui->PasswordTexte->setEchoMode(QLineEdit::Password);

    // / Connection des éléments de l'interface
    connect(ui->OkButton,
            &pushButton::clicked,
            this,
            &ConnectionDialog::checkConnectionIds);
    connect(ui->QuitButton,
            &pushButton::clicked,
            this,
            &ConnectionDialog::Quit);

    connection_db = new connectionDataBase;

}

// / Destructeur
ConnectionDialog::~ConnectionDialog()
{
    delete ui;
    connection_db->getDatabaseConnection().close();
}


void ConnectionDialog::updateEnteredIds()
{
    // les variables sont initialisées en fonction de ce qu'il y a dans les champs correspondants
    enteredUsername =  ui->UsernameTexte->text();
    enteredPass = ui->PasswordTexte->text();

    // Si au moins un des champs est vide, on le signal avec un message
    if (enteredUsername.isEmpty() || enteredPass.isEmpty())
        msgBox::warning(NULL,
                             Message::MsgBoxTitle::title_ConnectionRequestInformationLack,
                             Message::MsgBoxContent::content_ConnectionRequestInformationLack);


}

bool ConnectionDialog::compareEnteredIds()
{
    // Création du la requête de connection de la base de données qui contient les identifiants de connection
    QSqlQuery connectionQuery (connection_db->getDatabaseConnection());

    // Demande dans la table à accéder aux champs username et password
    if (!connectionQuery.exec("SELECT Username, password FROM users"))
        msgBox::critical(NULL, "Error !", connectionQuery.lastError().text());

    // Tant qu'il y a des données on les parcours ...
    while (connectionQuery.next())
    {
        // Pour chaque ligne on stock les informations recontrées
        QString usrNme = connectionQuery.value(0).toString();
        QString pwd = connectionQuery.value(1).toString();

        // Puis on compare la valeur hashé de ce qui est entré avec ce qui est stocké dans la base de données
        if (usrNme == connectionDataBase::hashWithoutSalt(enteredUsername)
                && pwd == connectionDataBase::hashWithSalt(enteredPass))
        {
            // S'ils correspondent -> IDENTIFICATION OK !
            return true;
        }
    }

    // Sinon si on a pas recontré d'éléments qui correspondent -> message d'erreur d'autentification
    msgBox::critical(NULL,
                          Message::MsgBoxTitle::Error_Msg::title_AuthentificationError,
                          Message::MsgBoxContent::content_AuthentificationError);

    // On néttoie les champs qui ont étés remplis dans les Line Edit correspondants
    ui->UsernameTexte->clear();
    ui->PasswordTexte->clear();

    // La fonction renvoie faux pour signaler que les informations ne correspondent pas !
    return false;
}

void ConnectionDialog::checkConnectionIds()
{
    // On met à jour les variables enteredUsername et enteredPass pour être sûr de leur validité
    updateEnteredIds();

    // Si l'autentification réussie -> on affiche un message pour le signaler
    if (compareEnteredIds())
    {
        // Enregistrement du dernier utilisateur connecté
        QSettings settings(QSettings::IniFormat, QSettings::UserScope, qApp->organizationName(), qApp->applicationName());
        qDebug() << enteredUsername;
        settings.setValue("connection/UserId", enteredUsername);
        // *****************************************************
        msgBox::information(NULL,
                                 Message::MsgBoxTitle::title_Connection_Ok,
                                 QString(Message::MsgBoxContent::content_Connection_Ok).arg(enteredUsername));
        isConnected = true;

        close();
    }
    //update();
}

void ConnectionDialog::Quit()
{
    return exit(0);
}

void ConnectionDialog::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Escape:
        return;
    default:
        break;
    }

    dialog::keyPressEvent(event);
}

void ConnectionDialog::closeEvent(QCloseEvent *)
{
    if (!isConnected) return exit(0);
    else return;
}
