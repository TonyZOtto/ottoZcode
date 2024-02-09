#include "CommandLine.h"

#include "BaseApplication.h"

CommandLine::CommandLine(int argc, char *argv[], BaseApplication *parent)
    : QObject{parent}
    , cmRawArgumentList(parseRawArguments(argc, argv))
{}

void CommandLine::process()
{

}

// static
QStringList CommandLine::parseRawArguments(int argc, char *argv[])
{
    QStringList result;
    for (int ix = 0; ix < argc; ++ix)
        result.append(QString(argv[ix]));
    return result;
}
