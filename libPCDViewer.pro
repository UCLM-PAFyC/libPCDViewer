#-------------------------------------------------
#
# Project created by QtCreator 2019-03-08T16:35:14
#
#-------------------------------------------------
debug_and_release {
    CONFIG -= debug_and_release
    CONFIG += debug_and_release
}

# ensure one "debug" or "release" in CONFIG so they can be used as
# conditionals instead of writing "CONFIG(debug, debug|release)"...
CONFIG(debug, debug|release) {
    CONFIG -= debug release
    CONFIG += debug
    }
CONFIG(release, debug|release) {
        CONFIG -= debug release
        CONFIG += release
}

QT       += widgets opengl xml

TARGET = libPCDViewer
TEMPLATE = lib

DESTDIR_RELEASE=C:\dev\release
DESTDIR_DEBUG=C:\dev\debug
#OSGEO4W_PATH="C:\Program Files\QGIS 2.18"
OSGEO4W_PATH="C:\Program Files\QGIS 3.4"
LASTOOLS_PATH = E:\Qt5CreatorPrograms\TIDOP_TOOLS_USAL\libs\LASTools2019
PCDVIEWER_MCVC_PATH="..\PcdViewer_V1.4_src"

INCLUDEPATH += . $$OSGEO4W_PATH/include
INCLUDEPATH += $$LASTOOLS_PATH\LASlib\inc
INCLUDEPATH += $$LASTOOLS_PATH\LASzip\src
INCLUDEPATH += ../../libs/libCRS
INCLUDEPATH += ../../libs/libParameters
INCLUDEPATH += ../../libs
INCLUDEPATH += ../../libs/libIGDAL
INCLUDEPATH += ../../libs/libPointCloudDbManager
INCLUDEPATH += ../../libs/libModelManagementTools
INCLUDEPATH += ../../libs/libWidgets
INCLUDEPATH += ../PcdViewer_V1.4_src
INCLUDEPATH += ../PcdViewer_V1.4_src/pcdviewer

INCLUDEPATH += .
INCLUDEPATH += $$PCDVIEWER_MCVC_PATH/basic
INCLUDEPATH += $$PCDVIEWER_MCVC_PATH/geometry
INCLUDEPATH += $$PCDVIEWER_MCVC_PATH/math
INCLUDEPATH += $$PCDVIEWER_MCVC_PATH/QGLViewer
INCLUDEPATH += $$PCDVIEWER_MCVC_PATH/widget

CGAL_DIR ="E:\Librerias\CGAL-14.3_vs2014_x64"
INCLUDEPATH += $$CGAL_DIR/include

BOOS_DIR ="E:\Librerias\boost_1_68_0_vs2014_x64"
INCLUDEPATH += $$BOOS_DIR

DEFINES += LIBPCDVIEWER_LIBRARY

SOURCES += \
    PCDViewerMainWindow.cpp \
    ../PcdViewer_V1.4_src/PcdViewer/select_tool.cpp \
    ../PcdViewer_V1.4_src/PcdViewer/select_vertex_lasso_tool.cpp \
    ../PcdViewer_V1.4_src/PcdViewer/select_vertex_rectangle_tool.cpp \
    ../PcdViewer_V1.4_src/PcdViewer/tool_manager3d.cpp \
    ../PcdViewer_V1.4_src/PcdViewer/tool3D.cpp \
    PCDViewerManager.cpp \
    paint_canvas.cpp

HEADERS += \
    libPCDViewer_global.h \
    PCDViewerMainWindow.h \
    ../PcdViewer_V1.4_src/PcdViewer/select_tool.h \
    ../PcdViewer_V1.4_src/PcdViewer/select_vertex_lasso_tool.h \
    ../PcdViewer_V1.4_src/PcdViewer/select_vertex_rectangle_tool.h \
    ../PcdViewer_V1.4_src/PcdViewer/tool_manager3d.h \
    ../PcdViewer_V1.4_src/PcdViewer/tool_name.h \
    ../PcdViewer_V1.4_src/PcdViewer/tool3D.h \
    ../PcdViewer_V1.4_src/PcdViewer/tree_widge_titem.h \
    PCDViewerManager.h \
    paint_canvas.h


debug{
    DESTDIR = $$DESTDIR_DEBUG
    LIBS += -L$$DESTDIR_DEBUG
    LIBS += -L$$LASTOOLS_PATH/lib64D
    LIBS += -llaslib
}else{
    DESTDIR = $$DESTDIR_RELEASE
    LIBS += -L$$DESTDIR_RELEASE
    LIBS += -L$$LASTOOLS_PATH/lib64
    LIBS += -llaslib
}

LIBS += -llibPointCloudDbManager
LIBS += -llibModelManagementTools
LIBS += -llibWidgets
#LIBS += -llibCRS
#LIBS += -llibIGDAL
#LIBS += -llibParameters

LIBS += -L$$OSGEO4W_PATH\bin
LIBS += $$OSGEO4W_PATH\lib\geos_c.lib
#LIBS += $$OSGEO4W_PATH\lib\gsl.lib
LIBS += $$OSGEO4W_PATH\lib\proj_i.lib
LIBS += $$OSGEO4W_PATH\lib\gdal_i.lib
LIBS += $$OSGEO4W_PATH\lib\libtiff_i.lib

LIBS += -lbasic
LIBS += -lgeometry
LIBS += -lmath
LIBS += -lqglviewer
LIBS += -lwidget
LIBS += -lopengl32#.lib
LIBS += -lglu32#.lib

debug{
    DESTDIR = $$DESTDIR_DEBUG
    LIBS += -L$$DESTDIR_DEBUG
}else{
    DESTDIR = $$DESTDIR_RELEASE
    LIBS += -L$$DESTDIR_RELEASE
}

RESOURCES += \
    Resources/PcdViewer.qrc

#unix {
#    target.path = /usr/lib
#    INSTALLS += target
#}

FORMS += \
    PCDViewerMainWindow.ui
