#include "IfSearchApplication.h"


#include <QtDebug>
#include <QDateTime>
#include <QTimer>
#include <QTimeZone>
#include <QVersionNumber>

#include <ConsoleStdIO>
#include <FileInfo>

#include "IfSearchInitializer.h"
#include "IfSearchProperties.h"

IfSearchApplication::IfSearchApplication(int argc, char *argv[])
    : ConsoleApplication(argc, argv)
{
    setObjectName("IfSearchConsoleApplication:" + QCoreApplication::applicationName());
    io()->writeline(QString("Hello %1 %2")
                .arg(QCoreApplication::applicationName(),
                     QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")));
}

void IfSearchApplication::initialize()
{
    io()->writeline(QString("Initializing %1").arg(QDateTime::currentDateTime().toString("hh:mm:ss")));
    ConsoleApplication::initialize();
    initializer()->initialize();
    emit initialized();
}

void IfSearchApplication::configure()
{
    io()->writeline(QString("Configurating %1").arg(QDateTime::currentDateTime().toString("hh:mm:ss")));
    ConsoleApplication::configure();
    // TODO Anything?
    emit configured();
}

void IfSearchApplication::start()
{
    io()->writeline(QString("Starting %1").arg(QDateTime::currentDateTime().toString("hh:mm:ss")));
    ConsoleApplication::start();

    emit started();
}

void IfSearchApplication::finish()
{
    io()->writeline(QString("Finishing %1").arg(QDateTime::currentDateTime().toString("hh:mm:ss")));
    ConsoleApplication::finish();

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
