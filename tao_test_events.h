// *****************************************************************************
// tao_test_events.h                                               Tao3D project
// *****************************************************************************
//
// File description:
//
//    Tao events spcific for test.
//
//
//
//
//
//
//
// *****************************************************************************
// This software is licensed under the GNU General Public License v3
// (C) 2012,2019, Christophe de Dinechin <christophe@dinechin.org>
// *****************************************************************************
// This file is part of Tao3D
//
// Tao3D is free software: you can r redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Tao3D is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Tao3D, in a file named COPYING.
// If not, see <https://www.gnu.org/licenses/>.
// *****************************************************************************
#ifndef TAO_TEST_EVENTS_H
#define TAO_TEST_EVENTS_H

#include "../tao_synchro/tao_control_event.h"

class TaoCheckEvent: public TaoControlEvent
// ----------------------------------------------------------------------------
//   Class used to store CheckPoint events with other events
// ----------------------------------------------------------------------------
{
public:
    TaoCheckEvent(int num, quint32 delay, double thr = 0.0)
        : TaoControlEvent(delay), number(num), threshold(thr),
          absolutePageTime(0.0), playedImage(NULL) {}

    virtual ~TaoCheckEvent()
    {
        if (playedImage)
        {
            delete playedImage;
            playedImage = NULL;
        }
    }

    virtual QString toTaoCmd();

    virtual QDataStream & serializeData(QDataStream &out);
    virtual QDataStream & unserializeData(QDataStream &in, quint32 e_type);
    virtual void simulateNow(QWidget *w);

    virtual quint32 getType() { return CHECK_EVENT_TYPE;}

public:
    qint16  number;
    double threshold;
    double absolutePageTime;
    QImage * playedImage;
public:
    TaoCheckEvent(quint32 delay)
        : TaoControlEvent(delay) {}

};

#endif // TAO_TEST_EVENTS_H
