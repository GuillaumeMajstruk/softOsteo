CONFIG += c++14

QT += widgets gui core uitools sql

HEADERS += \
    Messages/messages.hpp \
    UserInterface/interfaceGlobal.hpp \
    UserInterface/screen.hpp \
    UserInterface/userinterfaceloader.hpp \
    UserInterface/UserInterfaceSourcesFiles/mainwindow.hpp \
    UserInterface/UserInterfaceSourcesFiles/selectpatientscreen.hpp \
    UserInterface/UserInterfaceSourcesFiles/welcomescreen.hpp \
    DataBase/database.h \
    UserInterface/ConnectionScreen/connectiondialog.h \
    UserInterface/UserInterfaceSourcesFiles/createpatientscreen.h

SOURCES += \
    UserInterface/userinterfaceloader.cpp \
    UserInterface/UserInterfaceSourcesFiles/mainwindow.cpp \
    UserInterface/UserInterfaceSourcesFiles/selectpatientscreen.cpp \
    UserInterface/UserInterfaceSourcesFiles/welcomescreen.cpp \
    main.cpp \
    DataBase/database.cpp \
    UserInterface/ConnectionScreen/connectiondialog.cpp \
    UserInterface/UserInterfaceSourcesFiles/createpatientscreen.cpp

FORMS += \
    UserInterface/ui_Files/mainwindow.ui \
    UserInterface/ui_Files/SelectPatientScreen.ui \
    UserInterface/ui_Files/WelcomeScreen.ui \
    UserInterface/ui_Files/ConnectionDialog.ui \
    UserInterface/ui_Files/CreatePatientScreen.ui \
    UserInterface/ui_Files/CreateNewDateScreen.ui

RESOURCES += \
    resources.qrc

OTHER_FILES += \
    ConnectionDataBase/connectionDB.db
