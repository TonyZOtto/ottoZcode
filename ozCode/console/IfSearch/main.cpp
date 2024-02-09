#include <QCoreApplication>
#include <QDateTime>
#include <QStringList>
#include <QTimer>

#include "IfSearchConsoleApplication.h"
#include "../../version.h"


int main(int argc, char *argv[])
{
    IfSearchConsoleApplication a(argc, argv);
    QCoreApplication::setApplicationName("ozStatus");
    QCoreApplication::setApplicationVersion(VER_STRING);
    QCoreApplication::setOrganizationName(VER_ORGNAME);

    QTimer::singleShot(500, &a, &IfSearchConsoleApplication::initialize);
    return a.coreApplication()->exec();
}
