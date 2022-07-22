#ifndef MESSAGE_H
#define MESSAGE_H

#include <QString>
#include <QDebug>
#include <QDataStream>

struct Message
{
   QByteArray serialise() const {
       return text.toUtf8();
   }

    friend QDataStream& operator>>(QDataStream& out, Message& msg)
    {
        QByteArray message;
        out >> message;
        msg.text = message;

        return out;
    }

    QString text;
};

#endif // MESSAGE_H
