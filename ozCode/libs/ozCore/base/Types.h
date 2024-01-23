//!file {ottozcode}/src/libs/ozCore/Types.h Common typedef's
#pragma once

#include <QtGlobal>
#include <QByteArray>
#include <QList>
#include <QString>

typedef quint8          BYTE;
typedef quint16         WORD;
typedef quint32         DWORD;
typedef quint64         QWORD;
typedef quint128        OWORD;
typedef qint16          SWORD;
typedef qint32          SDWORD;
typedef qint64          SQWORD;
typedef qint128         SOWORD;
typedef quintptr        NWORD;
typedef qptrdiff        SNWORD;

typedef QString         UText;
typedef QWORD           EpochMilliseconds;
typedef qsizetype       Index;
typedef size_t          Count;

typedef QList<int>      IntList;
