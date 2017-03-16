#ifndef DATAENCRYPTOR_HPP
#define DATAENCRYPTOR_HPP


#include <QCryptographicHash>
#include <QByteArray>
#include <QString>
#include <QDebug>
#include <QChar>

class connectionDataBase;

enum CharLimit
{
    charMove = 6,
    minChar = 97,
    maxChar = 122,
    minNum = 48,
    maxNum = 57
};


// Class de cryptage de donnée pour le programme softOsteo
class dataEncryptor
{
    friend class QCryptographicHash;

    // Pour faire en sorte que la classe connectionDataBase puisse accéder aux fonctions
    // de dataEncryptor
    friend class connectionDataBase;

public: // Constructeur
    explicit dataEncryptor();

public: // Fonctions publiques
    // une fonction pour crypter des chaines de caractères (tout en faisant en sorte qu'elles soient décryptables)
    static QString encrypt (const QString& strToEncrypt);

    // la fonction de décryptage de la fonction précédente
    static QString decrypt (const QString& strToDecrypt);

    // ceci est un test pour voir si je peux streamer ou pas

private: // fonctions privées
#ifndef SALT_BEFORE
#define SALT_BEFORE "sjkdfnqAH12J"
#endif // SALT_BEFORE

#ifndef SALT_AFTER
#define SALT_AFTER  "12NLKU3jh!ça"
#endif // SALT_AFTER

    // Retourne le résultat du hashage avec la méthode sha256 de la chaine passée en paramètre
    // sous la forme d'une chaine de caractères
    static QString hashIt_SHA256 (const QString& strToHash);

    // Pareil que la fonction hashIt_SHA256 mais en utilisant la méthode md5
    static QString hashIt_MD5(const QString& strToHash);

    // Vérifie que la chaine de caractères à crypter n'est pas vide
    // sachant que l'on considère qu'elle est vide si elle n'est composée
    // que d'espace(s)
    static bool strToCryptNotEmpty (const QString& strToCrypt);

};

#endif // DATAENCRYPTOR_HPP
