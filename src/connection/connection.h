/****************************************************************************
**
**    This file is part of Lorris.
**    Copyright (C) 2012 Vojtěch Boček
**
**    Contact: <vbocek@gmail.com>
**             https://github.com/Tasssadar
**
**    Lorris is free software: you can redistribute it and/or modify
**    it under the terms of the GNU General Public License as published by
**    the Free Software Foundation, either version 3 of the License, or
**    (at your option) any later version.
**
**    Lorris is distributed in the hope that it will be useful,
**    but WITHOUT ANY WARRANTY; without even the implied warranty of
**    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**    GNU General Public License for more details.
**
**    You should have received a copy of the GNU General Public License
**    along with Lorris.  If not, see <http://www.gnu.org/licenses/>.
**
****************************************************************************/

#ifndef CONNECTION_H
#define CONNECTION_H

#include <QString>
#include <QObject>
#include <QDataStream>
#include <set>
#include <QGridLayout>
#include <QVector>
#include <QMetaType>
#include <QPointer>

class WorkTab;
class WorkTabInfo;

enum ConnectionState {
    st_disconnected,
    st_connecting,
    st_connected
};

// TODO: maybe we should just remove this and use dynamic_cast?
enum ConnectionType
{
    CONNECTION_SERIAL_PORT = 0,
    CONNECTION_SHUPITO_TUNNEL = 1,
    CONNECTION_SHUPITO     = 2,
    CONNECTION_TCP_SOCKET  = 3,
    MAX_CON_TYPE           = 4
};

enum PrimaryConnectionType {
    pct_port = (1<<0),
    pct_shupito = (1<<1)
};

Q_DECLARE_FLAGS(PrimaryConnectionTypes, PrimaryConnectionType)
Q_DECLARE_OPERATORS_FOR_FLAGS(PrimaryConnectionTypes)

class Connection : public QObject
{
    Q_OBJECT

public:
    explicit Connection(ConnectionType type);
    ~Connection();

    bool removable() const { return m_removable; }
    void setRemovable(bool value) { m_removable = value; emit changed(); }

    quint8 getType() { return m_type; }

    void setIDString(const QString& str) { if (m_idString != str) { m_idString = str; emit changed(); } }
    QString const & GetIDString() const { return m_idString; }

    QString const & name() const { return m_idString; }
    void setName(const QString& str) { this->setIDString(str); }

    virtual QString details() const
    {
        // XXX
        return QString::number(m_refcount);
    }

    virtual bool Open() { return false; }
    virtual void OpenConcurrent() = 0;
    virtual void Close() {}

    bool isOpen() const { return m_state == st_connected; }
    ConnectionState state() const { return m_state; }

    void addRef();
    void release();
    void addTabRef();
    void releaseTab();

    virtual QHash<QString, QVariant> config() const;
    virtual bool applyConfig(QHash<QString, QVariant> const & config);

Q_SIGNALS:
    void connectResult(Connection *con, bool open);
    void connected(bool connected);
    void stateChanged(ConnectionState state);
    void changed();

    // This will be emitted right before a *planned* disconnect happens
    // to allow clients to send shutdown chatter.
    void disconnecting();

protected:
    void SetState(ConnectionState state);
    void SetOpen(bool open);

private:
    ConnectionState m_state;
    QString m_idString;
    int m_refcount;
    int m_tabcount;
    bool m_removable;
    quint8 m_type;
};

Q_DECLARE_METATYPE(Connection *)

class PortConnection : public Connection
{
    Q_OBJECT

Q_SIGNALS:
    void dataRead(const QByteArray& data);

public:
    explicit PortConnection(ConnectionType type) : Connection(type) {}

public slots:
    virtual void SendData(const QByteArray & /*data*/) {}
};

template <typename T>
class ConnectionPointer
{
public:
    explicit ConnectionPointer(T * conn = 0)
        : m_conn(conn)
    {
    }

    ConnectionPointer(ConnectionPointer const & other)
        : m_conn(other.m_conn)
    {
        if (m_conn)
            m_conn->addRef();
    }

    template <typename U>
    ConnectionPointer(ConnectionPointer<U> const & other)
        : m_conn(other.data())
    {
        if (m_conn)
            m_conn->addRef();
    }

    static ConnectionPointer fromPtr(T * conn)
    {
        ConnectionPointer res(conn);
        if (res)
            res->addRef();
        return res;
    }

    ~ConnectionPointer()
    {
        this->reset();
    }

    ConnectionPointer & operator=(ConnectionPointer const & other)
    {
        if (other.m_conn)
            other.m_conn->addRef();
        if (m_conn)
            m_conn->release();
        m_conn = other.m_conn;
        return *this;
    }

    template <typename U>
    ConnectionPointer & operator=(ConnectionPointer<U> const & other)
    {
        if (other)
            other->addRef();
        if (m_conn)
            m_conn->release();
        m_conn = other.data();
        return *this;
    }

    void reset(T * conn = 0)
    {
        if (m_conn)
            m_conn->release();
        m_conn = conn;
    }

    T * data() const { return m_conn; }
    T * operator->() const { return m_conn; }

    template <typename U>
    ConnectionPointer<U> staticCast() const
    {
        ConnectionPointer<U> res(static_cast<U *>(m_conn.data()));
        if (res)
            res->addRef();
        return res;
    }

    template <typename U>
    ConnectionPointer<U> dynamicCast() const
    {
        ConnectionPointer<U> res(dynamic_cast<U *>(m_conn.data()));
        if (res)
            res->addRef();
        return res;
    }

    typedef T* (ConnectionPointer::* UnspecifiedBoolType)() const;
    operator UnspecifiedBoolType() const { return m_conn? &ConnectionPointer::data: 0; }

    friend bool operator==(ConnectionPointer const & lhs, ConnectionPointer const & rhs)
    {
        return lhs.m_conn == rhs.m_conn;
    }

    friend bool operator!=(ConnectionPointer const & lhs, ConnectionPointer const & rhs)
    {
        return lhs.m_conn != rhs.m_conn;
    }

private:
    QPointer<T> m_conn;
};

#endif // CONNECTION_H
