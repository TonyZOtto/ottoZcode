#include "IfSearchConsoleApplication.h"


#include <QtDebug>
#include <QTimer>

#include <QDateTime>
#include <QTimeZone>
#include <QVersionNumber>

#include <ConsoleStdIO>
#include <FileInfo>

IfSearchConsoleApplication::IfSearchConsoleApplication(int argc, char *argv[])
    : ConsoleApplication(argc, argv)
{
    setObjectName("IfSearchConsoleApplication:" + QCoreApplication::applicationName());
    io()->writeline(QString("Hello %1").arg(QCoreApplication::applicationName()));

}

void IfSearchConsoleApplication::initialize()
{
    io()->writeline(QString("Hello %1").arg(QCoreApplication::applicationName()));

}

void IfSearchConsoleApplication::configure()
{
    io()->writeline(QString("Hello %1").arg(QCoreApplication::applicationName()));

}

void IfSearchConsoleApplication::start()
{

}

void IfSearchConsoleApplication::finish()
{

}

void IfSearchConsoleApplication::addOptions()
{
    // TODO
}

void IfSearchConsoleApplication::processOptions()
{
    // TODO
}
