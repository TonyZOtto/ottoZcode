#ifndef IFSEARCHCONSOLEAPPLICATION_H
#define IFSEARCHCONSOLEAPPLICATION_H

#include <QObject>
#include <ConsoleApplication>

class IfSearchConsoleApplication : public ConsoleApplication
{
    Q_OBJECT
public:
    IfSearchConsoleApplication(int argc, char *argv[]);

public slots:
    virtual void initialize();
    virtual void configure();
    virtual void start();
    virtual void finish();


protected:
    virtual void addOptions();
    virtual void processOptions();

private slots:

};

#endif // IFSEARCHCONSOLEAPPLICATION_H
