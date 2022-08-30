#ifndef ROOM_H
#define ROOM_H

#include <QList>
#include <QObject>
#include <QQmlEngine>

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

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(int playerCount READ playerCount WRITE setPlayerCount NOTIFY playerCountChanged)
    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged)
    Q_PROPERTY(Status status READ status WRITE setStatus NOTIFY statusChanged)
    Q_PROPERTY(Access access READ access WRITE setAccess NOTIFY accessChanged)
    Q_PROPERTY(int maxPlayerCount READ maxPlayerCount WRITE setMaxPlayerCount NOTIFY maxPlayerCountChanged)
    Q_PROPERTY(int initialBet READ initialBet WRITE setInitialBet NOTIFY initialBetChanged)

    enum Status {
        Waiting = 0,
        Playing
    };
    Q_ENUM(Status)

    enum Access {
        Private = 0,
        Public
    };
    Q_ENUM(Access)

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

    static void registerType()
    {
        qmlRegisterType<Room>("Room", 1, 0, "Room");
    }

signals:
    void nameChanged();
    void playerCountChanged();
    void passwordChanged();
    void statusChanged();
    void accessChanged();
    void idChanged();
    void maxPlayerCountChanged();
    void initialBetChanged();

private:
    int m_id = -1;
    int m_maxPlayerCount = Globals::MIN_PLAYERS;
    QString m_name = "default";
    Status m_status = Waiting;
    int m_playerCount = 0;
    Access m_access = Public;
    int m_initialBet = Globals::MIN_INITIAL_BET;
    QString m_password = "";
};

#endif // ROOM_H
