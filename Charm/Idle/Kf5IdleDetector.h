/*
  Kf5IdleDetector.h

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

#ifndef KF5IDLEDETECTOR_H
#define KF5IDLEDETECTOR_H

#include "IdleDetector.h"

#include <QTimer>

class Kf5IdleDetector : public IdleDetector
{
    Q_OBJECT
public:
    explicit Kf5IdleDetector(QObject *parent);

protected:
    void onIdlenessDurationChanged() override;

private Q_SLOTS:
    void slotResumeFromIdle();
    void slotIdleTimeoutReached(int timerId);

private:
    int mTimerId = -1;
};

#endif /* KF5IDLEDETECTOR_H */
