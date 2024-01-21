#pragma once

#include <QtCore/qglobal.h>

#if defined(QTCV_LIBRARY)
#define QTCV_EXPORT Q_DECL_EXPORT
#else
#define QTCV_EXPORT Q_DECL_IMPORT
#endif
