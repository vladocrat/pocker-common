#include "room.h"

#include <QDataStream>
#include <QByteArray>
#include <QDebug>
#include <QIODevice>

#include "protocol.h"

Room::Room(int id) : m_id(id)
{

}

Room::Room()
{

}

Room::Room(const Room& other)
{
    m_id = other.id();
    m_name = other.name();
    m_status = other.status();
    m_playerCount = other.playerCount();
    m_maxPlayerCount = other.maxPlayerCount();
    m_access = other.access();
    m_initialBet = other.initialBet();

    if (other.access() == Room::Private) {
        m_password = other.password();
    }
}

Room& Room::operator=(const Room& other)
{
    if (this == &other) {
        return *this;
    }

    Room* room = new Room(other);

    return *room;
}

Room::~Room()
{

}

int Room::id() const
{
    return m_id;
}

QString Room::password() const
{
    return m_password;
}

QString Room::name() const
{
    return m_name;
}

Room::Status Room::status() const
{
    return m_status;
}

int Room::playerCount() const
{
    return m_playerCount;
}

Room::Access Room::access() const
{
    return m_access;
}

QString Room::statusString() const
{
    switch (m_status) {
    case Waiting:
    {
        return "Waiting";
    }
    case Playing:
    {
        return "Playing";
    }
    default:
    {
        return "udentified";
    }
    }
}

QString Room::accessString() const
{
    switch (m_access) {
    case Private:
    {
        return "Private";
    }
    case Public:
    {
        return "Public";
    }
    default:
    {
        return "udentified";
    }
    }
}

Room::Access Room::toAccess(int number)
{
    switch (number) {
    case 1: {
        return Room::Access::Public;
    }
    case 0: {
        return Room::Access::Private;
    }
    default:
    {
        qDebug() << "unkown command";
        break;
    }
    }

    return {};
}

int Room::initialBet() const
{
    return m_initialBet;
}

int Room::maxPlayerCount() const
{
    return m_maxPlayerCount;
}

void Room::setName(const QString& name)
{
    m_name = name;
}

void Room::setStatus(Status status)
{
    m_status = status;
}

void Room::setPlayerCount(int playerCount)
{
    m_playerCount = playerCount;
}

void Room::setAccess(Access access)
{
    m_access = access;
}

void Room::setAccess(int access)
{
    switch (access) {
    case 0:
    {
        m_access = Access::Private;
        break;
    }
    case 1:
    {
        m_access = Access::Public;
        break;
    }
    default: {
        qDebug() << "undentified";
        break;
    }
    }
}

void Room::setInitialBet(int bet)
{
    m_initialBet = bet;
}

void Room::setId(int id)
{
    m_id = id;
}

void Room::setMaxPlayerCount(int maxPlayerCount)
{
    m_maxPlayerCount = maxPlayerCount;
}

void Room::setPassword(const QString& password)
{
    m_password = password;
}

Room Room::deserialise(const QByteArray& arr)
{
    QDataStream stream(arr);
    Room room;
    stream >> room.m_id
            >> room.m_name
            >> room.m_status
            >> room.m_playerCount
            >> room.m_access
            >> room.m_initialBet
            >> room.m_password
            >> room.m_maxPlayerCount;

    return room;
}

QByteArray Room::serialise(const Room& room)
{
    QByteArray arr;
    QDataStream stream(&arr, QIODevice::WriteOnly);
    stream << room.id()
           << room.name()
           << room.status()
           << room.playerCount()
           << room.access()
           << room.initialBet()
           << room.password()
           << room.maxPlayerCount();

    qDebug() << arr.size();

    return arr;
}

