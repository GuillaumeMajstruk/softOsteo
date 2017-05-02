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

#ifndef DATAENCRYPTOR_HPP
#define DATAENCRYPTOR_HPP


#include <QCryptographicHash>
#include <QByteArray>

#include "typedefs.hpp"

#include <QDebug>
#include <QChar>

class connectionDataBase;

// Défini des "bornes" pour les fonctions de cryptage/décrytage
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

public: // Constructeur *****************************************************************

    explicit dataEncryptor();

public: // Fonctions publiques **********************************************************

    // une fonction pour crypter des chaines de caractères
    static string encrypt (const string& strToEncrypt);

    // fonction de décryptage de la fonction précédente
    static string decrypt (const string& strToDecrypt);

private: // fonctions privées ***********************************************************

// Définitions des sels de chiffrage ***********
#ifndef SALT_BEFORE
#define SALT_BEFORE "sjkdfnqAH12J"
#endif // SALT_BEFORE

#ifndef SALT_AFTER
#define SALT_AFTER  "12NLKU3jh!ça"
#endif // SALT_AFTER
// *********************************************

    // Retourne le résultat du hash avec la méthode sha256 de la chaine passée en paramètre
    // sous la forme d'une chaine de caractères
    static string hashIt_SHA256 (const string& strToHash);

    // Pareil que la fonction hashIt_SHA256 mais en utilisant la méthode md5
    static string hashIt_MD5(const string& strToHash);

    // Vérifie que la chaine de caractères à crypter n'est pas vide
    // sachant que l'on considère qu'elle est vide si elle n'est composée
    // que d'espace(s)
    static bool strToCryptNotEmpty (const string& strToCrypt);

};

#endif // DATAENCRYPTOR_HPP
