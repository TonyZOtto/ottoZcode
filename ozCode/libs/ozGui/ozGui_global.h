#pragma once

#include <QtCore/qglobal.h>

#if defined(OZGUI_LIBRARY)
#define OZGUI_EXPORT Q_DECL_EXPORT
#else
#define OZGUI_EXPORT Q_DECL_IMPORT
#endif
