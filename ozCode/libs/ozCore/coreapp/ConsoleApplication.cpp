#include "ConsoleApplication.h"

#include "ConsoleStdIO.h"

ConsoleApplication::ConsoleApplication(int argc, char *argv[])
    : BaseApplication(argc, argv, this)
    , mpStdIO(new ConsoleStdIO(this))
{
    setObjectName("ConsoleApplication:" + QCoreApplication::applicationName());
    qInfo() << Q_FUNC_INFO << objectName();
}

ConsoleStdIO *ConsoleApplication::io() const
{
    Q_CHECK_PTR(mpStdIO);
    return mpStdIO;
}

void ConsoleApplication::initialize()
{
    BaseApplication::initialize();
}

void ConsoleApplication::configure()
{

}

void ConsoleApplication::start()
{

}

void ConsoleApplication::finish()
{

}

