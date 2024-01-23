#pragma once

#include <QObject>

#include <QFile>
#include <QFileDevice>
#include <QFileInfo>
#include <QIODevice>
#include <QString>
#include <QSettings>

class BaseSettings : public QObject
{
    Q_OBJECT
public: // types
    typedef QSettings::SettingsMap Map;

public: // ctors
    explicit BaseSettings(QObject *parent = nullptr);
    BaseSettings(QFile * file, QObject *parent = nullptr);
    BaseSettings(const QString &fileName, QObject *parent = nullptr);
    BaseSettings(const QFileInfo &fileInfo, QObject *parent = nullptr);

public: // const
    QFileInfo fileInfo() const;
    QVariant value(const QString &Key) const;
    Map values(const QString &groupKey) const;
    Map values() const;
    Map watched() const;
    Map defaults() const;

public: // non-const
    bool open(QFile * file, const QIODevice::OpenMode om=QIODevice::ReadWrite);
    bool open(const QString &fileName, const QIODevice::OpenMode om=QIODevice::ReadWrite);
    bool open(const QFileInfo &fileInfo, const QIODevice::OpenMode om=QIODevice::ReadWrite);

public slots:
    void addWatch(const QString &key);
    void removeWatch(const QString &key);
    void value(const QString &Key, const QVariant &var);
    void values(const QString &groupKey, const Map &vars);
    void values(const Map &vars);
    void defaults(const Map &vars);
    void open(const QIODevice::OpenMode om=QIODevice::ReadWrite);
    void read();
    void write();
    void close();

signals:
    void watching(const QString &key, const QVariant &initialValue);
    void watched(const QString &key, const QVariant &newValue);
    void readed(const QFileInfo &fi);
    void written(const QFileInfo &fi);
    void opened(const QFileInfo &fi, const QIODevice::OpenMode om);
    void closed(const QFileInfo &fi);
    void fileError(const QFileDevice::FileError fe, const QString &es);

private:
    QSettings * mpSettings=nullptr;
    QFile * mpFile=nullptr;
    QFileInfo mFileInfo;
    QIODevice::OpenMode mOpenMode=QIODevice::NotOpen;
    Map mWatchValues;
    Map mCurrentValues;
    Map mDefaultValues;
};

