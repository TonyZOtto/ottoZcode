## QT -= gui
QT *= gui
QT *= widgets

TEMPLATE = lib
DEFINES += OZCORE_LIBRARY
CONFIG += c++17
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

include(../libs.pri)

SOURCES += \
    AText.cpp \
    coreapp/ApplicationSettings.cpp \
    coreapp/BaseApplication.cpp \
    coreapp/CommandLine.cpp \
    coreapp/ConsoleApplication.cpp \
    coreapp/ConsoleStdIO.cpp \
    coreapp/ObjectHelper.cpp \
    coreapp/SettingsName.cpp \
    filesys/FileInfo.cpp \
    ident/Key.cpp \
    ident/KeyMap.cpp \
    ident/KeySeg.cpp \
    ozCore.cpp

HEADERS += \
    ../../include/ConsoleApplication \
    ../../include/ConsoleStdIO \
    ../../include/FileInfo \
    ../../include/GadgetHelper \
    ../../include/Types \
    AText.h \
    Types.h \
    coreapp/ApplicationSettings.h \
    coreapp/BaseApplication.h \
    coreapp/CommandLine.h \
    coreapp/ConsoleApplication.h \
    coreapp/ConsoleStdIO.h \
    coreapp/ObjectHelper.h \
    coreapp/SettingsName.h \
    filesys/FileInfo.h \
    ident/Key.h \
    ident/KeyMap.h \
    ident/KeySeg.h \
    ozCore_global.h \
    ozCore.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
