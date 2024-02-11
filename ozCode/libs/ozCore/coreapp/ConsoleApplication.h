#pragma once
#include "../ozCore.h"

#include <QObject>

class BaseApplication;
class ConsoleStdIO;

class OZCORE_EXPORT ConsoleApplication : public QObject
{
    Q_OBJECT
public: // ctors
    ConsoleApplication(BaseApplication * parent=nullptr);

public: // pointers
    BaseApplication *base() const;
    ConsoleStdIO *io() const;

public: // non-const

    void initialize();
    void configure();
    void start();
    void finish();

protected: // non-const

protected:

private:
    BaseApplication * mpBaseApplication=nullptr;
    ConsoleStdIO * mpStdIO=nullptr;
};

inline BaseApplication *ConsoleApplication::base() const
{
    Q_CHECK_PTR(mpBaseApplication); return mpBaseApplication;
}

inline ConsoleStdIO *ConsoleApplication::io() const
{
    Q_CHECK_PTR(mpStdIO); return mpStdIO;
}
