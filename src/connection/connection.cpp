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

#include "connection.h"
#include "../WorkTab/WorkTab.h"
#include <QStringBuilder>

Connection::Connection(ConnectionType type)
    : m_state(st_disconnected), m_refcount(1), m_tabcount(0), m_removable(true), m_type(type)
{
}

Connection::~Connection()
{
    // Note that m_refcount need not be 0 here. We allow connections
    // to be destroyed explicitly via releaseAll() and clients must
    // listen to either destroying() or destroyed() signal.
}

QString Connection::details() const
{
    // XXX
    return QString::number(m_refcount);
}


void Connection::SetState(ConnectionState state)
{
    bool oldOpen = (m_state == st_connected);
    bool newOpen = (state == st_connected);

    if(state != m_state)
    {
        m_state = state;
        if (oldOpen != newOpen)
            emit connected(newOpen);
        emit stateChanged(state);
    }
}

void Connection::SetOpen(bool open)
{
    if (open)
        this->SetState(st_connected);
    else
        this->SetState(st_disconnected);
}

void Connection::addRef()
{
    ++m_refcount;
}

void Connection::release()
{
    if (--m_refcount == 0)
    {
        emit destroying();
        delete this;
    }
}

void Connection::addTabRef()
{
    addRef();
    ++m_tabcount;
}

void Connection::releaseTab()
{
    if(--m_tabcount == 0)
        Close();
    release();
}

QHash<QString, QVariant> Connection::config() const
{
    QHash<QString, QVariant> res;
    res["name"] = this->name();
    return res;
}

bool Connection::applyConfig(QHash<QString, QVariant> const & config)
{
    this->setName(config.value("name").toString());
    return true;
}

void Connection::releaseAll()
{
    emit destroying();
    delete this;
}
