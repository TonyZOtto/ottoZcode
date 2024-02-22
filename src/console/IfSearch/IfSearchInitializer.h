#ifndef IFSEARCHINITIALIZER_H
#define IFSEARCHINITIALIZER_H

#include <QObject>

class IfSearchApplication;

class IfSearchInitializer : public QObject
{
    Q_OBJECT
public: // ctors
    explicit IfSearchInitializer(IfSearchApplication *parent = nullptr);

public: // non-const
    void initialize();


signals:

private:
    void initializeIO();
    void hello();
    void setDefaults();
    void goodbye();

private:
    IfSearchApplication * mpConsole=nullptr;
};

#endif // IFSEARCHINITIALIZER_H
