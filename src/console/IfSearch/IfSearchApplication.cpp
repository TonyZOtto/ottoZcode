#include "IfSearchApplication.h"


#include <QtDebug>
#include <QCoreApplication>
#include <QDateTime>
#include <QTimer>
#include <QTimeZone>
#include <QVersionNumber>

#include <ConsoleApplication>
#include <ConsoleStdIO>
#include <FileInfo>

#include "IfSearchInitializer.h"
#include "IfSearchProperties.h"

IfSearchApplication::IfSearchApplication(int argc, char *argv[])
    : BaseApplication(argc, argv, BaseApplication::Console)
    , mpInitializer(new IfSearchInitializer(this))
    , mpProperties(new IfSearchProperties(this))
{
    setObjectName("IfSearchConsoleApplication:" + QCoreApplication::applicationName());
    console()->io()->writeline(QString("Hello %1 %2")
                .arg(QCoreApplication::applicationName(),
                     QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")));
}

void IfSearchApplication::initialize()
{
    console()->io()->writeline(QString("Initializing %1").arg(QDateTime::currentDateTime().toString("hh:mm:ss")));
    console()->initialize();
    initializer()->initialize();
    emit initialized();
}

void IfSearchApplication::configure()
{
    console()->io()->writeline(QString("Configurating %1").arg(QDateTime::currentDateTime().toString("hh:mm:ss")));
    console()->configure();
    // TODO Anything?
    emit configured();
}

void IfSearchApplication::start()
{
    initialize();
    configure();
    console()->io()->writeline(QString("Starting %1").arg(QDateTime::currentDateTime().toString("hh:mm:ss")));
    console()->start();

    emit started();
}

void IfSearchApplication::finish()
{
    console()->io()->writeline(QString("Finishing %1").arg(QDateTime::currentDateTime().toString("hh:mm:ss")));
    console()->finish();

    emit finished();
}

void IfSearchApplication::addOptions()
{
    // TODO
}

void IfSearchApplication::processOptions()
{
    // TODO
}
