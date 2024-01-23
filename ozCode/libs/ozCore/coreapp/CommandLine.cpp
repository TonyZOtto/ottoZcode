#include "CommandLine.h"

CommandLine::CommandLine(QObject *parent) : QObject{parent} {;}
CommandLine::CommandLine(const QStringList &rawArgs, QObject *parent)
    : QObject{parent}, cmRawArguments(rawArgs) {;}
