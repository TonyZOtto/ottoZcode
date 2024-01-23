#pragma once

#include <QFileInfo>

#include <QFile>
#include <QIODevice>
#include <QString>
#include <QStringList>
#include <QTimeZone>

#include "../base/Types.h"

class FileInfo : QFileInfo
{
public:


public: // ctors
    FileInfo();
    FileInfo(const QString &fpath);

public: // const
    bool isNull() const;
    Count byteCount() const;
    QStringList infoStrings(int verbosity=-1) const;
    QFile * file(const QIODevice::OpenMode &mode,
                 QObject * parent=nullptr);
    QString permissionsString() const;

    QDateTime born() const;
    QDateTime modified() const;
    QDateTime used() const;
    QDateTime time(const QFile::FileTime ft,
                   const QTimeZone &tz=QTimeZone::LocalTime);

public: // non-const
    QFileInfo & it();

private: // const
    QString flagString(const bool isSet=true) const;

private: // non-const

private:
};

Q_DECLARE_METATYPE(FileInfo);
