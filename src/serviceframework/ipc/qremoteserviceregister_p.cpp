/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the QtSystems module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "../qserviceclientcredentials_p.h"
#include "qremoteserviceregister_p.h"
#include "instancemanager_p.h"

#include <QCoreApplication>

QT_BEGIN_NAMESPACE

QRemoteServiceRegisterPrivate::QRemoteServiceRegisterPrivate(QObject* parent)
    : QObject(parent), iFilter(0),
      securityOptions(QRemoteServiceRegister::NoOptions),
      userIdentifier(0), userIdentifierSet(false),
      groupIdentifier(0), groupIdentifierSet(false)
{
    setQuitOnLastInstanceClosed(true);
}

QRemoteServiceRegisterPrivate::~QRemoteServiceRegisterPrivate()
{
}

//void QRemoteServiceRegisterPrivate::publishServices( const QString& ident)
//{
//  qWarning("QRemoteServiceregisterPrivate::publishServices has not been reimplemented");
//}
//
//void QRemoteServiceRegisterPrivate::processIncoming()
//{
//  qWarning("QRemoteServiceRegisterPrivate::processIncoming has not been reimplemented");
//}

bool QRemoteServiceRegisterPrivate::quitOnLastInstanceClosed() const
{
    return m_quit;
}

void QRemoteServiceRegisterPrivate::setQuitOnLastInstanceClosed(bool quit)
{
    m_quit = quit;
    if (m_quit) {
        connect(InstanceManager::instance(), SIGNAL(allInstancesClosed()), QCoreApplication::instance(), SLOT(quit()));
    }
    else {
        disconnect(InstanceManager::instance(), SIGNAL(allInstancesClosed()), QCoreApplication::instance(), SLOT(quit()));
    }
}

QRemoteServiceRegister::SecurityFilter QRemoteServiceRegisterPrivate::setSecurityFilter(QRemoteServiceRegister::SecurityFilter filter)
{
    QRemoteServiceRegister::SecurityFilter f;
    f = filter;
    iFilter = filter;
    return f;
}

void QRemoteServiceRegisterPrivate::setSecurityOptions(QRemoteServiceRegister::SecurityAccessOptions options)
{
    securityOptions = options;
}

QRemoteServiceRegister::SecurityFilter QRemoteServiceRegisterPrivate::getSecurityFilter()
{
    return iFilter;
}

QRemoteServiceRegister::SecurityAccessOptions QRemoteServiceRegisterPrivate::getSecurityOptions() const
{
    return securityOptions;
}

void QRemoteServiceRegisterPrivate::setBaseUserIdentifier(qintptr uid)
{
    userIdentifier = uid;
    userIdentifierSet = true;
}

qintptr QRemoteServiceRegisterPrivate::getBaseUserIdentifier() const
{
    return userIdentifier;
}

bool QRemoteServiceRegisterPrivate::isBaseUserIdentifierSet() const
{
    return userIdentifierSet;
}

void QRemoteServiceRegisterPrivate::setBaseGroupIdentifier(qintptr gid)
{
    groupIdentifier = gid;
    groupIdentifierSet = true;
}

qintptr QRemoteServiceRegisterPrivate::getBaseGroupIdentifier() const
{
    return groupIdentifier;
}

bool QRemoteServiceRegisterPrivate::isBaseGroupIdentifierSet() const
{
    return groupIdentifierSet;
}


#include "moc_qremoteserviceregister_p.cpp"
QT_END_NAMESPACE
