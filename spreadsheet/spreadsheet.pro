greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    mainwindow.h \
    spreadsheet.h \
    gotocelldialog.h \
    ui_gotocelldialog.h \
    sortdialog.h \
    ui_sortdialog.h \
    cell.h \
    finddialog.h

SOURCES += \
    mainwindow.cpp \
    main.cpp \
    spreadsheet.cpp \
    gotocelldialog.cpp \
    sortdialog.cpp \
    cell.cpp \
    finddialog.cpp

RESOURCES += \
    spreadsheet.qrc

FORMS += \
    gotocelldialog.ui \
    sortdialog.ui
