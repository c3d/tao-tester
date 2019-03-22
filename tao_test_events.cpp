// *****************************************************************************
// tao_test_events.cpp                                             Tao3D project
// *****************************************************************************
//
// File description:
//
//    Tao events specific for test.
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

#include "tao_test_events.h"
#include "../tao_synchro/event_capture.h"
#include "widget_tests.h"


// ============================================================================
//
//   TaoCheckEvent Class
//
// ============================================================================

QDataStream &TaoCheckEvent::serializeData(QDataStream &out)
// ----------------------------------------------------------------------------
//  Serialize event specific data.
// ----------------------------------------------------------------------------
{
    out << number;
    out << threshold;
    if (playedImage)
        out << *playedImage;
    else
        out << QImage();
    return out;
}


QDataStream & TaoCheckEvent::unserializeData(QDataStream &in,
                                             quint32)
// ----------------------------------------------------------------------------
//  Unserialize event specific data.
// ----------------------------------------------------------------------------
{
    playedImage = new QImage();
    in >> number;
    in >> threshold;
    in >> *(playedImage);
    return in;
}


void TaoCheckEvent::simulateNow(QWidget */*w*/)
// ----------------------------------------------------------------------------
//  Perform a check againts the reference view.
// ----------------------------------------------------------------------------
{
//    QImage shot = synchroBasic::base->widget->grabFrameBuffer(false);
//    playedImage = new QImage(shot);
    WidgetTests * player =
            dynamic_cast<WidgetTests *>(synchroBasic::base->tao_event_handler);
    if (player)
        player->shotImage = &playedImage;
}


QString TaoCheckEvent::toTaoCmd()
// ----------------------------------------------------------------------------
//  Return a command line for Tao.
// ----------------------------------------------------------------------------
{
    QString cmd = QString("test_add_check %1, %2, %3").
            arg(number).arg(delay).arg(threshold);
    return cmd;
}
