TARGET = gxde-introduction
TEMPLATE = app
QT = core gui widgets dbus
CONFIG += link_pkgconfig c++11
# Qt6 version of dframeworkdbus (libdframeworkdbus-qt6)
DFRAMEWORK_PATH = $$(DFRAMEWORK_PATH)
isEmpty(DFRAMEWORK_PATH) {
    INCLUDEPATH += /usr/include/libdframeworkdbus-qt6-6.0
} else {
    INCLUDEPATH += $$DFRAMEWORK_PATH/include/libdframeworkdbus-qt6-6.0
    LIBS += -L$$DFRAMEWORK_PATH/lib
}
LIBS += -ldframeworkdbus-qt6
PKGCONFIG += dtk2widget
DESTDIR    = $$_PRO_FILE_PWD_

isEmpty(PREFIX){
    PREFIX = /usr
}

HEADERS += \
    src/basemodulewidget.h \
    src/mainwindow.h \
    src/model.h \
    src/normalwindow.h \
    src/worker.h \
    src/modules/about.h \
    src/modules/desktopmodemodule.h \
    src/modules/iconmodule.h \
    src/modules/moduleinterface.h \
    src/modules/normalmodule.h \
    src/modules/support.h \
    src/modules/wmmodemodule.h \
    src/modules/welcomemodule.h \
    src/widgets/basewidget.h \
    src/widgets/borderwidget.h \
    src/widgets/bottomnavigation.h \
    src/widgets/navigationbutton.h \
    src/widgets/nextbutton.h \
    src/modules/photoslide.h

SOURCES += \
    src/basemodulewidget.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/model.cpp \
    src/normalwindow.cpp \
    src/worker.cpp \
    src/modules/about.cpp \
    src/modules/desktopmodemodule.cpp \
    src/modules/iconmodule.cpp \
    src/modules/moduleinterface.cpp \
    src/modules/normalmodule.cpp \
    src/modules/support.cpp \
    src/modules/wmmodemodule.cpp \
    src/modules/welcomemodule.cpp \
    src/widgets/basewidget.cpp \
    src/widgets/borderwidget.cpp \
    src/widgets/bottomnavigation.cpp \
    src/widgets/navigationbutton.cpp \
    src/widgets/nextbutton.cpp \
    src/modules/photoslide.cpp

RESOURCES += \
    gxde-introduction.qrc

desktop.path = $$PREFIX/share/applications/
desktop.files += $$PWD/gxde-introduction.desktop

target.path = $$PREFIX/bin/

TRANSLATIONS = translations/gxde-introduction_zh_CN.ts

# Automating generation .qm files from .ts files
DEFINES += DISABLE_VIDEO

CONFIG(release, debug|release) {
    system($$PWD/translate_generation.sh)
}

qm_files.path = $$PREFIX/share/gxde-introduction/translations/
qm_files.files = translations/*.qm

icon.path = $$PREFIX/share/icons/hicolor/scalable/apps
icon.files = resources/gxde-introduction.svg

INSTALLS += desktop target icon qm_files

DISTFILES +=
