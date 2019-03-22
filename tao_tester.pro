# ******************************************************************************
# tao_tester.pro                                                   Tao3D project
# ******************************************************************************
#
# File description:
# Qt build file for the Tao Test module
#
#
#
#
#
#
#
# ******************************************************************************
# This software is licensed under the GNU General Public License v3
# (C) 2012, Baptiste Soulisse <baptiste.soulisse@taodyne.com>
# (C) 2012, Catherine Burvelle <catherine@taodyne.com>
# (C) 2012,2015,2019, Christophe de Dinechin <christophe@dinechin.org>
# (C) 2012, Jérôme Forissier <jerome@taodyne.com>
# ******************************************************************************
# This file is part of Tao3D
#
# Tao3D is free software: you can r redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Tao3D is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Tao3D, in a file named COPYING.
# If not, see <https://www.gnu.org/licenses/>.
# ******************************************************************************

MODINSTDIR = tao_tester

include(../modules.pri)

release:QMAKE_CXXFLAGS -= -Werror  # Workaround QTBUG-14437 (GCC 4.4)

TBL_SOURCES = tao_tester.tbl

QT += core gui opengl testlib

OTHER_FILES += \
    tao_tester.tbl \
    tao_tester.xl

HEADERS += \
    widget_tests.h \
    tao_tester.h \
    save_test_dialog.h \
    traces.tbl \
    test_display.h \
    ../tao_synchro/event_handler.h \
    ../tao_synchro/tao_control_event.h \
    ../tao_synchro/event_capture.h \
    tao_test_events.h

SOURCES += \
    widget_tests.cpp \
    tao_tester.cpp \
    save_test_dialog.cpp \
    test_display.cpp \
    ../tao_synchro/tao_control_event.cpp \
    ../tao_synchro/event_capture.cpp \
    tao_test_events.cpp

FORMS += \
    save_test_dialog.ui
