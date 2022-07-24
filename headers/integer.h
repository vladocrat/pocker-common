#ifndef INTEGER_H
#define INTEGER_H

#include <QByteArray>

struct Integer
{
    explicit Integer(int value);

    QByteArray serialise();
    static Integer deserealise(const QByteArray&);

    int val = 0;
};

#endif // INTEGER_H
