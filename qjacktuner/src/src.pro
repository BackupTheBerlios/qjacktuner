# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./src
# Target is an application:  ../bin/qjacktuner

TARGET=../bin/qjacktuner
TEMPLATE =app
CONFIG += release thread qt
LIBS += -ljack
LANGUAGE = C++
SOURCES += qtuna.cpp \
           measure.cpp \
           jack.cpp \
           tools.cpp \
           halbbanddezimator.cpp \
           scala.cpp 
HEADERS += halbbanddezimator.h \
           jack.h \
           scala.h \
           tools.h \
           value.h \
           MainWindow.ui.h 
FORMS += MainWindow.ui 
