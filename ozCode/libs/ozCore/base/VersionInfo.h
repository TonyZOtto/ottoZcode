//!file {ottozcode}/src/libs/ozCore/base/VersionInfo.h Manage version numbers; wraps QVersionNumber
#pragma once
#include "ozCore.h"

#include <QObject>

#include <QCoreApplication>
#include <QDateTime>
#include <QString>
#include <QVersionNumber>

#include "Types.h"

class OZCORE_EXPORT VersionInfo : public QObject
{
    Q_GADGET
public:
    enum Option
    {
        $None       = 0,
        ShowV       = 0x00000001,
        Minor3wide  = 0x00000002,
        NoRelease   = 0x00000040,
        ShowQWord   = 0x00000080,
        Dotted      = 0x00000100,
    };
    Q_DECLARE_FLAGS(Options, Option)
    Q_FLAGS(Options)

public:
    VersionInfo(void);
    VersionInfo(const int maj,
                const int min,
                const int brn,
                const int rel,
                const QString &org=QString(),
                const QString &app=QString(),
                const QString &copy=QString(),
                const QString &noti=QString(),
                const QString &comm=QString());

public: // const
    bool isNull() const;
    QString string(const Options opts=$None) const;
    QWORD toQWord(void) const;
    QVersionNumber number() const;
    QString builtString(const QString &format="MM-dd-yyyy hh:mm:ss") const;
    QStringList copyrightList() const;
    QStringList noticeList() const;
    void check(quint32 key) const;
    void setApp(QCoreApplication *pApp) const;

public: // non-const
    void set(const IntList &il);
    void set(const int maj, const int min, const int brn, const int rel);
    void set(const QString &s);




private:
    void setBuilt();
    QString toString(const Options opts) const;
    QString dottedString() const;
    QString releaseString(const Options opts) const;

private: // static
    static QString parse(const QString &s);

    // ===================== PROPERTIES ====================
private:
    int m_major;
    int m_minor;
    int m_branch;
    int m_release;
    QString m_appname;
    QString m_orgname;
    QString m_copyright;
    QString m_notice;
    QString m_comment;
    QDateTime m_built;
    Q_PROPERTY(int major READ major CONSTANT FINAL)
    Q_PROPERTY(int minor READ minor CONSTANT FINAL)
    Q_PROPERTY(int branch READ branch CONSTANT FINAL)
    Q_PROPERTY(int release READ release CONSTANT FINAL)
    Q_PROPERTY(QString appname READ appname CONSTANT FINAL)
    Q_PROPERTY(QString orgname READ orgname CONSTANT FINAL)
    Q_PROPERTY(QString copyright READ copyright CONSTANT FINAL)
    Q_PROPERTY(QString notice READ notice CONSTANT FINAL)
    Q_PROPERTY(QString comment READ comment CONSTANT FINAL)
    Q_PROPERTY(QDateTime built READ built CONSTANT FINAL)
    int major() const
    {
        return m_major;
    }
    int minor() const
    {
        return m_minor;
    }
    int branch() const
    {
        return m_branch;
    }
    int release() const
    {
        return m_release;
    }
    QString appname() const
    {
        return m_appname;
    }
    QString orgname() const
    {
        return m_orgname;
    }
    QString copyright() const
    {
        return m_copyright;
    }
    QString notice() const
    {
        return m_notice;
    }
    QString comment() const
    {
        return m_comment;
    }
    QDateTime built() const
    {
        return m_built;
    }
};
