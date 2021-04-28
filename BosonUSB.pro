QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle
VERSION = 0.0.1
QT_CONFIG -= no-pkg-config
CONFIG  += link_pkgconfig
PKGCONFIG += opencv
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += /usr/local/include/opencv
INCLUDEPATH += /usr/local/include/opencv2
INCLUDEPATH += /usr/local/include/opencv4
LIBS += -L/usr/local/lib -lopencv_imgproc -lopencv_core -lopencv_highgui

SOURCES += \
        src/main.cpp \
        src/mainapplication.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    src/mainapplication.hpp
    # add open CV
    unix {
        CONFIG += link_pkgconfig
        PKGCONFIG += opencv
    }
