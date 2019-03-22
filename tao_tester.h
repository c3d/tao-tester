#ifndef TAO_TESTER_H
#define TAO_TESTER_H
// *****************************************************************************
// tao_tester.h                                                    Tao3D project
// *****************************************************************************
//
// File description:
//
//   Definition of the interface between XLR and native code
//   for the "tao tester" module.
//   Tests...
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

#include "tao/module_api.h"
#include "main.h"

using namespace XL;

// Commands for toolbar
Tree_p startRecTest(Tree_p self);
Tree_p stop(Tree_p self);
Tree_p playTest(Tree_p self, bool makeRef);
Tree_p saveTest(Tree_p self);
Tree_p resetTest(Tree_p self);
Tree_p testCheck(Tree_p self);

// Definition of events to be load
Tree_p testDef(Context *,
               Tree_p self, Text_p name, Integer_p fId, Text_p desc, Tree_p body,
               Integer_p width, Integer_p height);

Tree_p testAddKeyPress(Tree_p self, Integer_p key,
                       Integer_p modifiers, Integer_p delay );

Tree_p testAddKeyRelease(Tree_p self, Integer_p key,
                         Integer_p modifiers, Integer_p delay );

Tree_p testAddMousePress(Tree_p self, Integer_p button, Integer_p buttons,
                         Integer_p modifiers, Integer_p x, Integer_p y,
                         Integer_p delay);

Tree_p testAddMouseRelease(Tree_p self, Integer_p button,
                           Integer_p buttons,
                           Integer_p modifiers, Integer_p x, Integer_p y,
                           Integer_p delay);

Tree_p testAddMouseDClick(Tree_p self, Integer_p button, Integer_p buttons,
                          Integer_p modifiers, Integer_p x, Integer_p y,
                          Integer_p delay);

Tree_p testAddMouseMove(Tree_p self, Integer_p button, Integer_p buttons,
                        Integer_p modifiers,
                        Integer_p x, Integer_p y, Integer_p delay);

Tree_p testAddAction(Tree_p self, Text_p name, Integer_p delay);

Tree_p testAddCheck(Tree_p self, Integer_p num, Integer_p delay, double thr);

Tree_p testAddFont(Tree_p self, Text_p diagname, Text_p ftname,
                   Integer_p delay);

Tree_p testAddFile(Tree_p self, Text_p diagname, Text_p filename,
                   Integer_p delay);

Tree_p testAddColor(Tree_p self, Text_p diagname, Text_p colname,
                    Real_p alpha, Integer_p delay);

Tree_p testAddCloseDialog(Tree_p self, Text_p diagname,
                          Integer_p result, Integer_p delay);

extern "C" int module_init(const Tao::ModuleApi *a, const Tao::ModuleInfo *m);


#endif // TAO_TESTER_H
