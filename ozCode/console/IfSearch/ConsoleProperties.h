#ifndef CONSOLEPROPERTIES_H
#define CONSOLEPROPERTIES_H

#include <QObject>

class ConsoleProperties : public QObject
{
    Q_OBJECT
public: // types
    enum State
    {
        $null           = 0,
        Initializing,
        Configuraing,
        SettingUp,
        Running,
        Paused,
        ShuttingDown,
        $max
    };

public:
    explicit ConsoleProperties(QObject *parent = nullptr);

signals:

private:
//    State m_state=$null;

};

#endif // CONSOLEPROPERTIES_H
