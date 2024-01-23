#pragma once

#include <QSettings>
#include <QString>

class SettingsName
{
public: // types
    enum Mode
    {
        $null = 0,
        FileName,
        OrgApp,
    };

public: // ctors
    SettingsName();
    SettingsName(const QString &s);

public: // const
    bool isNull() const;
    Mode mode() const;
    QString string() const;
    QString fileName() const;
    QString orgName() const;
    QString appName() const;

public: // non-const
    void set(const QString &s);

private:
    void setFileName();
    void setOrgApp();

private:
    Mode mMode=$null;
    QSettings::Scope mScope=QSettings::UserScope;
    QString mString;
    QString mFileName;
    QString mOrgName;
    QString mAppName;
};
