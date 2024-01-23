#pragma once

#include <QObject>

#include <QCommandLineOption>
#include <QStringList>

#include "BaseSettings.h"
#include "SettingsName.h"

class CommandLine : public QObject
{
    Q_OBJECT
public: // types
    typedef QList<QCommandLineOption> OptionList;

public: // ctors
    explicit CommandLine(QObject *parent = nullptr);
    CommandLine(const QStringList &rawArgs, QObject *parent = nullptr);

public: // const
    const QStringList positionalArguments() const;

public: // non-const
    void addOption(const QCommandLineOption &opt);

public slots:
    void preprocess();
    void process();

private slots:

signals:

private:
    const QStringList cmRawArguments;
    OptionList mOptions;
    QStringList mArguments;
    SettingsName mSettingsName;
    BaseSettings::Map mSettingsMap;
    QStringList mPositionalArguments;

};
