#ifndef ROOM_H
#define ROOM_H

#include <QList>
#include <QObject>

#include "Globals.h"

class Room : public QObject
{
    Q_OBJECT
public:
    Room(int id);
    Room();
    Room(const Room&);
    Room& operator=(const Room& other);
    virtual ~Room();

    enum Status {
        Waiting = 0,
        Playing
    };

    enum Access {
        Private = 0,
        Public
    };

    int id() const;
    QString password() const;
    QString name() const;
    Status status() const;
    int playerCount() const;
    Access access() const;
    QString statusString() const;
    QString accessString() const;
    int initialBet() const;
    int maxPlayerCount() const;
    void setName(const QString&);
    void setStatus(Status);
    void setPlayerCount(int);
    void setAccess(Access);
    void setAccess(int);
    void setInitialBet(int);
    void setId(int);
    void setMaxPlayerCount(int);
    void setPassword(const QString&);

    static Access toAccess(int);
    static Room deserialise(const QByteArray&);
    static QByteArray serialise(const Room&);

private:
    int m_id = -1;
    int m_maxPlayerCount = Globals::MIN_PLAYERS;
    QString m_name = "default";
    Status m_status = Waiting;
    int m_playerCount = 1;
    Access m_access = Public;
    int m_initialBet = Globals::MIN_INITIAL_BET;
    QString m_password = "";
};

#endif // ROOM_H
