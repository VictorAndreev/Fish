QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    enemyfish.cpp \
    fishabstract.cpp \
    gamewidget.cpp \
    main.cpp \
    playerfish.cpp \
    widget.cpp

HEADERS += \
    common.h \
    enemyfish.h \
    fishabstract.h \
    gamewidget.h \
    playerfish.h \
    widget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += C:\cpp_libs\SFML-2.5.1\include
LIBS += -LC:\cpp_libs\SFML-2.5.1\lib -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

RESOURCES +=
