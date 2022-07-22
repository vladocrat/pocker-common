#ifndef REGISTERDATA_H
#define REGISTERDATA_H

#include "LoginData.h"

struct RegisterData : public LoginData
{
    QByteArray serialise() const
    {
        QByteArray arr;
        QDataStream stream(arr);
        stream << login << password << email;

        return arr;
    }

    friend QDataStream& operator<<(QDataStream& out, const RegisterData& data)
    {
        return out << data.login << data.password << data.email;
    }

    QString email;
};

#endif // REGISTERDATA_H
