#ifndef LIBPCDVIEWER_H
#define LIBPCDVIEWER_H

#include <QWidget>
#include <QObject>

#include "../../libs/libModelManagementTools/ModelDbManager.h"
#include "../../libs/libPointCloudDbManager/PointCloudDbManager.h"
#include "libPCDViewer_global.h"
#include "PCDViewerMainWindow.h"

namespace PCDViewer{
class LIBPCDVIEWERSHARED_EXPORT PCDViewerManager: public QObject
{
    Q_OBJECT
public:
    inline PCDViewerManager(QWidget *parent = 0)
    {
        mPtrPCDbManager=NULL;
        mPtrModelDbManager=NULL;
        if(parent==0)
        {
            mPtrParentWidget=new QWidget();
        }
        else
        {
            mPtrParentWidget=parent;
        }
        mPtrParentWidget=parent;
        mPtrPCDViewerMainWindow=NULL;
    };
    static inline PCDViewerManager * getInstance(void )
    {
        if ( mInstance == 0 ) mInstance = new PCDViewerManager;
            return mInstance;
    };
    ~PCDViewerManager();
//    bool initialize(QString pointCloudFileName,
//                    QString& strError);
//    PCDViewerManager(QWidget *parent = 0);
    bool getUpdatedPoints(QMap<int,QString>& tilesTableNamesById,
                          QVector<int>& pointsTilesTableNameId,
                          QVector<int>& pointsIdInTileTable,
                          QString& strError);
    bool initialize(QString &strError);
    bool loadPointCloudFile(QString pointCloudFileName,
                            QString& strError);
    bool loadPointCloudFromSpatialiteDb(QString& dbFileName,
                                        QString wktGeometry,
                                        int geometryCrsEpsgCode,
                                        QString geometryCrsProj4String,
                                        QString& strError);
    bool resetUpdatedPoints(QString& strError);
    bool setModelDbManager(ModelDb::ModelDbManager* ptrModelDbManager,
                           QString modelProjectSpatialiteDbFileName,
                           QString &strError);
    void setPointCloudDbManager(PointCloudDb::PointCloudDbManager *ptrPCDbManager){mPtrPCDbManager=ptrPCDbManager;};
    bool setSymbology(QString fileName,
                      QString& strError);
    bool showPCDViewerMainWindow(QString& strError);
private:
    PCDViewerMainWindow* mPtrPCDViewerMainWindow;
    QWidget* mPtrParentWidget;
    static PCDViewerManager * mInstance;
    PointCloudDb::PointCloudDbManager* mPtrPCDbManager;
    ModelDb::ModelDbManager* mPtrModelDbManager;
    QString mModelProjectSpatialiteDbFileName;
};
}

#endif // LIBPCDVIEWER_H
