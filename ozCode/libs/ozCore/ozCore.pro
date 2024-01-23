## QT -= gui
QT *= gui
QT *= widgets

TEMPLATE = lib
DEFINES += OZCORE_LIBRARY
CONFIG += c++17
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

include(../libs.pri)

SOURCES += \
    base/AText.cpp \
    base/EpochTime.cpp \
    base/NanosecondsElapsed.cpp \
    base/VersionInfo.cpp \
    coreapp/ApplicationSettings.cpp \
    coreapp/BaseApplication.cpp \
    coreapp/BaseSettings.cpp \
    coreapp/CommandLine.cpp \
    coreapp/ConsoleApplication.cpp \
    coreapp/ConsoleStdIO.cpp \
    coreapp/ObjectHelper.cpp \
    coreapp/SettingsName.cpp \
    filesys/FileInfo.cpp \
    ident/Uid.cpp \
    ozCore.cpp

HEADERS += \
    ../../include/ConsoleApplication \
    ../../include/ConsoleStdIO \
    ../../include/FileInfo \
    ../../include/GadgetHelper \
    ../../include/Types \
    ../../version.h \
    base/Types.h \
    base/AText.h \
    base/EpochTime.h \
    base/NanosecondsElapsed.h \
    base/Types.h \
    base/VersionInfo.h \
    coreapp/ApplicationSettings.h \
    coreapp/BaseApplication.h \
    coreapp/BaseSettings.h \
    coreapp/CommandLine.h \
    coreapp/ConsoleApplication.h \
    coreapp/ConsoleStdIO.h \
    coreapp/ObjectHelper.h \
    coreapp/SettingsName.h \
    filesys/FileInfo.h \
    ident/Uid.h \
    ozCore_global.h \
    ozCore.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
