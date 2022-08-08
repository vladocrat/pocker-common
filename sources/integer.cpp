#include "integer.h"

#include <QDataStream>
#include <QIODevice>

Integer::Integer(int value) : val(value) {}

Integer Integer::deserealise(const QByteArray& arr)
{
    int number;
    QDataStream stream(arr);
    stream >> number;

    return Integer(number);
}

QByteArray Integer::serialise()
{
    QByteArray arr;
    QDataStream stream(&arr, QIODevice::WriteOnly);
    stream << val;

    return arr;
}
