#include "ConsoleInitializer.h"

#include <QCoreApplication>

#include "IfSearchConsoleApplication.h"

ConsoleInitializer::ConsoleInitializer(IfSearchConsoleApplication *parent)
    : QObject{parent}
{
    setObjectName("ConsoleInitializer:" + QCoreApplication::applicationName());
}

void ConsoleInitializer::initialize()
{
    // MUSTDO ConsoleInitializer::initialize()
}

void ConsoleInitializer::initializeIO()
{
    // MUSTDO ConsoleInitializer::initializeIO()
}

void ConsoleInitializer::hello()
{
// MUSTDO ConsoleInitializer::hello()

}

void ConsoleInitializer::setDefaults()
{
// MUSTDO ConsoleInitializer::setDefaults()

}

void ConsoleInitializer::goodbye()
{
// MUSTDO ConsoleInitializer::goodbye()

}
