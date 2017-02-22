#include "dataencryptor.hpp"

dataEncryptor::dataEncryptor() {}

QString dataEncryptor::hashIt_SHA256(const QString& strToHash)
{
    return QCryptographicHash::hash(strToHash.toUtf8(), QCryptographicHash::Sha256).toHex();
}

QString dataEncryptor::hashIt_MD5(const QString &strToHash)
{
    return QCryptographicHash::hash(strToHash.toUtf8(), QCryptographicHash::Md5).toHex();
}
