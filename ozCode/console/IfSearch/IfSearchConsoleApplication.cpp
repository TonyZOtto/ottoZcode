#include "IfSearchConsoleApplication.h"


#include <QtDebug>
#include <QDateTime>
#include <QTimer>
#include <QTimeZone>
#include <QVersionNumber>

#include <ConsoleStdIO>
#include <FileInfo>

#include "ConsoleInitializer.h"
#include "ConsoleProperties.h"

IfSearchConsoleApplication::IfSearchConsoleApplication(int argc, char *argv[])
    : ConsoleApplication(argc, argv)
{
    setObjectName("IfSearchConsoleApplication:" + QCoreApplication::applicationName());
    io()->writeline(QString("Hello %1 %2")
                .arg(QCoreApplication::applicationName(),
                     QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")));
//    QTimer::singleShot(1000, this, &IfSearchConsoleApplication::initialize);
}

void IfSearchConsoleApplication::initialize()
{
//    props()->m_state = Initializing;
    io()->writeline(QString("Initializing %1").arg(QDateTime::currentDateTime().toString("hh:mm:ss")));
    connect(this, &IfSearchConsoleApplication::initialized,
            this, &IfSearchConsoleApplication::configure);
    connect(this, &IfSearchConsoleApplication::configured,
            this, &IfSearchConsoleApplication::start);
    emit initialized();
}

void IfSearchConsoleApplication::configure()
{
    io()->writeline(QString("Configurating %1").arg(QDateTime::currentDateTime().toString("hh:mm:ss")));

    emit configured();
}

void IfSearchConsoleApplication::start()
{
    io()->writeline(QString("Starting %1").arg(QDateTime::currentDateTime().toString("hh:mm:ss")));

    emit started();
}

void IfSearchConsoleApplication::finish()
{
    io()->writeline(QString("Finishing %1").arg(QDateTime::currentDateTime().toString("hh:mm:ss")));

    emit finished();
}

void IfSearchConsoleApplication::addOptions()
{
    // TODO
}

void IfSearchConsoleApplication::processOptions()
{
    // TODO
}
