#pragma once

#include <ConsoleApplication>

#include <QStringList>

class StatusConsoleApplication : public ConsoleApplication
{
    Q_OBJECT
public:
    StatusConsoleApplication(int argc, char *argv[]);

public slots:
    void start();

private slots:
    void exeInfo();
    void qtInfo();
    void libInfo();
    void finish();

private:
    QStringList mLibraryNames;
};
