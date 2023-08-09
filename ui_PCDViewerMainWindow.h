/********************************************************************************
** Form generated from reading UI file 'PCDViewerMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PCDVIEWERMAINWINDOW_H
#define UI_PCDVIEWERMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PCDViewerMainWindow
{
public:
    QAction *actionFullScreen;
    QAction *actionFitWindow;
    QAction *actionSceneManipulation;
    QAction *actionPerspectiveOrthographic;
    QAction *actionShowCoordinateSystem;
    QAction *actionIncreasePointSize;
    QAction *actionDecreasePointSize;
    QAction *actionSelectPointsByRectangle;
    QAction *actionSelectPointsByPolygon;
    QAction *actionSelectPointsByFreehand;
    QAction *actionUnselectPoints;
    QAction *actionDeleteSelectedPoints;
    QAction *actionAssignColorByHeight;
    QAction *actionAssignColorByIntensity;
    QAction *actionAssignColorByRGB;
    QAction *actionAssignColorByClassification;
    QAction *actionAssignColorByObjectClassification;
    QAction *actionActionAssignColorByObjectClassification;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuView;
    QMenu *menuSeelct;
    QMenu *menuHelp;
    QStatusBar *statusbar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout_5;
    QToolBox *toolBox;
    QWidget *manualEditingProcessesPage;
    QGridLayout *gridLayout_11;
    QTabWidget *processTabWidget_2;
    QWidget *tab_2;
    QGridLayout *gridLayout_14;
    QSpacerItem *horizontalSpacer_16;
    QSpacerItem *horizontalSpacer_14;
    QRadioButton *selectOnlyRadioButton;
    QRadioButton *changeClassRadioButton;
    QRadioButton *removeRadioButton;
    QRadioButton *unselectRadioButton;
    QRadioButton *recoverRadioButton;
    QRadioButton *toOriginalClassRadioButton;
    QTabWidget *processSelectedPointsTabWidget_2;
    QWidget *classesToProcessTab_2;
    QGridLayout *gridLayout_15;
    QPushButton *allClassesPushButton;
    QPushButton *toClass2PushButton;
    QPushButton *toClass1PushButton;
    QPushButton *toClass6PushButton;
    QPushButton *toClass7PushButton;
    QPushButton *toClass3PushButton;
    QPushButton *toClass5PushButton;
    QPushButton *toClass4PushButton;
    QPushButton *toClass9PushButton;
    QLabel *label_6;
    QPushButton *toClass0PushButton;
    QSpacerItem *horizontalSpacer_17;
    QPushButton *toClass12PushButton;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout_19;
    QCheckBox *visibleClass0CheckBox;
    QCheckBox *visibleClass1CheckBox;
    QCheckBox *visibleClass2CheckBox;
    QCheckBox *visibleClass6CheckBox;
    QLabel *label_8;
    QCheckBox *visibleClass3CheckBox;
    QCheckBox *visibleClass4CheckBox;
    QCheckBox *visibleClass5CheckBox;
    QSpacerItem *horizontalSpacer_19;
    QCheckBox *visibleClass7CheckBox;
    QCheckBox *visibleClass9CheckBox;
    QCheckBox *visibleClass12CheckBox;
    QWidget *lockedClassesTab_2;
    QGridLayout *gridLayout_16;
    QGridLayout *gridLayout_17;
    QCheckBox *lockedClass0CheckBox;
    QCheckBox *lockedClass1CheckBox;
    QCheckBox *lockedClass2CheckBox;
    QCheckBox *lockedClass6CheckBox;
    QLabel *label_7;
    QCheckBox *lockedClass3CheckBox;
    QCheckBox *lockedClass4CheckBox;
    QCheckBox *lockedClass5CheckBox;
    QSpacerItem *horizontalSpacer_18;
    QCheckBox *lockedClass7CheckBox;
    QCheckBox *lockedClass9CheckBox;
    QCheckBox *lockedClass12CheckBox;
    QWidget *altitudeDifferencesAnalisysTab_2;
    QGridLayout *gridLayout_18;
    QSpacerItem *horizontalSpacer_21;
    QPushButton *getAltitudeStatisticsForSelectedPointsPushButton;
    QSpacerItem *horizontalSpacer_22;
    QLabel *meanAltitudeLabel_2;
    QLineEdit *meanAltitudeLineEdit;
    QLabel *stdAltitudeLabel_2;
    QLineEdit *stdAltitudeLineEdit;
    QPushButton *getDifferencesAltitudeForSelectedPointsPushButton;
    QLineEdit *altitudeDifferenceLineEdit;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *verticalSpacer_3;
    QWidget *modelingObjectsProcessingPage;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QComboBox *objectClassComboBox;
    QPushButton *addObjectClassPushButton;
    QPushButton *removeObjectClassPpushButton;
    QPushButton *editObjectClassPushButton;
    QLabel *label_2;
    QComboBox *objectComboBox;
    QPushButton *addObjectPushButton;
    QPushButton *removeObjectPpushButton;
    QPushButton *editObjectPushButton;
    QTabWidget *tabWidget;
    QWidget *processWithSelectedPointsTab;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout;
    QFrame *visibleObjectClassesFrame;
    QFrame *visibleObjectsFrame;
    QFrame *lockedObjectClassesFrame;
    QFrame *lockedObjectsFrame;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *assignToObjectRadioButton;
    QRadioButton *unassignToObjectRadioButton;
    QRadioButton *selectOnlyObjectRadioButton;
    QRadioButton *unselectObjectRadioButton;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QComboBox *selectObjectComboBox;
    QPushButton *processSelectedObjectPointsPushButton;
    QWidget *parametricGeometriesTab;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_7;
    QFrame *visibleParametricGeometriesObjectClassesFrame;
    QFrame *visibleParametricGeometriesObjectsFrame;
    QFrame *lockedObjectClassesFrame_2;
    QFrame *lockedObjectsFrame_2;
    QSpacerItem *verticalSpacer;
    QTreeWidget *treeWidget;
    QPlainTextEdit *plainTextEditOutput;
    QToolBar *toolBar;

    void setupUi(QMainWindow *PCDViewerMainWindow)
    {
        if (PCDViewerMainWindow->objectName().isEmpty())
            PCDViewerMainWindow->setObjectName(QString::fromUtf8("PCDViewerMainWindow"));
        PCDViewerMainWindow->resize(1062, 905);
        actionFullScreen = new QAction(PCDViewerMainWindow);
        actionFullScreen->setObjectName(QString::fromUtf8("actionFullScreen"));
        actionFullScreen->setCheckable(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Resources/fullscreen.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFullScreen->setIcon(icon);
        actionFitWindow = new QAction(PCDViewerMainWindow);
        actionFitWindow->setObjectName(QString::fromUtf8("actionFitWindow"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Resources/mActionZoomFullExtent.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFitWindow->setIcon(icon1);
        actionSceneManipulation = new QAction(PCDViewerMainWindow);
        actionSceneManipulation->setObjectName(QString::fromUtf8("actionSceneManipulation"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Resources/mActionPan.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSceneManipulation->setIcon(icon2);
        actionPerspectiveOrthographic = new QAction(PCDViewerMainWindow);
        actionPerspectiveOrthographic->setObjectName(QString::fromUtf8("actionPerspectiveOrthographic"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Resources/perspective.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPerspectiveOrthographic->setIcon(icon3);
        actionShowCoordinateSystem = new QAction(PCDViewerMainWindow);
        actionShowCoordinateSystem->setObjectName(QString::fromUtf8("actionShowCoordinateSystem"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Resources/axis.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShowCoordinateSystem->setIcon(icon4);
        actionIncreasePointSize = new QAction(PCDViewerMainWindow);
        actionIncreasePointSize->setObjectName(QString::fromUtf8("actionIncreasePointSize"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Resources/mActionZoomIn.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionIncreasePointSize->setIcon(icon5);
        actionDecreasePointSize = new QAction(PCDViewerMainWindow);
        actionDecreasePointSize->setObjectName(QString::fromUtf8("actionDecreasePointSize"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Resources/mActionZoomOut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDecreasePointSize->setIcon(icon6);
        actionSelectPointsByRectangle = new QAction(PCDViewerMainWindow);
        actionSelectPointsByRectangle->setObjectName(QString::fromUtf8("actionSelectPointsByRectangle"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Resources/mActionSelectRectangle.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelectPointsByRectangle->setIcon(icon7);
        actionSelectPointsByPolygon = new QAction(PCDViewerMainWindow);
        actionSelectPointsByPolygon->setObjectName(QString::fromUtf8("actionSelectPointsByPolygon"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Resources/mActionSelectPolygon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelectPointsByPolygon->setIcon(icon8);
        actionSelectPointsByFreehand = new QAction(PCDViewerMainWindow);
        actionSelectPointsByFreehand->setObjectName(QString::fromUtf8("actionSelectPointsByFreehand"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Resources/mActionSelectFreehand.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelectPointsByFreehand->setIcon(icon9);
        actionUnselectPoints = new QAction(PCDViewerMainWindow);
        actionUnselectPoints->setObjectName(QString::fromUtf8("actionUnselectPoints"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/Resources/mActionDeleteSelected.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUnselectPoints->setIcon(icon10);
        actionDeleteSelectedPoints = new QAction(PCDViewerMainWindow);
        actionDeleteSelectedPoints->setObjectName(QString::fromUtf8("actionDeleteSelectedPoints"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/Resources/deleted_selected.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDeleteSelectedPoints->setIcon(icon11);
        actionAssignColorByHeight = new QAction(PCDViewerMainWindow);
        actionAssignColorByHeight->setObjectName(QString::fromUtf8("actionAssignColorByHeight"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/Resources/color_by_height.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAssignColorByHeight->setIcon(icon12);
        actionAssignColorByIntensity = new QAction(PCDViewerMainWindow);
        actionAssignColorByIntensity->setObjectName(QString::fromUtf8("actionAssignColorByIntensity"));
        actionAssignColorByRGB = new QAction(PCDViewerMainWindow);
        actionAssignColorByRGB->setObjectName(QString::fromUtf8("actionAssignColorByRGB"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/Resources/mActionAssignColorByRGB.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAssignColorByRGB->setIcon(icon13);
        actionAssignColorByClassification = new QAction(PCDViewerMainWindow);
        actionAssignColorByClassification->setObjectName(QString::fromUtf8("actionAssignColorByClassification"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/Resources/mActionAssignColorByClassification.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAssignColorByClassification->setIcon(icon14);
        actionAssignColorByObjectClassification = new QAction(PCDViewerMainWindow);
        actionAssignColorByObjectClassification->setObjectName(QString::fromUtf8("actionAssignColorByObjectClassification"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/Resources/mActionAssignColorByObjectClassification.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAssignColorByObjectClassification->setIcon(icon15);
        actionActionAssignColorByObjectClassification = new QAction(PCDViewerMainWindow);
        actionActionAssignColorByObjectClassification->setObjectName(QString::fromUtf8("actionActionAssignColorByObjectClassification"));
        actionActionAssignColorByObjectClassification->setIcon(icon15);
        centralwidget = new QWidget(PCDViewerMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(600, 800));
        PCDViewerMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PCDViewerMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1062, 21));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuSeelct = new QMenu(menubar);
        menuSeelct->setObjectName(QString::fromUtf8("menuSeelct"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        PCDViewerMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(PCDViewerMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        PCDViewerMainWindow->setStatusBar(statusbar);
        dockWidget = new QDockWidget(PCDViewerMainWindow);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        gridLayout_5 = new QGridLayout(dockWidgetContents);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        toolBox = new QToolBox(dockWidgetContents);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setMinimumSize(QSize(440, 380));
        manualEditingProcessesPage = new QWidget();
        manualEditingProcessesPage->setObjectName(QString::fromUtf8("manualEditingProcessesPage"));
        manualEditingProcessesPage->setGeometry(QRect(0, 0, 443, 326));
        gridLayout_11 = new QGridLayout(manualEditingProcessesPage);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        processTabWidget_2 = new QTabWidget(manualEditingProcessesPage);
        processTabWidget_2->setObjectName(QString::fromUtf8("processTabWidget_2"));
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_14 = new QGridLayout(tab_2);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        horizontalSpacer_16 = new QSpacerItem(106, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_14->addItem(horizontalSpacer_16, 1, 3, 1, 2);

        horizontalSpacer_14 = new QSpacerItem(106, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_14->addItem(horizontalSpacer_14, 0, 3, 1, 2);

        selectOnlyRadioButton = new QRadioButton(tab_2);
        selectOnlyRadioButton->setObjectName(QString::fromUtf8("selectOnlyRadioButton"));

        gridLayout_14->addWidget(selectOnlyRadioButton, 0, 1, 1, 1);

        changeClassRadioButton = new QRadioButton(tab_2);
        changeClassRadioButton->setObjectName(QString::fromUtf8("changeClassRadioButton"));
        changeClassRadioButton->setChecked(true);

        gridLayout_14->addWidget(changeClassRadioButton, 0, 0, 1, 1);

        removeRadioButton = new QRadioButton(tab_2);
        removeRadioButton->setObjectName(QString::fromUtf8("removeRadioButton"));

        gridLayout_14->addWidget(removeRadioButton, 0, 2, 1, 1);

        unselectRadioButton = new QRadioButton(tab_2);
        unselectRadioButton->setObjectName(QString::fromUtf8("unselectRadioButton"));

        gridLayout_14->addWidget(unselectRadioButton, 1, 1, 1, 1);

        recoverRadioButton = new QRadioButton(tab_2);
        recoverRadioButton->setObjectName(QString::fromUtf8("recoverRadioButton"));

        gridLayout_14->addWidget(recoverRadioButton, 1, 2, 1, 1);

        toOriginalClassRadioButton = new QRadioButton(tab_2);
        toOriginalClassRadioButton->setObjectName(QString::fromUtf8("toOriginalClassRadioButton"));

        gridLayout_14->addWidget(toOriginalClassRadioButton, 1, 0, 1, 1);

        processSelectedPointsTabWidget_2 = new QTabWidget(tab_2);
        processSelectedPointsTabWidget_2->setObjectName(QString::fromUtf8("processSelectedPointsTabWidget_2"));
        classesToProcessTab_2 = new QWidget();
        classesToProcessTab_2->setObjectName(QString::fromUtf8("classesToProcessTab_2"));
        gridLayout_15 = new QGridLayout(classesToProcessTab_2);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        allClassesPushButton = new QPushButton(classesToProcessTab_2);
        allClassesPushButton->setObjectName(QString::fromUtf8("allClassesPushButton"));

        gridLayout_15->addWidget(allClassesPushButton, 0, 0, 1, 1);

        toClass2PushButton = new QPushButton(classesToProcessTab_2);
        toClass2PushButton->setObjectName(QString::fromUtf8("toClass2PushButton"));

        gridLayout_15->addWidget(toClass2PushButton, 0, 2, 1, 1);

        toClass1PushButton = new QPushButton(classesToProcessTab_2);
        toClass1PushButton->setObjectName(QString::fromUtf8("toClass1PushButton"));

        gridLayout_15->addWidget(toClass1PushButton, 0, 1, 1, 1);

        toClass6PushButton = new QPushButton(classesToProcessTab_2);
        toClass6PushButton->setObjectName(QString::fromUtf8("toClass6PushButton"));

        gridLayout_15->addWidget(toClass6PushButton, 0, 3, 1, 1);

        toClass7PushButton = new QPushButton(classesToProcessTab_2);
        toClass7PushButton->setObjectName(QString::fromUtf8("toClass7PushButton"));

        gridLayout_15->addWidget(toClass7PushButton, 2, 1, 1, 1);

        toClass3PushButton = new QPushButton(classesToProcessTab_2);
        toClass3PushButton->setObjectName(QString::fromUtf8("toClass3PushButton"));

        gridLayout_15->addWidget(toClass3PushButton, 1, 1, 1, 1);

        toClass5PushButton = new QPushButton(classesToProcessTab_2);
        toClass5PushButton->setObjectName(QString::fromUtf8("toClass5PushButton"));

        gridLayout_15->addWidget(toClass5PushButton, 1, 3, 1, 1);

        toClass4PushButton = new QPushButton(classesToProcessTab_2);
        toClass4PushButton->setObjectName(QString::fromUtf8("toClass4PushButton"));

        gridLayout_15->addWidget(toClass4PushButton, 1, 2, 1, 1);

        toClass9PushButton = new QPushButton(classesToProcessTab_2);
        toClass9PushButton->setObjectName(QString::fromUtf8("toClass9PushButton"));

        gridLayout_15->addWidget(toClass9PushButton, 2, 2, 1, 1);

        label_6 = new QLabel(classesToProcessTab_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_15->addWidget(label_6, 1, 0, 1, 1);

        toClass0PushButton = new QPushButton(classesToProcessTab_2);
        toClass0PushButton->setObjectName(QString::fromUtf8("toClass0PushButton"));

        gridLayout_15->addWidget(toClass0PushButton, 2, 3, 1, 1);

        horizontalSpacer_17 = new QSpacerItem(91, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_15->addItem(horizontalSpacer_17, 2, 0, 1, 1);

        toClass12PushButton = new QPushButton(classesToProcessTab_2);
        toClass12PushButton->setObjectName(QString::fromUtf8("toClass12PushButton"));

        gridLayout_15->addWidget(toClass12PushButton, 3, 1, 1, 1);

        processSelectedPointsTabWidget_2->addTab(classesToProcessTab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_19 = new QGridLayout();
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        visibleClass0CheckBox = new QCheckBox(tab);
        visibleClass0CheckBox->setObjectName(QString::fromUtf8("visibleClass0CheckBox"));

        gridLayout_19->addWidget(visibleClass0CheckBox, 0, 0, 1, 1);

        visibleClass1CheckBox = new QCheckBox(tab);
        visibleClass1CheckBox->setObjectName(QString::fromUtf8("visibleClass1CheckBox"));

        gridLayout_19->addWidget(visibleClass1CheckBox, 0, 1, 1, 1);

        visibleClass2CheckBox = new QCheckBox(tab);
        visibleClass2CheckBox->setObjectName(QString::fromUtf8("visibleClass2CheckBox"));

        gridLayout_19->addWidget(visibleClass2CheckBox, 0, 2, 1, 1);

        visibleClass6CheckBox = new QCheckBox(tab);
        visibleClass6CheckBox->setObjectName(QString::fromUtf8("visibleClass6CheckBox"));

        gridLayout_19->addWidget(visibleClass6CheckBox, 0, 3, 1, 1);

        label_8 = new QLabel(tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_19->addWidget(label_8, 1, 0, 1, 1);

        visibleClass3CheckBox = new QCheckBox(tab);
        visibleClass3CheckBox->setObjectName(QString::fromUtf8("visibleClass3CheckBox"));

        gridLayout_19->addWidget(visibleClass3CheckBox, 1, 1, 1, 1);

        visibleClass4CheckBox = new QCheckBox(tab);
        visibleClass4CheckBox->setObjectName(QString::fromUtf8("visibleClass4CheckBox"));

        gridLayout_19->addWidget(visibleClass4CheckBox, 1, 2, 1, 1);

        visibleClass5CheckBox = new QCheckBox(tab);
        visibleClass5CheckBox->setObjectName(QString::fromUtf8("visibleClass5CheckBox"));

        gridLayout_19->addWidget(visibleClass5CheckBox, 1, 3, 1, 1);

        horizontalSpacer_19 = new QSpacerItem(70, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_19->addItem(horizontalSpacer_19, 2, 0, 1, 1);

        visibleClass7CheckBox = new QCheckBox(tab);
        visibleClass7CheckBox->setObjectName(QString::fromUtf8("visibleClass7CheckBox"));

        gridLayout_19->addWidget(visibleClass7CheckBox, 2, 1, 1, 1);

        visibleClass9CheckBox = new QCheckBox(tab);
        visibleClass9CheckBox->setObjectName(QString::fromUtf8("visibleClass9CheckBox"));

        gridLayout_19->addWidget(visibleClass9CheckBox, 2, 2, 1, 1);

        visibleClass12CheckBox = new QCheckBox(tab);
        visibleClass12CheckBox->setObjectName(QString::fromUtf8("visibleClass12CheckBox"));

        gridLayout_19->addWidget(visibleClass12CheckBox, 2, 3, 1, 1);


        gridLayout_2->addLayout(gridLayout_19, 0, 0, 1, 1);

        processSelectedPointsTabWidget_2->addTab(tab, QString());
        lockedClassesTab_2 = new QWidget();
        lockedClassesTab_2->setObjectName(QString::fromUtf8("lockedClassesTab_2"));
        gridLayout_16 = new QGridLayout(lockedClassesTab_2);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        gridLayout_17 = new QGridLayout();
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        lockedClass0CheckBox = new QCheckBox(lockedClassesTab_2);
        lockedClass0CheckBox->setObjectName(QString::fromUtf8("lockedClass0CheckBox"));

        gridLayout_17->addWidget(lockedClass0CheckBox, 0, 0, 1, 1);

        lockedClass1CheckBox = new QCheckBox(lockedClassesTab_2);
        lockedClass1CheckBox->setObjectName(QString::fromUtf8("lockedClass1CheckBox"));

        gridLayout_17->addWidget(lockedClass1CheckBox, 0, 1, 1, 1);

        lockedClass2CheckBox = new QCheckBox(lockedClassesTab_2);
        lockedClass2CheckBox->setObjectName(QString::fromUtf8("lockedClass2CheckBox"));

        gridLayout_17->addWidget(lockedClass2CheckBox, 0, 2, 1, 1);

        lockedClass6CheckBox = new QCheckBox(lockedClassesTab_2);
        lockedClass6CheckBox->setObjectName(QString::fromUtf8("lockedClass6CheckBox"));

        gridLayout_17->addWidget(lockedClass6CheckBox, 0, 3, 1, 1);

        label_7 = new QLabel(lockedClassesTab_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_17->addWidget(label_7, 1, 0, 1, 1);

        lockedClass3CheckBox = new QCheckBox(lockedClassesTab_2);
        lockedClass3CheckBox->setObjectName(QString::fromUtf8("lockedClass3CheckBox"));

        gridLayout_17->addWidget(lockedClass3CheckBox, 1, 1, 1, 1);

        lockedClass4CheckBox = new QCheckBox(lockedClassesTab_2);
        lockedClass4CheckBox->setObjectName(QString::fromUtf8("lockedClass4CheckBox"));

        gridLayout_17->addWidget(lockedClass4CheckBox, 1, 2, 1, 1);

        lockedClass5CheckBox = new QCheckBox(lockedClassesTab_2);
        lockedClass5CheckBox->setObjectName(QString::fromUtf8("lockedClass5CheckBox"));

        gridLayout_17->addWidget(lockedClass5CheckBox, 1, 3, 1, 1);

        horizontalSpacer_18 = new QSpacerItem(70, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_17->addItem(horizontalSpacer_18, 2, 0, 1, 1);

        lockedClass7CheckBox = new QCheckBox(lockedClassesTab_2);
        lockedClass7CheckBox->setObjectName(QString::fromUtf8("lockedClass7CheckBox"));

        gridLayout_17->addWidget(lockedClass7CheckBox, 2, 1, 1, 1);

        lockedClass9CheckBox = new QCheckBox(lockedClassesTab_2);
        lockedClass9CheckBox->setObjectName(QString::fromUtf8("lockedClass9CheckBox"));

        gridLayout_17->addWidget(lockedClass9CheckBox, 2, 2, 1, 1);

        lockedClass12CheckBox = new QCheckBox(lockedClassesTab_2);
        lockedClass12CheckBox->setObjectName(QString::fromUtf8("lockedClass12CheckBox"));

        gridLayout_17->addWidget(lockedClass12CheckBox, 2, 3, 1, 1);


        gridLayout_16->addLayout(gridLayout_17, 0, 0, 1, 1);

        processSelectedPointsTabWidget_2->addTab(lockedClassesTab_2, QString());

        gridLayout_14->addWidget(processSelectedPointsTabWidget_2, 2, 0, 1, 5);

        processTabWidget_2->addTab(tab_2, QString());
        altitudeDifferencesAnalisysTab_2 = new QWidget();
        altitudeDifferencesAnalisysTab_2->setObjectName(QString::fromUtf8("altitudeDifferencesAnalisysTab_2"));
        gridLayout_18 = new QGridLayout(altitudeDifferencesAnalisysTab_2);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        horizontalSpacer_21 = new QSpacerItem(116, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_18->addItem(horizontalSpacer_21, 0, 0, 1, 2);

        getAltitudeStatisticsForSelectedPointsPushButton = new QPushButton(altitudeDifferencesAnalisysTab_2);
        getAltitudeStatisticsForSelectedPointsPushButton->setObjectName(QString::fromUtf8("getAltitudeStatisticsForSelectedPointsPushButton"));

        gridLayout_18->addWidget(getAltitudeStatisticsForSelectedPointsPushButton, 0, 2, 1, 3);

        horizontalSpacer_22 = new QSpacerItem(89, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_18->addItem(horizontalSpacer_22, 0, 5, 1, 1);

        meanAltitudeLabel_2 = new QLabel(altitudeDifferencesAnalisysTab_2);
        meanAltitudeLabel_2->setObjectName(QString::fromUtf8("meanAltitudeLabel_2"));

        gridLayout_18->addWidget(meanAltitudeLabel_2, 1, 0, 1, 1);

        meanAltitudeLineEdit = new QLineEdit(altitudeDifferencesAnalisysTab_2);
        meanAltitudeLineEdit->setObjectName(QString::fromUtf8("meanAltitudeLineEdit"));
        meanAltitudeLineEdit->setReadOnly(true);

        gridLayout_18->addWidget(meanAltitudeLineEdit, 1, 1, 1, 2);

        stdAltitudeLabel_2 = new QLabel(altitudeDifferencesAnalisysTab_2);
        stdAltitudeLabel_2->setObjectName(QString::fromUtf8("stdAltitudeLabel_2"));

        gridLayout_18->addWidget(stdAltitudeLabel_2, 1, 3, 1, 1);

        stdAltitudeLineEdit = new QLineEdit(altitudeDifferencesAnalisysTab_2);
        stdAltitudeLineEdit->setObjectName(QString::fromUtf8("stdAltitudeLineEdit"));
        stdAltitudeLineEdit->setReadOnly(true);

        gridLayout_18->addWidget(stdAltitudeLineEdit, 1, 4, 1, 2);

        getDifferencesAltitudeForSelectedPointsPushButton = new QPushButton(altitudeDifferencesAnalisysTab_2);
        getDifferencesAltitudeForSelectedPointsPushButton->setObjectName(QString::fromUtf8("getDifferencesAltitudeForSelectedPointsPushButton"));
        getDifferencesAltitudeForSelectedPointsPushButton->setMinimumSize(QSize(170, 0));

        gridLayout_18->addWidget(getDifferencesAltitudeForSelectedPointsPushButton, 2, 0, 1, 4);

        altitudeDifferenceLineEdit = new QLineEdit(altitudeDifferencesAnalisysTab_2);
        altitudeDifferenceLineEdit->setObjectName(QString::fromUtf8("altitudeDifferenceLineEdit"));
        altitudeDifferenceLineEdit->setReadOnly(true);

        gridLayout_18->addWidget(altitudeDifferenceLineEdit, 2, 4, 1, 2);

        verticalSpacer_7 = new QSpacerItem(20, 121, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_18->addItem(verticalSpacer_7, 3, 2, 1, 1);

        processTabWidget_2->addTab(altitudeDifferencesAnalisysTab_2, QString());

        gridLayout_11->addWidget(processTabWidget_2, 0, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 177, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_11->addItem(verticalSpacer_3, 1, 0, 1, 1);

        toolBox->addItem(manualEditingProcessesPage, QString::fromUtf8("Manual Editing Processes"));
        modelingObjectsProcessingPage = new QWidget();
        modelingObjectsProcessingPage->setObjectName(QString::fromUtf8("modelingObjectsProcessingPage"));
        modelingObjectsProcessingPage->setGeometry(QRect(0, 0, 440, 326));
        gridLayout_6 = new QGridLayout(modelingObjectsProcessingPage);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label = new QLabel(modelingObjectsProcessingPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(81, 0));
        label->setMaximumSize(QSize(81, 16777215));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        objectClassComboBox = new QComboBox(modelingObjectsProcessingPage);
        objectClassComboBox->setObjectName(QString::fromUtf8("objectClassComboBox"));

        gridLayout_3->addWidget(objectClassComboBox, 0, 1, 1, 1);

        addObjectClassPushButton = new QPushButton(modelingObjectsProcessingPage);
        addObjectClassPushButton->setObjectName(QString::fromUtf8("addObjectClassPushButton"));
        addObjectClassPushButton->setMinimumSize(QSize(45, 0));
        addObjectClassPushButton->setMaximumSize(QSize(45, 16777215));

        gridLayout_3->addWidget(addObjectClassPushButton, 0, 2, 1, 1);

        removeObjectClassPpushButton = new QPushButton(modelingObjectsProcessingPage);
        removeObjectClassPpushButton->setObjectName(QString::fromUtf8("removeObjectClassPpushButton"));
        removeObjectClassPpushButton->setMinimumSize(QSize(60, 0));
        removeObjectClassPpushButton->setMaximumSize(QSize(60, 16777215));

        gridLayout_3->addWidget(removeObjectClassPpushButton, 0, 3, 1, 1);

        editObjectClassPushButton = new QPushButton(modelingObjectsProcessingPage);
        editObjectClassPushButton->setObjectName(QString::fromUtf8("editObjectClassPushButton"));
        editObjectClassPushButton->setMinimumSize(QSize(45, 0));
        editObjectClassPushButton->setMaximumSize(QSize(45, 16777215));

        gridLayout_3->addWidget(editObjectClassPushButton, 0, 4, 1, 1);

        label_2 = new QLabel(modelingObjectsProcessingPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

        objectComboBox = new QComboBox(modelingObjectsProcessingPage);
        objectComboBox->setObjectName(QString::fromUtf8("objectComboBox"));

        gridLayout_3->addWidget(objectComboBox, 1, 1, 1, 1);

        addObjectPushButton = new QPushButton(modelingObjectsProcessingPage);
        addObjectPushButton->setObjectName(QString::fromUtf8("addObjectPushButton"));
        addObjectPushButton->setMinimumSize(QSize(45, 0));
        addObjectPushButton->setMaximumSize(QSize(45, 16777215));

        gridLayout_3->addWidget(addObjectPushButton, 1, 2, 1, 1);

        removeObjectPpushButton = new QPushButton(modelingObjectsProcessingPage);
        removeObjectPpushButton->setObjectName(QString::fromUtf8("removeObjectPpushButton"));
        removeObjectPpushButton->setMinimumSize(QSize(60, 0));
        removeObjectPpushButton->setMaximumSize(QSize(60, 16777215));

        gridLayout_3->addWidget(removeObjectPpushButton, 1, 3, 1, 1);

        editObjectPushButton = new QPushButton(modelingObjectsProcessingPage);
        editObjectPushButton->setObjectName(QString::fromUtf8("editObjectPushButton"));
        editObjectPushButton->setEnabled(false);
        editObjectPushButton->setMinimumSize(QSize(45, 0));
        editObjectPushButton->setMaximumSize(QSize(45, 16777215));

        gridLayout_3->addWidget(editObjectPushButton, 1, 4, 1, 1);


        gridLayout_6->addLayout(gridLayout_3, 0, 0, 1, 1);

        tabWidget = new QTabWidget(modelingObjectsProcessingPage);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        processWithSelectedPointsTab = new QWidget();
        processWithSelectedPointsTab->setObjectName(QString::fromUtf8("processWithSelectedPointsTab"));
        gridLayout_4 = new QGridLayout(processWithSelectedPointsTab);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        visibleObjectClassesFrame = new QFrame(processWithSelectedPointsTab);
        visibleObjectClassesFrame->setObjectName(QString::fromUtf8("visibleObjectClassesFrame"));
        visibleObjectClassesFrame->setMinimumSize(QSize(350, 25));
        visibleObjectClassesFrame->setFrameShape(QFrame::StyledPanel);
        visibleObjectClassesFrame->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(visibleObjectClassesFrame, 0, 0, 1, 1);

        visibleObjectsFrame = new QFrame(processWithSelectedPointsTab);
        visibleObjectsFrame->setObjectName(QString::fromUtf8("visibleObjectsFrame"));
        visibleObjectsFrame->setMinimumSize(QSize(350, 25));
        visibleObjectsFrame->setFrameShape(QFrame::StyledPanel);
        visibleObjectsFrame->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(visibleObjectsFrame, 1, 0, 1, 1);

        lockedObjectClassesFrame = new QFrame(processWithSelectedPointsTab);
        lockedObjectClassesFrame->setObjectName(QString::fromUtf8("lockedObjectClassesFrame"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lockedObjectClassesFrame->sizePolicy().hasHeightForWidth());
        lockedObjectClassesFrame->setSizePolicy(sizePolicy);
        lockedObjectClassesFrame->setMinimumSize(QSize(350, 25));
        lockedObjectClassesFrame->setFrameShape(QFrame::StyledPanel);
        lockedObjectClassesFrame->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(lockedObjectClassesFrame, 2, 0, 1, 1);

        lockedObjectsFrame = new QFrame(processWithSelectedPointsTab);
        lockedObjectsFrame->setObjectName(QString::fromUtf8("lockedObjectsFrame"));
        lockedObjectsFrame->setMinimumSize(QSize(350, 25));
        lockedObjectsFrame->setFrameShape(QFrame::StyledPanel);
        lockedObjectsFrame->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(lockedObjectsFrame, 3, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        assignToObjectRadioButton = new QRadioButton(processWithSelectedPointsTab);
        assignToObjectRadioButton->setObjectName(QString::fromUtf8("assignToObjectRadioButton"));
        assignToObjectRadioButton->setChecked(true);

        horizontalLayout_2->addWidget(assignToObjectRadioButton);

        unassignToObjectRadioButton = new QRadioButton(processWithSelectedPointsTab);
        unassignToObjectRadioButton->setObjectName(QString::fromUtf8("unassignToObjectRadioButton"));

        horizontalLayout_2->addWidget(unassignToObjectRadioButton);

        selectOnlyObjectRadioButton = new QRadioButton(processWithSelectedPointsTab);
        selectOnlyObjectRadioButton->setObjectName(QString::fromUtf8("selectOnlyObjectRadioButton"));

        horizontalLayout_2->addWidget(selectOnlyObjectRadioButton);

        unselectObjectRadioButton = new QRadioButton(processWithSelectedPointsTab);
        unselectObjectRadioButton->setObjectName(QString::fromUtf8("unselectObjectRadioButton"));

        horizontalLayout_2->addWidget(unselectObjectRadioButton);


        gridLayout_4->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(processWithSelectedPointsTab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(70, 0));
        label_3->setMaximumSize(QSize(70, 16777215));

        horizontalLayout->addWidget(label_3);

        selectObjectComboBox = new QComboBox(processWithSelectedPointsTab);
        selectObjectComboBox->setObjectName(QString::fromUtf8("selectObjectComboBox"));

        horizontalLayout->addWidget(selectObjectComboBox);

        processSelectedObjectPointsPushButton = new QPushButton(processWithSelectedPointsTab);
        processSelectedObjectPointsPushButton->setObjectName(QString::fromUtf8("processSelectedObjectPointsPushButton"));
        processSelectedObjectPointsPushButton->setMinimumSize(QSize(75, 0));
        processSelectedObjectPointsPushButton->setMaximumSize(QSize(75, 16777215));

        horizontalLayout->addWidget(processSelectedObjectPointsPushButton);


        gridLayout_4->addLayout(horizontalLayout, 2, 0, 1, 1);

        tabWidget->addTab(processWithSelectedPointsTab, QString());
        parametricGeometriesTab = new QWidget();
        parametricGeometriesTab->setObjectName(QString::fromUtf8("parametricGeometriesTab"));
        layoutWidget = new QWidget(parametricGeometriesTab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 352, 120));
        gridLayout_7 = new QGridLayout(layoutWidget);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        visibleParametricGeometriesObjectClassesFrame = new QFrame(layoutWidget);
        visibleParametricGeometriesObjectClassesFrame->setObjectName(QString::fromUtf8("visibleParametricGeometriesObjectClassesFrame"));
        visibleParametricGeometriesObjectClassesFrame->setMinimumSize(QSize(350, 25));
        visibleParametricGeometriesObjectClassesFrame->setFrameShape(QFrame::StyledPanel);
        visibleParametricGeometriesObjectClassesFrame->setFrameShadow(QFrame::Raised);

        gridLayout_7->addWidget(visibleParametricGeometriesObjectClassesFrame, 0, 0, 1, 1);

        visibleParametricGeometriesObjectsFrame = new QFrame(layoutWidget);
        visibleParametricGeometriesObjectsFrame->setObjectName(QString::fromUtf8("visibleParametricGeometriesObjectsFrame"));
        visibleParametricGeometriesObjectsFrame->setMinimumSize(QSize(350, 25));
        visibleParametricGeometriesObjectsFrame->setFrameShape(QFrame::StyledPanel);
        visibleParametricGeometriesObjectsFrame->setFrameShadow(QFrame::Raised);

        gridLayout_7->addWidget(visibleParametricGeometriesObjectsFrame, 1, 0, 1, 1);

        lockedObjectClassesFrame_2 = new QFrame(layoutWidget);
        lockedObjectClassesFrame_2->setObjectName(QString::fromUtf8("lockedObjectClassesFrame_2"));
        sizePolicy.setHeightForWidth(lockedObjectClassesFrame_2->sizePolicy().hasHeightForWidth());
        lockedObjectClassesFrame_2->setSizePolicy(sizePolicy);
        lockedObjectClassesFrame_2->setMinimumSize(QSize(350, 25));
        lockedObjectClassesFrame_2->setFrameShape(QFrame::StyledPanel);
        lockedObjectClassesFrame_2->setFrameShadow(QFrame::Raised);

        gridLayout_7->addWidget(lockedObjectClassesFrame_2, 2, 0, 1, 1);

        lockedObjectsFrame_2 = new QFrame(layoutWidget);
        lockedObjectsFrame_2->setObjectName(QString::fromUtf8("lockedObjectsFrame_2"));
        lockedObjectsFrame_2->setMinimumSize(QSize(350, 25));
        lockedObjectsFrame_2->setFrameShape(QFrame::StyledPanel);
        lockedObjectsFrame_2->setFrameShadow(QFrame::Raised);

        gridLayout_7->addWidget(lockedObjectsFrame_2, 3, 0, 1, 1);

        tabWidget->addTab(parametricGeometriesTab, QString());

        gridLayout_6->addWidget(tabWidget, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 12, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer, 2, 0, 1, 1);

        toolBox->addItem(modelingObjectsProcessingPage, QString::fromUtf8("Modeling Objects Processing"));

        gridLayout_5->addWidget(toolBox, 0, 0, 1, 1);

        treeWidget = new QTreeWidget(dockWidgetContents);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(3, QString::fromUtf8("4"));
        __qtreewidgetitem->setText(2, QString::fromUtf8("3"));
        __qtreewidgetitem->setText(1, QString::fromUtf8("2"));
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setFrameShape(QFrame::StyledPanel);
        treeWidget->setAutoScrollMargin(0);
        treeWidget->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::SelectedClicked);
        treeWidget->setTabKeyNavigation(true);
        treeWidget->setProperty("showDropIndicator", QVariant(false));
        treeWidget->setAlternatingRowColors(true);
        treeWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        treeWidget->setRootIsDecorated(true);
        treeWidget->setUniformRowHeights(true);
        treeWidget->setSortingEnabled(false);
        treeWidget->setAnimated(true);
        treeWidget->setExpandsOnDoubleClick(true);
        treeWidget->setColumnCount(4);
        treeWidget->header()->setMinimumSectionSize(30);
        treeWidget->header()->setDefaultSectionSize(95);

        gridLayout_5->addWidget(treeWidget, 1, 0, 1, 1);

        plainTextEditOutput = new QPlainTextEdit(dockWidgetContents);
        plainTextEditOutput->setObjectName(QString::fromUtf8("plainTextEditOutput"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(plainTextEditOutput->sizePolicy().hasHeightForWidth());
        plainTextEditOutput->setSizePolicy(sizePolicy1);
        plainTextEditOutput->setMinimumSize(QSize(0, 120));
        plainTextEditOutput->setFocusPolicy(Qt::NoFocus);
        plainTextEditOutput->setAcceptDrops(false);
        plainTextEditOutput->setAutoFillBackground(false);
        plainTextEditOutput->setUndoRedoEnabled(false);
        plainTextEditOutput->setLineWrapMode(QPlainTextEdit::WidgetWidth);
        plainTextEditOutput->setReadOnly(true);

        gridLayout_5->addWidget(plainTextEditOutput, 2, 0, 1, 1);

        dockWidget->setWidget(dockWidgetContents);
        PCDViewerMainWindow->addDockWidget(Qt::LeftDockWidgetArea, dockWidget);
        toolBar = new QToolBar(PCDViewerMainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        PCDViewerMainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuSeelct->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuView->addAction(actionFullScreen);
        menuView->addAction(actionFitWindow);
        menuView->addSeparator();
        menuView->addAction(actionSceneManipulation);
        menuView->addSeparator();
        menuView->addAction(actionPerspectiveOrthographic);
        menuView->addAction(actionShowCoordinateSystem);
        menuView->addSeparator();
        menuView->addAction(actionIncreasePointSize);
        menuView->addAction(actionDecreasePointSize);
        menuView->addSeparator();
        menuView->addAction(actionAssignColorByClassification);
        menuView->addAction(actionAssignColorByRGB);
        menuView->addAction(actionAssignColorByHeight);
        menuView->addAction(actionActionAssignColorByObjectClassification);
        menuView->addAction(actionAssignColorByIntensity);
        menuSeelct->addAction(actionSelectPointsByRectangle);
        menuSeelct->addAction(actionSelectPointsByPolygon);
        menuSeelct->addAction(actionSelectPointsByFreehand);
        menuSeelct->addSeparator();
        menuSeelct->addAction(actionUnselectPoints);
        toolBar->addSeparator();
        toolBar->addAction(actionAssignColorByClassification);
        toolBar->addAction(actionAssignColorByRGB);
        toolBar->addAction(actionAssignColorByHeight);
        toolBar->addSeparator();
        toolBar->addAction(actionAssignColorByObjectClassification);
        toolBar->addAction(actionFitWindow);
        toolBar->addAction(actionSceneManipulation);
        toolBar->addSeparator();
        toolBar->addAction(actionIncreasePointSize);
        toolBar->addAction(actionDecreasePointSize);
        toolBar->addSeparator();
        toolBar->addAction(actionSelectPointsByRectangle);
        toolBar->addAction(actionSelectPointsByFreehand);
        toolBar->addAction(actionUnselectPoints);
        toolBar->addSeparator();

        retranslateUi(PCDViewerMainWindow);

        toolBox->setCurrentIndex(1);
        processTabWidget_2->setCurrentIndex(0);
        processSelectedPointsTabWidget_2->setCurrentIndex(0);
        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(PCDViewerMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PCDViewerMainWindow)
    {
        PCDViewerMainWindow->setWindowTitle(QCoreApplication::translate("PCDViewerMainWindow", "MainWindow", nullptr));
        actionFullScreen->setText(QCoreApplication::translate("PCDViewerMainWindow", "Full Screen", nullptr));
        actionFitWindow->setText(QCoreApplication::translate("PCDViewerMainWindow", "Zoom Full Extent", nullptr));
        actionSceneManipulation->setText(QCoreApplication::translate("PCDViewerMainWindow", "Pan", nullptr));
        actionPerspectiveOrthographic->setText(QCoreApplication::translate("PCDViewerMainWindow", "Perspective/Orthographic", nullptr));
        actionShowCoordinateSystem->setText(QCoreApplication::translate("PCDViewerMainWindow", "Show Coordinate System", nullptr));
        actionIncreasePointSize->setText(QCoreApplication::translate("PCDViewerMainWindow", "Zoom In Point Size", nullptr));
        actionIncreasePointSize->setIconText(QCoreApplication::translate("PCDViewerMainWindow", "Zoom In Point Size", nullptr));
#if QT_CONFIG(tooltip)
        actionIncreasePointSize->setToolTip(QCoreApplication::translate("PCDViewerMainWindow", "Zoom In Point Size", nullptr));
#endif // QT_CONFIG(tooltip)
        actionDecreasePointSize->setText(QCoreApplication::translate("PCDViewerMainWindow", "Zoom Out Point Size", nullptr));
        actionDecreasePointSize->setIconText(QCoreApplication::translate("PCDViewerMainWindow", "Zoom Out Point Size", nullptr));
        actionSelectPointsByRectangle->setText(QCoreApplication::translate("PCDViewerMainWindow", "Select Points by Rectangle", nullptr));
        actionSelectPointsByPolygon->setText(QCoreApplication::translate("PCDViewerMainWindow", "Select Points by Polygon", nullptr));
        actionSelectPointsByFreehand->setText(QCoreApplication::translate("PCDViewerMainWindow", "Select Points by Freehand", nullptr));
        actionUnselectPoints->setText(QCoreApplication::translate("PCDViewerMainWindow", "Unselect Points", nullptr));
        actionDeleteSelectedPoints->setText(QCoreApplication::translate("PCDViewerMainWindow", "Delete Selected Points", nullptr));
        actionAssignColorByHeight->setText(QCoreApplication::translate("PCDViewerMainWindow", "Assign Color by Height", nullptr));
        actionAssignColorByIntensity->setText(QCoreApplication::translate("PCDViewerMainWindow", "Assign Color by Intensity", nullptr));
        actionAssignColorByRGB->setText(QCoreApplication::translate("PCDViewerMainWindow", "Assign Color by RGB", nullptr));
        actionAssignColorByClassification->setText(QCoreApplication::translate("PCDViewerMainWindow", "Assign Color by Classification", nullptr));
        actionAssignColorByObjectClassification->setText(QCoreApplication::translate("PCDViewerMainWindow", "Assign Color by Object Classification", nullptr));
        actionActionAssignColorByObjectClassification->setText(QCoreApplication::translate("PCDViewerMainWindow", "actionAssignColorByObjectClassification", nullptr));
        menuView->setTitle(QCoreApplication::translate("PCDViewerMainWindow", "View", nullptr));
        menuSeelct->setTitle(QCoreApplication::translate("PCDViewerMainWindow", "Seelct", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("PCDViewerMainWindow", "Help", nullptr));
        selectOnlyRadioButton->setText(QCoreApplication::translate("PCDViewerMainWindow", "Select only", nullptr));
        changeClassRadioButton->setText(QCoreApplication::translate("PCDViewerMainWindow", "Change class to", nullptr));
        removeRadioButton->setText(QCoreApplication::translate("PCDViewerMainWindow", "Remove", nullptr));
        unselectRadioButton->setText(QCoreApplication::translate("PCDViewerMainWindow", "Unselect", nullptr));
        recoverRadioButton->setText(QCoreApplication::translate("PCDViewerMainWindow", "Recover", nullptr));
        toOriginalClassRadioButton->setText(QCoreApplication::translate("PCDViewerMainWindow", "To Original Class", nullptr));
        allClassesPushButton->setText(QCoreApplication::translate("PCDViewerMainWindow", "All classes", nullptr));
        toClass2PushButton->setText(QCoreApplication::translate("PCDViewerMainWindow", "2 - Ground", nullptr));
        toClass1PushButton->setText(QCoreApplication::translate("PCDViewerMainWindow", "1 - Unclassified", nullptr));
        toClass6PushButton->setText(QCoreApplication::translate("PCDViewerMainWindow", "6 - Building", nullptr));
        toClass7PushButton->setText(QCoreApplication::translate("PCDViewerMainWindow", "7 - Low Point", nullptr));
        toClass3PushButton->setText(QCoreApplication::translate("PCDViewerMainWindow", "3 - Low", nullptr));
        toClass5PushButton->setText(QCoreApplication::translate("PCDViewerMainWindow", "5 - High", nullptr));
        toClass4PushButton->setText(QCoreApplication::translate("PCDViewerMainWindow", "4 - Medium", nullptr));
        toClass9PushButton->setText(QCoreApplication::translate("PCDViewerMainWindow", "9 - Water", nullptr));
        label_6->setText(QCoreApplication::translate("PCDViewerMainWindow", "Vegetation:", nullptr));
        toClass0PushButton->setText(QCoreApplication::translate("PCDViewerMainWindow", "0 - Created", nullptr));
        toClass12PushButton->setText(QCoreApplication::translate("PCDViewerMainWindow", "12 - Overlap", nullptr));
        processSelectedPointsTabWidget_2->setTabText(processSelectedPointsTabWidget_2->indexOf(classesToProcessTab_2), QCoreApplication::translate("PCDViewerMainWindow", "Classes to process", nullptr));
        visibleClass0CheckBox->setText(QCoreApplication::translate("PCDViewerMainWindow", "0-Created", nullptr));
        visibleClass1CheckBox->setText(QCoreApplication::translate("PCDViewerMainWindow", "1-Unclassified", nullptr));
        visibleClass2CheckBox->setText(QCoreApplication::translate("PCDViewerMainWindow", "2-Ground", nullptr));
        visibleClass6CheckBox->setText(QCoreApplication::translate("PCDViewerMainWindow", "6-Building", nullptr));
        label_8->setText(QCoreApplication::translate("PCDViewerMainWindow", "Vegetation:", nullptr));
        visibleClass3CheckBox->setText(QCoreApplication::translate("PCDViewerMainWindow", "3-Low", nullptr));
        visibleClass4CheckBox->setText(QCoreApplication::translate("PCDViewerMainWindow", "4-Medium", nullptr));
        visibleClass5CheckBox->setText(QCoreApplication::translate("PCDViewerMainWindow", "5-High", nullptr));
        visibleClass7CheckBox->setText(QCoreApplication::translate("PCDViewerMainWindow", "7-Low Point", nullptr));
        visibleClass9CheckBox->setText(QCoreApplication::translate("PCDViewerMainWindow", "9-Water", nullptr));
        visibleClass12CheckBox->setText(QCoreApplication::translate("PCDViewerMainWindow", "12-Overlap", nullptr));
        processSelectedPointsTabWidget_2->setTabText(processSelectedPointsTabWidget_2->indexOf(tab), QCoreApplication::translate("PCDViewerMainWindow", "Visible classes", nullptr));
        lockedClass0CheckBox->setText(QCoreApplication::translate("PCDViewerMainWindow", "0-Created", nullptr));
        lockedClass1CheckBox->setText(QCoreApplication::translate("PCDViewerMainWindow", "1-Unclassified", nullptr));
        lockedClass2CheckBox->setText(QCoreApplication::translate("PCDViewerMainWindow", "2-Ground", nullptr));
        lockedClass6CheckBox->setText(QCoreApplication::translate("PCDViewerMainWindow", "6-Building", nullptr));
        label_7->setText(QCoreApplication::translate("PCDViewerMainWindow", "Vegetation:", nullptr));
        lockedClass3CheckBox->setText(QCoreApplication::translate("PCDViewerMainWindow", "3-Low", nullptr));
        lockedClass4CheckBox->setText(QCoreApplication::translate("PCDViewerMainWindow", "4-Medium", nullptr));
        lockedClass5CheckBox->setText(QCoreApplication::translate("PCDViewerMainWindow", "5-High", nullptr));
        lockedClass7CheckBox->setText(QCoreApplication::translate("PCDViewerMainWindow", "7-Low Point", nullptr));
        lockedClass9CheckBox->setText(QCoreApplication::translate("PCDViewerMainWindow", "9-Water", nullptr));
        lockedClass12CheckBox->setText(QCoreApplication::translate("PCDViewerMainWindow", "12-Overlap", nullptr));
        processSelectedPointsTabWidget_2->setTabText(processSelectedPointsTabWidget_2->indexOf(lockedClassesTab_2), QCoreApplication::translate("PCDViewerMainWindow", "Locked classes", nullptr));
        processTabWidget_2->setTabText(processTabWidget_2->indexOf(tab_2), QCoreApplication::translate("PCDViewerMainWindow", "Process with selected points", nullptr));
        getAltitudeStatisticsForSelectedPointsPushButton->setText(QCoreApplication::translate("PCDViewerMainWindow", "Get altitude statistics for selected points", nullptr));
        meanAltitudeLabel_2->setText(QCoreApplication::translate("PCDViewerMainWindow", "Mean (m):", nullptr));
        stdAltitudeLabel_2->setText(QCoreApplication::translate("PCDViewerMainWindow", "Std (m):", nullptr));
        getDifferencesAltitudeForSelectedPointsPushButton->setText(QCoreApplication::translate("PCDViewerMainWindow", "Altitude - Mean, for selected point (m):", nullptr));
        processTabWidget_2->setTabText(processTabWidget_2->indexOf(altitudeDifferencesAnalisysTab_2), QCoreApplication::translate("PCDViewerMainWindow", "Altitudes differences analisys", nullptr));
        toolBox->setItemText(toolBox->indexOf(manualEditingProcessesPage), QCoreApplication::translate("PCDViewerMainWindow", "Manual Editing Processes", nullptr));
        label->setText(QCoreApplication::translate("PCDViewerMainWindow", "Objects classes:", nullptr));
        addObjectClassPushButton->setText(QCoreApplication::translate("PCDViewerMainWindow", "Add", nullptr));
        removeObjectClassPpushButton->setText(QCoreApplication::translate("PCDViewerMainWindow", "Remvoe", nullptr));
        editObjectClassPushButton->setText(QCoreApplication::translate("PCDViewerMainWindow", "Edit", nullptr));
        label_2->setText(QCoreApplication::translate("PCDViewerMainWindow", "Object:", nullptr));
        addObjectPushButton->setText(QCoreApplication::translate("PCDViewerMainWindow", "Add", nullptr));
        removeObjectPpushButton->setText(QCoreApplication::translate("PCDViewerMainWindow", "Remvoe", nullptr));
        editObjectPushButton->setText(QCoreApplication::translate("PCDViewerMainWindow", "Edit", nullptr));
#if QT_CONFIG(accessibility)
        tabWidget->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        assignToObjectRadioButton->setText(QCoreApplication::translate("PCDViewerMainWindow", "Assign to object", nullptr));
        unassignToObjectRadioButton->setText(QCoreApplication::translate("PCDViewerMainWindow", "Unassign to object", nullptr));
        selectOnlyObjectRadioButton->setText(QCoreApplication::translate("PCDViewerMainWindow", "Select only", nullptr));
        unselectObjectRadioButton->setText(QCoreApplication::translate("PCDViewerMainWindow", "Unselect", nullptr));
        label_3->setText(QCoreApplication::translate("PCDViewerMainWindow", "Select Object:", nullptr));
        processSelectedObjectPointsPushButton->setText(QCoreApplication::translate("PCDViewerMainWindow", "Process", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(processWithSelectedPointsTab), QCoreApplication::translate("PCDViewerMainWindow", "Process with selected points", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(parametricGeometriesTab), QCoreApplication::translate("PCDViewerMainWindow", "Parametric geometries", nullptr));
        toolBox->setItemText(toolBox->indexOf(modelingObjectsProcessingPage), QCoreApplication::translate("PCDViewerMainWindow", "Modeling Objects Processing", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("PCDViewerMainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PCDViewerMainWindow: public Ui_PCDViewerMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PCDVIEWERMAINWINDOW_H
