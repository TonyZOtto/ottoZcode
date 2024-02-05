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

public slots:
    virtual void initialize();
    virtual void configure();
    virtual void start();
    virtual void finish();

protected:

private:
    ConsoleStdIO * mpStdIO=nullptr;
};
