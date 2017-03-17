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
