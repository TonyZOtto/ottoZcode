#pragma once

#include <QObject>

class ApplicationSettings : public QObject
{
    Q_OBJECT
public:
    explicit ApplicationSettings(QObject *parent = nullptr);

signals:
};
