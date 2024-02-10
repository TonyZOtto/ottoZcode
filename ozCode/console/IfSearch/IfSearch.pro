QT = core
CONFIG += c++17 cmdline
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../console.pri)
include(../../useCore.pri)

SOURCES += \
        IfSearchApplication.cpp \
        IfSearchInitializer.cpp \
        IfSearchProperties.cpp \
        main.cpp

HEADERS += \
    IfSearchApplication.h \
    IfSearchInitializer.h \
    IfSearchProperties.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

