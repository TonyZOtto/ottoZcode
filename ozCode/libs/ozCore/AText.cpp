#include "AText.h"


QString AText::toString() const
{
    return QString(*this);
}

char AText::takeFirstChar()
{
    char result = 0;
    if ( ! isEmpty()) result = *(first(1)).data();
    removeFirst();
    return result;
}

// static
QStringList AText::toStringList(const List atl)
{
    QStringList result;
    foreach (AText at, atl)
        result << at.toString();
    return result;
}
