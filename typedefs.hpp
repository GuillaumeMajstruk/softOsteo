//    softOsteo is the name of the software.
//    This software integrates many functionalities such as patient management, data records, data
//    management, patient consultation, etc..., to help an osteopath in his professional life.
//    Copyright (C) 2017  MAJSTRUK Guillaume.

//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.

//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.

//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef TYPEDEFS_H
#define TYPEDEFS_H


// Essaie d'utiliser les forward déclaration à la place des includes ...
class QPushButton;
class QLineEdit;
class QMessageBox;
class QPlainTextEdit;
class QDialog;
class QLabel;
class QListWidget;
class QComboBox;
class QSpinBox;
class QCheckBox;

/// Ce fichier contient des typedefs qui m'évitent à avoir à taper les
/// noms entiers des objets de type widgets de QT

typedef QPushButton         pushButton;
typedef QLineEdit           lineEdit;
typedef QMessageBox         msgBox;
typedef QPlainTextEdit      plainTextEdit;
typedef QDialog             dialog;
typedef QLabel              label;
typedef QListWidget         listWidget;
typedef QComboBox           comboBox;
typedef QSpinBox            spinBox;
typedef QCheckBox           checkBox;

#endif // TYPEDEFS_H
