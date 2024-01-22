#pragma once
#include "../ozCore.h"

#include <QObject>

class OZCORE_EXPORT CommandLine : public QObject
{
    Q_OBJECT
public:
    explicit CommandLine(QObject *parent = nullptr);

signals:
};
