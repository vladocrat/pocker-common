#ifndef LOGINDATA_H
#define LOGINDATA_H

#include <QString>
#include <QDataStream>

struct LoginData
{
    QByteArray serialise() const
    {
        QByteArray arr;
        QDataStream stream(&arr, QIODevice::WriteOnly);
        stream << login << password;

        return arr;
    }

    friend QDataStream& operator<<(QDataStream& out, const LoginData& data)
    {
        return out << data.login << data.password;
    }

    QString login;
    QString password;
};

#endif // LOGINDATA_H
