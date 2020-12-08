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

DESTDIR_RELEASE= ./../../../build/release
DESTDIR_DEBUG= ./../../../build/debug
#OSGEO4W_PATH="C:\Program Files\QGIS 2.18"
OSGEO4W_PATH="C:\Program Files\QGIS 3.10"
LASTOOLS_PATH = ./../../../depends/LASTools2019
PCDVIEWER_MCVC_PATH=./../../../depends/pcdviewer/PcdViewer_V1.4_src
#BOOS_DIR ="E:\Librerias\boost_1_68_0_vs2014_x64"
BOOST_PATH= ./../../../depends/boost_1_68_0_vs2014_x64
#CGAL_DIR ="E:\Librerias\CGAL-14.3_vs2014_x64"
#CGAL_PATH= ./../../../depends/CGAL-5.0-beta1
CGAL_PATH= ./../../../depends/CGAL-14.3_vs2014_x64
EIGEN_PATH= ./../../../depends/eigen-eigen-323c052e1731

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
INCLUDEPATH += $$PCDVIEWER_MCVC_PATH
INCLUDEPATH += $$PCDVIEWER_MCVC_PATH/pcdviewer
INCLUDEPATH += $$EIGEN_PATH

INCLUDEPATH += .
INCLUDEPATH += $$PCDVIEWER_MCVC_PATH/basic
INCLUDEPATH += $$PCDVIEWER_MCVC_PATH/geometry
INCLUDEPATH += $$PCDVIEWER_MCVC_PATH/math
INCLUDEPATH += $$PCDVIEWER_MCVC_PATH/QGLViewer
INCLUDEPATH += $$PCDVIEWER_MCVC_PATH/widget

#INCLUDEPATH += $$CGAL_DIR/include
INCLUDEPATH += $$CGAL_PATH/include

#INCLUDEPATH += $$BOOS_DIR
INCLUDEPATH += $$BOOST_PATH

DEFINES += LIBPCDVIEWER_LIBRARY

SOURCES += \
    PCDViewerMainWindow.cpp \
    $$PCDVIEWER_MCVC_PATH/PcdViewer/select_tool.cpp \
    $$PCDVIEWER_MCVC_PATH/PcdViewer/select_vertex_lasso_tool.cpp \
    $$PCDVIEWER_MCVC_PATH/PcdViewer/select_vertex_rectangle_tool.cpp \
    $$PCDVIEWER_MCVC_PATH/PcdViewer/tool_manager3d.cpp \
    $$PCDVIEWER_MCVC_PATH/PcdViewer/tool3D.cpp \
    PCDViewerManager.cpp \
    paint_canvas.cpp

HEADERS += \
    libPCDViewer_global.h \
    PCDViewerMainWindow.h \
    $$PCDVIEWER_MCVC_PATH/PcdViewer/select_tool.h \
    $$PCDVIEWER_MCVC_PATH/PcdViewer/select_vertex_lasso_tool.h \
    $$PCDVIEWER_MCVC_PATH/PcdViewer/select_vertex_rectangle_tool.h \
    $$PCDVIEWER_MCVC_PATH/PcdViewer/tool_manager3d.h \
    $$PCDVIEWER_MCVC_PATH/PcdViewer/tool_name.h \
    $$PCDVIEWER_MCVC_PATH/PcdViewer/tool3D.h \
    $$PCDVIEWER_MCVC_PATH/PcdViewer/tree_widge_titem.h \
    PCDViewerManager.h \
    paint_canvas.h


debug{
    DESTDIR = $$DESTDIR_DEBUG
    LIBS += -L$$DESTDIR_DEBUG
    LIBS += -L$$LASTOOLS_PATH/lib64D
    LIBS += -llaslib
    LIBS += $$CGAL_PATH/lib/CGAL-vc140-mt-gd-4.13.lib
    LIBS += $$CGAL_PATH/lib/CGAL-vc140-mt-4.13.lib
    LIBS += $$PCDVIEWER_MCVC_PATH/x64/Debug/basic.lib
    LIBS += $$PCDVIEWER_MCVC_PATH/x64/Debug/geometry.lib
    LIBS += $$PCDVIEWER_MCVC_PATH/x64/Debug/math.lib
    LIBS += $$PCDVIEWER_MCVC_PATH/x64/Debug/qglviewer.lib
    LIBS += $$PCDVIEWER_MCVC_PATH/x64/Debug/widget.lib
}else{
    DESTDIR = $$DESTDIR_RELEASE
    LIBS += -L$$DESTDIR_RELEASE
    LIBS += -L$$LASTOOLS_PATH/lib64
    LIBS += -llaslib
    LIBS += $$CGAL_PATH/lib/CGAL-vc140-mt-4.13.lib
    LIBS += $$PCDVIEWER_MCVC_PATH/x64/Release/basic.lib
    LIBS += $$PCDVIEWER_MCVC_PATH/x64/Release/geometry.lib
    LIBS += $$PCDVIEWER_MCVC_PATH/x64/Release/math.lib
    LIBS += $$PCDVIEWER_MCVC_PATH/x64/Release/qglviewer.lib
    LIBS += $$PCDVIEWER_MCVC_PATH/x64/Release/widget.lib
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

#LIBS += -lbasic
#LIBS += -lgeometry
#LIBS += -lmath
#LIBS += -lqglviewer
#LIBS += -lwidget
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
