#ifndef IFSEARCHCONSOLEAPPLICATION_H
#define IFSEARCHCONSOLEAPPLICATION_H

#include <QObject>
#include <ConsoleApplication>

/*
#include "IfSearchConsoleApplication.h"
Q_GLOBAL_STATIC(IfSearchConsoleApplication, CONS);
*/

class ConsoleInitializer;
class ConsoleProperties;

class IfSearchConsoleApplication : public ConsoleApplication
{
    Q_OBJECT
public:
    IfSearchConsoleApplication(int argc, char *argv[]);


public: // pointers
    ConsoleInitializer * initializer();
    ConsoleProperties * props();

public slots:
    virtual void initialize();
    virtual void configure();
    virtual void start();
    virtual void finish();

signals:
    void initialized();
    void configured();
    void started();
    void finished();



protected:
    virtual void addOptions();
    virtual void processOptions();

private slots:


private:
    ConsoleInitializer * mpInitializer=nullptr;
    ConsoleProperties * mpProperties=nullptr;

};

inline ConsoleInitializer *IfSearchConsoleApplication::initializer()
{
    Q_CHECK_PTR(mpInitializer); return mpInitializer;
}

inline ConsoleProperties *IfSearchConsoleApplication::props()
{
    Q_CHECK_PTR(mpProperties); return mpProperties;
}

#endif // IFSEARCHCONSOLEAPPLICATION_H
