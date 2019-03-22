#ifndef TEST_DISPLAY_H
#define TEST_DISPLAY_H
// *****************************************************************************
// test_display.h                                                  Tao3D project
// *****************************************************************************
//
// File description:
//
//    Tao display module to test presentation in offline mode.
//
//
//
//
//
//
//
// *****************************************************************************
// This software is licensed under the GNU General Public License v3
// (C) 2012,2014,2019, Christophe de Dinechin <christophe@dinechin.org>
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


#include "tao/module_api.h"
#include "tao/tao_gl.h"
#include <iostream>
#include <QString>

struct test_display
{
public:
    test_display(int w, int h);
    virtual ~test_display();
    int                            w, h;
    Tao::ModuleApi::fbo *          frame;
    bool                           shot;
    QString                        filename;
    void                           do_display();
    static void                    display(void *);
    static void *                  use();
    static void                    unuse(void *obj);
    static const Tao::ModuleApi *  tao;
    void                           resize(int w, int h);
    static std::ostream &          debug();

};

extern "C" int module_init(const Tao::ModuleApi *a, const Tao::ModuleInfo *m);

#endif // TEST_DISPLAY_H
