# {Eclipse6}/src/useCore.pri
include(LIBDIR.pri)
include(DESTDIR.pri)

INCLUDEPATH *= $$LIBDIR/ozCore
windows:LIBS *= -lozCore2
linux:LIBS *= -lozCore
LIBS *= -L$$DESTDIR
message(--------/src/useCore.pri LIBS=$$LIBS DESTDIR==$$DESTDIR LIBDIR==$$LIBDIR )


