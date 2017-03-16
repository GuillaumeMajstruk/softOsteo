#include "createpatientscreen.h"

CreatePatientScreen::CreatePatientScreen(Screen *parent):
    Screen(parent)
{
    // Met à jour le nom de l'interface
    setInterfaceName(SharedVar::InterfaceName::CreatePatientScreen_name);

    // Met à jour le nom d'objet de l'interface
    setInterfaceObjectName(SharedVar::InterfaceObjectName::CreatePatientScreen_obj_name);


    // Charge l'interface depuis le fichier .ui grâce à userInterfaceLoader
    m_interface = userInterfaceLoader(DYNAMIC).loadUi<CreatePatientScreen>(m_objectInterfaceName += ".ui");


}
