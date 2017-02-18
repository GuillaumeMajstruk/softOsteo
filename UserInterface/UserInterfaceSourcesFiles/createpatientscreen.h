#ifndef CREATEPATIENTSCREEN_H
#define CREATEPATIENTSCREEN_H

#include <QWidget>
#include <QTabWidget>

#include "UserInterface/userinterfaceloader.hpp"

class CreatePatientScreen: public Screen
{
    Q_OBJECT
public:
    explicit CreatePatientScreen(Screen *parent = 0);
    virtual ~CreatePatientScreen() {}
};

#endif // CREATEPATIENTSCREEN_H
