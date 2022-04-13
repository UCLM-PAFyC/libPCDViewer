#include <QMessageBox>
#include <QFileDialog>
#include <QLabel>
#include <QStatusBar>
#include <QSettings>
#include <QCloseEvent>
#include <QPlainTextEdit>
#include <QAbstractItemModel>
#include <QStandardItemModel>
#include <QGroupBox>
#include <QColorDialog>
#include <QComboBox>
#include <QListView>

#include <math.h>
//#include "main_window.h"
#include "paint_canvas.h"
#include "../geometry/file_io.h"
#include "../geometry/point_set.h"
#include "../widget/logger.h"
#include "../widget/message_box.h"
#include "../geometry/vertex_group.h"
#include "../basic/file_system.h"
#include "../widget/logger.h"
//#include "dlg_down_sampling.h"
//#include "dlg_rotate_point_cloud.h"
#include "../geometry/color_table.h"
#include "tree_widge_titem.h"

#include "PCDViewerMainWindow.h"
#include "ui_PCDViewerMainWindow.h"
#include "../../libs/libModelManagementTools/ModelDbManager.h"
#include "../../libs/libPointCloudDbManager/PointCloudDbManager.h"
#include "../../libs/libPointCloudDbManager/PointCloudSpatialiteDb.h"

#include "../../libs/libModelManagementTools/ModelDbManagerDefinitions.h"
#include "../../libs/libModelManagementTools/ModelObject.h"
#include "../../libs/libModelManagementTools/ModelObjectClass.h"
#include "../../libs/libModelManagementTools/ModelProjectSpatialiteDb.h"

using namespace std;
using namespace qglviewer;

PCDViewerMainWindow::PCDViewerMainWindow(PointCloudDb::PointCloudDbManager *ptrPCDbManager,
                                         QWidget *parent) :
    QMainWindow(parent),
    mPtrPCDbManager(ptrPCDbManager),
    ui(new Ui::PCDViewerMainWindow)
{
    mPtrModelDbManager=NULL;
    ui->setupUi(this);

    //////////////////////////////////////////////////////////////////////////

    QGLFormat format = QGLFormat::defaultFormat();
    format.setSampleBuffers(true);
    format.setSamples(8);

    mMainCanvas = new PaintCanvas(format, this);
    mMainCanvas->setAttribute(Qt::WA_MouseTracking);

    setCentralWidget(mMainCanvas);
    Logger::init(mMainCanvas);

    ui->dockWidget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);

    //////////////////////////////////////////////////////////////////////////

    QStringList headerLabels;
    headerLabels << "Index" << "Label" << "Conf" << "#Point";
    ui->treeWidget->setHeaderLabels(headerLabels);
    //treeWidget->setSortingEnabled(true);

    // for the index column, narrow the width
    ui->treeWidget->setColumnWidth(0, 80);

    connect(ui->treeWidget, SIGNAL(itemChanged(QTreeWidgetItem*, int)), this, SLOT(treeItemDataChanged(QTreeWidgetItem*, int)));

    //////////////////////////////////////////////////////////////////////////

    createStatusBar();
    createActions();
    createMenus();

//	readSettings();
    setWindowTitle("Point Cloud Viewer");

    setContextMenuPolicy(Qt::CustomContextMenu);
    setWindowIcon(QIcon(":/Resources/icon.png"));

    //setFixedSize(1200, 900);
    setWindowState(Qt::WindowMaximized);

    setFocusPolicy(Qt::ClickFocus);

    mMainCanvas->camera()->setType(Camera::PERSPECTIVE);
    initialize();
//    mPointSet=NULL;
//    showMaximized();
}

PCDViewerMainWindow::~PCDViewerMainWindow()
{
    delete(mVisibleObjectClassesComboCheckBox);
    delete(mVisibleObjectsComboCheckBox);
    delete(mLockedObjectClassesComboCheckBox);
    delete(mLockedObjectsComboCheckBox);
//    delete(mSelectedObjectComboCheckBox);
    delete ui;
}

void PCDViewerMainWindow::closeEvent(QCloseEvent *event)
{
    this->hide();
    emit(closed());
    event->ignore();
}

void PCDViewerMainWindow::createActions()
{
    // file menu
//	createActionsForFileMenu();

    // view menu
    createActionsForViewMenu();

    // select
    createActionsForSelectMenu();

    // edit menu
    createActionsForEditMenu();

    // about menu
//	connect(actionAbout, SIGNAL(triggered()), this, SLOT(about()));
//	connect(actionAboutQt, SIGNAL(triggered()), this, SLOT(aboutQt()));
}

void PCDViewerMainWindow::createActionsForEditMenu()
{
//	connect(actionShowNormals, SIGNAL(toggled(bool)), mainCanvas_, SLOT(setShowNormals(bool)));

    connect(ui->actionDeleteSelectedPoints, SIGNAL(triggered()), mMainCanvas, SLOT(deleteSelectedPoints()));
//	connect(actionDownSampling, SIGNAL(triggered()), this, SLOT(downSampling()));

    //	connect(actionRotatePointCloud, SIGNAL(triggered()), this, SLOT(rotatePointCloud()));
}

bool PCDViewerMainWindow::initialize()
{
    mLockedClassesByClassId.clear();
    for(int i=PCDVIEWERMAINWINDOW_CLASS_ID_MINIMUM_VALUE;i<PCDVIEWERMAINWINDOW_CLASS_ID_MAXIMUM_VALUE;i++)
    {
        mLockedClassesByClassId[i]=false;
        mVisibleClassesByClassId[i]=true;
    }
    ui->visibleClass0CheckBox->setChecked(true);
    ui->visibleClass1CheckBox->setChecked(true);
    ui->visibleClass2CheckBox->setChecked(true);
    ui->visibleClass3CheckBox->setChecked(true);
    ui->visibleClass4CheckBox->setChecked(true);
    ui->visibleClass5CheckBox->setChecked(true);
    ui->visibleClass6CheckBox->setChecked(true);
    ui->visibleClass7CheckBox->setChecked(true);
    ui->visibleClass9CheckBox->setChecked(true);
    ui->visibleClass12CheckBox->setChecked(true);
    ui->getDifferencesAltitudeForSelectedPointsPushButton->setEnabled(false);

    //    ui->actionAssignColorByHeight->setEnabled(false);
    ui->actionAssignColorByIntensity->setEnabled(false);

    ui->actionAssignColorByObjectClassification->setEnabled(false);
    ui->modelingObjectsProcessingPage->setEnabled(false);

    QString title=PCDVIEWERMAINWINDOW_COMBOCHECKBOX_VISIBLE_OBJECT_CLASSES_TITLE;
    mVisibleObjectClassesComboCheckBox=new QComboCheckBox(title,
                                                           ui->visibleObjectClassesFrame);
    connect(mVisibleObjectClassesComboCheckBox,SIGNAL(pressChecked(int,bool,QString,QString)),
            this, SLOT(onVisibleObjectClassesComboCheckBox(int,bool,QString,QString)));
//    mVisibleObjectClassesComboCheckBox->showMaximized();
    mVisibleObjectClassesComboCheckBox->setMinimumWidth(340);

    title=PCDVIEWERMAINWINDOW_COMBOCHECKBOX_VISIBLE_OBJECTS_TITLE;
    mVisibleObjectsComboCheckBox=new QComboCheckBox(title,
                                                    ui->visibleObjectsFrame);
    connect(mVisibleObjectsComboCheckBox,SIGNAL(pressChecked(int,bool,QString,QString)),
            this, SLOT(onVisibleObjectsComboCheckBox(int,bool,QString,QString)));
//    mVisibleObjectsComboCheckBox->showMaximized();
    mVisibleObjectsComboCheckBox->setMinimumWidth(340);

    title=PCDVIEWERMAINWINDOW_COMBOCHECKBOX_LOCKED_OBJECT_CLASSES_TITLE;
    mLockedObjectClassesComboCheckBox=new QComboCheckBox(title,
                                                   ui->lockedObjectClassesFrame);
    connect(mLockedObjectClassesComboCheckBox,SIGNAL(pressChecked(int,bool,QString,QString)),
            this, SLOT(onLockedObjectClassesComboCheckBox(int,bool,QString,QString)));
//    mLockedObjectClassesComboCheckBox->showMaximized();
    mLockedObjectClassesComboCheckBox->setMinimumWidth(340);

    title=PCDVIEWERMAINWINDOW_COMBOCHECKBOX_LOCKED_OBJECTS_TITLE;
    mLockedObjectsComboCheckBox=new QComboCheckBox(title,
                                                   ui->lockedObjectsFrame);
    connect(mLockedObjectsComboCheckBox,SIGNAL(pressChecked(int,bool,QString,QString)),
            this, SLOT(onLockedObjectsComboCheckBox(int,bool,QString,QString)));
//    mLockedObjectsComboCheckBox->showMaximized();
    mLockedObjectsComboCheckBox->setMinimumWidth(340);

//    title=PCDVIEWERMAINWINDOW_COMBOCHECKBOX_SELECTED_OBJECT_TITLE;
//    mSelectedObjectComboCheckBox=new QComboCheckBox(title,
//                                                    ui->selectedObjectFrame);
//    connect(mSelectedObjectComboCheckBox,SIGNAL(pressChecked(int,bool,QString,QString)),
//            this, SLOT(onSelectedObjectComboCheckBox(int,bool,QString,QString)));



    title=PCDVIEWERMAINWINDOW_COMBOCHECKBOX_VISIBLE_PG_OBJECT_CLASSES_TITLE;
    mVisiblePGObjectClassesComboCheckBox=new QComboCheckBox(title,
                                                           ui->visibleParametricGeometriesObjectClassesFrame);
    connect(mVisiblePGObjectClassesComboCheckBox,SIGNAL(pressChecked(int,bool,QString,QString)),
            this, SLOT(onVisibleParametricGeometriesObjectClassesComboCheckBox(int,bool,QString,QString)));
//    mVisibleObjectClassesComboCheckBox->showMaximized();
    mVisiblePGObjectClassesComboCheckBox->setMinimumWidth(340);

    title=PCDVIEWERMAINWINDOW_COMBOCHECKBOX_VISIBLE_PG_OBJECTS_TITLE;
    mVisiblePGsComboCheckBox=new QComboCheckBox(title,
                                                    ui->visibleParametricGeometriesObjectsFrame);
    connect(mVisiblePGsComboCheckBox,SIGNAL(pressChecked(int,bool,QString,QString)),
            this, SLOT(onVisibleParametricGeometriesObjectsComboCheckBox(int,bool,QString,QString)));
//    mVisibleObjectsComboCheckBox->showMaximized();
    mVisiblePGsComboCheckBox->setMinimumWidth(340);
    ui->parametricGeometriesTab->setEnabled(false);
    return(true);
}

void PCDViewerMainWindow::recoverLockedClassesFromGui()
{
    mLockedClassesByClassId[0]=ui->lockedClass0CheckBox->isChecked();
    mLockedClassesByClassId[1]=ui->lockedClass1CheckBox->isChecked();
    mLockedClassesByClassId[2]=ui->lockedClass2CheckBox->isChecked();
    mLockedClassesByClassId[3]=ui->lockedClass3CheckBox->isChecked();
    mLockedClassesByClassId[4]=ui->lockedClass4CheckBox->isChecked();
    mLockedClassesByClassId[5]=ui->lockedClass5CheckBox->isChecked();
    mLockedClassesByClassId[6]=ui->lockedClass6CheckBox->isChecked();
    mLockedClassesByClassId[7]=ui->lockedClass6CheckBox->isChecked();
    mLockedClassesByClassId[9]=ui->lockedClass9CheckBox->isChecked();
    mLockedClassesByClassId[12]=ui->lockedClass12CheckBox->isChecked();
}

void PCDViewerMainWindow::createActionsForSelectMenu()
{
    QActionGroup* toolActionGroup = new QActionGroup(this);
    toolActionGroup->addAction(ui->actionSceneManipulation);
    toolActionGroup->addAction(ui->actionSelectPointsByPolygon);
    toolActionGroup->addAction(ui->actionSelectPointsByRectangle);
    toolActionGroup->addAction(ui->actionSelectPointsByFreehand);
    toolActionGroup->addAction(ui->actionUnselectPoints);
    connect(toolActionGroup, SIGNAL(triggered(QAction*)), this, SLOT(operationModeChanged(QAction*)));
    ui->actionSelectPointsByPolygon->setEnabled(false);
}

void PCDViewerMainWindow::createActionsForViewMenu()
{
    connect(ui->actionPerspectiveOrthographic, SIGNAL(toggled(bool)), mMainCanvas, SLOT(setPerspectiveMode(bool)));
    mMainCanvas->setPerspectiveMode(false);

    connect(ui->actionFullScreen, SIGNAL(toggled(bool)), this, SLOT(setFullScreen(bool)));
    connect(ui->actionFitWindow, SIGNAL(triggered()), mMainCanvas, SLOT(fitScreen()));

    connect(ui->actionIncreasePointSize, SIGNAL(triggered()), mMainCanvas, SLOT(increasePointSize()));
    connect(ui->actionDecreasePointSize, SIGNAL(triggered()), mMainCanvas, SLOT(decreasePointSize()));

    connect(ui->actionShowCoordinateSystem, SIGNAL(toggled(bool)), mMainCanvas, SLOT(setShowCoordinateSystem(bool)));

    connect(ui->actionAssignColorByRGB, SIGNAL(triggered()), this, SLOT(assignColorByRGB()));
    connect(ui->actionAssignColorByHeight, SIGNAL(triggered()), this, SLOT(assignColorByHeight()));
    connect(ui->actionAssignColorByClassification, SIGNAL(triggered()), this, SLOT(assignColorByClassification()));
    connect(ui->actionAssignColorByObjectClassification, SIGNAL(triggered()), this, SLOT(assignColorByObjectClassification()));
//    connect(ui->actionAssignColorByHeight, SIGNAL(triggered()), mMainCanvas, SLOT(assignColorByHeight()));
//	connect(ui->actionAssignColorByNormal, SIGNAL(triggered()), mainCanvas_, SLOT(assignColorByNormal()));


}



void PCDViewerMainWindow::createMenus()
{
//	actionSeparator = ui->menuFile->addSeparator();
//	QList<QAction*> actions;
//	for (int i = 0; i < MaxRecentFiles; ++i)
//		actions.push_back(actionsRecentFile[i]);
//	menuFile->insertActions(actionExit, actions);
}

void PCDViewerMainWindow::createStatusBar()
{
    statusLabel = new QLabel("Ready");
    statusLabel->setAlignment(Qt::AlignHCenter);
    statusLabel->setMinimumSize(statusLabel->sizeHint());

    spacerLabel = new QLabel;

    coordinateUnderMouseLabel = new QLabel(this);
    coordinateUnderMouseLabel->setAlignment(Qt::AlignLeft);
    //coordinateUnderMouseLabel->setMinimumSize(coordinateUnderMouseLabel->sizeHint());

    numVerticesLabel = new QLabel;
    numVerticesLabel->setIndent(80);
    numVerticesLabel->setAlignment(Qt::AlignRight);
    //numVerticesLabel->setMinimumSize(numVerticesLabel->sizeHint());

    numVertexGroupsLabel = new QLabel;
    numVertexGroupsLabel->setIndent(80);
    numVertexGroupsLabel->setAlignment(Qt::AlignRight);
    //numVertexGroupsLabel->setMinimumSize(numVerticesLabel->sizeHint());

    statusBar()->addWidget(statusLabel);
    statusBar()->addWidget(spacerLabel, 0);
    statusBar()->addWidget(coordinateUnderMouseLabel, 1);
    statusBar()->addWidget(numVerticesLabel, 0);
    statusBar()->addWidget(numVertexGroupsLabel, 0);

    updateStatusBar();
    updateAnnotationTable();
}

bool PCDViewerMainWindow::loadPointCloud(const QString &fileName)
{
    if (fileName == mCurrentPointCloudFileName)
        return false;

    PointSet* ptc = FileIO::read_point_cloud(fileName.toStdString());

    if (ptc == nil)
    {
        showStatusMessage(tr("Loading failed"), 500);
        return false;
    }
    else
    {
        mMainCanvas->setPointSet(ptc);

        setCurrentPointCloudFile(fileName);
        showStatusMessage(tr("File loaded"), 500);

        mMainCanvas->updateCanvas();
        return true;
    }
}

bool PCDViewerMainWindow::loadPointCloudFromSpatialiteDb(QString &dbFileName,
                                                         QString wktGeometry,
                                                         int geometryCrsEpsgCode,
                                                         QString geometryCrsProj4String,
                                                         QString &strError)
{
    mViewParametricGeometries=true;
    if(!QFile::exists(dbFileName))
    {
        strError=QObject::tr("PCDViewerMainWindow::loadPointCloudFromSpatialiteDb");
        strError+=QObject::tr("\nNot exists Point Cloud File:\n%1").arg(dbFileName);
        return(false);
    }
    clearPoints();
    QString strAuxError;
    QVector<QString> ignoreTilesTableName;
    bool showProgressDialog=true;
    bool tilesFullGeometry=false;
    if(!mPtrPCDbManager->getPointsFromWktGeometry(dbFileName,
                                                 wktGeometry,
                                                 geometryCrsEpsgCode,
                                                 geometryCrsProj4String,
                                                 mTilesTableNamesById,
                                                 mPointsTilesTableNameId,
                                                 mPointsIdInTileTable,
                                                 mPointsGpsTime,
                                                 mPointsBlue,
                                                 mPointsRed,
                                                 mPointsGreen,
                                                 mPointsNir,
                                                 mPointsIntensity,
                                                 mPointsReturns,
                                                 mPointsReturn,
                                                 mPointsClass,
                                                 mPointsClassNew,
                                                 mPointsRemoved,
                                                 mPointsFc,
                                                 mPointsSc,
                                                 mPointsHeight,
                                                 mPointsAltitude,
                                                 strAuxError,
                                                 ignoreTilesTableName,
                                                  showProgressDialog,
                                                  tilesFullGeometry))
    {
        strError=QObject::tr("PCDViewerMainWindow::loadPointCloudFromSpatialiteDb");
        strError+=QObject::tr("\nError recovering points from database:\n%1\nError:\n%2")
                .arg(dbFileName).arg(strAuxError);
        clearPoints();
        return(false);
    }
    if(mPointsFc.size()==0)
    {
        return(true);
    }
    bool storePointsData=true;
    if(!mPtrPCDbManager->getStorePointsData(dbFileName,
                                            storePointsData,
                                            strError))
    {
        QString title="PCDViewerMainWindow::loadPointCloudFromSpatialiteDb";
        QString msg=QObject::tr("Error recovering store points data for file:\n%1\nError:\n%1")
                .arg(mCurrentPointCloudFileName).arg(strError);
        QMessageBox::information(this,title,msg);
        return(false);
    }
    // carga de los puntos
    double minimumFc=10000000.0;
    double maximumFc=-10000000.0;
    double minimumSc=10000000.0;
    double maximumSc=-10000000.0;
    double minimumAltitude=10000000.0;
    double maximumAltitude=-10000000.0;
    int maximumColorValue=0;
    int maximumIntensity=0;
    mPointsPGDbId.clear();
    mPointsPGDbId.resize(mPointsFc.size());
    mPointsPGDbId.fill(-1);
    for(int i=0;i<mPointsFc.size();i++)
    {
        if(!storePointsData)
        {
            if(mPointsClassNew[i]==POINTCLOUDDB_CLASS_NUMBER_REMOVE)
            {
                mPointsClassNew[i]=mPointsClass[i];
            }
        }
        if(mPointsFc[i]<minimumFc)
        {
            minimumFc=mPointsFc[i];
        }
        if(mPointsFc[i]>maximumFc)
        {
            maximumFc=mPointsFc[i];
        }
        if(mPointsSc[i]<minimumSc)
        {
            minimumSc=mPointsSc[i];
        }
        if(mPointsSc[i]>maximumSc)
        {
            maximumSc=mPointsSc[i];
        }
        if(mPointsAltitude[i]<minimumAltitude)
        {
            minimumAltitude=mPointsAltitude[i];
        }
        if(mPointsAltitude[i]>maximumAltitude)
        {
            maximumAltitude=mPointsAltitude[i];
        }
        if(mPointsBlue.size()>0)
        {
            if(mPointsBlue[i]>maximumColorValue)
            {
                maximumColorValue=mPointsBlue[i];
            }
            if(mPointsRed[i]>maximumColorValue)
            {
                maximumColorValue=mPointsRed[i];
            }
            if(mPointsGreen[i]>maximumColorValue)
            {
                maximumColorValue=mPointsGreen[i];
            }
        }
        if(mPointsIntensity.size()>0)
        {
            if(mPointsIntensity[i]>maximumIntensity)
            {
                maximumIntensity=mPointsIntensity[i];
            }
        }
    }
    mRGBColorToUnit=1.0/255.0;
    if(maximumColorValue>255)
    {
        mRGBColorToUnit=1.0/65535.0;
    }
    minimumFc=floor(minimumFc);
    maximumFc=ceil(maximumFc);
    minimumSc=floor(minimumSc);
    maximumSc=ceil(maximumSc);
    minimumAltitude=floor(minimumAltitude);
    maximumAltitude=ceil(maximumAltitude);
    mMinimumFc=minimumFc;
    mMaximumFc=maximumFc;
    mMinimumSc=minimumSc;
    mMaximumSc=maximumSc;
    mMinimumAltitude=minimumAltitude;
    mMaximumAltitude=maximumAltitude;

//    double angle_x=0;
//    double angle_y=0;
//    double angle_z=0;
//    mMainCanvas->rotatePointCloud(angle_x, angle_y, angle_z);

//    mMainCanvas->updateCanvas();
//    QFileInfo dbFileInfo(dbFileName);
//    QString outputFileName=dbFileInfo.absolutePath()+"/"+dbFileInfo.completeBaseName()+".lab";
//    savePointCloud(outputFileName);
    bool existsClassification=true;
    if(!mPtrPCDbManager->getExistsClassification(dbFileName,existsClassification,strAuxError))
    {
        strError=QObject::tr("PCDViewerMainWindow::loadPointCloudFromSpatialiteDb");
        strError+=QObject::tr("\nError recovering if exists classification from database:\n%1\nError:\n%2")
                .arg(dbFileName).arg(strAuxError);
        clearPoints();
        return(false);
    }
    bool existsRGB=true;
    if(!mPtrPCDbManager->getExistsRGB(dbFileName,existsRGB,strAuxError))
    {
        strError=QObject::tr("PCDViewerMainWindow::loadPointCloudFromSpatialiteDb");
        strError+=QObject::tr("\nError recovering if exists RGB from database:\n%1\nError:\n%2")
                .arg(dbFileName).arg(strAuxError);
        clearPoints();
        return(false);
    }
    if(!existsRGB)
    {
        ui->actionAssignColorByRGB->setEnabled(false);
    }
    else
    {
        ui->actionAssignColorByRGB->setEnabled(true);
    }
    ui->actionAssignColorByClassification->setEnabled(true);
//    if(!existsClassification)
//    {
//        ui->actionAssignColorByClassification->setEnabled(false);
//    }
//    else
//    {
//        ui->actionAssignColorByClassification->setEnabled(true);
//    }
    int num_points_parametric=0;
    QVector<QVector<double> > pointsPGCoordinates;
    if(mPtrModelDbManager!=NULL)
    {
        bool ok=false;
        QString strAuxError;
        PointCloudDb::PointCloudSpatialiteDb* ptrPCSpatialiteDb=mPtrPCDbManager->getPointCloudSpatialiteDb(dbFileName,ok,strAuxError);
        if(!ok)
        {
            strError=QObject::tr("PCDViewerMainWindow::loadPointCloudFromSpatialiteDb");
            strError+=QObject::tr("\nError recovering point cloud spatialite database:\n%1\nError:\n%2")
                    .arg(dbFileName).arg(strAuxError);
            clearPoints();
            return(false);
        }
        mTilesDbIdById.clear();
        mPointsTilesDbId.clear();

        mPointsObjectDbId.clear(); // -1 si no pertenece a ninguno
        mPointsDbId.clear();
        mObjectNameByObjectDbId.clear();
        mObjectClassDbIdByObjectDbId.clear();
        mObjectClassNameByObjectClassId.clear();
        mObjectClassColorByObjectClassId.clear();
        ui->objectClassComboBox->clear();
        ui->objectComboBox->clear();
        mVisibleObjectClassesComboCheckBox->removeAll();
        mVisibleObjectsComboCheckBox->removeAll();
        mLockedObjectClassesComboCheckBox->removeAll();
        mLockedObjectsComboCheckBox->removeAll();
        ui->selectObjectComboBox->clear();
        mLockedObjectClassesByObjectClassId.clear();
        mVisibleObjectClassesByObjectClassId.clear();
        mLockedObjectsByObjectId.clear();
        mVisibleObjectsByObjectId.clear();

        mPGNameByPGDbId.clear();;
        mPGObjectDbIdByPGDbId.clear();;
        mPGDbIdsByPGObjectDbId.clear();;
        mVisiblePGObjectClassesByObjectClassId.clear();;
        mVisiblePGPByGDbId.clear();; // un objeto puede tener varias

//        mPointsPGDbId.clear();; // -1 si no pertenece a ninguno, para consultar para cualquier punto
//        mPointsPGDbId.resize(mPointsIdInTileTable.size());
//        for(int np=0;np<mPointsIdInTileTable.size();np++)
//        {
//            mPointsPGDbId[np]=-1;
//        }

        QMap<int,QString>::const_iterator iter1=mTilesTableNamesById.begin();
        while(iter1!=mTilesTableNamesById.end())
        {
            QString tileTableName=iter1.value();
            int tileDbId=ptrPCSpatialiteDb->getTileDbId(tileTableName);
            if(tileDbId==-1)
            {
                strError=QObject::tr("PCDViewerMainWindow::loadPointCloudFromSpatialiteDb");
                strError+=QObject::tr("\nError recovering tile: %1\nin point cloud spatialite database:\n%2")
                        .arg(tileTableName).arg(dbFileName);
                clearPoints();
                return(false);
            }
            mTilesDbIdById[iter1.key()]=tileDbId;
            iter1++;
        }
        for(int np=0;np<mPointsIdInTileTable.size();np++)
        {
            int tileTableNameId=mPointsTilesTableNameId[np];
            QString tileTableName=mTilesTableNamesById[tileTableNameId];
            if(!mTilesDbIdById.contains(tileTableNameId))
            {
                strError=QObject::tr("PCDViewerMainWindow::loadPointCloudFromSpatialiteDb");
                strError+=QObject::tr("\nFor point: %1 rrror recovering tile: %1\nin point cloud spatialite database:\n%2")
                        .arg(QString::number(np)).arg(tileTableName).arg(dbFileName);
                clearPoints();
                return(false);
            }
            mPointsTilesDbId.push_back(mTilesDbIdById[tileTableNameId]);
        }
        // Datos
//        QVector<int> mPointsIdInTileTable;
//        QVector<int> mPointsTilesDbId;

        // Resultados
//        QVector<int> mPointsObjectDbId; // -1 si no pertenece a ningunon
//        QMap<int,QString> mObjectNameByObjectDbId;
//        QMap<int,int> mObjectClassDbIdByObjectDbId;
//        QMap<int,QString> mObjectClassNameByObjectClassId;
//        QMap<int,QVector<int> > mObjectClassColorByObjectClassId;
        ModelDb::ModelProjectSpatialiteDb* ptrModelProjectSpatialiteDb=mPtrModelDbManager->getModelProjectSpatialiteDb(mModelProjectSpatialiteDbFileName,ok,strAuxError);
        if(!ok)
        {
            strError=QObject::tr("PCDViewerMainWindow::loadPointCloudFromSpatialiteDb");
            strError+=QObject::tr("\nError recovering model project spatialite database:\n%1\nError:\n%2")
                    .arg(mModelProjectSpatialiteDbFileName).arg(strAuxError);
            clearPoints();
            return(false);
        }

        if(!ptrModelProjectSpatialiteDb->getPointsObjectsAndObjectClassesSymbology(ptrPCSpatialiteDb,
                                                                                   mPointsIdInTileTable,
                                                                                   mPointsTilesDbId,
                                                                                   mPointsObjectDbId,
                                                                                   mPointsDbId,
                                                                                   mObjectNameByObjectDbId,
                                                                                   mObjectClassDbIdByObjectDbId,
                                                                                   mObjectClassNameByObjectClassId,
                                                                                   mObjectClassColorByObjectClassId,
                                                                                   strAuxError))
        {
            strError=QObject::tr("PCDViewerMainWindow::loadPointCloudFromSpatialiteDb");
            strError+=QObject::tr("\nError recovering points objects from spatialite database:\n%1\nError:\n%2")
                    .arg(mModelProjectSpatialiteDbFileName).arg(strAuxError);
            clearPoints();
            return(false);
        }

        if(mViewParametricGeometries)
        {
            // antes de:
            // mObjectClassDbIdByObjectDbId[MODELDBMANAGERDEFINITIONS_NO_OBJECT_ID]=MODELDBMANAGERDEFINITIONS_NO_OBJECT_CLASS_ID;
            // Obtener objetos y resto de valores cuando no hay puntos, a partir de geometrías paramétricas
            QVector<QString> objectsTilesTableNames;
            QMap<int,QString>::const_iterator iterTiles=mTilesTableNamesById.begin();
            while(iterTiles!=mTilesTableNamesById.end())
            {
                objectsTilesTableNames.push_back(iterTiles.value());
                iterTiles++;
            }
            if(!ptrModelProjectSpatialiteDb->getPointsObjectsAndObjectClassesSymbology(ptrPCSpatialiteDb,
                                                                                       wktGeometry,
                                                                                       geometryCrsEpsgCode,
                                                                                       geometryCrsProj4String,
                                                                                       objectsTilesTableNames,
                                                                                       mObjectNameByObjectDbId,
                                                                                       mObjectClassDbIdByObjectDbId,
                                                                                       mObjectClassNameByObjectClassId,
                                                                                       mObjectClassColorByObjectClassId,
                                                                                       strAuxError))
            {
                strError=QObject::tr("PCDViewerMainWindow::loadPointCloudFromSpatialiteDb");
                strError+=QObject::tr("\nError recovering points objects from spatialite database:\n%1\nError:\n%2")
                        .arg(mModelProjectSpatialiteDbFileName).arg(strAuxError);
                clearPoints();
                return(false);
            }

            QMap<int,QString> pGNameByPGDbId;
            QMap<int,int> pGObjectDbIdByPGDbId;
            QMap<int,QVector<int> > pGDbIdsByPGObjectDbId;
            QVector<int> pointsPGDbId; // -1 si no pertenece a ninguno, para consultar para cualquier punto
            double step=0.10;
            if(!ptrModelProjectSpatialiteDb->getParametricGeometriesPointsObjects(ptrPCSpatialiteDb,
                                                                                  mObjectClassDbIdByObjectDbId,
                                                                                  objectsTilesTableNames,
                                                                                  pGNameByPGDbId,
                                                                                  pGObjectDbIdByPGDbId,
                                                                                  pGDbIdsByPGObjectDbId,
                                                                                  pointsPGDbId,
                                                                                  pointsPGCoordinates,
                                                                                  strAuxError,
                                                                                  step))
            {
                strError=QObject::tr("PCDViewerMainWindow::loadPointCloudFromSpatialiteDb");
                strError+=QObject::tr("\nError recovering parametric geometry points objects from spatialite database:\n%1\nError:\n%2")
                        .arg(mModelProjectSpatialiteDbFileName).arg(strAuxError);
                clearPoints();
                return(false);
            }
            if(pointsPGCoordinates.size()>0)
            {
                num_points_parametric+=pointsPGCoordinates.size();
                for(int npp=0;npp<pointsPGCoordinates.size();npp++)
                {
                    int parametricGeometryDbId=pointsPGDbId[npp];
                    int objectDbId=pGObjectDbIdByPGDbId[parametricGeometryDbId];
                    int classObjectDbId=mObjectClassDbIdByObjectDbId[objectDbId];
                    mPointsObjectDbId.push_back(objectDbId);
                    mPointsPGDbId.push_back(parametricGeometryDbId);
                    if(!mVisiblePGObjectClassesByObjectClassId.contains(classObjectDbId))
                    {
                        QString name=mObjectClassNameByObjectClassId[classObjectDbId];
                        QString strObjectClassDbId=QString::number(classObjectDbId);
                        mVisiblePGObjectClassesComboCheckBox->addCheckItem(name,strObjectClassDbId,Qt::Checked);
                        mVisiblePGObjectClassesByObjectClassId[classObjectDbId]=true;
                    }
                    if(!mVisiblePGPByGDbId.contains(parametricGeometryDbId))
                    {
                        QString objectName=mObjectNameByObjectDbId[objectDbId];
                        QString name=objectName+PCDVIEWERMAINWINDOW_SYMBOLOGY_NAME_STRING_SEPARATOR;
                        name+=pGNameByPGDbId[parametricGeometryDbId];
                        QString strPGDbId=QString::number(parametricGeometryDbId);
                        mVisiblePGsComboCheckBox->addCheckItem(name,strPGDbId,Qt::Checked);
                        mVisiblePGPByGDbId[parametricGeometryDbId]=true;
                    }
                }
                QMap<int,QString>::const_iterator iterPGNames=pGNameByPGDbId.begin();
                while(iterPGNames!=pGNameByPGDbId.end())
                {
                    int pgDbId=iterPGNames.key();
                    QString pgName=iterPGNames.value();
                    int objectDbId=pGObjectDbIdByPGDbId[pgDbId];
                    QString objectName=mObjectNameByObjectDbId[objectDbId];
                    QString name=objectName+PCDVIEWERMAINWINDOW_SYMBOLOGY_NAME_STRING_SEPARATOR;
                    name+=iterPGNames.value();
                    mPGNameByPGDbId[pgDbId]=name;
                    mPGObjectDbIdByPGDbId[pgDbId]=objectDbId;
                    iterPGNames++;
                }
                ui->parametricGeometriesTab->setEnabled(true);
            }
        }

        QString strNoObjecClasstId=QString::number(MODELDBMANAGERDEFINITIONS_NO_OBJECT_CLASS_ID);
        QString noObjectClassName=MODELDBMANAGERDEFINITIONS_NO_OBJECT_CLASS_NAME;
        QString strNoObjectId=QString::number(MODELDBMANAGERDEFINITIONS_NO_OBJECT_ID);
        QString noObjectName=MODELDBMANAGERDEFINITIONS_NO_OBJECT_NAME;
        QVector<int> noObjectClassColor(4);
        noObjectClassColor[0]=MODELDBMANAGERDEFINITIONS_NO_COLOR_RED;
        noObjectClassColor[1]=MODELDBMANAGERDEFINITIONS_NO_COLOR_GREEN;
        noObjectClassColor[2]=MODELDBMANAGERDEFINITIONS_NO_COLOR_BLUE;
        noObjectClassColor[3]=MODELDBMANAGERDEFINITIONS_NO_COLOR_ALPHA;
        mObjectNameByObjectDbId[MODELDBMANAGERDEFINITIONS_NO_OBJECT_ID]=noObjectName;
        mObjectClassDbIdByObjectDbId[MODELDBMANAGERDEFINITIONS_NO_OBJECT_ID]=MODELDBMANAGERDEFINITIONS_NO_OBJECT_CLASS_ID;
        mObjectClassNameByObjectClassId[MODELDBMANAGERDEFINITIONS_NO_OBJECT_CLASS_ID]=MODELDBMANAGERDEFINITIONS_NO_OBJECT_CLASS_NAME;
        mObjectClassColorByObjectClassId[MODELDBMANAGERDEFINITIONS_NO_OBJECT_CLASS_ID]=noObjectClassColor;

        mObjectClassRGBColorToUnit=1.0/255.0;
        ui->objectClassComboBox->addItem(PCDVIEWERMAINWINDOW_NO_COMBO_SELECT);
        QMap<int,QString>::const_iterator iterObjectClasses=mObjectClassNameByObjectClassId.begin();
        while(iterObjectClasses!=mObjectClassNameByObjectClassId.end())
        {
            QString name=iterObjectClasses.value();
            if(name.compare(MODELDBMANAGERDEFINITIONS_NO_OBJECT_CLASS_NAME,Qt::CaseInsensitive)!=0)
            {
                ui->objectClassComboBox->addItem(name);
            }
            iterObjectClasses++;
        }

        ui->objectComboBox->addItem(PCDVIEWERMAINWINDOW_NO_COMBO_SELECT);
        QMap<int,QString>::const_iterator iterObject=mObjectNameByObjectDbId.begin();
        while(iterObject!=mObjectNameByObjectDbId.end())
        {
            QString name=iterObject.value();
            if(name.compare(MODELDBMANAGERDEFINITIONS_NO_OBJECT_NAME,Qt::CaseInsensitive)!=0)
            {
                ui->objectComboBox->addItem(name);
            }
            //            ui->objectComboBox->addItem(name);
            iterObject++;
        }

        iterObjectClasses=mObjectClassNameByObjectClassId.begin();
        while(iterObjectClasses!=mObjectClassNameByObjectClassId.end())
        {
            QString name=iterObjectClasses.value();
            QString strObjectClassDbId=QString::number(iterObjectClasses.key());
            mVisibleObjectClassesComboCheckBox->addCheckItem(name,strObjectClassDbId,Qt::Checked);
            mLockedObjectClassesComboCheckBox->addCheckItem(name,strObjectClassDbId,Qt::Unchecked);
            mLockedObjectClassesByObjectClassId[iterObjectClasses.key()]=false;
            mVisibleObjectClassesByObjectClassId[iterObjectClasses.key()]=true;
            iterObjectClasses++;
        }

        ui->selectObjectComboBox->addItem(PCDVIEWERMAINWINDOW_NO_COMBO_SELECT);
        iterObject=mObjectNameByObjectDbId.begin();
        while(iterObject!=mObjectNameByObjectDbId.end())
        {
            QString name=iterObject.value();
            QString strObjectDbId=QString::number(iterObject.key());
            mVisibleObjectsComboCheckBox->addCheckItem(name,strObjectDbId,Qt::Checked);
            mLockedObjectsComboCheckBox->addCheckItem(name,strObjectDbId,Qt::Unchecked);
            //            mSelectedObjectComboCheckBox->addCheckItem(name,strObjectDbId,Qt::Unchecked);
            ui->selectObjectComboBox->addItem(name);
            mLockedObjectsByObjectId[iterObject.key()]=false;
            mVisibleObjectsByObjectId[iterObject.key()]=true;
            iterObject++;
        }

        /*
        if(mViewParametricGeometries)
        {
            if(pointsPGCoordinates.size()>0)
            {
                num_points_parametric+=pointsPGCoordinates.size();
                for(int npp=0;npp<pointsPGCoordinates.size();npp++)
                {
                    int parametricGeometryDbId=pointsPGDbId[npp];
                    int objectDbId=pGObjectDbIdByPGDbId[parametricGeometryDbId];
                    int classObjectDbId=mObjectClassDbIdByObjectDbId[objectDbId];
                    mPointsObjectDbId.push_back(objectDbId);
                    mPointsPGDbId.push_back(parametricGeometryDbId);
                    if(!mVisiblePGObjectClassesByObjectClassId.contains(classObjectDbId))
                    {
                        QString name=mObjectClassNameByObjectClassId[classObjectDbId];
                        QString strObjectClassDbId=QString::number(classObjectDbId);
                        mVisiblePGObjectClassesComboCheckBox->addCheckItem(name,strObjectClassDbId,Qt::Checked);
                        mVisiblePGObjectClassesByObjectClassId[classObjectDbId]=true;
                    }
                    if(!mVisiblePGPByGDbId.contains(parametricGeometryDbId))
                    {
                        QString objectName=mObjectNameByObjectDbId[objectDbId];
                        QString name=objectName+PCDVIEWERMAINWINDOW_SYMBOLOGY_NAME_STRING_SEPARATOR;
                        name+=pGNameByPGDbId[parametricGeometryDbId];
                        QString strPGDbId=QString::number(parametricGeometryDbId);
                        mVisiblePGsComboCheckBox->addCheckItem(name,strPGDbId,Qt::Checked);
                        mVisiblePGPByGDbId[parametricGeometryDbId]=true;
                    }
                }
                QMap<int,QString>::const_iterator iterPGNames=pGNameByPGDbId.begin();
                while(iterPGNames!=pGNameByPGDbId.end())
                {
                    int pgDbId=iterPGNames.key();
                    QString pgName=iterPGNames.value();
                    int objectDbId=pGObjectDbIdByPGDbId[pgDbId];
                    QString objectName=mObjectNameByObjectDbId[objectDbId];
                    QString name=objectName+PCDVIEWERMAINWINDOW_SYMBOLOGY_NAME_STRING_SEPARATOR;
                    name+=iterPGNames.value();
                    mPGNameByPGDbId[pgDbId]=name;
                    mPGObjectDbIdByPGDbId[pgDbId]=objectDbId;
                    iterPGNames++;
                }
                ui->parametricGeometriesTab->setEnabled(true);
            }
        }
        */
    }
    int num_points=mPointsTilesTableNameId.size();
    int num_total_points=num_points+num_points_parametric;
//    mPointSet = new PointSet;
    PointSet* pointSet=new PointSet;
    Vertex** vertices = new Vertex*[num_total_points];
    for (int i=0; i<num_points; ++i)
    {
        float x=mPointsFc[i]-mMinimumFc;
        float y=mPointsSc[i]-mMinimumSc;
        float z=mPointsAltitude[i]-mMinimumAltitude;
        float nx=0.0;
        float ny=0.0;
        float nz=1.0;
        float r=((float)mPointsRed[i])*mRGBColorToUnit;
        float g=((float)mPointsGreen[i])*mRGBColorToUnit;
        float b=((float)mPointsBlue[i])*mRGBColorToUnit;
        vertices[i] = new Vertex(x, y, z, nx, ny, nz);
        vertices[i]->set_color(Colorf(r, g, b));
        vertices[i]->set_index(i);
    }
    if(num_points_parametric>0)
    {
        for (int i=num_points; i<num_total_points; ++i)
        {
            float x=pointsPGCoordinates[i-num_points][0]-mMinimumFc;
            float y=pointsPGCoordinates[i-num_points][1]-mMinimumSc;
            float z=pointsPGCoordinates[i-num_points][2]-mMinimumAltitude;
            float nx=0.0;
            float ny=0.0;
            float nz=1.0;
            float r=0.;//((float)mPointsRed[i])*mRGBColorToUnit;
            float g=0.;//((float)mPointsGreen[i])*mRGBColorToUnit;
            float b=0.;//((float)mPointsBlue[i])*mRGBColorToUnit;
            vertices[i] = new Vertex(x, y, z, nx, ny, nz);
            vertices[i]->set_color(Colorf(r, g, b));
            vertices[i]->set_index(i);
        }
    }

//    mPointSet->set_vertices(vertices, num_points);
    pointSet->set_vertices(vertices, num_total_points);

    //    mMainCanvas->setPointSet(mPointSet);
    mMainCanvas->setPointSet(pointSet);

    setCurrentPointCloudFile(dbFileName);
    showStatusMessage(tr("File loaded"), 500);
    assignColorByClassification();
    if(!existsClassification)
    {
        if(existsRGB)
        {
            assignColorByRGB();
        }
        else
        {
            assignColorByHeight();
        }
    }
    return(true);
}

bool PCDViewerMainWindow::resetUpdatedPoints(QString &strError)
{
    mUpdatedPointsIdInTileTable.clear();
    return(true);
}

bool PCDViewerMainWindow::setModelDbManager(ModelDb::ModelDbManager *ptrModelDbManager,
                                            QString modelProjectSpatialiteDbFileName,
                                            QString strError)
{
    QString strAuxError;
    if(!ptrModelDbManager->openModelProjectSpatialiteDb(modelProjectSpatialiteDbFileName,
                                                        strAuxError))
    {
        strError=QObject::tr("PCDViewerMainWindow::setModelDbManager");
        strError+=QObject::tr("\nError opening model project spatialite database:\n%1")
                .arg(modelProjectSpatialiteDbFileName);
        return(false);
    }
    mPtrModelDbManager=ptrModelDbManager;
    mModelProjectSpatialiteDbFileName=modelProjectSpatialiteDbFileName;
    ui->actionAssignColorByObjectClassification->setEnabled(true);
    ui->modelingObjectsProcessingPage->setEnabled(true);
}

void PCDViewerMainWindow::assignColorByClassification()
{
    if(mMainCanvas->pointSet()==NULL)
    {
        return;
    }
    int numberOfPoints=mMainCanvas->pointSet()->nb_vertices();
    double classColorToUnit=1.0/255.0;
    for(int nv=0;nv<numberOfPoints;nv++)
    {
        if(mPointsPGDbId[nv]!=-1) // es de geometria parametrica
        {
            mMainCanvas->pointSet()->vertices()[nv]->set_visible(false);
            continue;
        }
        int classId=mPointsClassNew[nv];
        mMainCanvas->pointSet()->vertices()[nv]->set_visible(mVisibleClassesByClassId[classId]);
        bool isRemoved=mPointsRemoved[nv];
        int classColorRed=0;
        int classColorGreen=0;
        int classColorBlue=0;
        int classColorAlpha=255;
//        if(!mClassColorByClassId.contains(classId))
//        {
//            strError=QObject::tr("PCDViewerMainWindow::setModelDbManager");
//            strError+=QObject::tr("\nError opening model project spatialite database:\n%1")
//                    .arg(modelProjectSpatialiteDbFileName);
//            return(false);
//        }
        if(!isRemoved
                &&mClassColorByClassId.contains(classId))
        {
            classColorRed=mClassColorByClassId[classId][0];
            classColorGreen=mClassColorByClassId[classId][1];
            classColorBlue=mClassColorByClassId[classId][2];
            classColorAlpha=mClassColorByClassId[classId][3];
        }
        else
        {
            classColorRed=mClassColorByClassId[mClassIdRemovedPoints][0];
            classColorGreen=mClassColorByClassId[mClassIdRemovedPoints][1];
            classColorBlue=mClassColorByClassId[mClassIdRemovedPoints][2];
            classColorAlpha=mClassColorByClassId[mClassIdRemovedPoints][3];
        }
        float r=classColorRed*classColorToUnit;
        float g=classColorGreen*classColorToUnit;
        float b=classColorBlue*classColorToUnit;
        Colorf color(r, g, b);
//        mPointSet->vertices()[nv]->set_color(color);
        mMainCanvas->pointSet()->vertices()[nv]->set_color(color);
    }

    QMap<int,QString>::const_iterator iterClass=mClassNameByClassId.begin();
    bool removeVertexGroups=false;
    if(mVertexGroupByClassId.size()!=0)
    {
        while(iterClass!=mClassNameByClassId.end())
        {
            int classId=iterClass.key();
            mMainCanvas->pointSet()->remove_vertex_group(mVertexGroupByClassId[classId]);
            iterClass++;
            delete(mVertexGroupByClassId[classId]);
        }
        mVertexGroupByClassId.clear();
    }
    if(mVertexGroupByObjectId.size()>0)
    {
        int objectId=MODELDBMANAGERDEFINITIONS_NO_OBJECT_ID;
        mMainCanvas->pointSet()->remove_vertex_group(mVertexGroupByObjectId[objectId]);
        delete(mVertexGroupByObjectId[objectId]);
        QMap<int,QString>::const_iterator iterObject=mObjectNameByObjectDbId.begin();
        while(iterObject!=mObjectNameByObjectDbId.end())
        {
            int objectId=iterObject.key();
            if(objectId==MODELDBMANAGERDEFINITIONS_NO_OBJECT_ID)
            {
                iterObject++;
                continue;
            }
            mMainCanvas->pointSet()->remove_vertex_group(mVertexGroupByObjectId[objectId]);
            iterObject++;
            delete(mVertexGroupByObjectId[objectId]);
        }
        mVertexGroupByObjectId.clear();
    }
    iterClass=mClassNameByClassId.begin();
    while(iterClass!=mClassNameByClassId.end())
    {
        int classId=iterClass.key();
        QString className=iterClass.value();
        int classColorRed=mClassColorByClassId[classId][0];
        int classColorGreen=mClassColorByClassId[classId][1];
        int classColorBlue=mClassColorByClassId[classId][2];
        int classColorAlpha=mClassColorByClassId[classId][3];
        float r=classColorRed*classColorToUnit;
        float g=classColorGreen*classColorToUnit;
        float b=classColorBlue*classColorToUnit;
        Colorf color(r, g, b);
        VertexGroup* vertexGroup = new VertexGroup;
        std::string label=className.toLower().toStdString();
        vertexGroup->set_label(label);
        vertexGroup->set_color(color);
        mVertexGroupByClassId[classId]=vertexGroup;
        iterClass++;
    }
    for (int i=0; i<numberOfPoints; ++i)
    {
        if(mPointsPGDbId[i]!=-1) // es de geometria parametrica
        {
            continue;
        }
        int classId=mPointsClassNew[i];
        bool isRemoved=mPointsRemoved[i];
        if(isRemoved)
        {
            mVertexGroupByClassId[mClassIdRemovedPoints]->push_back(mMainCanvas->pointSet()->vertices()[i]);
        }
        else
        {
            if(mVertexGroupByClassId.contains(classId))
            {
                mVertexGroupByClassId[classId]->push_back(mMainCanvas->pointSet()->vertices()[i]);
            }
        }
    }
    iterClass=mClassNameByClassId.begin();
    while(iterClass!=mClassNameByClassId.end())
    {
        int classId=iterClass.key();
//        mPointSet->add_vertex_group(mVertexGroupByClassId[classId]);
        mMainCanvas->pointSet()->add_vertex_group(mVertexGroupByClassId[classId]);
        iterClass++;
    }
    mMainCanvas->updateCanvas();
    ui->manualEditingProcessesPage->setEnabled(true);
    ui->modelingObjectsProcessingPage->setEnabled(false);
    ui->toolBox->setCurrentIndex(0);
}

void PCDViewerMainWindow::assignColorByObjectClassification()
{
    if(mMainCanvas->pointSet()==NULL)
    {
        return;
    }
    double classColorToUnit=mObjectClassRGBColorToUnit;
    int numberOfPoints=mMainCanvas->pointSet()->nb_vertices();
    for(int nv=0;nv<numberOfPoints;nv++)
    {
        int classColorRed,classColorGreen,classColorBlue,classColorAlpha;
        bool visible=true;
        int objectId,objectClassId;
        if(mPointsPGDbId[nv]==-1)
        {
            objectId=mPointsObjectDbId[nv];
            objectClassId=mObjectClassDbIdByObjectDbId[objectId];
            if(!mVisibleObjectClassesByObjectClassId[objectClassId])
            {
                visible=false;
            }
            else
            {
                if(!mVisibleObjectsByObjectId[objectId])
                {
                    visible=false;
                }
            }
        }
        else
        {
            int pgDbId=mPointsPGDbId[nv];
            objectId=mPGObjectDbIdByPGDbId[pgDbId];
            objectClassId=mObjectClassDbIdByObjectDbId[objectId];
            if(!mVisibleObjectClassesByObjectClassId[objectClassId])
            {
                visible=false;
            }
            else
            {
                if(!mVisibleObjectsByObjectId[objectId])
                {
                    visible=false;
                }
            }
            if(!mVisiblePGObjectClassesByObjectClassId[objectClassId])
            {
                visible=false;
            }
            else
            {
                if(!mVisiblePGPByGDbId[pgDbId])
                {
                    visible=false;
                }
            }
        }
        mMainCanvas->pointSet()->vertices()[nv]->set_visible(visible);
//        bool isRemoved=mPointsRemoved[nv];
//        if(!isRemoved)
//        {
            classColorRed=mObjectClassColorByObjectClassId[objectClassId][0];
            classColorGreen=mObjectClassColorByObjectClassId[objectClassId][1];
            classColorBlue=mObjectClassColorByObjectClassId[objectClassId][2];
            classColorAlpha=mObjectClassColorByObjectClassId[objectClassId][3];
//        }
//        else
//        {
//            classColorRed=mClassColorByClassId[mClassIdRemovedPoints][0];
//            classColorGreen=mClassColorByClassId[mClassIdRemovedPoints][1];
//            classColorBlue=mClassColorByClassId[mClassIdRemovedPoints][2];
//            classColorAlpha=mClassColorByClassId[mClassIdRemovedPoints][3];
//        }
        /*
        if(objectId!=-1)
        {
            int objectClassId=mObjectClassDbIdByObjectDbId[objectId];
            bool visible=true;
            if(!mVisibleObjectClassesByObjectClassId[objectClassId])
            {
                visible=false;
            }
            else
            {
                if(!mVisibleObjectsByObjectId[objectId])
                {
                    visible=false;
                }
            }
            mMainCanvas->pointSet()->vertices()[nv]->set_visible(visible);
//            bool isRemoved=mPointsRemoved[nv];
//            if(!isRemoved)
//            {
                classColorRed=mObjectClassColorByObjectClassId[objectClassId][0];
                classColorGreen=mObjectClassColorByObjectClassId[objectClassId][1];
                classColorBlue=mObjectClassColorByObjectClassId[objectClassId][2];
                classColorAlpha=mObjectClassColorByObjectClassId[objectClassId][3];
//            }
//            else
//            {
//                classColorRed=mClassColorByClassId[mClassIdRemovedPoints][0];
//                classColorGreen=mClassColorByClassId[mClassIdRemovedPoints][1];
//                classColorBlue=mClassColorByClassId[mClassIdRemovedPoints][2];
//                classColorAlpha=mClassColorByClassId[mClassIdRemovedPoints][3];
//            }
        }
        else
        {
            classColorRed=PCDVIEWERMAINWINDOW_COMBOCHECKBOX_NO_COLOR_RED;
            classColorGreen=PCDVIEWERMAINWINDOW_COMBOCHECKBOX_NO_COLOR_RED;
            classColorBlue=mClassColorByClassId[mClassIdRemovedPoints][2];
            classColorAlpha=mClassColorByClassId[mClassIdRemovedPoints][3];
        }
        */
        float r=classColorRed*classColorToUnit;
        float g=classColorGreen*classColorToUnit;
        float b=classColorBlue*classColorToUnit;
        Colorf color(r, g, b);
//        mPointSet->vertices()[nv]->set_color(color);
        mMainCanvas->pointSet()->vertices()[nv]->set_color(color);
    }

//    const std::vector<VertexGroup*> vertexGroups=mMainCanvas->pointSet()->vertex_groups();
//    for(int i=0;i<vertexGroups.size();i++)
//    {
//        VertexGroup* vertexG
//    }
    // Eliminar los grupos de vertices existentes
    // Caso de que existan por estar previamente visualizado por clases
    if(mVertexGroupByClassId.size()>0)
    {
        QMap<int,QString>::const_iterator iterClass=mClassNameByClassId.begin();
        while(iterClass!=mClassNameByClassId.end())
        {
            int classId=iterClass.key();
            mMainCanvas->pointSet()->remove_vertex_group(mVertexGroupByClassId[classId]);
            iterClass++;
            delete(mVertexGroupByClassId[classId]);
        }
        mVertexGroupByClassId.clear();
    }
    if(mVertexGroupByObjectId.size()>0)
    {
        int objectId=MODELDBMANAGERDEFINITIONS_NO_OBJECT_ID; // por si no hay puntos sin asignar
        mMainCanvas->pointSet()->remove_vertex_group(mVertexGroupByObjectId[objectId]);
        delete(mVertexGroupByObjectId[objectId]);
        QMap<int,QString>::const_iterator iterObject=mObjectNameByObjectDbId.begin();
        while(iterObject!=mObjectNameByObjectDbId.end())
        {
            int objectId=iterObject.key();
            if(objectId==MODELDBMANAGERDEFINITIONS_NO_OBJECT_ID)
            {
                iterObject++;
                continue;
            }
            mMainCanvas->pointSet()->remove_vertex_group(mVertexGroupByObjectId[objectId]);
            iterObject++;
            delete(mVertexGroupByObjectId[objectId]);
        }
        mVertexGroupByObjectId.clear();
    }
    // grupo para los puntos que no pertenecen a objetos
    {
        QString objectName=MODELDBMANAGERDEFINITIONS_NO_OBJECT_NAME;
        int objectId=MODELDBMANAGERDEFINITIONS_NO_OBJECT_ID;
        int classColorRed=mObjectClassColorByObjectClassId[MODELDBMANAGERDEFINITIONS_NO_OBJECT_CLASS_ID][0];
        int classColorGreen=mObjectClassColorByObjectClassId[MODELDBMANAGERDEFINITIONS_NO_OBJECT_CLASS_ID][1];
        int classColorBlue=mObjectClassColorByObjectClassId[MODELDBMANAGERDEFINITIONS_NO_OBJECT_CLASS_ID][2];
        int classColorAlpha=mObjectClassColorByObjectClassId[MODELDBMANAGERDEFINITIONS_NO_OBJECT_CLASS_ID][3];
        float r=classColorRed*classColorToUnit;
        float g=classColorGreen*classColorToUnit;
        float b=classColorBlue*classColorToUnit;
        Colorf color(r, g, b);
        VertexGroup* vertexGroup = new VertexGroup;
        std::string label=objectName.toLower().toStdString();
        vertexGroup->set_label(label);
        vertexGroup->set_color(color);
        mVertexGroupByObjectId[objectId]=vertexGroup;
    }
    QMap<int,QString>::const_iterator iterObject=mObjectNameByObjectDbId.begin();
    while(iterObject!=mObjectNameByObjectDbId.end())
    {
        int objectId=iterObject.key();
        if(objectId==MODELDBMANAGERDEFINITIONS_NO_OBJECT_ID)
        {
            iterObject++;
            continue;
        }
        QString objectName=iterObject.value();
        int objectClassId=mObjectClassDbIdByObjectDbId[objectId];
        int classColorRed=mObjectClassColorByObjectClassId[objectClassId][0];
        int classColorGreen=mObjectClassColorByObjectClassId[objectClassId][1];
        int classColorBlue=mObjectClassColorByObjectClassId[objectClassId][2];
        int classColorAlpha=mObjectClassColorByObjectClassId[objectClassId][3];
        float r=classColorRed*classColorToUnit;
        float g=classColorGreen*classColorToUnit;
        float b=classColorBlue*classColorToUnit;
        Colorf color(r, g, b);
        VertexGroup* vertexGroup = new VertexGroup;
        std::string label=objectName.toLower().toStdString();
        vertexGroup->set_label(label);
        vertexGroup->set_color(color);
        mVertexGroupByObjectId[objectId]=vertexGroup;
        iterObject++;
    }
    for (int i=0; i<numberOfPoints; ++i)
    {
        int objectId;
        if(mPointsPGDbId[i]==-1)
        {
            objectId=mPointsObjectDbId[i];
        }
        else
        {
            continue;
        }
        if(mVertexGroupByObjectId.contains(objectId))
        {
            mVertexGroupByObjectId[objectId]->push_back(mMainCanvas->pointSet()->vertices()[i]);
        }
    }
    {
        int objectId=-1;
        mMainCanvas->pointSet()->add_vertex_group(mVertexGroupByObjectId[objectId]);
    }
    iterObject=mObjectNameByObjectDbId.begin();
    while(iterObject!=mObjectNameByObjectDbId.end())
    {
        int objectId=iterObject.key();
        if(objectId==MODELDBMANAGERDEFINITIONS_NO_OBJECT_ID)
        {
            iterObject++;
            continue;
        }
//        mPointSet->add_vertex_group(mVertexGroupByClassId[classId]);
        mMainCanvas->pointSet()->add_vertex_group(mVertexGroupByObjectId[objectId]);
        iterObject++;
    }
    mMainCanvas->updateCanvas();
    ui->manualEditingProcessesPage->setEnabled(false);
    ui->modelingObjectsProcessingPage->setEnabled(true);
    ui->toolBox->setCurrentIndex(1);
}

void PCDViewerMainWindow::assignColorByHeight()
{
//    if(mPointSet==NULL)
//    {
//        return;
//    }
    if(mMainCanvas->pointSet()==NULL)
    {
        return;
    }
    float factor = 256.0f / (mMaximumAltitude - mMinimumAltitude);
    double classColorToUnit=mObjectClassRGBColorToUnit;
//    Vertex** vertices=mPointSet->vertices();
//    int numberOfVertices=mPointSet->nb_vertices();
    Vertex** vertices=mMainCanvas->pointSet()->vertices();
    int numberOfVertices=mMainCanvas->pointSet()->nb_vertices();
    for (int i=0; i<numberOfVertices; ++i)
    {
        if(mPointsPGDbId[i]!=-1)
        {
            mMainCanvas->pointSet()->vertices()[i]->set_visible(false);
            continue;
        }
        Vertex* v = vertices[i];
//        int index = static_cast<int>((v->point().z() - mMinimumAltitude) * factor);
        int index = static_cast<int>((v->point().z() - 0.) * factor);
        const Colorf& color = Global::color_from_table(index);
//        float grayHeightColor=(v->point().z() - mMinimumAltitude) * factor;
//        float grayHeightColor=v->point().z() * factor;
//        float r=grayHeightColor*classColorToUnit;
//        float g=grayHeightColor*classColorToUnit;
//        float b=grayHeightColor*classColorToUnit;
//        Colorf color(r, g, b);
        v->set_color(color);
        int classId=mPointsClassNew[i];
        mMainCanvas->pointSet()->vertices()[i]->set_visible(mVisibleClassesByClassId[classId]);
    }
    mMainCanvas->updateCanvas();
    ui->manualEditingProcessesPage->setEnabled(true);
    ui->modelingObjectsProcessingPage->setEnabled(false);
    ui->toolBox->setCurrentIndex(0);
}

void PCDViewerMainWindow::assignColorByRGB()
{
    if(mMainCanvas->pointSet()==NULL)
    {
        return;
    }
    for(int nv=0;nv<mPointsClassNew.size();nv++)
    {
        if(mPointsPGDbId[nv]!=-1)
        {
            mMainCanvas->pointSet()->vertices()[nv]->set_visible(false);
            continue;
        }
        int classId=mPointsClassNew[nv];
        int red=mPointsRed[nv];
        int green=mPointsGreen[nv];
        int blue=mPointsBlue[nv];
//        int classColorAlpha=mClassColorByClassId[classId][3];
        float r=((float)mPointsRed[nv])*mRGBColorToUnit;
        float g=((float)mPointsGreen[nv])*mRGBColorToUnit;
        float b=((float)mPointsBlue[nv])*mRGBColorToUnit;
        Colorf color(r, g, b);
//        mPointSet->vertices()[nv]->set_color(color);
        mMainCanvas->pointSet()->vertices()[nv]->set_color(color);
        mMainCanvas->pointSet()->vertices()[nv]->set_visible(mVisibleClassesByClassId[classId]);
    }
    mMainCanvas->updateCanvas();
    ui->manualEditingProcessesPage->setEnabled(true);
    ui->modelingObjectsProcessingPage->setEnabled(false);
    ui->toolBox->setCurrentIndex(0);
}

void PCDViewerMainWindow::operationModeChanged(QAction* act)
{
    if (act == ui->actionSceneManipulation)
    {
        mMainCanvas->sceneManipulation();
    }
    else if (act == ui->actionSelectPointsByRectangle)
    {
        mMainCanvas->selectPointsByRectangle();        
    }
    else if (act == ui->actionSelectPointsByRectangle)
    {
        mMainCanvas->selectPointsByLasso();
    }
    else if (act == ui->actionSelectPointsByFreehand)
    {
        mMainCanvas->selectPointsByLasso();
    }
    else if (act == ui->actionUnselectPoints)
    {
        this->unselectPoints();
    }
    // no se pueden seleccionar puntos de geometrias parametricas
    Vertex** vertices=mMainCanvas->pointSet()->vertices();
    int numberOfVertices=mMainCanvas->pointSet()->nb_vertices();
    for (int i=0; i<numberOfVertices; ++i)
    {
        if(mPointsPGDbId[i]!=-1)
        {
            Vertex* v = vertices[i];
            v->set_selected(false);
        }
    }
    mMainCanvas->updateCanvas();
}

SceneGraph* PCDViewerMainWindow::output(const std::string& msg)
{
    std::cout << msg ;

    ui->plainTextEditOutput->moveCursor(QTextCursor::End);
    ui->plainTextEditOutput->insertPlainText(QString::fromStdString(msg));
    ui->plainTextEditOutput->repaint();
    ui->plainTextEditOutput->update();
    return mMainCanvas;
}

bool PCDViewerMainWindow::existsPoints()
{
    if(mPointsFc.size()>0)
    {
        return(true);
    }
    return(false);
}

bool PCDViewerMainWindow::getUpdatedPoints(QMap<int, QString> &tilesTableNamesById,
                                           QVector<int> &pointsTilesTableNameId,
                                           QVector<int> &pointsIdInTileTable,
                                           QString &strError)
{
    tilesTableNamesById.clear();
    pointsTilesTableNameId.clear();
    pointsIdInTileTable.clear();
    for(int np=0;np<mUpdatedPointsIdInTileTable.size();np++)
    {
        int pointIdInTileTable=mPointsIdInTileTable[mUpdatedPointsIdInTileTable[np]];
        int pointTileTableNameId=mPointsTilesTableNameId[mUpdatedPointsIdInTileTable[np]];
        QString tileTableName=mTilesTableNamesById[pointTileTableNameId];
        pointsIdInTileTable.push_back(pointIdInTileTable);
        pointsTilesTableNameId.push_back(pointTileTableNameId);
        if(!tilesTableNamesById.contains(pointTileTableNameId))
        {
            tilesTableNamesById[pointTileTableNameId]=tileTableName;
        }
    }
    return(true);
}

bool PCDViewerMainWindow::savePointCloud(const QString &fileName)
{
//    if (mPointSet == NULL)
//        return false;
    if (mMainCanvas->pointSet() == NULL)
        return false;
//    bool result = FileIO::save_point_cloud(mPointSet, fileName.toStdString());
    bool result = FileIO::save_point_cloud(mMainCanvas->pointSet(), fileName.toStdString());
    if (result)
    {
//		setCurrentPointCloudFile(fileName);
        showStatusMessage(tr("File saved"), 500);
        return true;
    }
    else
    {
        showStatusMessage(tr("Saving failed"), 500);
        return false;
    }
}

bool PCDViewerMainWindow::setSymbology(QString fileName,
                                       QString &strError)
{
    mClassColorByClassId.clear();
    mClassNameByClassId.clear();
    mClassIdRemovedPoints=-99;
    if(!QFile::exists(fileName))
    {
        strError=QObject::tr("PCDViewerMainWindow::setSymbology");
        strError+=QObject::tr("\nNot exists symbology file:\n%1").arg(fileName);
        return(false);
    }
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        strError=QObject::tr("PCDViewerMainWindow::setSymbology");
        strError+=QObject::tr("\nError opening symbology file:\n%1").arg(fileName);
        return(false);
    }
    QTextStream in(&file);
    int nline=0;
    QString strSeparator=PCDVIEWERMAINWINDOW_SYMBOLOGY_FILE_STRING_SEPARATOR;
    while(!in.atEnd())
    {
        nline++;
        QString strLine=in.readLine();
        strLine=strLine.trimmed();
//        if(!strSeparator.isEmpty())
//            strLine=strLine.replace(strSeparator,strBlankSeparator);
        QStringList strList;
        if(!strLine.isEmpty())
        {
//            QStringList strList=strLine.split(QRegExp("\\s+"));
            strList=strLine.split(strSeparator);
            int numberOfItemsInLine=strList.size();
            if(numberOfItemsInLine!=PCDVIEWERMAINWINDOW_SYMBOLOGY_FILE_NUMBER_OF_ITEMS)
            {
                strError=QObject::tr("PCDViewerMainWindow::setSymbology");
                strError+=QObject::tr("\nThere are no %1 items in line %2 in symbology file:\n%3")
                        .arg(QString::number(PCDVIEWERMAINWINDOW_SYMBOLOGY_FILE_NUMBER_OF_ITEMS))
                        .arg(QString::number(nline)).arg(fileName);
                return(false);
            }
        }
        else
        {
            continue;
        }
        int id,red,green,blue,alpha;
        QString name;
        bool isRemoved=false;
        for(int nf=1;nf<=PCDVIEWERMAINWINDOW_SYMBOLOGY_FILE_NUMBER_OF_ITEMS;nf++)
        {
            QString fieldValue=strList.at(nf-1);
            int intValue;
            if(nf==PCDVIEWERMAINWINDOW_SYMBOLOGY_FILE_ITEM_CLASS_ID
                    ||nf==PCDVIEWERMAINWINDOW_SYMBOLOGY_FILE_ITEM_CLASS_COLOR_RED
                    ||nf==PCDVIEWERMAINWINDOW_SYMBOLOGY_FILE_ITEM_CLASS_COLOR_GREEN
                    ||nf==PCDVIEWERMAINWINDOW_SYMBOLOGY_FILE_ITEM_CLASS_COLOR_BLUE
                    ||nf==PCDVIEWERMAINWINDOW_SYMBOLOGY_FILE_ITEM_CLASS_COLOR_ALPHA)
            {
                bool okToInt=false;
                intValue=fieldValue.toInt(&okToInt);
                if(!okToInt)
                {
                    strError=QObject::tr("PCDViewerMainWindow::setSymbology");
                    strError+=QObject::tr("\nNo integer value in field number %1 in line %2 in symbology file:\n%3")
                            .arg(QString::number(nf))
                            .arg(QString::number(nline)).arg(fileName);
                    return(false);
                }
            }
            if(nf==PCDVIEWERMAINWINDOW_SYMBOLOGY_FILE_ITEM_CLASS_COLOR_RED
                    ||nf==PCDVIEWERMAINWINDOW_SYMBOLOGY_FILE_ITEM_CLASS_COLOR_GREEN
                    ||nf==PCDVIEWERMAINWINDOW_SYMBOLOGY_FILE_ITEM_CLASS_COLOR_BLUE
                    ||nf==PCDVIEWERMAINWINDOW_SYMBOLOGY_FILE_ITEM_CLASS_COLOR_ALPHA)
            {
                if(intValue<PCDVIEWERMAINWINDOW_SYMBOLOGY_FILE_ITEM_CLASS_COLOR_MINIMUM_VALUE
                        ||intValue>PCDVIEWERMAINWINDOW_SYMBOLOGY_FILE_ITEM_CLASS_COLOR_MAXIMUM_VALUE)
                {
                    strError=QObject::tr("PCDViewerMainWindow::setSymbology");
                    strError+=QObject::tr("\nValue in field number %1 out of domain [%2,%3] in line %4 in symbology file:\n%4")
                            .arg(QString::number(nf))
                            .arg(QString::number(PCDVIEWERMAINWINDOW_SYMBOLOGY_FILE_ITEM_CLASS_COLOR_MINIMUM_VALUE))
                            .arg(QString::number(PCDVIEWERMAINWINDOW_SYMBOLOGY_FILE_ITEM_CLASS_COLOR_MAXIMUM_VALUE))
                            .arg(QString::number(nline)).arg(fileName);
                    return(false);
                }
            }
            if(nf==PCDVIEWERMAINWINDOW_SYMBOLOGY_FILE_ITEM_CLASS_ID)
            {
                if(mClassNameByClassId.contains(intValue))
                {
                    strError=QObject::tr("PCDViewerMainWindow::setSymbology");
                    strError+=QObject::tr("\nRepeat class id value %1 in line %2 in symbology file:\n%3")
                            .arg(QString::number(intValue))
                            .arg(QString::number(nline)).arg(fileName);
                    return(false);
                }
                id=intValue;
            }
            if(nf==PCDVIEWERMAINWINDOW_SYMBOLOGY_FILE_ITEM_CLASS_NAME)
            {
                name=fieldValue;
                if(name.compare(PCDVIEWERMAINWINDOW_SYMBOLOGY_REMOVED_POINTS_TAG_1,Qt::CaseInsensitive)==0
                        ||name.compare(PCDVIEWERMAINWINDOW_SYMBOLOGY_REMOVED_POINTS_TAG_1,Qt::CaseInsensitive)==0)
                {
                    isRemoved=true;
                }
            }
            if(nf==PCDVIEWERMAINWINDOW_SYMBOLOGY_FILE_ITEM_CLASS_COLOR_RED)
            {
                red=intValue;
            }
            if(nf==PCDVIEWERMAINWINDOW_SYMBOLOGY_FILE_ITEM_CLASS_COLOR_GREEN)
            {
                green=intValue;
            }
            if(nf==PCDVIEWERMAINWINDOW_SYMBOLOGY_FILE_ITEM_CLASS_COLOR_BLUE)
            {
                blue=intValue;
            }
            if(nf==PCDVIEWERMAINWINDOW_SYMBOLOGY_FILE_ITEM_CLASS_COLOR_ALPHA)
            {
                alpha=intValue;
            }
        }
        QVector<int> color(4);
        color[0]=red;
        color[1]=green;
        color[2]=blue;
        color[3]=alpha;
        mClassNameByClassId[id]=name;
        mClassColorByClassId[id]=color;
        if(isRemoved)
        {
            mClassIdRemovedPoints=id;
        }
    }
    if(mClassIdRemovedPoints==-99)
    {
        strError=QObject::tr("PCDViewerMainWindow::setSymbology");
        strError+=QObject::tr("\nThere is no symbology for removed points in symbology file:\n%1")
                .arg(fileName);
        return(false);
    }
    file.close();
    return(true);
}

void PCDViewerMainWindow::setCurrentPointCloudFile(const QString &fileName)
{
    mCurrentPointCloudFileName = fileName;
    curDataDirectory_ = fileName.left(fileName.lastIndexOf("/"));

    setWindowModified(false);

    QString shownName = "Untitled";
    if (!mCurrentPointCloudFileName.isEmpty())
    {
        shownName = strippedName(mCurrentPointCloudFileName);
//		recentFiles_.removeAll(mCurrentPointCloudFileName);
//		recentFiles_.prepend(mCurrentPointCloudFileName);
//        updateRecentFileActions();
    }

    setWindowTitle(tr("%1[*] - %2").arg(shownName).arg(tr("Point Cloud Viewer")));
}

void PCDViewerMainWindow::setFullScreen(bool b)
{
    if (b)
        showFullScreen();
    else
        showMaximized();
}

void PCDViewerMainWindow::showCoordinateUnderMouse(const Point3f& p, bool found)
{
    if (found)
    {
        QString coordString = QString(" XYZ = [%1, %2, %3]")
                .arg(QString::number(p.x()+mMinimumFc,'f',3))
                .arg(QString::number(p.y()+mMinimumSc,'f',3))
                .arg(QString::number(p.z()+mMinimumAltitude,'f',3));
//                .arg(p.y()).arg(p.z());
        coordinateUnderMouseLabel->setText(coordString);
    }
    else
    {
//        coordinateUnderMouseLabel->setText(" XYZ = [-0.0, -0.0, -0.0]");
        coordinateUnderMouseLabel->setText(" No point select");
    }
}

void PCDViewerMainWindow::showPixelPositionUnderMouse(const QPoint& p)
{
    QString coordString = QString(" XY = [%1, %2]").arg(p.x()).arg(p.y());
    coordinateUnderMouseLabel->setText(coordString);
}

void PCDViewerMainWindow::showStatusMessage(const QString &text, int timeout/* = 0*/)
{
    statusBar()->showMessage(text, timeout);
    updateStatusBar();
}

QString PCDViewerMainWindow::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}

void PCDViewerMainWindow::unselectPoints()
{
//    Vertex** vertices=mPointSet->vertices();
//    int numberOfVertices=mPointSet->nb_vertices();
    Vertex** vertices=mMainCanvas->pointSet()->vertices();
    int numberOfVertices=mMainCanvas->pointSet()->nb_vertices();
    for (int i=0; i<numberOfVertices; ++i)
    {
        Vertex* v = vertices[i];
        if(v->is_selected())
        {
            v->set_selected(false);
        }
    }
    mMainCanvas->updateCanvas();
}

void PCDViewerMainWindow::treeItemDataChanged(QTreeWidgetItem* it, int col)
{
    if (col == 1)
    {// change label
        TreeWidgetItem* item = dynamic_cast<TreeWidgetItem*>(it);
        std::string new_label = item->data(col, Qt::DisplayRole).toString().toStdString();

        // replace all spaces with '-'
        for (unsigned int i=0; i<new_label.size(); ++i)
        {
            char c = new_label[i];
            if (c == ' ')
                new_label[i] = '-';
        }

        item->setData(col, Qt::DisplayRole, QString::fromStdString(new_label));

        VertexGroup* g = item->vertex_group();
        g->set_label(new_label);
    }
    else if (col == 2)
    {// change confidence
        TreeWidgetItem* item = dynamic_cast<TreeWidgetItem*>(it);
        float new_conf = item->data(col, Qt::DisplayRole).toFloat();
        item->setData(col, Qt::DisplayRole, new_conf);

        VertexGroup* g = item->vertex_group();
        g->set_confidence(new_conf);
    }
}

void PCDViewerMainWindow::clearPoints()
{
    mTilesTableNamesById.clear();
    mPointsTilesTableNameId.clear();
    mPointsIdInTileTable.clear();
    mPointsGpsTime.clear();
    mPointsBlue.clear();
    mPointsRed.clear();
    mPointsGreen.clear();
    mPointsNir.clear();
    mPointsIntensity.clear();
    mPointsReturns.clear();
    mPointsReturn.clear();
    mPointsClass.clear();
    mPointsClassNew.clear();
    mPointsRemoved.clear();
    mPointsFc.clear();
    mPointsSc.clear();
    mPointsHeight.clear();
    mPointsAltitude.clear();
    mUpdatedPointsIdInTileTable.clear();
    mPointsPGDbId.clear();
//    if(mPointSet!=NULL)
//    {
//        delete(mPointSet);
//    }
}

void PCDViewerMainWindow::updateAnnotationTable()
{
    PointSet* ps = mMainCanvas->pointSet();
    if (ps == nil)
        return;

    // clear current :-) tricky
    ui->treeWidget->setCurrentItem(nil);

    //////////////////////////////////////////////////////////////////////////

    std::vector<VertexGroup*>& groups = ps->vertex_groups();
    unsigned int item_count = ui->treeWidget->topLevelItemCount();

    // step 1. remove redundant top level tree items
    if (item_count > groups.size())
    { // remove items that will not be used
        unsigned int num_to_remove = item_count - groups.size();
        for (unsigned int i=0; i<num_to_remove; ++i)
        {
            // remove last top level item
            int idx_top_item = ui->treeWidget->topLevelItemCount() - 1;
            QTreeWidgetItem* top_item = ui->treeWidget->topLevelItem(idx_top_item);
            // delete item; // no need, Qt will do this

            ui->treeWidget->takeTopLevelItem(idx_top_item);
            //treeWidget->removeItemWidget(top_item, 0);
        }
    }

    // step 1. remove redundant child level tree items
    item_count = ui->treeWidget->topLevelItemCount();
    for (unsigned int i=0; i<item_count; ++i)
    {
        if (groups.size() > i)
        { // make sure the group corresponding to current item does exist
            QTreeWidgetItem* top_item = ui->treeWidget->topLevelItem(i);

            unsigned int item_chld_count = top_item->childCount();
            unsigned int group_chld_count = groups[i]->children().size();
            if (item_chld_count > group_chld_count)
            {
                unsigned int num_chld_to_remove = item_chld_count - group_chld_count;
                for (unsigned int j=0; j<num_chld_to_remove; ++j)
                {
                    int idx_chld_item = top_item->childCount() - 1;
                    //top_item->removeChild(top_item->child(idx_chld_item));	// remove last child item
                    top_item->takeChild(idx_chld_item);	// remove last child item
                }
            }
        }
    }

    if (groups.empty())
        return;

    //////////////////////////////////////////////////////////////////////////

    for (unsigned int i=0; i<groups.size(); ++i)
    {
        TreeWidgetItem* item = dynamic_cast<TreeWidgetItem*>(ui->treeWidget->topLevelItem(i));
        if (item == nil)
        {
            item = new TreeWidgetItem;
            item->setFlags(item->flags() | Qt::ItemIsEditable);
            ui->treeWidget->addTopLevelItem(item);
        }

        VertexGroup* g = groups[i];
        Colorf		 c = g->color();
        QColor		 color(c.r() * 255, c.g() * 255, c.b() * 255);
        QString      label = QString::fromStdString(g->label());
        float		 conf = g->confidence();
        unsigned int num_point = g->size();

        item->set_vertex_group(g);
        item->setData(0, Qt::DisplayRole, i+1);
        item->setData(1, Qt::DecorationRole, color);
        item->setData(1, Qt::DisplayRole, label);
        item->setData(2, Qt::DisplayRole, conf);
        item->setData(3, Qt::DisplayRole, num_point);

        // the children
        std::vector<VertexGroup*> children = g->children();
        for (unsigned int j=0; j<children.size(); ++j)
        {
            VertexGroup* chd = children[j];

            c = chd->color();
            color = QColor(c.r() * 255, c.g() * 255, c.b() * 255);
            label = QString::fromStdString(chd->label());
            conf = chd->confidence();
            num_point = chd->size();

            TreeWidgetItem* chd_item = dynamic_cast<TreeWidgetItem*>(item->child(j));
            if (chd_item == nil)
            {
                chd_item = new TreeWidgetItem;
                chd_item->setFlags(chd_item->flags() | Qt::ItemIsEditable);
                item->addChild(chd_item);
            }

            chd_item->set_vertex_group(chd);
            chd_item->setData(0, Qt::DisplayRole, QString("(%1)").arg(j+1));
            chd_item->setData(1, Qt::DecorationRole, color);
            chd_item->setData(1, Qt::DisplayRole, label);
            chd_item->setData(2, Qt::DisplayRole, conf);
            chd_item->setData(3, Qt::DisplayRole, num_point);
        }
    }

    ui->treeWidget->update();
}

//void PCDViewerMainWindow::updateRecentFileActions()
//{
//	QMutableStringListIterator i(recentFiles_);
//	while (i.hasNext()) {
//		if (!QFile::exists(i.next()))
//			i.remove();
//	}

//	for (int j = 0; j < MaxRecentFiles; ++j) {
//		if (j < recentFiles_.count()) {
//			QString text = tr("&%1 %2").arg(j + 1).arg(strippedName(recentFiles_[j]));
//			actionsRecentFile[j]->setText(text);
//			actionsRecentFile[j]->setData(recentFiles_[j]);
//			actionsRecentFile[j]->setVisible(true);
//		} else {
//			actionsRecentFile[j]->setVisible(false);
//		}
//	}

//	actionSeparator->setVisible(!recentFiles_.isEmpty());
//}

void PCDViewerMainWindow::updateStatusBar()
{
    unsigned int nb_points = 0;
    unsigned int nb_groups = 0;
    PointSet* ps = mMainCanvas->pointSet();
    if (ps != nil)
    {
        nb_points = ps->nb_vertices();
        nb_groups = ps->vertex_groups().size();
    }

    numVerticesLabel->setText( QString("#points: %1").arg(nb_points) );
    numVertexGroupsLabel->setText( QString("#groups: %1").arg(nb_groups) );
}


void PCDViewerMainWindow::on_changeClassRadioButton_clicked()
{
    unenableAllClasses();
}

void PCDViewerMainWindow::on_selectOnlyRadioButton_clicked()
{
    unenableAllClasses();
}

void PCDViewerMainWindow::on_removeRadioButton_clicked()
{
    enableAllClasses();
}

void PCDViewerMainWindow::on_toOriginalClassRadioButton_clicked()
{
    enableAllClasses();
}

void PCDViewerMainWindow::on_unselectRadioButton_clicked()
{
    unenableAllClasses();
}

void PCDViewerMainWindow::on_recoverRadioButton_clicked()
{
    enableAllClasses();
}

void PCDViewerMainWindow::on_allClassesPushButton_clicked()
{
    int newClass = -1;
    actionWithSelectedPoints(newClass);
}

void PCDViewerMainWindow::on_toClass1PushButton_clicked()
{
    int newClass = 1;
    actionWithSelectedPoints(newClass);
}

void PCDViewerMainWindow::on_toClass2PushButton_clicked()
{
    int newClass = 2;
    actionWithSelectedPoints(newClass);
}

void PCDViewerMainWindow::on_toClass6PushButton_clicked()
{
    int newClass = 6;
    actionWithSelectedPoints(newClass);
}

void PCDViewerMainWindow::on_toClass3PushButton_clicked()
{
    int newClass = 3;
    actionWithSelectedPoints(newClass);
}

void PCDViewerMainWindow::on_toClass4PushButton_clicked()
{
    int newClass = 4;
    actionWithSelectedPoints(newClass);
}

void PCDViewerMainWindow::on_toClass5PushButton_clicked()
{
    int newClass = 5;
    actionWithSelectedPoints(newClass);
}

void PCDViewerMainWindow::on_toClass7PushButton_clicked()
{
    int newClass = 7;
    actionWithSelectedPoints(newClass);
}

void PCDViewerMainWindow::on_toClass9PushButton_clicked()
{
    int newClass = 9;
    actionWithSelectedPoints(newClass);
}

void PCDViewerMainWindow::on_toClass0PushButton_clicked()
{
    int newClass = 0;
    actionWithSelectedPoints(newClass);
}

void PCDViewerMainWindow::on_getAltitudeStatisticsForSelectedPointsPushButton_clicked()
{
    if(mMainCanvas->pointSet()==NULL)
    {
        return;
    }
    ui->meanAltitudeLineEdit->clear();
    ui->stdAltitudeLineEdit->clear();
    ui->altitudeDifferenceLineEdit->clear();
    ui->getDifferencesAltitudeForSelectedPointsPushButton->setEnabled(false);
    Vertex** vertices=mMainCanvas->pointSet()->vertices();
    int numberOfVertices=mMainCanvas->pointSet()->nb_vertices();
    QVector<int> selectedPointsIndex;
    QMap<QString,QVector<int> > pointsIdByTileTableName;
    for (int i=0; i<numberOfVertices; ++i)
    {
        Vertex* v = vertices[i];
        if(v->is_selected())
        {
            if(mPointsPGDbId[i]!=-1)
            {
                continue;
            }
            selectedPointsIndex.push_back(i);
            int tileTableNameId=mPointsTilesTableNameId[i];
            QString tileTableName=mTilesTableNamesById[tileTableNameId];
            if(!pointsIdByTileTableName.contains(tileTableName))
            {
                QVector<int> aux;
                pointsIdByTileTableName[tileTableName]=aux;
            }
            int pointIdInTileTable=mPointsIdInTileTable[i];
            pointsIdByTileTableName[tileTableName].push_back(pointIdInTileTable);
        }
    }
    if(selectedPointsIndex.size()==0)
    {
        QString title="PCDViewerMainWindow::actionWithSelectedPoints";
        QString msg=QObject::tr("No points selected");
        QMessageBox::information(this,title,msg);
        return;
    }
    double meanAltitude=0.0;
    for(int i=0;i<selectedPointsIndex.size();i++)
    {
        int pointIndexPosition=selectedPointsIndex[i];
        double altitude=mPointsAltitude[pointIndexPosition];
        meanAltitude+=altitude;
    }
    meanAltitude=meanAltitude/selectedPointsIndex.size();
    ui->meanAltitudeLineEdit->setText(QString::number(meanAltitude,'f',PCDVIEWERMAINWINDOW_LINEAR_PRECISION));
    if(selectedPointsIndex.size()>1)
    {
        double stdAltitude=0.0;
        for(int i=0;i<selectedPointsIndex.size();i++)
        {
            int pointIndexPosition=selectedPointsIndex[i];
            double altitude=mPointsAltitude[pointIndexPosition];
            stdAltitude+=pow(meanAltitude-altitude,2.0);
        }
        stdAltitude=sqrt(stdAltitude/(selectedPointsIndex.size()-1));
        ui->stdAltitudeLineEdit->setText(QString::number(stdAltitude,'f',PCDVIEWERMAINWINDOW_LINEAR_PRECISION));
    }
    ui->getDifferencesAltitudeForSelectedPointsPushButton->setEnabled(true);
}

void PCDViewerMainWindow::on_getDifferencesAltitudeForSelectedPointsPushButton_clicked()
{
    if(mMainCanvas->pointSet()==NULL)
    {
        return;
    }
    ui->altitudeDifferenceLineEdit->clear();
//    ui->getDifferencesAltitudeForSelectedPointsPushButton->setEnabled(false);
    Vertex** vertices=mMainCanvas->pointSet()->vertices();
    int numberOfVertices=mMainCanvas->pointSet()->nb_vertices();
    QVector<int> selectedPointsIndex;
    QMap<QString,QVector<int> > pointsIdByTileTableName;
    for (int i=0; i<numberOfVertices; ++i)
    {
        Vertex* v = vertices[i];
        if(v->is_selected())
        {
            if(mPointsPGDbId[i]!=-1)
            {
                continue;
            }
            selectedPointsIndex.push_back(i);
            int tileTableNameId=mPointsTilesTableNameId[i];
            QString tileTableName=mTilesTableNamesById[tileTableNameId];
            if(!pointsIdByTileTableName.contains(tileTableName))
            {
                QVector<int> aux;
                pointsIdByTileTableName[tileTableName]=aux;
            }
            int pointIdInTileTable=mPointsIdInTileTable[i];
            pointsIdByTileTableName[tileTableName].push_back(pointIdInTileTable);
        }
    }
    if(selectedPointsIndex.size()!=1)
    {
        QString title="PCDViewerMainWindow::actionWithSelectedPoints";
        QString msg=QObject::tr("No one point selected");
        QMessageBox::information(this,title,msg);
        return;
    }
    QString strMeanAltitude=ui->meanAltitudeLineEdit->text().trimmed();
    if(strMeanAltitude.isEmpty())
    {
        QString title="PCDViewerMainWindow::actionWithSelectedPoints";
        QString msg=QObject::tr("No mean altitude computed");
        QMessageBox::information(this,title,msg);
        return;
    }
    double meanAltitude=strMeanAltitude.toDouble();
    double pointAltitude=mPointsAltitude[selectedPointsIndex[0]];
    double altitudeDifference=pointAltitude-meanAltitude;
    ui->altitudeDifferenceLineEdit->setText(QString::number(altitudeDifference,'f',PCDVIEWERMAINWINDOW_LINEAR_PRECISION));
}

void PCDViewerMainWindow::actionWithSelectedPoints(int newClass)
{
    if(mMainCanvas->pointSet()==NULL)
    {
        return;
    }
    Vertex** vertices=mMainCanvas->pointSet()->vertices();
    int numberOfVertices=mMainCanvas->pointSet()->nb_vertices();
    QVector<int> selectedPointsIndex;
    QMap<QString,QVector<int> > pointsIdByTileTableName;
    for (int i=0; i<numberOfVertices; ++i)
    {
        if(mPointsPGDbId[i]!=-1)
        {
            continue;
        }
        Vertex* v = vertices[i];
        if(v->is_selected())
        {
            selectedPointsIndex.push_back(i);
            int tileTableNameId=mPointsTilesTableNameId[i];
            QString tileTableName=mTilesTableNamesById[tileTableNameId];
            if(!pointsIdByTileTableName.contains(tileTableName))
            {
                QVector<int> aux;
                pointsIdByTileTableName[tileTableName]=aux;
            }
            int pointIdInTileTable=mPointsIdInTileTable[i];
            pointsIdByTileTableName[tileTableName].push_back(pointIdInTileTable);
        }
    }
    if(selectedPointsIndex.size()==0)
    {
        QString title="PCDViewerMainWindow::actionWithSelectedPoints";
        QString msg=QObject::tr("No valid points selected");
        QMessageBox::information(this,title,msg);
        return;
    }
    recoverLockedClassesFromGui();

    QString strError;
    bool storePointsData=true;
    if(!mPtrPCDbManager->getStorePointsData(mCurrentPointCloudFileName,
                                            storePointsData,
                                            strError))
    {
        QString title="PCDViewerMainWindow::actionWithSelectedPoints";
        QString msg=QObject::tr("Error recovering store points data for file:\n%1\nError:\n%1")
                .arg(mCurrentPointCloudFileName).arg(strError);
        QMessageBox::information(this,title,msg);
        return;
    }
    if(ui->removeRadioButton->isChecked())
    {
        int classToRemove=newClass;
        bool allClasses=false;
        if(classToRemove==-1)
        {
            allClasses=true;
        }
        if(!mPtrPCDbManager->removeSelectedPoints(mCurrentPointCloudFileName,
                                                  pointsIdByTileTableName,
                                                  classToRemove,
                                                  mLockedClassesByClassId,
                                                  strError))
        {
            QString title="PCDViewerMainWindow::actionWithSelectedPoints";
            QString msg=QObject::tr("Error removing selected points\nError:\n%1")
                    .arg(strError);
            QMessageBox::information(this,title,msg);
            return;
        }
        for(int i=0;i<selectedPointsIndex.size();i++)
        {
            int pointNewClass=mPointsClassNew[selectedPointsIndex[i]];
            if(mLockedClassesByClassId.contains(pointNewClass))
            {
                if(mLockedClassesByClassId[pointNewClass])
                {
                    continue;
                }
            }
            if(allClasses)
            {
                mPointsRemoved[selectedPointsIndex[i]]=true;
                if(!storePointsData)
                {
                    mPointsClassNew[selectedPointsIndex[i]]=mPointsClass[selectedPointsIndex[i]];
                    mPointsRemoved[selectedPointsIndex[i]]=true;
                    if(mUpdatedPointsIdInTileTable.indexOf(selectedPointsIndex[i])==-1)
                    {
                        mUpdatedPointsIdInTileTable.push_back(selectedPointsIndex[i]);
                    }
                }
            }
            else if(pointNewClass==classToRemove)
            {
                mPointsRemoved[selectedPointsIndex[i]]=true;
                if(!storePointsData)
                {
                    mPointsClassNew[selectedPointsIndex[i]]=mPointsClass[selectedPointsIndex[i]];
                    mPointsRemoved[selectedPointsIndex[i]]=true;
                    if(mUpdatedPointsIdInTileTable.indexOf(selectedPointsIndex[i])==-1)
                    {
                        mUpdatedPointsIdInTileTable.push_back(selectedPointsIndex[i]);
                    }
                }
            }
        }
    }
    if(ui->changeClassRadioButton->isChecked())
    {
        if(!mPtrPCDbManager->changeClassToSelectedPoints(mCurrentPointCloudFileName,
                                                         pointsIdByTileTableName,
                                                         newClass,
                                                         mLockedClassesByClassId,
                                                         strError))
        {
            QString title="PCDViewerMainWindow::actionWithSelectedPoints";
            QString msg=QObject::tr("Error removing selected points\nError:\n%1")
                    .arg(strError);
            QMessageBox::information(this,title,msg);
            return;
        }
        for(int i=0;i<selectedPointsIndex.size();i++)
        {
            if(mPointsRemoved[selectedPointsIndex[i]])
            {
                continue;
            }
            int pointNewClass=mPointsClassNew[selectedPointsIndex[i]];
            if(pointNewClass==newClass)
            {
                continue;
            }
            if(mLockedClassesByClassId.contains(pointNewClass))
            {
                if(mLockedClassesByClassId[pointNewClass])
                {
                    continue;
                }
            }
            mPointsClassNew[selectedPointsIndex[i]]=newClass;
            if(!storePointsData)
            {
                if(mUpdatedPointsIdInTileTable.indexOf(selectedPointsIndex[i])==-1)
                {
                    mUpdatedPointsIdInTileTable.push_back(selectedPointsIndex[i]);
                }
            }
        }
    }
    if(ui->recoverRadioButton->isChecked())
    {
        int classToRecover=newClass;
        bool allClasses=false;
        if(classToRecover==-1)
        {
            allClasses=true;
        }
        if(!mPtrPCDbManager->recoverSelectedPoints(mCurrentPointCloudFileName,
                                                   pointsIdByTileTableName,
                                                   classToRecover,
                                                   mLockedClassesByClassId,
                                                   strError))
        {
            QString title="PCDViewerMainWindow::actionWithSelectedPoints";
            QString msg=QObject::tr("Error removing selected points\nError:\n%1")
                    .arg(strError);
            QMessageBox::information(this,title,msg);
            return;
        }
        for(int i=0;i<selectedPointsIndex.size();i++)
        {
            int pointNewClass=mPointsClassNew[selectedPointsIndex[i]];
            if(mLockedClassesByClassId.contains(pointNewClass))
            {
                if(mLockedClassesByClassId[pointNewClass])
                {
                    continue;
                }
            }
            if(allClasses)
            {
                mPointsRemoved[selectedPointsIndex[i]]=false;
                if(!storePointsData)
                {
                    if(mUpdatedPointsIdInTileTable.indexOf(selectedPointsIndex[i])==-1)
                    {
                        mUpdatedPointsIdInTileTable.push_back(selectedPointsIndex[i]);
                    }
                }
            }
            else if(pointNewClass==classToRecover)
            {
                mPointsRemoved[selectedPointsIndex[i]]=false;
                if(!storePointsData)
                {
                    if(mUpdatedPointsIdInTileTable.indexOf(selectedPointsIndex[i])==-1)
                    {
                        mUpdatedPointsIdInTileTable.push_back(selectedPointsIndex[i]);
                    }
                }
            }
        }
    }
    if(ui->toOriginalClassRadioButton->isChecked())
    {
        int classToOriginal=newClass;
        bool allClasses=false;
        if(classToOriginal==-1)
        {
            allClasses=true;
        }
        if(!mPtrPCDbManager->toOriginalClassSelectedPoints(mCurrentPointCloudFileName,
                                                           pointsIdByTileTableName,
                                                           classToOriginal,
                                                           mLockedClassesByClassId,
                                                           strError))
        {
            QString title="PCDViewerMainWindow::actionWithSelectedPoints";
            QString msg=QObject::tr("Error removing selected points\nError:\n%1")
                    .arg(strError);
            QMessageBox::information(this,title,msg);
            return;
        }
        for(int i=0;i<selectedPointsIndex.size();i++)
        {
            if(mPointsRemoved[selectedPointsIndex[i]])
            {
                continue;
            }
            int pointNewClass=mPointsClassNew[selectedPointsIndex[i]];
            if(!allClasses)
            {
                if(pointNewClass!=classToOriginal)
                {
                    continue;
                }
            }
            if(mLockedClassesByClassId.contains(pointNewClass))
            {
                if(mLockedClassesByClassId[pointNewClass])
                {
                    continue;
                }
            }
            int pointClass=mPointsClass[selectedPointsIndex[i]];
            mPointsClassNew[selectedPointsIndex[i]]=pointClass;
            if(!storePointsData)
            {
                if(mUpdatedPointsIdInTileTable.indexOf(selectedPointsIndex[i])==-1)
                {
                    mUpdatedPointsIdInTileTable.push_back(selectedPointsIndex[i]);
                }
            }
        }
    }
    if(ui->selectOnlyRadioButton->isChecked())
    {
        // duda con clases bloqueadas
        int classToSelect=newClass;
        for(int i=0;i<selectedPointsIndex.size();i++)
        {
            int pointNewClass=mPointsClassNew[selectedPointsIndex[i]];
            if(pointNewClass!=classToSelect)
            {
                if(mLockedClassesByClassId.contains(pointNewClass))
                {
                    if(mLockedClassesByClassId[pointNewClass])
                    {
                        continue;
                    }
                }
                mMainCanvas->pointSet()->vertices()[selectedPointsIndex[i]]->set_selected(false);
            }
        }
    }
    if(ui->unselectRadioButton->isChecked())
    {
        // duda con clases bloqueadas
        int classToUnselect=newClass;
        for(int i=0;i<selectedPointsIndex.size();i++)
        {
            int pointNewClass=mPointsClassNew[selectedPointsIndex[i]];
            if(pointNewClass==classToUnselect)
            {
                if(mLockedClassesByClassId.contains(pointNewClass))
                {
                    if(mLockedClassesByClassId[pointNewClass])
                    {
                        continue;
                    }
                }
                mMainCanvas->pointSet()->vertices()[selectedPointsIndex[i]]->set_selected(false);
            }
        }
    }
    assignColorByClassification();
}

void PCDViewerMainWindow::enableAllClasses()
{
    ui->allClassesPushButton->setEnabled(true);
}

void PCDViewerMainWindow::unenableAllClasses()
{
    ui->allClassesPushButton->setEnabled(false);
}

void PCDViewerMainWindow::on_toClass12PushButton_clicked()
{
    int newClass = 12;
    actionWithSelectedPoints(newClass);
}

void PCDViewerMainWindow::on_visibleClass0CheckBox_clicked()
{
    mVisibleClassesByClassId[0]=ui->visibleClass0CheckBox->isChecked();
    actionSetVisiblePoints();
}

void PCDViewerMainWindow::on_visibleClass1CheckBox_clicked()
{
    mVisibleClassesByClassId[1]=ui->visibleClass1CheckBox->isChecked();
    actionSetVisiblePoints();
}

void PCDViewerMainWindow::on_visibleClass2CheckBox_clicked()
{
    mVisibleClassesByClassId[2]=ui->visibleClass2CheckBox->isChecked();
    actionSetVisiblePoints();
}

void PCDViewerMainWindow::on_visibleClass6CheckBox_clicked()
{
    mVisibleClassesByClassId[6]=ui->visibleClass6CheckBox->isChecked();
    actionSetVisiblePoints();
}

void PCDViewerMainWindow::on_visibleClass3CheckBox_clicked()
{
    mVisibleClassesByClassId[3]=ui->visibleClass3CheckBox->isChecked();
    actionSetVisiblePoints();
}

void PCDViewerMainWindow::on_visibleClass4CheckBox_clicked()
{
    mVisibleClassesByClassId[4]=ui->visibleClass4CheckBox->isChecked();
    actionSetVisiblePoints();
}

void PCDViewerMainWindow::on_visibleClass5CheckBox_clicked()
{
    mVisibleClassesByClassId[5]=ui->visibleClass5CheckBox->isChecked();
    actionSetVisiblePoints();
}

void PCDViewerMainWindow::on_visibleClass7CheckBox_clicked()
{
    mVisibleClassesByClassId[7]=ui->visibleClass7CheckBox->isChecked();
    actionSetVisiblePoints();
}

void PCDViewerMainWindow::on_visibleClass9CheckBox_clicked()
{
    mVisibleClassesByClassId[9]=ui->visibleClass9CheckBox->isChecked();
    actionSetVisiblePoints();
}

void PCDViewerMainWindow::on_visibleClass12CheckBox_clicked()
{
    mVisibleClassesByClassId[12]=ui->visibleClass12CheckBox->isChecked();
    actionSetVisiblePoints();
}

void PCDViewerMainWindow::onVisibleObjectClassesComboCheckBox(int row, bool isChecked, QString text, QString data)
{
    int objectClassDbId=data.toInt();
    mVisibleObjectClassesByObjectClassId[objectClassDbId]=isChecked;
//    QString title="PCDViewerMainWindow::onVisibleObjectClassesComboCheckBox";
//    QString msg=QObject::tr("Row: %1").arg(QString::number(row));
//    if(isChecked)
//    {
//        msg+=QObject::tr("\nChecked: true");
//    }
//    else
//    {
//        msg+=QObject::tr("\nChecked: false");
//    }
//    msg+=QObject::tr("\nText: %1").arg(text);
//    msg+=QObject::tr("\nData: %1").arg(data);
//    QMessageBox::information(this,title,msg);
    assignColorByObjectClassification();
}

void PCDViewerMainWindow::onVisibleObjectsComboCheckBox(int row, bool isChecked, QString text, QString data)
{
    int objectDbId=data.toInt();
    mVisibleObjectsByObjectId[objectDbId]=isChecked;
//    QString title="PCDViewerMainWindow::onVisibleObjectsComboCheckBox";
//    QString msg=QObject::tr("Row: %1").arg(QString::number(row));
//    if(isChecked)
//    {
//        msg+=QObject::tr("\nChecked: true");
//    }
//    else
//    {
//        msg+=QObject::tr("\nChecked: false");
//    }
//    msg+=QObject::tr("\nText: %1").arg(text);
//    msg+=QObject::tr("\nData: %1").arg(data);
//    QMessageBox::information(this,title,msg);
    assignColorByObjectClassification();
}

void PCDViewerMainWindow::onLockedObjectClassesComboCheckBox(int row, bool isChecked, QString text, QString data)
{
    int objectClassDbId=data.toInt();
    mLockedObjectClassesByObjectClassId[objectClassDbId]=isChecked;
//    QString title="PCDViewerMainWindow::onLockedObjectClassesComboCheckBox";
//    QString msg=QObject::tr("Row: %1").arg(QString::number(row));
//    if(isChecked)
//    {
//        msg+=QObject::tr("\nChecked: true");
//    }
//    else
//    {
//        msg+=QObject::tr("\nChecked: false");
//    }
//    msg+=QObject::tr("\nText: %1").arg(text);
//    msg+=QObject::tr("\nData: %1").arg(data);
//    QMessageBox::information(this,title,msg);
    return;
}

void PCDViewerMainWindow::onLockecObjectsComboCheckBox(int row, bool isChecked, QString text, QString data)
{
    int objectDbId=data.toInt();
    mLockedObjectsByObjectId[objectDbId]=isChecked;
//    QString title="PCDViewerMainWindow::onLockecObjectsComboCheckBox";
//    QString msg=QObject::tr("Row: %1").arg(QString::number(row));
//    if(isChecked)
//    {
//        msg+=QObject::tr("\nChecked: true");
//    }
//    else
//    {
//        msg+=QObject::tr("\nChecked: false");
//    }
//    msg+=QObject::tr("\nText: %1").arg(text);
//    msg+=QObject::tr("\nData: %1").arg(data);
//    QMessageBox::information(this,title,msg);
    return;
}

//void PCDViewerMainWindow::onSelectedObjectComboCheckBox(int row, bool isChecked, QString text, QString data)
//{
//    QString title="PCDViewerMainWindow::onSelectedObjectComboCheckBox";
//    QString msg=QObject::tr("Row: %1").arg(QString::number(row));
//    if(isChecked)
//    {
//        msg+=QObject::tr("\nChecked: true");
//    }
//    else
//    {
//        msg+=QObject::tr("\nChecked: false");
//    }
//    msg+=QObject::tr("\nText: %1").arg(text);
//    msg+=QObject::tr("\nData: %1").arg(data);
//    QMessageBox::information(this,title,msg);
//    return;
//}

void PCDViewerMainWindow::actionSetVisiblePoints()
{
    assignColorByClassification();
}

void PCDViewerMainWindow::on_processSelectedObjectPointsPushButton_clicked()
{
    if(mMainCanvas->pointSet()==NULL)
    {
        return;
    }
    if(mPtrModelDbManager==NULL)
    {
        return;
    }
    bool ok=false;
    QString strAuxError;
    ModelDb::ModelProjectSpatialiteDb* ptrModelProjectSpatialiteDb=mPtrModelDbManager->getModelProjectSpatialiteDb(mModelProjectSpatialiteDbFileName,ok,strAuxError);
    if(!ok)
    {
        QString title=QObject::tr("PCDViewerMainWindow::on_processSelectedObjectPointsPushButton_clicked");
        QString msg=QObject::tr("\nError recovering model project spatialite database:\n%1\nError:\n%2")
                .arg(mModelProjectSpatialiteDbFileName).arg(strAuxError);
        QMessageBox::information(this,title,msg);
        return;
    }
    int pctDbId=ptrModelProjectSpatialiteDb->getPointCloudSpatialiteDbDbIdFromFileName(mCurrentPointCloudFileName);
    QString selectedObjectName=ui->selectObjectComboBox->currentText();
    if(selectedObjectName.compare(PCDVIEWERMAINWINDOW_NO_COMBO_SELECT,Qt::CaseInsensitive)==0)
    {
        QString title="PCDViewerMainWindow::on_processSelectedObjectPointsPushButton_clicked";
        QString msg=QObject::tr("Select an object");
        QMessageBox::information(this,title,msg);
        return;
    }
    QMap<int,QString>::const_iterator iterObject=mObjectNameByObjectDbId.begin();
    int selectedObjectId=-2;
    while(iterObject!=mObjectNameByObjectDbId.end())
    {
        if(iterObject.value().compare(selectedObjectName,Qt::CaseInsensitive)==0)
        {
            selectedObjectId=iterObject.key();
            break;
        }
        iterObject++;
    }
    Vertex** vertices=mMainCanvas->pointSet()->vertices();
    int numberOfVertices=mMainCanvas->pointSet()->nb_vertices();
    QVector<int> selectedPointsIndex;
    for (int i=0; i<numberOfVertices; ++i)
    {
        if(mPointsPGDbId[i]!=-1)
        {
            continue;
        }
        Vertex* v = vertices[i];
        if(v->is_selected())
        {
            selectedPointsIndex.push_back(i);
        }
    }
    if(selectedPointsIndex.size()==0)
    {
        QString title="PCDViewerMainWindow::on_processSelectedObjectPointsPushButton_clicked";
        QString msg=QObject::tr("No valid points selected");
        QMessageBox::information(this,title,msg);
        return;
    }
    if(ui->selectOnlyObjectRadioButton->isChecked())
    {
        for(int i=0;i<selectedPointsIndex.size();i++)
        {
            int pointObjectId=mPointsObjectDbId[selectedPointsIndex[i]];
            int pointObjectClassId=mObjectClassDbIdByObjectDbId[pointObjectId];
            if(pointObjectId!=selectedObjectId)
            {
                if(mLockedObjectClassesByObjectClassId[pointObjectClassId])
                {
                    continue;
                }
                else if(mLockedObjectsByObjectId[pointObjectId])
                {
                    continue;
                }
                mMainCanvas->pointSet()->vertices()[selectedPointsIndex[i]]->set_selected(false);
            }
        }
    }
    if(ui->unselectObjectRadioButton->isChecked())
    {
        for(int i=0;i<selectedPointsIndex.size();i++)
        {
            int pointObjectId=mPointsObjectDbId[selectedPointsIndex[i]];
            int pointObjectClassId=mObjectClassDbIdByObjectDbId[pointObjectId];
            if(pointObjectId==selectedObjectId)
            {
                if(mLockedObjectClassesByObjectClassId[pointObjectClassId])
                {
                    continue;
                }
                else if(mLockedObjectsByObjectId[pointObjectId])
                {
                    continue;
                }
                mMainCanvas->pointSet()->vertices()[selectedPointsIndex[i]]->set_selected(false);
            }
        }
    }
    else if(ui->assignToObjectRadioButton->isChecked())
    {
        QVector<int> removeObjectPointsObjectDbId;
        QVector<int> removeObjectPointsPositionInContainers;
        QVector<int> changeObjectPointsObjectDbId;
        QVector<int> changeObjectPointsPositionInContainers;
//        QMap<int,int> insertObjectPointsTileDbIdByPointIdInTile;
        QVector<int> insertObjectPointsPointIdInTile;
        QVector<int> insertObjectPointsPointTileDbId;
        QVector<int> insertObjectPointsPositionInContainers;
        for (int i=0; i<selectedPointsIndex.size(); ++i)
        {
            Vertex* v = vertices[selectedPointsIndex[i]];
//            if(v->is_selected())
//            {
                int positionInContainers=selectedPointsIndex[i];
                int pointIdInTile=mPointsIdInTileTable[positionInContainers];
                int pointObjectId=mPointsObjectDbId[positionInContainers];
                int pointObjectClassId=mObjectClassDbIdByObjectDbId[pointObjectId];
                int tileDbId=mPointsTilesDbId[positionInContainers];
                int pointDbId=mPointsDbId[positionInContainers]; // puede ser -1 si no pertenece a ningun objeto
                if(pointObjectId!=selectedObjectId)
                {
                    if(mLockedObjectClassesByObjectClassId[pointObjectClassId])
                    {
                        continue;
                    }
                    else if(mLockedObjectsByObjectId[pointObjectId])
                    {
                        continue;
                    }
                    if(selectedObjectId==MODELDBMANAGERDEFINITIONS_NO_OBJECT_ID)
                    {
                        if(pointObjectId!=MODELDBMANAGERDEFINITIONS_NO_OBJECT_ID) // punto insertado a objeto hay que eliminarlo
                        {
                            removeObjectPointsObjectDbId.push_back(pointDbId);
                            removeObjectPointsPositionInContainers.push_back(positionInContainers);
                        }
                    }
                    else
                    {
                        if(pointObjectId==MODELDBMANAGERDEFINITIONS_NO_OBJECT_ID) // punto no asignado, hay que insertarlo
                        {
//                            insertObjectPointsTileDbIdByPointIdInTile[pointIdInTile]=tileDbId;
                            insertObjectPointsPointIdInTile.push_back(pointIdInTile);
                            insertObjectPointsPointTileDbId.push_back(tileDbId);
                            insertObjectPointsPositionInContainers.push_back(positionInContainers);
                        }
                        else // punto insertado, hay que cambiarlo
                        {
                            changeObjectPointsObjectDbId.push_back(pointDbId);
                            changeObjectPointsPositionInContainers.push_back(positionInContainers);
                        }
                    }
//                }
            }
        }
//        mPtrModelDbManager=ptrModelDbManager;
//        mModelProjectSpatialiteDbFileName=modelProjectSpatialiteDbFileName;
        // Desasignar
        if(removeObjectPointsObjectDbId.size()==0
                &&changeObjectPointsObjectDbId.size()==0
                &&insertObjectPointsPointIdInTile.size()==0)
        {
            return;
        }
        // Eliminar
        if(removeObjectPointsObjectDbId.size()>0)
        {
            if(!ptrModelProjectSpatialiteDb->removeObjectPoints(removeObjectPointsObjectDbId,strAuxError))
            {
                QString title=QObject::tr("PCDViewerMainWindow::on_processSelectedObjectPointsPushButton_clicked");
                QString msg=QObject::tr("\nError removing object points from model project spatialite database:\n%1\nError:\n%2")
                        .arg(mModelProjectSpatialiteDbFileName).arg(strAuxError);
                QMessageBox::information(this,title,msg);
                return;
            }
            for(int i=0;i<removeObjectPointsPositionInContainers.size();i++)
            {
                int positionInContainers=removeObjectPointsPositionInContainers[i];
                mPointsObjectDbId[positionInContainers]=MODELDBMANAGERDEFINITIONS_NO_OBJECT_ID;
            }
        }
        // Cambiar
        if(changeObjectPointsObjectDbId.size()>0)
        {
            if(!ptrModelProjectSpatialiteDb->changeObjectPoints(selectedObjectId,changeObjectPointsObjectDbId,strAuxError))
            {
                QString title=QObject::tr("PCDViewerMainWindow::on_processSelectedObjectPointsPushButton_clicked");
                QString msg=QObject::tr("\nError removing object points from model project spatialite database:\n%1\nError:\n%2")
                        .arg(mModelProjectSpatialiteDbFileName).arg(strAuxError);
                QMessageBox::information(this,title,msg);
                return;
            }
            for(int i=0;i<changeObjectPointsPositionInContainers.size();i++)
            {
                int positionInContainers=changeObjectPointsPositionInContainers[i];
                mPointsObjectDbId[positionInContainers]=selectedObjectId;
            }
        }
        // Insertar
        if(insertObjectPointsPointIdInTile.size()>0)
        {
//            QVector<int> insertTilesDbId=;
//            QVector<int> insertPointsIdInTile;
//            QMap<int,int>::const_iterator iterInsert=insertObjectPointsTileDbIdByPointIdInTile.begin();
//            while(iterInsert!=insertObjectPointsTileDbIdByPointIdInTile.end())
//            {
//                int pointIdInTile=iterInsert.key();
//                int tileId=iterInsert.value();
//                insertPointsIdInTile.push_back(pointIdInTile);
//                insertTilesDbId.push_back(tileId);
//                iterInsert++;
//            }
//            QVector<int> insertObjectPointsPositionInContainers;
            QVector<int> insertObjectPointsObjectDbId;
            if(!ptrModelProjectSpatialiteDb->insertObjectPoints(selectedObjectId,
                                                                pctDbId,
                                                                insertObjectPointsPointTileDbId,
                                                                insertObjectPointsPointIdInTile,
                                                                insertObjectPointsObjectDbId,
                                                                strAuxError))
            {
                QString title=QObject::tr("PCDViewerMainWindow::on_processSelectedObjectPointsPushButton_clicked");
                QString msg=QObject::tr("\nError inserting object points from model project spatialite database:\n%1\nError:\n%2")
                        .arg(mModelProjectSpatialiteDbFileName).arg(strAuxError);
                QMessageBox::information(this,title,msg);
                return;
            }
            for(int i=0;i<insertObjectPointsPositionInContainers.size();i++)
            {
                int positionInContainers=insertObjectPointsPositionInContainers[i];
                int pointObjectDbId=insertObjectPointsObjectDbId[i];
                mPointsObjectDbId[positionInContainers]=selectedObjectId;
                mPointsDbId[positionInContainers]=pointObjectDbId;
            }
        }
        unselectPoints();
    }
    assignColorByObjectClassification();
}

void PCDViewerMainWindow::on_editObjectClassPushButton_clicked()
{
    QString selectObjectClass=ui->objectClassComboBox->currentText();
    if(selectObjectClass.compare(PCDVIEWERMAINWINDOW_NO_COMBO_SELECT,Qt::CaseInsensitive)==0)
    {
        QString title="PCDViewerMainWindow::on_processSelectedObjectPointsPushButton_clicked";
        QString msg=QObject::tr("Select an object class");
        QMessageBox::information(this,title,msg);
        return;
    }
    int objectClassDbId=-2;
    QMap<int,QString>::const_iterator iter=mObjectClassNameByObjectClassId.begin();
    while(iter!=mObjectClassNameByObjectClassId.end())
    {
        if(iter.value().compare(selectObjectClass,Qt::CaseInsensitive)==0)
        {
            objectClassDbId=iter.key();
            break;
        }
        iter++;
    }
    QString strAuxError;
    bool ok=false;
    ModelDb::ModelProjectSpatialiteDb* ptrModelProjectSpatialiteDb=mPtrModelDbManager->getModelProjectSpatialiteDb(mModelProjectSpatialiteDbFileName,ok,strAuxError);
    if(!ok)
    {
        QString title="PCDViewerMainWindow::on_processSelectedObjectPointsPushButton_clicked";
        QString msg=QObject::tr("Error recovering model project spatialite database:\n%1\nError:\n%2")
                .arg(mModelProjectSpatialiteDbFileName).arg(strAuxError);
        QMessageBox::information(this,title,msg);
        return;
    }
    bool colorChanged=false;
    if(!ptrModelProjectSpatialiteDb->editModelObjectClass(objectClassDbId,colorChanged,strAuxError,this))
    {
        QString title="PCDViewerMainWindow::on_processSelectedObjectPointsPushButton_clicked";
        QString msg=QObject::tr("Error editing model object class: %1 from database:\n%2\nError:\n%3")
                .arg(selectObjectClass).arg(mModelProjectSpatialiteDbFileName).arg(strAuxError);
        QMessageBox::information(this,title,msg);
        return;
    }
    if(colorChanged)
    {
        ModelDb::ModelObjectClass* ptrModelObjectClass=ptrModelProjectSpatialiteDb->getObjectClass(objectClassDbId);
        if(ptrModelObjectClass==NULL)
        {
            QString title="PCDViewerMainWindow::on_processSelectedObjectPointsPushButton_clicked";
            QString msg=QObject::tr("Error recoverign model object class database id: %1 from database:\n%2\nError:\n%3")
                    .arg(QString::number(objectClassDbId)).arg(mModelProjectSpatialiteDbFileName).arg(strAuxError);
            QMessageBox::information(this,title,msg);
            return;
        }
        int red,green,blue,alpha;
        ptrModelObjectClass->getColor(red,green,blue,alpha);
        QVector<int> newColor(4);
        newColor[0]=red;
        newColor[1]=green;
        newColor[2]=blue;
        newColor[3]=alpha;
        mObjectClassColorByObjectClassId[objectClassDbId]=newColor;
        assignColorByObjectClassification();
    }
}

void PCDViewerMainWindow::onVisibleParametricGeometriesObjectClassesComboCheckBox(int row,
                                                                                  bool isChecked,
                                                                                  QString text,
                                                                                  QString data)
{
    int objectClassDbId=data.toInt();
    mVisiblePGObjectClassesByObjectClassId[objectClassDbId]=isChecked;
//    QString title="PCDViewerMainWindow::onVisibleObjectClassesComboCheckBox";
//    QString msg=QObject::tr("Row: %1").arg(QString::number(row));
//    if(isChecked)
//    {
//        msg+=QObject::tr("\nChecked: true");
//    }
//    else
//    {
//        msg+=QObject::tr("\nChecked: false");
//    }
//    msg+=QObject::tr("\nText: %1").arg(text);
//    msg+=QObject::tr("\nData: %1").arg(data);
//    QMessageBox::information(this,title,msg);
    assignColorByObjectClassification();
}

void PCDViewerMainWindow::onVisibleParametricGeometriesObjectsComboCheckBox(int row,
                                                                            bool isChecked,
                                                                            QString text,
                                                                            QString data)
{
    int pgObjectDbId=data.toInt();
    mVisiblePGPByGDbId[pgObjectDbId]=isChecked;
//    QString title="PCDViewerMainWindow::onVisibleObjectsComboCheckBox";
//    QString msg=QObject::tr("Row: %1").arg(QString::number(row));
//    if(isChecked)
//    {
//        msg+=QObject::tr("\nChecked: true");
//    }
//    else
//    {
//        msg+=QObject::tr("\nChecked: false");
//    }
//    msg+=QObject::tr("\nText: %1").arg(text);
//    msg+=QObject::tr("\nData: %1").arg(data);
//    QMessageBox::information(this,title,msg);
    assignColorByObjectClassification();
}
