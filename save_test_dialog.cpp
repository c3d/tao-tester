// *****************************************************************************
// save_test_dialog.cpp                                            Tao3D project
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
#include "save_test_dialog.h"
#include "ui_save_test_dialog.h"
#include <QFileDialog>


Save_test_dialog::Save_test_dialog(QWidget *parent,
                                   QString name, QString loc,
                                   int fid, QString desc,
                                   double threshold) :
    QDialog(parent), name(name), loc(loc), fid(fid), desc(desc),threshold(threshold),
    ui(new Ui::Save_test_dialog)
{
    ui->setupUi(this);
    ui->nameEdit->setText(name);
    ui->locEdit->setText(loc);
    ui->fidEdit->setText(QString("%1").arg(fid));
    ui->thresholdEdit->setText(QString("%1").arg(threshold));
    ui->descEdit->setDocument(new QTextDocument(desc, this));
    connect(ui->locChange, SIGNAL(clicked()), this, SLOT(changeLoc()));
}

Save_test_dialog::~Save_test_dialog()
{
    delete ui;
}

void Save_test_dialog::changeLoc()
{

    QString dir =
            QFileDialog::getExistingDirectory(this,
                                              tr("Change test location"),
                                              loc);
    ui->locEdit->setText(dir);
}

void Save_test_dialog::accept()
{
    name = ui->nameEdit->text();
    loc = ui->locEdit->text();
    fid = ui->fidEdit->text().toInt();
    desc = ui->descEdit->toPlainText();
    threshold = ui->thresholdEdit->text().toDouble();
    QDialog::accept();
}

//void Save_test_dialog::reject()
//{
//    QDialog::reject();
//}

