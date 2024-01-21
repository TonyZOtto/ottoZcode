#include "BaseApplication.h"

#include <QApplication>
#include <QCoreApplication>
#include <QGuiApplication>

#include "../filesys/FileInfo.h"
#include "ApplicationSettings.h"
#include "CommandLine.h"


BaseApplication::BaseApplication(int argc, char *argv[],
                                 ConsoleApplication *console)
    : QObject(nullptr)
    , cmpQCoreApplication(new QCoreApplication(argc, argv))
    , cmpConsoleApplication(console)
    , cmpCommandLine(new CommandLine(this))
    , cmpApplicationSettings(new ApplicationSettings(this))
    , cmExeFileInfo(FileInfo(QCoreApplication::applicationFilePath()))
    , cmRawArgumentList(parseArguments(argc, argv))

{
    Q_CHECK_PTR(cmpQCoreApplication);
    Q_ASSERT( ! QCoreApplication::arguments().isEmpty());
    setObjectName("BaseApplication:" + cmpQCoreApplication->applicationName());
    qInfo() << Q_FUNC_INFO << objectName();

}

BaseApplication::BaseApplication(int argc, char *argv[], GuiApplication *gui)
    : QObject(nullptr)
    , cmpQGuiApplication(new QGuiApplication(argc, argv))
    , cmpGuiApplication(gui)
    , cmpCommandLine(new CommandLine(this))
    , cmpApplicationSettings(new ApplicationSettings(this))
    , cmExeFileInfo(FileInfo(QCoreApplication::applicationFilePath()))
    , cmRawArgumentList(parseArguments(argc, argv))
{
    Q_CHECK_PTR(cmpQGuiApplication);
    setObjectName("BaseApplication:" + cmpQGuiApplication->applicationName());
    qInfo() << Q_FUNC_INFO << objectName();

}

BaseApplication::BaseApplication(int argc, char *argv[], WidgetApplication *wgtapp)
    : QObject(nullptr)
    , cmpQApplication(new QApplication(argc, argv))
    , cmpWidgetApplication(wgtapp)
    , cmpCommandLine(new CommandLine(this))
    , cmpApplicationSettings(new ApplicationSettings(this))
    , cmExeFileInfo(FileInfo(QCoreApplication::applicationFilePath()))
    , cmRawArgumentList(parseArguments(argc, argv))
{
    Q_CHECK_PTR(cmpQApplication);
    setObjectName("BaseApplication:" + cmpQApplication->applicationName());
    qInfo() << Q_FUNC_INFO << objectName();

}

const QCoreApplication * BaseApplication::coreApplication() const
{
    Q_CHECK_PTR(cmpQCoreApplication);
    return cmpQCoreApplication;
}

const QGuiApplication *BaseApplication::guiApplication() const
{
    Q_CHECK_PTR(cmpQGuiApplication);
    return cmpQGuiApplication;
}

const QApplication *BaseApplication::widgetApplication() const
{
    Q_CHECK_PTR(cmpQApplication);
    return cmpQApplication;
}

// static
QStringList BaseApplication::parseArguments(int argc, char *argv[])
{
    QStringList result;
    for (int ix = 0; ix < argc; ++ix)
        result.append(QString(argv[ix]));
    return result;
}


