#pragma once
#include "../ozCore.h"

#include <QObject>

#include "SettingsName.h"

class OZCORE_EXPORT CommandLine : public QObject
{
    Q_OBJECT
public: // ctors
    explicit CommandLine(QObject *parent = nullptr);

public: // const
    const SettingsName::List settingsNameList() const;

public: // non-const
    void process();

signals:

private:
    SettingsName::List mSettingsNameList;

};

inline const SettingsName::List CommandLine::settingsNameList() const
{
    return mSettingsNameList;
}
