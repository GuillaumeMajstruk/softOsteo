#include "connectiondialog.h"
#include "ui_connectiondialog.h"

ConnectionDialog::ConnectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectionDialog)
{
    /// Mise à jour de l'interface
    ui->setupUi(this);

    /// Définition de la taille fixe de la fenêtre de connection
    setFixedSize(250, 150);
    this->setWindowState(Qt::WindowActive);

    /// Mise à jour des Tooltips
    ui->UsernameTexte->setToolTip(Message::ToolTips::tt_Connection_UserName);
    ui->PasswordTexte->setToolTip(Message::ToolTips::tt_Connection_Password);

    /// Mise à jour du mode de remplissage de QLineEdit "PasswordText"
    ui->PasswordTexte->setEchoMode(QLineEdit::Password);

    /// Connection des éléments de l'interface
    connect(ui->OkButton,
            &QPushButton::clicked,
            this,
            &ConnectionDialog::checkConnectionIds);
    connect(ui->QuitButton,
            &QPushButton::clicked,
            this,
            &ConnectionDialog::Quit);

    connection_db = new dataBase;

}

/// Destructeur
ConnectionDialog::~ConnectionDialog()
{
    delete ui;
}


void ConnectionDialog::updateEnteredIds()
{
    enteredUsername =  ui->UsernameTexte->text();
    enteredPass = ui->PasswordTexte->text();

    if (enteredUsername.isEmpty() || enteredPass.isEmpty())
        QMessageBox::warning(NULL,
                             Message::MsgBoxTitle::title_ConnectionRequestInformationLack,
                             Message::MsgBoxContent::content_ConnectionRequestInformationLack);


}

bool ConnectionDialog::compareEnteredIds()
{
    if (enteredUsername != m_userName || enteredPass != m_password)
    {
        QMessageBox::critical(NULL,
                              Message::MsgBoxTitle::Error_Msg::title_AuthentificationError,
                              Message::MsgBoxContent::content_AuthentificationError);

        ui->UsernameTexte->clear();
        ui->PasswordTexte->clear();
        return false;
    }
    else return true;
}

void ConnectionDialog::checkConnectionIds()
{
    updateEnteredIds();
    if (compareEnteredIds())
    {
        QMessageBox::information(NULL,
                                 Message::MsgBoxTitle::title_Connection_Ok,
                                 QString(Message::MsgBoxContent::content_Connection_Ok).arg(enteredUsername));
        isConnected = true;

        close();
    }
    update();
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

    QDialog::keyPressEvent(event);
}

void ConnectionDialog::closeEvent(QCloseEvent *)
{
    if (!isConnected) return exit(0);
    else return;
}
