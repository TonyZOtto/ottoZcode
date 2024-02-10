#include <QCoreApplication>
#include <QDateTime>
#include <QStringList>
#include <QTimer>

#include "IfSearchApplication.h"
#include "../../version.h"


int main(int argc, char *argv[])
{
    IfSearchApplication a(argc, argv);
    QCoreApplication::setApplicationName("ozStatus");
    QCoreApplication::setApplicationVersion(VER_STRING);
    QCoreApplication::setOrganizationName(VER_ORGNAME);

    QTimer::singleShot(500, &a, &IfSearchApplication::initialize);
    return a.coreApplication()->exec();
}
