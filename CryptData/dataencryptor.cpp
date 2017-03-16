#include "dataencryptor.hpp"

dataEncryptor::dataEncryptor() {}

bool dataEncryptor::strToCryptNotEmpty(const QString &strToCrypt)
{
    int charNumerator = 0;
    for (int it = 0; it < strToCrypt.size(); ++it)
    {
        if (!strToCrypt[it].isSpace()) charNumerator++;
        else continue;
    }
    return charNumerator;
}

QString dataEncryptor::hashIt_SHA256(const QString& strToHash)
{
    return QCryptographicHash::hash(strToHash.toUtf8(), QCryptographicHash::Sha256).toHex();
}

QString dataEncryptor::hashIt_MD5(const QString &strToHash)
{
    return QCryptographicHash::hash(strToHash.toUtf8(), QCryptographicHash::Md5).toHex();
}


QString dataEncryptor::encrypt(const QString &strToEncrypt)
{
    QString minimizedStr = strToEncrypt.toLower();
    QString cryptedStr;
    for (QString::const_iterator i = minimizedStr.begin(); i != minimizedStr.end(); ++i)
    {
        QChar crypted;

        // Si le char est une lettre
        if (isalpha(i->toLatin1()))
        {
            if (!islower(i->toLatin1())) tolower(i->toLatin1());
            if ( (i->toLatin1() + CharLimit::charMove) <= CharLimit::maxChar ) crypted = i->toLatin1() + CharLimit::charMove;
            else crypted = CharLimit::minChar + ((i->toLatin1() + CharLimit::charMove) - CharLimit::maxChar - 1);
        }
        // Si le char est un chiffre
        else if (isdigit(i->toLatin1()))
        {

            if ( (i->toLatin1() + CharLimit::charMove) <= CharLimit::maxNum ) crypted = i->toLatin1() + CharLimit::charMove;
            else crypted = CharLimit::minNum + ((i->toLatin1() + CharLimit::charMove) - CharLimit::maxNum - 1);
        }
        // Sinon
        else crypted = i->toLatin1();

        cryptedStr.append(crypted);
    }



    if (strToCryptNotEmpty(cryptedStr)) return cryptedStr;
    else return QString("erreur la chaine est vide !");
}

QString dataEncryptor::decrypt(const QString &strToDecrypt)
{
    QString decryptedStr;
    for (QString::const_iterator i = strToDecrypt.begin(); i != strToDecrypt.end(); ++i)
    {
        QChar decrypted;
        // Si le char est une lettre
        if (isalpha(i->toLatin1()))
        {
            if ( (i->toLatin1() - CharLimit::charMove) >= CharLimit::minChar ) decrypted = (char)(i->toLatin1() - CharLimit::charMove);
            else decrypted = CharLimit::maxChar + ((i->toLatin1() - CharLimit::charMove) - CharLimit::minChar  + 1);
        }
        // Si le char est un chiffre
        else if (isdigit(i->toLatin1()))
        {
            if ( (i->toLatin1() - CharLimit::charMove) >= CharLimit::minNum ) decrypted = (char)(i->toLatin1() - CharLimit::charMove);
            else decrypted = CharLimit::maxNum + ((i->toLatin1() - CharLimit::charMove) - CharLimit::minNum  + 1);

        }
        // Sinon
        else decrypted = i->toLatin1();
        decryptedStr.append(decrypted);
    }

    if (strToCryptNotEmpty(decryptedStr)) return decryptedStr;
    else return QString("erreur la chaine est vide !");
}
