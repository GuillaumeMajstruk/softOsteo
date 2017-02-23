#ifndef MESSAGES_HPP
#define MESSAGES_HPP
// /////////////////////////////////////////////
// / Contient tous les messages du programme ///
// /////////////////////////////////////////////
#include <QString>

typedef const char* Msg;

    namespace Message
    {
        namespace Question
        {
            static Msg msg_sureToQuit = "Êtes-vous sûr de vouloir quitter ?";
        }

        namespace QActionText
        {
            static Msg QA_maximizedMode = "Mode Pl&ein Écran";
            static Msg QA_windowedMode = "Mode &fenêtré";
        }

        namespace MsgBoxTitle
        {
            static Msg title_Quit = "Quitter ?";

            static Msg title_ConnectionToDataBase_Ok = "Connection Etablie !";

            static Msg title_ConnectionRequestInformationLack = "Manque d'information(s) !";
            static Msg title_Connection_Ok = "Connection réussie.";

            struct Error_Msg
            {
                static constexpr Msg title_Error = "Error !";
                static constexpr Msg title_AuthentificationError = "Erreur d'authentification !";
            };
        }

        namespace MsgBoxContent
        {
            static Msg content_DatabaseConnectionError = "Impossible d'établir la connection à la base de donnée !";
            static Msg content_DatabaseConnectionOk = "Connection à la base de donnée établie avec succés.";
            static Msg content_ConnectionRequestInformationLack = "Tous les champs doivent être remplis.";
            static Msg content_AuthentificationError = "Les identifiants rentrés sont invalides !";
            static Msg content_Connection_Ok = "Connection réussie !\nBienvenue %1";
        }

        namespace ToolTips
        {
            static Msg tt_Connection_UserName = "Entrez ici votre nom d'utilisateur pour pouvoir vous connecter.";
            static Msg tt_Connection_Password = "Entrez ici votre mot de passe pour pouvoir vous connecter.";
        }
    }
#endif /// MESSAGES_HPP
