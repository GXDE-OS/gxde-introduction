TARGET = gxde-introduction
TEMPLATE = app
QT = core gui widgets dbus multimedia multimediawidgets
CONFIG += link_pkgconfig c++11
PKGCONFIG += dtkwidget dframeworkdbus libgxmr
DESTDIR    = $$_PRO_FILE_PWD_

#load(dtk_qmake)

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
    src/modules/videowidget.h \
    src/modules/wmmodemodule.h \
    src/widgets/basewidget.h \
    src/widgets/borderwidget.h \
    src/widgets/bottomnavigation.h \
    src/widgets/navigationbutton.h \
    src/widgets/nextbutton.h \
    src/dvideowidget.h \
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
    src/modules/videowidget.cpp \
    src/modules/wmmodemodule.cpp \
    src/widgets/basewidget.cpp \
    src/widgets/borderwidget.cpp \
    src/widgets/bottomnavigation.cpp \
    src/widgets/navigationbutton.cpp \
    src/widgets/nextbutton.cpp \
    src/dvideowidget.cpp \
    src/modules/photoslide.cpp

RESOURCES += \
    gxde-introduction.qrc

desktop.path = $$PREFIX/share/applications/
desktop.files += $$PWD/gxde-introduction.desktop

target.path = $$PREFIX/bin/

TRANSLATIONS = translations/gxde-introduction_zh_CN.ts

# Automating generation .qm files from .ts files
CONFIG(release, debug|release) {
    system($$PWD/translate_generation.sh)
}

qm_files.path = $$PREFIX/share/gxde-introduction/translations/
qm_files.files = translations/*.qm

icon.path = $$PREFIX/share/icons/hicolor/scalable/apps
icon.files = resources/gxde-introduction.svg

INSTALLS += desktop target icon qm_files

#host_mips64 | host_sw_64 : {
    DEFINES += DISABLE_VIDEO
    HEADERS -= src/modules/videowidget.h
    SOURCES -= src/modules/videowidget.cpp
    PKGCONFIG -= libgxmr
#}


videos.path = $$PREFIX/share/gxde-introduction/
videos.files += resources/desktop/*.mp4
videos.files += resources/desktop/*.ass
INSTALLS += videos


DISTFILES +=
