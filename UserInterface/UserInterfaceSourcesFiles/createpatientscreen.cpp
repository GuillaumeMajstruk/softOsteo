#include "createpatientscreen.h"

CreatePatientScreen::CreatePatientScreen(Screen *parent):
    Screen(parent)
{
    // Charge l'interface depuis le fichier .ui grâce à userInterfaceLoader
    m_interface = userInterfaceLoader(DYNAMIC).loadUi<CreatePatientScreen>("createpatientscreen.ui");

    // Met à jour le nom de l'interface
    setInterfaceName(Global::InterfaceName::CreatePatientScreen_name);

    // Met à jour le nom d'objet de l'interface
    setInterfaceObjectName(Global::InterfaceObjectName::CreatePatientScreen_obj_name);

}
