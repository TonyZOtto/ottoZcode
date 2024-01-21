#pragma once
#include "../ozCore.h"

#include <QCoreApplication>

#include <QStringList>

#include "BaseApplication.h"
class ConsoleStdIO;

class OZCORE_EXPORT ConsoleApplication : public BaseApplication
{
    Q_OBJECT
public:
    ConsoleApplication(int argc, char *argv[]);

public: // const
    ConsoleStdIO *io() const;

public: // non-const

private:
    ConsoleStdIO * mpStdIO=nullptr;
};
