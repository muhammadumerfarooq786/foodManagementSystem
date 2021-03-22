QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addemployee.cpp \
    addstock.cpp \
    administrator.cpp \
    cancelorder.cpp \
    completeorder.cpp \
    deleteemployee.cpp \
    employee.cpp \
    hotel.cpp \
    kitchen.cpp \
    main.cpp \
    mainwindow.cpp \
    manager.cpp \
    place_an_order.cpp \
    receptionists.cpp \
    searchorder.cpp \
    showallorders.cpp \
    stock.cpp

HEADERS += \
    addemployee.h \
    addstock.h \
    administrator.h \
    cancelorder.h \
    completeorder.h \
    deleteemployee.h \
    employee.h \
    hotel.h \
    kitchen.h \
    mainwindow.h \
    manager.h \
    place_an_order.h \
    receptionists.h \
    searchorder.h \
    showallorders.h \
    stock.h

FORMS += \
    addemployee.ui \
    addstock.ui \
    administrator.ui \
    cancelorder.ui \
    completeorder.ui \
    deleteemployee.ui \
    employee.ui \
    hotel.ui \
    hoteltime.ui \
    kitchen.ui \
    mainwindow.ui \
    manager.ui \
    place_an_order.ui \
    searchorder.ui \
    showallorders.ui \
    stock.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
