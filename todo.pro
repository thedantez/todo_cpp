QT += core gui widgets 

CONFIG += static
QMAKE_LFLAGS += -static -static-libgcc -static-libstdc++

SOURCES += \
    main.cpp \
    visual.cpp

HEADERS += visual.h 
