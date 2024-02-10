#pragma once
#include "../ozCore.h"

#include <QCoreApplication>

#include <QStringList>

#include "BaseApplication.h"
class ConsoleStdIO;

class OZCORE_EXPORT ConsoleApplication : public BaseApplication
{
    Q_OBJECT
public: // ctors
    ConsoleApplication(int argc, char *argv[]);

public: // pointers
    ConsoleStdIO *io() const;

public: // non-const

protected: // non-const
    void initialize();
    void configure();
    void start();
    void finish();

protected:

private:
    ConsoleStdIO * mpStdIO=nullptr;
};
