//!file {ottozcode}/src/libs/ozCore/ident/Uid.h Unique Identifier support
#pragma once
#include "ozCore.h"

#include <QMetaType>
#include <QString>
#include <QUuid>

#include "../base/Types.h"

/*
 * 00112233-4455-6677-8899-AABBCCDDEEFF
 *                    ^^    - Variant 0b111-.---- (7 = reserved)
 *          ^^              - Version 0b1111.---- (1=Time+MAC 4=Random)
 *           4         8    - Uid Format (8bits=256)
 *            55 6677       - Uid Group (24bits=~24M)
 * 00112233                 - Uid Class (32bits=~4G)
 *                      99 AABBCCDDEEFF (56bits Sequence/Random)
 *
 * 33 22 11 00 55 44 77 66 88 99 aa bb cc dd ee ff Microsoft Variant 2
 */

class OZCORE_EXPORT Uid
{
public: // types
    typedef BYTE Format; // split 2*4bits
    typedef DWORD Group; // actially 24bits
    typedef DWORD Class; // full 32bits
    typedef QWORD Value; // actially 56bits
    typedef OWORD Data;  // entire structure
    typedef union
    {
        OWORD   uOword;
        QWORD   uQword[2];
        DWORD   uDword[4];
        WORD    uWord[8];
        BYTE    uByte[16];
        struct
        {
            QWORD   sClass      : 32,
                    sVersion    : 4,
                    sFormat0    : 4,
                    sGroup      : 24;
            QWORD   sVariant    : 3,
                    sBit        : 1,
                    sFormat1    : 4,
                    sValue      : 56;
        };
    } Union;

    enum Flag
    {
        $null               = 0,
        VersionRandom       = 0x10000000,
        VersionSequential   = 0x20000000,
        VersionTimebased    = 0x40000000,
    };
    Q_DECLARE_FLAGS(Flags, Flag);

public: // ctors
    Uid(const Flags fs);
    Uid(const Format f, const Group g, const Class c,
        const Value v=0ULL, const Flags fs=$null);

public: // const
    QUuid uid() const { return mUuid; }
    bool isNull() const { return mUuid.isNull(); }
    bool flag(const Flag fl) const;
    QUuid::Version version() const { return mUuid.version(); }
    Format format() const;
    Group group() const;
    Class klass() const;
    Value value() const;
    QString tail() const;
    Data data() const { return mUuid.toUInt128(); }
    bool operator == (const Uid other) const;
    bool operator <  (const Uid other) const;

public: // non-const
    void uid(const QUuid uu) { mUuid = uu; }
    void version(const QUuid::Version ver);
    void format(const Format f);
    void group(const Group g);
    void klass(const Class c);
    void value(const Value v);
    void data(const Data d) { mUuid = QUuid::fromUInt128(d); }

private:
    QUuid mUuid;
    Flags mFlags;

public: // QMetaType
    Uid() = default;
    Uid(const Uid &other) = default;
    ~Uid() = default;
    Uid &operator = (const Uid &other) = default;
};

Q_DECLARE_METATYPE(Uid);
Q_DECLARE_TYPEINFO(Uid, Q_PRIMITIVE_TYPE);

/*
#include "DualMap.h"
#include "Uid.h"

template<typename T> class UidMap : public DualMap<Uid, T>
{
public: // ctors

public: // const
    Uid uid(const T &tt) const { return DualMap<Uid, T>::t(tt); }
    T t(const Uid u) const { return DualMap<Uid, T>::n(u); }

public: // non-const
    Uid add(const T &t, const bool okReplace=false);
    Success add(const Uid u, const T &t, const bool okReplace=false);

private:
};

template<typename T>
Uid UidMap<T>::add(const T &t, const bool okReplace)
{
    Success success(true);
    success.test( ! DualMap<Uid, T>::contains(t) || okReplace);
    const Uid cUid(Uid::VersionRandom);
    if (success)
        success.test(DualMap<Uid, T>::add(cUid, t));
    return success ? cUid : Uid();
}

template<typename T>
Success UidMap<T>::add(const Uid u, const T &t, const bool okReplace)
{
    Success success(true);
    success.test( ! DualMap<Uid, T>::contains(t) || okReplace);
    success.test( ! DualMap<Uid, T>::contains(u) || okReplace);
    if (success)
        success.test(DualMap<Uid, T>::add(u, t));
    return success;
}
*/
