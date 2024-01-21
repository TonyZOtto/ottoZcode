#pragma once

#include <QtCore/qglobal.h>

#if defined(OZWIDGETS_LIBRARY)
#define OZWIDGETS_EXPORT Q_DECL_EXPORT
#else
#define OZWIDGETS_EXPORT Q_DECL_IMPORT
#endif
