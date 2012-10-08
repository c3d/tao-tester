# ******************************************************************************
#  tao_tester.pro                                                  Tao project
# ******************************************************************************
# File Description:
# Qt build file for the Tao Test module
# ******************************************************************************
# This software is property of Taodyne SAS - Confidential
# Ce logiciel est la propriété de Taodyne SAS - Confidentiel
# (C) 2010 Catherine Burvelle <cathy@taodyne.com>
# (C) 2010 Taodyne SAS
# ******************************************************************************

MODINSTDIR = taoTester

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
