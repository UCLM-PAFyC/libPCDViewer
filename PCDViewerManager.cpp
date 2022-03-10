#include <QEventLoop>
#include "PCDViewerManager.h"

using namespace PCDViewer;

PCDViewerManager * PCDViewerManager::mInstance = 0;

//PCDViewerManager::PCDViewerManager(QWidget *parent)
//{
//    mPtrParentWidget=parent;
//    initialize();
//}

bool PCDViewerManager::loadPointCloudFile(QString pointCloudFileName,
                                          QString &strError)
{
//    QString pointCloudFileName="E:\\Qt5CreatorPrograms\\TIDOP_TOOLS_USAL\\pcdviewer\\PcdViewer_V1.4_src\\test_data.lab";
    mPtrPCDViewerMainWindow->loadPointCloud(pointCloudFileName);
    return(true);
}

bool PCDViewerManager::loadPointCloudFromSpatialiteDb(QString &dbFileName,
                                                      QString wktGeometry,
                                                      int geometryCrsEpsgCode,
                                                      QString geometryCrsProj4String,
                                                      QString &strError)
{
    return(mPtrPCDViewerMainWindow->loadPointCloudFromSpatialiteDb(dbFileName,
                                                                   wktGeometry,
                                                                   geometryCrsEpsgCode,
                                                                   geometryCrsProj4String,
                                                                   strError));
}

bool PCDViewerManager::resetUpdatedPoints(QString &strError)
{
    if(mPtrPCDViewerMainWindow==NULL)
    {
        strError=QObject::tr("PCDViewerManager::resetUpdatedPoints");
        strError+=QObject::tr("\nPCDViewerMainWindow is not initialized");
        return(false);
    }
    return(mPtrPCDViewerMainWindow->resetUpdatedPoints(strError));
}

bool PCDViewerManager::setModelDbManager(ModelDb::ModelDbManager *ptrModelDbManager,
                                         QString modelProjectSpatialiteDbFileName,
                                         QString& strError)
{
    QString strAuxError;
    if(!ptrModelDbManager->openModelProjectSpatialiteDb(modelProjectSpatialiteDbFileName,
                                                        strAuxError))
    {
        strError=QObject::tr("PCDViewerManager::setModelDbManager");
        strError+=QObject::tr("\nError opening model project spatialite database:\n%1")
                .arg(modelProjectSpatialiteDbFileName);
        return(false);
    }
    mPtrModelDbManager=ptrModelDbManager;
    mModelProjectSpatialiteDbFileName=modelProjectSpatialiteDbFileName;
    if(!mPtrPCDViewerMainWindow->setModelDbManager(mPtrModelDbManager,
                                                   mModelProjectSpatialiteDbFileName,
                                                   strError))
    {
        strError=QObject::tr("PCDViewerManager::setModelDbManager");
        strError+=QObject::tr("\nError opening model project spatialite database:\n%1")
                .arg(modelProjectSpatialiteDbFileName);
        return(false);
    }
    return(true);
}

bool PCDViewerManager::setSymbology(QString fileName,
                                    QString &strError)
{
    if(mPtrPCDViewerMainWindow==NULL)
    {
        strError=QObject::tr("PCDViewerManager::setSymbology");
        strError+=QObject::tr("\nPCDViewerMainWindow is not initialized");
        return(false);
    }
    return(mPtrPCDViewerMainWindow->setSymbology(fileName,strError));
}

bool PCDViewerManager::showPCDViewerMainWindow(QString& strError)
{
    if(!mPtrPCDViewerMainWindow->existsPoints())
    {
        strError=QObject::tr("PCDViewerManager::showPCDViewerMainWindow");
        strError+=QObject::tr("\nNo points in the selected region");
        return(false);
    }
    mPtrPCDViewerMainWindow->setWindowModality(Qt::ApplicationModal);
////    mPtrPCDViewerMainWindow->showMaximized();
//    bool isModal=mPtrPCDViewerMainWindow->isModal();
    mPtrPCDViewerMainWindow->show();
    QEventLoop loop;
    connect(mPtrPCDViewerMainWindow, SIGNAL(closed()), &loop, SLOT(quit()));
    loop.exec();
    return(true);
//    isModal=mPtrPCDViewerMainWindow->isModal();
//    int yo=1;
//    yo++;
}

//PCDViewerManager::PCDViewerManager(QWidget *parent)
//{
//    if(parent==0)
//    {
//        mPtrParentWidget=new QWidget();
//    }
//    else
//    {
//        mPtrParentWidget=parent;
//    }
//    mPtrPCDViewerMainWindow=NULL;
//}

//PCDViewerManager::~PCDViewerManager()
//{
//    if(mPtrPCDViewerMainWindow!=NULL)
//    {
//        delete(mPtrPCDViewerMainWindow);
//    }
//}

PCDViewerManager::~PCDViewerManager()
{
    if(mPtrPCDViewerMainWindow!=NULL)
    {
        delete(mPtrPCDViewerMainWindow);
    }
}

bool PCDViewerManager::getUpdatedPoints(QMap<int, QString> &tilesTableNamesById,
                                        QVector<int> &pointsTilesTableNameId,
                                        QVector<int> &pointsIdInTileTable,
                                        QString &strError)
{
    return(mPtrPCDViewerMainWindow->getUpdatedPoints(tilesTableNamesById,
                                                     pointsTilesTableNameId,
                                                     pointsIdInTileTable,
                                                     strError));
}

bool PCDViewerManager::initialize(QString& strError)
{
    if(mPtrPCDbManager==NULL)
    {
        strError=QObject::tr("PCDViewerManager::setSymbology");
        strError+=QObject::tr("\nPCDbManager is not initialized");
        return(false);
    }
    if(mPtrPCDViewerMainWindow==NULL)
    {
        mPtrPCDViewerMainWindow=new PCDViewerMainWindow(mPtrPCDbManager,
                                                        mPtrParentWidget);
    }
    return(true);
}
