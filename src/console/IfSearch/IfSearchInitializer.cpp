#include "IfSearchInitializer.h"

#include <QCoreApplication>

#include "IfSearchApplication.h"

IfSearchInitializer::IfSearchInitializer(IfSearchApplication *parent)
    : QObject{parent}
{
    setObjectName("ConsoleInitializer:" + QCoreApplication::applicationName());
}

void IfSearchInitializer::initialize()
{
    // MUSTDO ConsoleInitializer::initialize()
}

void IfSearchInitializer::initializeIO()
{
    // MUSTDO ConsoleInitializer::initializeIO()
}

void IfSearchInitializer::hello()
{
// MUSTDO ConsoleInitializer::hello()

}

void IfSearchInitializer::setDefaults()
{
// MUSTDO ConsoleInitializer::setDefaults()

}

void IfSearchInitializer::goodbye()
{
// MUSTDO ConsoleInitializer::goodbye()

}
