#include "EpochTime.h"

EpochTime EpochTime::current()
{
    return EpochTime(QDateTime::currentDateTime());
}
