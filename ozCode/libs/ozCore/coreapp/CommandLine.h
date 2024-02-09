#pragma once
#include "../ozCore.h"

#include <QObject>

#include "SettingsName.h"
class BaseApplication;

class OZCORE_EXPORT CommandLine : public QObject
{
    Q_OBJECT
public: // ctors
    explicit CommandLine(int argc, char *argv[], BaseApplication *parent = nullptr);

public: // const
    const QStringList rawArgumentList() const;
    const QStringList positionalArguments() const;
    const SettingsName::List settingsNameList() const;

public: // non-const
    void process();

private: // non-const
    void processIncludeFile(const QString atsArg);
    void processSettingValue(const QString dlrArg);
    void processSettingsName(const QString pctArg);

private: // static
    static QStringList parseRawArguments(int argc, char *argv[]);

signals:

private:
    const QStringList cmRawArgumentList;
    QStringList mCommandArguments;
    QStringList mPositionalArguments;
    SettingsName::List mSettingsNameList;

};


inline const QStringList CommandLine::rawArgumentList() const
{
    return cmRawArgumentList;
}

inline const SettingsName::List CommandLine::settingsNameList() const
{
    return mSettingsNameList;
}
