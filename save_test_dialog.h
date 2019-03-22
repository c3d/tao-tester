#ifndef SAVE_TEST_DIALOG_H
#define SAVE_TEST_DIALOG_H
// *****************************************************************************
// save_test_dialog.h                                              Tao3D project
// *****************************************************************************
//
// File description:
//
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

#include <QDialog>

namespace Ui {
    class Save_test_dialog;
}


class Save_test_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Save_test_dialog(QWidget *parent = 0,
                              QString name = "",
                              QString loc = "",
                              int fid = 0,
                              QString desc = "",
                              double threshold = 0.0);
    ~Save_test_dialog();

    QString name;
    QString loc;
    int fid;
    QString desc;
    double threshold;

public slots:
    void changeLoc();
    void accept();
//    void reject();

private:
    Ui::Save_test_dialog *ui;
};


#endif // SAVE_TEST_DIALOG_H
