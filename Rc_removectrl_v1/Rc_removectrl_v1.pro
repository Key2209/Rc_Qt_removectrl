QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QMAKE_ANDROID_PERMISSIONS += android.permission.ACCESS_WIFI_STATE
QMAKE_ANDROID_PERMISSIONS += android.permission.ACCESS_FINE_LOCATION









SOURCES += \
    androidinfoprovider.cpp \
    connectwidget.cpp \
    joystick.cpp \
    main.cpp \
    mybutton.cpp \
    myscroller_horiz.cpp \
    myscroller_vertical.cpp \
    rcwidget.cpp \
    udpservice.cpp \
    widget.cpp

HEADERS += \
    androidinfoprovider.h \
    connectwidget.h \
    datastruct.h \
    joystick.h \
    mybutton.h \
    myscroller_horiz.h \
    myscroller_vertical.h \
    rcwidget.h \
    udpservice.h \
    widget.h

FORMS += \
    connectwidget.ui \
    myscroller_horiz.ui \
    myscroller_vertical.ui \
    rcwidget.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res_Joystick/res_Joystick.qrc




DISTFILES += \
    android/AndroidManifest.xml \
    android/build.gradle \
    android/gradle.properties \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew \
    android/gradlew.bat \
    android/res/values/libs.xml \
    android/res/xml/qtprovider_paths.xml

contains(ANDROID_TARGET_ARCH,arm64-v8a) {
    ANDROID_PACKAGE_SOURCE_DIR = \
        $$PWD/android
}




