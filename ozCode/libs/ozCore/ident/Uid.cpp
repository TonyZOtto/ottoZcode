#include "Uid.h"

//Uid::Uid() {;} // fl QUuid()

Uid::Uid(const Flags fs)
    : mFlags(fs)
{
    QUuid::Version tVersion = QUuid::VerUnknown;
    if (flag(Uid::VersionRandom))           tVersion = QUuid::Random;
    else if (flag(Uid::VersionSequential))  tVersion = QUuid::Random;
    else if (flag(Uid::VersionTimebased))   tVersion = QUuid::Time;
    // else leave invalid

    if (QUuid::VerUnknown != tVersion)
        mUuid = QUuid::createUuid();
    // else leave null
    version(tVersion);
}

bool Uid::flag(const Flag fl) const
{
    return mFlags.testFlag(fl);
}

QString Uid::tail() const
{
    return mUuid.toString().right(12);
}

bool Uid::operator == (const Uid other) const
{
    return mUuid == other.mUuid;
}

bool Uid::operator < (const Uid other) const
{
    return mUuid < other.mUuid;
}

void Uid::version(const QUuid::Version ver)
{
    Union u;
    u.uOword = data();
    u.sVersion = ver;
    data(u.uOword);
}
