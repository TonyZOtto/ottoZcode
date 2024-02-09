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
    const QCoreApplication *coreApplication() const;
    const QGuiApplication *guiApplication() const;
    const QApplication * widgetApplication() const;

public: // non-const
    CommandLine * commandLine() const;
    ApplicationSettings * applicationSettings() const;

public slots:
    virtual void initialize();
    virtual void configure() {;} // MUDTDO
    virtual void start() {;} // MUSTDO
    virtual void finish() {;} // MUSTDO

protected:
    void addOption();
    virtual void addOptions() {;} // MUSTDO // = 0
    virtual void processOptions();

signals:

private:
    const QCoreApplication * cmpQCoreApplication=nullptr;
    const QGuiApplication * cmpQGuiApplication=nullptr;
    const QApplication * cmpQApplication=nullptr;
    const ConsoleApplication * cmpConsoleApplication=nullptr;
    const GuiApplication * cmpGuiApplication=nullptr;
    const WidgetApplication * cmpWidgetApplication=nullptr;
    CommandLine * mpCommandLine=nullptr;
    const ApplicationSettings * cmpApplicationSettings=nullptr;
    const FileInfo cmExeFileInfo;
};

inline const FileInfo BaseApplication::exeFileInfo() const
{
    return cmExeFileInfo;
}

inline CommandLine *BaseApplication::commandLine() const
{
    return mpCommandLine;
}
