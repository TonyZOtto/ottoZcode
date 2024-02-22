#ifndef IFSEARCHPROPERTIES_H
#define IFSEARCHPROPERTIES_H

#include <QObject>

class IfSearchProperties : public QObject
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
    explicit IfSearchProperties(QObject *parent = nullptr);

signals:

private:
//    State m_state=$null;

};

#endif // IFSEARCHPROPERTIES_H
