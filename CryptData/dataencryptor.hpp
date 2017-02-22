#ifndef DATAENCRYPTOR_HPP
#define DATAENCRYPTOR_HPP


#include <QCryptographicHash>
#include <QByteArray>
#include <QString>

class connectionDataBase;


// Class de cryptage de donnée pour le programme softOsteo
class dataEncryptor
{
    friend class QCryptographicHash;

    // Pour faire en sorte que la classe connectionDataBase puisse accéder aux fonctions
    // de dataEncryptor
    friend class connectionDataBase;

public:
    explicit dataEncryptor();

private:
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
};

#endif // DATAENCRYPTOR_HPP
