#pragma once

#include <QtCore/qglobal.h>

#if defined(OZMOVIE_LIBRARY)
#define OZMOVIE_EXPORT Q_DECL_EXPORT
#else
#define OZMOVIE_EXPORT Q_DECL_IMPORT
#endif
