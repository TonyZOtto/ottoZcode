#include "BaseApplication.h"

#include <QApplication>
#include <QCoreApplication>
#include <QGuiApplication>

#include "../filesys/FileInfo.h"
#include "ApplicationSettings.h"
#include "CommandLine.h"


BaseApplication::BaseApplication(int argc, char *argv[],
                                 ConsoleApplication *conapp)
    : QObject(nullptr)
    , cmpQCoreApplication(new QCoreApplication(argc, argv))
    , cmpConsoleApplication(conapp)
    , mpCommandLine(new CommandLine(argc, argv, this))
    , cmpApplicationSettings(new ApplicationSettings(this))
    , cmExeFileInfo(FileInfo(QCoreApplication::applicationFilePath()))

{
    Q_CHECK_PTR(cmpQCoreApplication);
    setObjectName("BaseApplication:" + cmpQCoreApplication->applicationName());
    qInfo() << Q_FUNC_INFO << objectName();

}

BaseApplication::BaseApplication(int argc, char *argv[], GuiApplication *guiapp)
    : QObject(nullptr)
    , cmpQGuiApplication(new QGuiApplication(argc, argv))
    , cmpGuiApplication(guiapp)
    , mpCommandLine(new CommandLine(argc, argv, this))
    , cmpApplicationSettings(new ApplicationSettings(this))
    , cmExeFileInfo(FileInfo(QCoreApplication::applicationFilePath()))
{
    Q_CHECK_PTR(cmpQGuiApplication);
    setObjectName("BaseApplication:" + cmpQGuiApplication->applicationName());
    qInfo() << Q_FUNC_INFO << objectName();

}

BaseApplication::BaseApplication(int argc, char *argv[], WidgetApplication *wgtapp)
    : QObject(nullptr)
    , cmpQApplication(new QApplication(argc, argv))
    , cmpWidgetApplication(wgtapp)
    , mpCommandLine(new CommandLine(argc, argv, this))
    , cmpApplicationSettings(new ApplicationSettings(this))
    , cmExeFileInfo(FileInfo(QCoreApplication::applicationFilePath()))
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

void BaseApplication::initialize()
{
    // TODO TBD
//    addOptions();
//    processOptions();
    commandLine()->process();
}

void BaseApplication::addOption()
{
    Q_ASSERT(!"MUSTDO"); // MUSTDO
}

void BaseApplication::processOptions()
{
    Q_ASSERT(!"MUSTDO"); // MUSTDO

}



