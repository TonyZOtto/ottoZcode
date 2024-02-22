TEMPLATE = subdirs

SUBDIRS += \
    If6Console      \
    eirBase6        \
    eirCore6        \
    eirExe6         \

If6Console.subdir       = ./console/If6Console
eirBase6.subdir         = ./libs/eirBase6
eirCore6.subdir         = ./libs/eirCore6
eirExe6.subdir          = ./libs/eirExe6

eirCore6.depends        = eirBase6
eirExe6.depends         = eirBase6 eirCore6
If6Console.depends      = eirBase6 eirCore6 eirExe6

