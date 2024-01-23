//!file {ottozcode}/src/libs/ozCore/base/EpochTime.h Epoch Milliseconds represemtation of date and time
#pragma once
#include "ozCore.h"

#include <QDateTime>
#include <QTime>

#include "Types.h"

class OZCORE_EXPORT EpochTime
{
public:
    EpochTime() : mMsec(0) {;}
    EpochTime(const SQWORD msec) : mMsec(msec) {;}
    EpochTime(const QTime qtm) : mMsec(qtm.msec()) {;}
    EpochTime(const QDateTime qdt) : mMsec(qdt.time().msec()) {;}

public: // const
    SQWORD toSQWord() const { return mMsec; }
    SQWORD operator() () const { return toSQWord(); }
    operator SQWORD() const { return toSQWord(); }

public: // non-const
    void clear();
    void set(const SQWORD msec) { mMsec = msec; }
    void set(const QTime qtm) { mMsec = qtm.msec(); }
    void set(const QDateTime qdt) { mMsec = qdt.time().msec(); }

public: // static
    static EpochTime current();

private:
    SQWORD mMsec;
};
