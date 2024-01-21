#ifndef OZPHOTO_GLOBAL_H
#define OZPHOTO_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(OZPHOTO_LIBRARY)
#define OZPHOTO_EXPORT Q_DECL_EXPORT
#else
#define OZPHOTO_EXPORT Q_DECL_IMPORT
#endif

#endif // OZPHOTO_GLOBAL_H
