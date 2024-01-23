//!file {ottozcode}/src/libs/ozCore/base/NanosecondsElapsed.h Unique Nanosecond-based identifier
#pragma once
#include "ozCore.h"

#include <QElapsedTimer>

#include "EpochTime.h"
#include "Types.h" // TODO const nanoPerMicro, etc.

class OZCORE_EXPORT NanosecondsElapsed
{
public:
    NanosecondsElapsed();

public: // const
    SQWORD nanoseconds() const
    {
        return duration().count();
    }
    SQWORD microseconds() const
    {
        return nanoseconds() / 1000;
    }
    SQWORD milliseconds() const
    {
        return microseconds() / 1000;
    }
    SQWORD seconds() const
    {
        return milliseconds() / 1000;
    }
    SQWORD minutes() const
    {
        return seconds() / 60;
    }
    SQWORD hours() const
    {
        return minutes() / 60;
    }
    QElapsedTimer::Duration duration() const
    {
        return mDuration;
    }
    bool operator < (const NanosecondsElapsed &other) const;

public: // non-const
    void sample();

public:
    static QElapsedTimer::ClockType clockType();
    static bool isMonotonic();

private:

private:
    static EpochTime mBaseEms;
    static QElapsedTimer mElapsedTimer;
    QElapsedTimer::Duration mDuration;
};

