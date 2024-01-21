#pragma once
#include "../ozCore.h"

#include <QObject>

#include <QStringList>
class QCoreApplication;
class QGuiApplication;
class QApplication;

#include "../filesys/FileInfo.h"

class ConsoleApplication;
class GuiApplication;
class WidgetApplication;
class CommandLine;
class ApplicationSettings;

class OZCORE_EXPORT BaseApplication : public QObject
{
    Q_OBJECT
public:
    BaseApplication(int argc, char *argv[], ConsoleApplication * console);
    BaseApplication(int argc, char *argv[], GuiApplication * gui);
    BaseApplication(int argc, char *argv[], WidgetApplication * wgtapp);

public: // const
    const FileInfo exeFileInfo() const;
    const QStringList rawArgumentList() const;
    const QStringList positionalArguments() const;
    const QCoreApplication *coreApplication() const;
    const QGuiApplication *guiApplication() const;
    const QApplication * widgetApplication() const;

public: // non-const
    CommandLine * commandLine() const;
    ApplicationSettings * applicationSettings() const;

signals:

private: // static
    QStringList parseArguments(int argc, char *argv[]);

private:
    const QCoreApplication * cmpQCoreApplication=nullptr;
    const QGuiApplication * cmpQGuiApplication=nullptr;
    const QApplication * cmpQApplication=nullptr;
    const ConsoleApplication * cmpConsoleApplication=nullptr;
    const GuiApplication * cmpGuiApplication=nullptr;
    const WidgetApplication * cmpWidgetApplication=nullptr;
    const CommandLine * cmpCommandLine=nullptr;
    const ApplicationSettings * cmpApplicationSettings=nullptr;
    const FileInfo cmExeFileInfo;
    const QStringList cmRawArgumentList;
    QStringList mPositionalArguments;
};

inline const FileInfo BaseApplication::exeFileInfo() const
{
    return cmExeFileInfo;
}

inline const QStringList BaseApplication::rawArgumentList() const
{
    return cmRawArgumentList;
}
