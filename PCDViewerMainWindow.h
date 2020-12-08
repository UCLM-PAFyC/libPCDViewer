#ifndef PCDVIEWERMAINWINDOW_H
#define PCDVIEWERMAINWINDOW_H

#define PCDVIEWERMAINWINDOW_SYMBOLOGY_FILE_STRING_SEPARATOR     "#"
#define PCDVIEWERMAINWINDOW_SYMBOLOGY_NAME_STRING_SEPARATOR     ":"
#define PCDVIEWERMAINWINDOW_SYMBOLOGY_FILE_NUMBER_OF_ITEMS          6
#define PCDVIEWERMAINWINDOW_SYMBOLOGY_FILE_ITEM_CLASS_ID            1
#define PCDVIEWERMAINWINDOW_SYMBOLOGY_FILE_ITEM_CLASS_NAME          2
#define PCDVIEWERMAINWINDOW_SYMBOLOGY_FILE_ITEM_CLASS_COLOR_RED     3
#define PCDVIEWERMAINWINDOW_SYMBOLOGY_FILE_ITEM_CLASS_COLOR_GREEN   4
#define PCDVIEWERMAINWINDOW_SYMBOLOGY_FILE_ITEM_CLASS_COLOR_BLUE    5
#define PCDVIEWERMAINWINDOW_SYMBOLOGY_FILE_ITEM_CLASS_COLOR_ALPHA   6
#define PCDVIEWERMAINWINDOW_SYMBOLOGY_FILE_ITEM_CLASS_COLOR_MINIMUM_VALUE     0
#define PCDVIEWERMAINWINDOW_SYMBOLOGY_FILE_ITEM_CLASS_COLOR_MAXIMUM_VALUE   255
#define PCDVIEWERMAINWINDOW_SYMBOLOGY_REMOVED_POINTS_TAG_1          "removed"
#define PCDVIEWERMAINWINDOW_SYMBOLOGY_REMOVED_POINTS_TAG_2          "deleted"

#define PCDVIEWERMAINWINDOW_CLASS_ID_MINIMUM_VALUE                0
#define PCDVIEWERMAINWINDOW_CLASS_ID_MAXIMUM_VALUE                31

#define PCDVIEWERMAINWINDOW_LINEAR_PRECISION                    3

#define PCDVIEWERMAINWINDOW_NO_COMBO_SELECT                    "..."

#define PCDVIEWERMAINWINDOW_COMBOCHECKBOX_VISIBLE_OBJECT_CLASSES_TITLE      "... Select Visible Object Classes ..."
#define PCDVIEWERMAINWINDOW_COMBOCHECKBOX_VISIBLE_OBJECTS_TITLE      "... Select Visible Objects ..."
#define PCDVIEWERMAINWINDOW_COMBOCHECKBOX_LOCKED_OBJECT_CLASSES_TITLE      "... Select Locked Object Classes ..."
#define PCDVIEWERMAINWINDOW_COMBOCHECKBOX_LOCKED_OBJECTS_TITLE      "... Select Locked Objects ..."
#define PCDVIEWERMAINWINDOW_COMBOCHECKBOX_SELECTED_OBJECT_TITLE      "... Select Object ..."

#define PCDVIEWERMAINWINDOW_COMBOCHECKBOX_VISIBLE_PG_OBJECT_CLASSES_TITLE      "... Select Visible Parametric Object Classes ..."
#define PCDVIEWERMAINWINDOW_COMBOCHECKBOX_VISIBLE_PG_OBJECTS_TITLE      "... Select Visible Parametric Objects ..."

#include <QMainWindow>
#include <QLabel>
#include <QtGui/QKeyEvent>

#include "geometry/geometry_types.h"
#include "geometry/point_set.h"
#include "../../libs/libWidgets/QComboCheckBox.h"

namespace PointCloudDb{
    class PointCloudDbManager;
}
namespace ModelDb{
    class ModelDbManager;
}

class PaintCanvas;
class VertexGroup;
class SceneGraph;
class QTreeWidgetItem;

namespace Ui {
class PCDViewerMainWindow;
}

class PCDViewerMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PCDViewerMainWindow(PointCloudDb::PointCloudDbManager *ptrPCDbManager,
                                 QWidget *parent = 0);
    ~PCDViewerMainWindow();
    PaintCanvas* canvas() { return mMainCanvas; }
    SceneGraph* output(const std::string& msg) ;

    bool existsPoints();
    bool getUpdatedPoints(QMap<int,QString>& tilesTableNamesById,
                          QVector<int>& pointsTilesTableNameId,
                          QVector<int>& pointsIdInTileTable,
                          QString& strError);
    bool setSymbology(QString fileName,
                      QString& strError);
    void showCoordinateUnderMouse(const Point3f& p, bool found);
    void showPixelPositionUnderMouse(const QPoint& p);

    void updateStatusBar();
    void updateAnnotationTable();

    bool loadPointCloud(const QString &fileName);
    bool loadPointCloudFromSpatialiteDb(QString& dbFileName,
                                        QString wktGeometry,
                                        int geometryCrsEpsgCode,
                                        QString geometryCrsProj4String,
                                        QString& strError);
    bool resetUpdatedPoints(QString& strError);
    bool setModelDbManager(ModelDb::ModelDbManager* ptrModelDbManager,
                           QString modelProjectSpatialiteDbFileName,
                           QString strError);

public slots:
    void assignColorByClassification();
    void assignColorByObjectClassification();
    void assignColorByHeight();
    void assignColorByRGB();
    void setFullScreen(bool b);
    void operationModeChanged(QAction* act);
    void treeItemDataChanged(QTreeWidgetItem* item, int col);

signals:
    void closed();

private slots:

    void on_changeClassRadioButton_clicked();

    void on_selectOnlyRadioButton_clicked();

    void on_removeRadioButton_clicked();

    void on_toOriginalClassRadioButton_clicked();

    void on_unselectRadioButton_clicked();

    void on_recoverRadioButton_clicked();

    void on_allClassesPushButton_clicked();

    void on_toClass1PushButton_clicked();

    void on_toClass2PushButton_clicked();

    void on_toClass6PushButton_clicked();

    void on_toClass3PushButton_clicked();

    void on_toClass4PushButton_clicked();

    void on_toClass5PushButton_clicked();

    void on_toClass7PushButton_clicked();

    void on_toClass9PushButton_clicked();

    void on_toClass0PushButton_clicked();

    void on_getAltitudeStatisticsForSelectedPointsPushButton_clicked();

    void on_getDifferencesAltitudeForSelectedPointsPushButton_clicked();

    void on_toClass12PushButton_clicked();

    void on_visibleClass0CheckBox_clicked();

    void on_visibleClass1CheckBox_clicked();

    void on_visibleClass2CheckBox_clicked();

    void on_visibleClass6CheckBox_clicked();

    void on_visibleClass3CheckBox_clicked();

    void on_visibleClass4CheckBox_clicked();

    void on_visibleClass5CheckBox_clicked();

    void on_visibleClass7CheckBox_clicked();

    void on_visibleClass9CheckBox_clicked();

    void on_visibleClass12CheckBox_clicked();

    void onVisibleObjectClassesComboCheckBox(int row,
                                             bool isChecked,
                                             QString text,
                                             QString data);

    void onVisibleObjectsComboCheckBox(int row,
                                       bool isChecked,
                                       QString text,
                                       QString data);

    void onLockedObjectClassesComboCheckBox(int row,
                                            bool isChecked,
                                            QString text,
                                            QString data);

    void onLockecObjectsComboCheckBox(int row,
                                      bool isChecked,
                                      QString text,
                                      QString data);

//    void onSelectedObjectComboCheckBox(int row,
//                                       bool isChecked,
//                                       QString text,
//                                       QString data);

    void on_processSelectedObjectPointsPushButton_clicked();

    void on_editObjectClassPushButton_clicked();

    void onVisibleParametricGeometriesObjectClassesComboCheckBox(int row,
                                                                 bool isChecked,
                                                                 QString text,
                                                                 QString data);

    void onVisibleParametricGeometriesObjectsComboCheckBox(int row,
                                                           bool isChecked,
                                                           QString text,
                                                           QString data);

private:
    void actionSetVisiblePoints();
    void actionWithSelectedPoints(int newClass);
    void enableAllClasses();
    void unenableAllClasses();
    void clearPoints();
    void closeEvent(QCloseEvent *event);

    void createMenus();
    void createActions();
    void createStatusBar();

//	void createActionsForFileMenu();
    void createActionsForViewMenu();
    void createActionsForSelectMenu();
    void createActionsForEditMenu();

    bool initialize();
    void recoverLockedClassesFromGui();

    //    bool loadPointCloud(const QString &fileName);
    bool savePointCloud(const QString &fileName);
    void setCurrentPointCloudFile(const QString &fileName);
    void showStatusMessage(const QString &text, int timeout = 0);
    QString strippedName(const QString &fullFileName);
//    void updateRecentFileActions();
    void unselectPoints();

    Ui::PCDViewerMainWindow *ui;
    PaintCanvas*  mMainCanvas;
    QString mCurrentPointCloudFileName;
    QString curDataDirectory_;
    QLabel *statusLabel,
        *spacerLabel,
        *coordinateUnderMouseLabel,
        *numVerticesLabel,
        *numVertexGroupsLabel;

    QMap<int,QString> mTilesTableNamesById;
    QVector<int> mPointsTilesTableNameId;
    QVector<int> mPointsIdInTileTable;
    QVector<int> mUpdatedPointsIdInTileTable;
    QVector<double> mPointsGpsTime;
    QVector<int> mPointsBlue;
    QVector<int> mPointsRed;
    QVector<int> mPointsGreen;
    QVector<int> mPointsNir;
    QVector<int> mPointsIntensity;
    QVector<int> mPointsReturns;
    QVector<int> mPointsReturn;
    QVector<int> mPointsClass;
    QVector<int> mPointsClassNew;
    QVector<bool> mPointsRemoved;
    QVector<double> mPointsFc;
    QVector<double> mPointsSc;
    QVector<double> mPointsHeight;
    QVector<double> mPointsAltitude;
    double mMinimumFc;
    double mMaximumFc;
    double mMinimumSc;
    double mMaximumSc;
    float mMinimumAltitude;
    float mMaximumAltitude;
//    PointSet* mPointSet;
    QString mSymbologyFileName;
    QMap<int,QString> mClassNameByClassId;
    int mClassIdRemovedPoints;
    QMap<int,QVector<int> > mClassColorByClassId;
    QMap<int,VertexGroup*> mVertexGroupByClassId;
    float mRGBColorToUnit;
    QMap<int,bool> mLockedClassesByClassId;
    QMap<int,bool> mVisibleClassesByClassId;
    PointCloudDb::PointCloudDbManager* mPtrPCDbManager;

    ModelDb::ModelDbManager* mPtrModelDbManager;
    QString mModelProjectSpatialiteDbFileName;
    QMap<int,int> mTilesDbIdById;
    QVector<int> mPointsTilesDbId;
    QVector<int> mPointsObjectDbId; // -1 si no pertenece a ninguno
    QVector<int> mPointsDbId;
    QMap<int,QString> mObjectNameByObjectDbId;
    QMap<int,int> mObjectClassDbIdByObjectDbId;
    QMap<int,QString> mObjectClassNameByObjectClassId;
    QMap<int,QVector<int> > mObjectClassColorByObjectClassId;
    QMap<int,VertexGroup*> mVertexGroupByObjectId;
    double mObjectClassRGBColorToUnit;
    QMap<int,bool> mLockedObjectClassesByObjectClassId;
    QMap<int,bool> mVisibleObjectClassesByObjectClassId;
    QMap<int,bool> mLockedObjectsByObjectId;
    QMap<int,bool> mVisibleObjectsByObjectId;

    QComboCheckBox* mVisibleObjectClassesComboCheckBox;
    QComboCheckBox* mVisibleObjectsComboCheckBox;
    QComboCheckBox* mLockedObjectClassesComboCheckBox;
    QComboCheckBox* mLockedObjectsComboCheckBox;
    QComboCheckBox* mSelectedObjectComboCheckBox;

    bool mViewParametricGeometries;
    QMap<int,QString> mPGNameByPGDbId;
    QMap<int,int> mPGObjectDbIdByPGDbId;
    QMap<int,QVector<int> > mPGDbIdsByPGObjectDbId;// un objeto puede tener varias
    QVector<int> mPointsPGDbId; // -1 si no pertenece a ninguno, para consultar para cualquier punto
    QMap<int,bool> mVisiblePGObjectClassesByObjectClassId;
    QMap<int,bool> mVisiblePGPByGDbId;
    QComboCheckBox* mVisiblePGObjectClassesComboCheckBox;
    QComboCheckBox* mVisiblePGsComboCheckBox;
};

#endif // PCDVIEWERMAINWINDOW_H
