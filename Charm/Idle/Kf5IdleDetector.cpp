/*
  Kf5IdleDetector.cpp

  This file is part of Charm, a task-based time tracking application.

  Copyright (C) 2008-2019 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com

  Author: Rémi Benoit <r3m1.benoit@gmail.com>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "Kf5IdleDetector.h"
#include "CharmCMake.h"
#include <KIdleTime>




Kf5IdleDetector::Kf5IdleDetector(QObject *parent)
    : IdleDetector(parent)
{
    setAvailable(false);

    connect(KIdleTime::instance(), &KIdleTime::resumingFromIdle, this, &Kf5IdleDetector::slotResumeFromIdle);
    connect(KIdleTime::instance(), QOverload<int, int>::of(&KIdleTime::timeoutReached), this, &Kf5IdleDetector::slotIdleTimeoutReached);

    mTimerId = KIdleTime::instance()->addIdleTimeout(idlenessDuration() * 1000);
    setAvailable(true);
}

void Kf5IdleDetector::onIdlenessDurationChanged()
{
    KIdleTime::instance()->removeIdleTimeout(mTimerId);
    mTimerId = KIdleTime::instance()->addIdleTimeout(idlenessDuration() * 1000);
}


void Kf5IdleDetector::slotResumeFromIdle()
{

}

void Kf5IdleDetector::slotIdleTimeoutReached(int timerId)
{
    const int idleSecs = idlenessDuration();
    maybeIdle(IdlePeriod(QDateTime::currentDateTime().addSecs(-idleSecs),
                         QDateTime::currentDateTime()));
}

