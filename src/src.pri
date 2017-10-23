INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD
LIBS += -L$$PWD/lib/ -ltbb

SOURCES += \
    $$PWD/main.cpp \
    $$PWD/mainwindow.cpp \
    $$PWD/glwidget277.cpp \
    $$PWD/mygl.cpp \
    $$PWD/shaderprogram.cpp \
    $$PWD/scene/camera.cpp \
    $$PWD/scene/cylinder.cpp \
    $$PWD/scene/sphere.cpp \
    $$PWD/face.cpp \
    $$PWD/halfedge.cpp \
    $$PWD/mesh.cpp \
    $$PWD/vertex.cpp \
    $$PWD/meshqlistwidget.cpp \
    $$PWD/joint.cpp \
    $$PWD/jointqtreewidget.cpp \
    $$PWD/ray.cpp \
    $$PWD/frame.cpp \
    $$PWD/keyframeslistwidget.cpp \
    $$PWD/timelineslider.cpp \
    $$PWD/easybmp.cpp

HEADERS += \
    $$PWD/mainwindow.h \
    $$PWD/glwidget277.h \
    $$PWD/mygl.h \
    $$PWD/shaderprogram.h \
    $$PWD/scene/camera.h \
    $$PWD/scene/cylinder.h \
    $$PWD/scene/sphere.h \
    $$PWD/la.h \
    $$PWD/face.h \
    $$PWD/halfedge.h \
    $$PWD/mesh.h \
    $$PWD/vertex.h \
    $$PWD/meshqlistwidget.h \
    $$PWD/joint.h \
    $$PWD/jointqtreewidget.h \
    $$PWD/ray.h \
    $$PWD/frame.h \
    $$PWD/keyframeslistwidget.h \
    $$PWD/timelineslider.h \
    $$PWD/easybmp.h

OTHER_FILES +=
