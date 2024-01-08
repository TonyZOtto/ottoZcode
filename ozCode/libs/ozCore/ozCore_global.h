#ifndef OZCORE_GLOBAL_H
#define OZCORE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(OZCORE_LIBRARY)
#define OZCORE_EXPORT Q_DECL_EXPORT
#else
#define OZCORE_EXPORT Q_DECL_IMPORT
#endif

#endif // OZCORE_GLOBAL_H
