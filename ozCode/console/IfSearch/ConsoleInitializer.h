#ifndef CONSOLEINITIALIZER_H
#define CONSOLEINITIALIZER_H

#include <QObject>

class IfSearchConsoleApplication;

class ConsoleInitializer : public QObject
{
    Q_OBJECT
public: // ctors
    explicit ConsoleInitializer(IfSearchConsoleApplication *parent = nullptr);

public: // non-const
    void initialize();


signals:

private:
    void initializeIO();
    void hello();
    void setDefaults();
    void goodbye();

private:
    IfSearchConsoleApplication * mpConsole=nullptr;
};

#endif // CONSOLEINITIALIZER_H
