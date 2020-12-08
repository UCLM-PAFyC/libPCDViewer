/********************************************************************************
** Form generated from reading UI file 'PCDViewerMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PCDVIEWERMAINWINDOW_H
#define UI_PCDVIEWERMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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
            PCDViewerMainWindow->setObjectName(QStringLiteral("PCDViewerMainWindow"));
        PCDViewerMainWindow->resize(1062, 905);
        actionFullScreen = new QAction(PCDViewerMainWindow);
        actionFullScreen->setObjectName(QStringLiteral("actionFullScreen"));
        actionFullScreen->setCheckable(true);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Resources/fullscreen.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFullScreen->setIcon(icon);
        actionFitWindow = new QAction(PCDViewerMainWindow);
        actionFitWindow->setObjectName(QStringLiteral("actionFitWindow"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Resources/mActionZoomFullExtent.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFitWindow->setIcon(icon1);
        actionSceneManipulation = new QAction(PCDViewerMainWindow);
        actionSceneManipulation->setObjectName(QStringLiteral("actionSceneManipulation"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Resources/mActionPan.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSceneManipulation->setIcon(icon2);
        actionPerspectiveOrthographic = new QAction(PCDViewerMainWindow);
        actionPerspectiveOrthographic->setObjectName(QStringLiteral("actionPerspectiveOrthographic"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Resources/perspective.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPerspectiveOrthographic->setIcon(icon3);
        actionShowCoordinateSystem = new QAction(PCDViewerMainWindow);
        actionShowCoordinateSystem->setObjectName(QStringLiteral("actionShowCoordinateSystem"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Resources/axis.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShowCoordinateSystem->setIcon(icon4);
        actionIncreasePointSize = new QAction(PCDViewerMainWindow);
        actionIncreasePointSize->setObjectName(QStringLiteral("actionIncreasePointSize"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Resources/mActionZoomIn.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionIncreasePointSize->setIcon(icon5);
        actionDecreasePointSize = new QAction(PCDViewerMainWindow);
        actionDecreasePointSize->setObjectName(QStringLiteral("actionDecreasePointSize"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/Resources/mActionZoomOut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDecreasePointSize->setIcon(icon6);
        actionSelectPointsByRectangle = new QAction(PCDViewerMainWindow);
        actionSelectPointsByRectangle->setObjectName(QStringLiteral("actionSelectPointsByRectangle"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/Resources/mActionSelectRectangle.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelectPointsByRectangle->setIcon(icon7);
        actionSelectPointsByPolygon = new QAction(PCDViewerMainWindow);
        actionSelectPointsByPolygon->setObjectName(QStringLiteral("actionSelectPointsByPolygon"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/Resources/mActionSelectPolygon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelectPointsByPolygon->setIcon(icon8);
        actionSelectPointsByFreehand = new QAction(PCDViewerMainWindow);
        actionSelectPointsByFreehand->setObjectName(QStringLiteral("actionSelectPointsByFreehand"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/Resources/mActionSelectFreehand.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelectPointsByFreehand->setIcon(icon9);
        actionUnselectPoints = new QAction(PCDViewerMainWindow);
        actionUnselectPoints->setObjectName(QStringLiteral("actionUnselectPoints"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/Resources/mActionDeleteSelected.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUnselectPoints->setIcon(icon10);
        actionDeleteSelectedPoints = new QAction(PCDViewerMainWindow);
        actionDeleteSelectedPoints->setObjectName(QStringLiteral("actionDeleteSelectedPoints"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/Resources/deleted_selected.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDeleteSelectedPoints->setIcon(icon11);
        actionAssignColorByHeight = new QAction(PCDViewerMainWindow);
        actionAssignColorByHeight->setObjectName(QStringLiteral("actionAssignColorByHeight"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/Resources/color_by_height.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAssignColorByHeight->setIcon(icon12);
        actionAssignColorByIntensity = new QAction(PCDViewerMainWindow);
        actionAssignColorByIntensity->setObjectName(QStringLiteral("actionAssignColorByIntensity"));
        actionAssignColorByRGB = new QAction(PCDViewerMainWindow);
        actionAssignColorByRGB->setObjectName(QStringLiteral("actionAssignColorByRGB"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/Resources/mActionAssignColorByRGB.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAssignColorByRGB->setIcon(icon13);
        actionAssignColorByClassification = new QAction(PCDViewerMainWindow);
        actionAssignColorByClassification->setObjectName(QStringLiteral("actionAssignColorByClassification"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/Resources/mActionAssignColorByClassification.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAssignColorByClassification->setIcon(icon14);
        actionAssignColorByObjectClassification = new QAction(PCDViewerMainWindow);
        actionAssignColorByObjectClassification->setObjectName(QStringLiteral("actionAssignColorByObjectClassification"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/Resources/mActionAssignColorByObjectClassification.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAssignColorByObjectClassification->setIcon(icon15);
        actionActionAssignColorByObjectClassification = new QAction(PCDViewerMainWindow);
        actionActionAssignColorByObjectClassification->setObjectName(QStringLiteral("actionActionAssignColorByObjectClassification"));
        actionActionAssignColorByObjectClassification->setIcon(icon15);
        centralwidget = new QWidget(PCDViewerMainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setMinimumSize(QSize(600, 800));
        PCDViewerMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PCDViewerMainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1062, 21));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuSeelct = new QMenu(menubar);
        menuSeelct->setObjectName(QStringLiteral("menuSeelct"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        PCDViewerMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(PCDViewerMainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        PCDViewerMainWindow->setStatusBar(statusbar);
        dockWidget = new QDockWidget(PCDViewerMainWindow);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        gridLayout_5 = new QGridLayout(dockWidgetContents);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        toolBox = new QToolBox(dockWidgetContents);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setMinimumSize(QSize(440, 380));
        manualEditingProcessesPage = new QWidget();
        manualEditingProcessesPage->setObjectName(QStringLiteral("manualEditingProcessesPage"));
        manualEditingProcessesPage->setGeometry(QRect(0, 0, 443, 326));
        gridLayout_11 = new QGridLayout(manualEditingProcessesPage);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        processTabWidget_2 = new QTabWidget(manualEditingProcessesPage);
        processTabWidget_2->setObjectName(QStringLiteral("processTabWidget_2"));
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_14 = new QGridLayout(tab_2);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        horizontalSpacer_16 = new QSpacerItem(106, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_14->addItem(horizontalSpacer_16, 1, 3, 1, 2);

        horizontalSpacer_14 = new QSpacerItem(106, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_14->addItem(horizontalSpacer_14, 0, 3, 1, 2);

        selectOnlyRadioButton = new QRadioButton(tab_2);
        selectOnlyRadioButton->setObjectName(QStringLiteral("selectOnlyRadioButton"));

        gridLayout_14->addWidget(selectOnlyRadioButton, 0, 1, 1, 1);

        changeClassRadioButton = new QRadioButton(tab_2);
        changeClassRadioButton->setObjectName(QStringLiteral("changeClassRadioButton"));
        changeClassRadioButton->setChecked(true);

        gridLayout_14->addWidget(changeClassRadioButton, 0, 0, 1, 1);

        removeRadioButton = new QRadioButton(tab_2);
        removeRadioButton->setObjectName(QStringLiteral("removeRadioButton"));

        gridLayout_14->addWidget(removeRadioButton, 0, 2, 1, 1);

        unselectRadioButton = new QRadioButton(tab_2);
        unselectRadioButton->setObjectName(QStringLiteral("unselectRadioButton"));

        gridLayout_14->addWidget(unselectRadioButton, 1, 1, 1, 1);

        recoverRadioButton = new QRadioButton(tab_2);
        recoverRadioButton->setObjectName(QStringLiteral("recoverRadioButton"));

        gridLayout_14->addWidget(recoverRadioButton, 1, 2, 1, 1);

        toOriginalClassRadioButton = new QRadioButton(tab_2);
        toOriginalClassRadioButton->setObjectName(QStringLiteral("toOriginalClassRadioButton"));

        gridLayout_14->addWidget(toOriginalClassRadioButton, 1, 0, 1, 1);

        processSelectedPointsTabWidget_2 = new QTabWidget(tab_2);
        processSelectedPointsTabWidget_2->setObjectName(QStringLiteral("processSelectedPointsTabWidget_2"));
        classesToProcessTab_2 = new QWidget();
        classesToProcessTab_2->setObjectName(QStringLiteral("classesToProcessTab_2"));
        gridLayout_15 = new QGridLayout(classesToProcessTab_2);
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        allClassesPushButton = new QPushButton(classesToProcessTab_2);
        allClassesPushButton->setObjectName(QStringLiteral("allClassesPushButton"));

        gridLayout_15->addWidget(allClassesPushButton, 0, 0, 1, 1);

        toClass2PushButton = new QPushButton(classesToProcessTab_2);
        toClass2PushButton->setObjectName(QStringLiteral("toClass2PushButton"));

        gridLayout_15->addWidget(toClass2PushButton, 0, 2, 1, 1);

        toClass1PushButton = new QPushButton(classesToProcessTab_2);
        toClass1PushButton->setObjectName(QStringLiteral("toClass1PushButton"));

        gridLayout_15->addWidget(toClass1PushButton, 0, 1, 1, 1);

        toClass6PushButton = new QPushButton(classesToProcessTab_2);
        toClass6PushButton->setObjectName(QStringLiteral("toClass6PushButton"));

        gridLayout_15->addWidget(toClass6PushButton, 0, 3, 1, 1);

        toClass7PushButton = new QPushButton(classesToProcessTab_2);
        toClass7PushButton->setObjectName(QStringLiteral("toClass7PushButton"));

        gridLayout_15->addWidget(toClass7PushButton, 2, 1, 1, 1);

        toClass3PushButton = new QPushButton(classesToProcessTab_2);
        toClass3PushButton->setObjectName(QStringLiteral("toClass3PushButton"));

        gridLayout_15->addWidget(toClass3PushButton, 1, 1, 1, 1);

        toClass5PushButton = new QPushButton(classesToProcessTab_2);
        toClass5PushButton->setObjectName(QStringLiteral("toClass5PushButton"));

        gridLayout_15->addWidget(toClass5PushButton, 1, 3, 1, 1);

        toClass4PushButton = new QPushButton(classesToProcessTab_2);
        toClass4PushButton->setObjectName(QStringLiteral("toClass4PushButton"));

        gridLayout_15->addWidget(toClass4PushButton, 1, 2, 1, 1);

        toClass9PushButton = new QPushButton(classesToProcessTab_2);
        toClass9PushButton->setObjectName(QStringLiteral("toClass9PushButton"));

        gridLayout_15->addWidget(toClass9PushButton, 2, 2, 1, 1);

        label_6 = new QLabel(classesToProcessTab_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_15->addWidget(label_6, 1, 0, 1, 1);

        toClass0PushButton = new QPushButton(classesToProcessTab_2);
        toClass0PushButton->setObjectName(QStringLiteral("toClass0PushButton"));

        gridLayout_15->addWidget(toClass0PushButton, 2, 3, 1, 1);

        horizontalSpacer_17 = new QSpacerItem(91, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_15->addItem(horizontalSpacer_17, 2, 0, 1, 1);

        toClass12PushButton = new QPushButton(classesToProcessTab_2);
        toClass12PushButton->setObjectName(QStringLiteral("toClass12PushButton"));

        gridLayout_15->addWidget(toClass12PushButton, 3, 1, 1, 1);

        processSelectedPointsTabWidget_2->addTab(classesToProcessTab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_19 = new QGridLayout();
        gridLayout_19->setObjectName(QStringLiteral("gridLayout_19"));
        visibleClass0CheckBox = new QCheckBox(tab);
        visibleClass0CheckBox->setObjectName(QStringLiteral("visibleClass0CheckBox"));

        gridLayout_19->addWidget(visibleClass0CheckBox, 0, 0, 1, 1);

        visibleClass1CheckBox = new QCheckBox(tab);
        visibleClass1CheckBox->setObjectName(QStringLiteral("visibleClass1CheckBox"));

        gridLayout_19->addWidget(visibleClass1CheckBox, 0, 1, 1, 1);

        visibleClass2CheckBox = new QCheckBox(tab);
        visibleClass2CheckBox->setObjectName(QStringLiteral("visibleClass2CheckBox"));

        gridLayout_19->addWidget(visibleClass2CheckBox, 0, 2, 1, 1);

        visibleClass6CheckBox = new QCheckBox(tab);
        visibleClass6CheckBox->setObjectName(QStringLiteral("visibleClass6CheckBox"));

        gridLayout_19->addWidget(visibleClass6CheckBox, 0, 3, 1, 1);

        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_19->addWidget(label_8, 1, 0, 1, 1);

        visibleClass3CheckBox = new QCheckBox(tab);
        visibleClass3CheckBox->setObjectName(QStringLiteral("visibleClass3CheckBox"));

        gridLayout_19->addWidget(visibleClass3CheckBox, 1, 1, 1, 1);

        visibleClass4CheckBox = new QCheckBox(tab);
        visibleClass4CheckBox->setObjectName(QStringLiteral("visibleClass4CheckBox"));

        gridLayout_19->addWidget(visibleClass4CheckBox, 1, 2, 1, 1);

        visibleClass5CheckBox = new QCheckBox(tab);
        visibleClass5CheckBox->setObjectName(QStringLiteral("visibleClass5CheckBox"));

        gridLayout_19->addWidget(visibleClass5CheckBox, 1, 3, 1, 1);

        horizontalSpacer_19 = new QSpacerItem(70, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_19->addItem(horizontalSpacer_19, 2, 0, 1, 1);

        visibleClass7CheckBox = new QCheckBox(tab);
        visibleClass7CheckBox->setObjectName(QStringLiteral("visibleClass7CheckBox"));

        gridLayout_19->addWidget(visibleClass7CheckBox, 2, 1, 1, 1);

        visibleClass9CheckBox = new QCheckBox(tab);
        visibleClass9CheckBox->setObjectName(QStringLiteral("visibleClass9CheckBox"));

        gridLayout_19->addWidget(visibleClass9CheckBox, 2, 2, 1, 1);

        visibleClass12CheckBox = new QCheckBox(tab);
        visibleClass12CheckBox->setObjectName(QStringLiteral("visibleClass12CheckBox"));

        gridLayout_19->addWidget(visibleClass12CheckBox, 2, 3, 1, 1);


        gridLayout_2->addLayout(gridLayout_19, 0, 0, 1, 1);

        processSelectedPointsTabWidget_2->addTab(tab, QString());
        lockedClassesTab_2 = new QWidget();
        lockedClassesTab_2->setObjectName(QStringLiteral("lockedClassesTab_2"));
        gridLayout_16 = new QGridLayout(lockedClassesTab_2);
        gridLayout_16->setObjectName(QStringLiteral("gridLayout_16"));
        gridLayout_17 = new QGridLayout();
        gridLayout_17->setObjectName(QStringLiteral("gridLayout_17"));
        lockedClass0CheckBox = new QCheckBox(lockedClassesTab_2);
        lockedClass0CheckBox->setObjectName(QStringLiteral("lockedClass0CheckBox"));

        gridLayout_17->addWidget(lockedClass0CheckBox, 0, 0, 1, 1);

        lockedClass1CheckBox = new QCheckBox(lockedClassesTab_2);
        lockedClass1CheckBox->setObjectName(QStringLiteral("lockedClass1CheckBox"));

        gridLayout_17->addWidget(lockedClass1CheckBox, 0, 1, 1, 1);

        lockedClass2CheckBox = new QCheckBox(lockedClassesTab_2);
        lockedClass2CheckBox->setObjectName(QStringLiteral("lockedClass2CheckBox"));

        gridLayout_17->addWidget(lockedClass2CheckBox, 0, 2, 1, 1);

        lockedClass6CheckBox = new QCheckBox(lockedClassesTab_2);
        lockedClass6CheckBox->setObjectName(QStringLiteral("lockedClass6CheckBox"));

        gridLayout_17->addWidget(lockedClass6CheckBox, 0, 3, 1, 1);

        label_7 = new QLabel(lockedClassesTab_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_17->addWidget(label_7, 1, 0, 1, 1);

        lockedClass3CheckBox = new QCheckBox(lockedClassesTab_2);
        lockedClass3CheckBox->setObjectName(QStringLiteral("lockedClass3CheckBox"));

        gridLayout_17->addWidget(lockedClass3CheckBox, 1, 1, 1, 1);

        lockedClass4CheckBox = new QCheckBox(lockedClassesTab_2);
        lockedClass4CheckBox->setObjectName(QStringLiteral("lockedClass4CheckBox"));

        gridLayout_17->addWidget(lockedClass4CheckBox, 1, 2, 1, 1);

        lockedClass5CheckBox = new QCheckBox(lockedClassesTab_2);
        lockedClass5CheckBox->setObjectName(QStringLiteral("lockedClass5CheckBox"));

        gridLayout_17->addWidget(lockedClass5CheckBox, 1, 3, 1, 1);

        horizontalSpacer_18 = new QSpacerItem(70, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_17->addItem(horizontalSpacer_18, 2, 0, 1, 1);

        lockedClass7CheckBox = new QCheckBox(lockedClassesTab_2);
        lockedClass7CheckBox->setObjectName(QStringLiteral("lockedClass7CheckBox"));

        gridLayout_17->addWidget(lockedClass7CheckBox, 2, 1, 1, 1);

        lockedClass9CheckBox = new QCheckBox(lockedClassesTab_2);
        lockedClass9CheckBox->setObjectName(QStringLiteral("lockedClass9CheckBox"));

        gridLayout_17->addWidget(lockedClass9CheckBox, 2, 2, 1, 1);

        lockedClass12CheckBox = new QCheckBox(lockedClassesTab_2);
        lockedClass12CheckBox->setObjectName(QStringLiteral("lockedClass12CheckBox"));

        gridLayout_17->addWidget(lockedClass12CheckBox, 2, 3, 1, 1);


        gridLayout_16->addLayout(gridLayout_17, 0, 0, 1, 1);

        processSelectedPointsTabWidget_2->addTab(lockedClassesTab_2, QString());

        gridLayout_14->addWidget(processSelectedPointsTabWidget_2, 2, 0, 1, 5);

        processTabWidget_2->addTab(tab_2, QString());
        altitudeDifferencesAnalisysTab_2 = new QWidget();
        altitudeDifferencesAnalisysTab_2->setObjectName(QStringLiteral("altitudeDifferencesAnalisysTab_2"));
        gridLayout_18 = new QGridLayout(altitudeDifferencesAnalisysTab_2);
        gridLayout_18->setObjectName(QStringLiteral("gridLayout_18"));
        horizontalSpacer_21 = new QSpacerItem(116, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_18->addItem(horizontalSpacer_21, 0, 0, 1, 2);

        getAltitudeStatisticsForSelectedPointsPushButton = new QPushButton(altitudeDifferencesAnalisysTab_2);
        getAltitudeStatisticsForSelectedPointsPushButton->setObjectName(QStringLiteral("getAltitudeStatisticsForSelectedPointsPushButton"));

        gridLayout_18->addWidget(getAltitudeStatisticsForSelectedPointsPushButton, 0, 2, 1, 3);

        horizontalSpacer_22 = new QSpacerItem(89, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_18->addItem(horizontalSpacer_22, 0, 5, 1, 1);

        meanAltitudeLabel_2 = new QLabel(altitudeDifferencesAnalisysTab_2);
        meanAltitudeLabel_2->setObjectName(QStringLiteral("meanAltitudeLabel_2"));

        gridLayout_18->addWidget(meanAltitudeLabel_2, 1, 0, 1, 1);

        meanAltitudeLineEdit = new QLineEdit(altitudeDifferencesAnalisysTab_2);
        meanAltitudeLineEdit->setObjectName(QStringLiteral("meanAltitudeLineEdit"));
        meanAltitudeLineEdit->setReadOnly(true);

        gridLayout_18->addWidget(meanAltitudeLineEdit, 1, 1, 1, 2);

        stdAltitudeLabel_2 = new QLabel(altitudeDifferencesAnalisysTab_2);
        stdAltitudeLabel_2->setObjectName(QStringLiteral("stdAltitudeLabel_2"));

        gridLayout_18->addWidget(stdAltitudeLabel_2, 1, 3, 1, 1);

        stdAltitudeLineEdit = new QLineEdit(altitudeDifferencesAnalisysTab_2);
        stdAltitudeLineEdit->setObjectName(QStringLiteral("stdAltitudeLineEdit"));
        stdAltitudeLineEdit->setReadOnly(true);

        gridLayout_18->addWidget(stdAltitudeLineEdit, 1, 4, 1, 2);

        getDifferencesAltitudeForSelectedPointsPushButton = new QPushButton(altitudeDifferencesAnalisysTab_2);
        getDifferencesAltitudeForSelectedPointsPushButton->setObjectName(QStringLiteral("getDifferencesAltitudeForSelectedPointsPushButton"));
        getDifferencesAltitudeForSelectedPointsPushButton->setMinimumSize(QSize(170, 0));

        gridLayout_18->addWidget(getDifferencesAltitudeForSelectedPointsPushButton, 2, 0, 1, 4);

        altitudeDifferenceLineEdit = new QLineEdit(altitudeDifferencesAnalisysTab_2);
        altitudeDifferenceLineEdit->setObjectName(QStringLiteral("altitudeDifferenceLineEdit"));
        altitudeDifferenceLineEdit->setReadOnly(true);

        gridLayout_18->addWidget(altitudeDifferenceLineEdit, 2, 4, 1, 2);

        verticalSpacer_7 = new QSpacerItem(20, 121, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_18->addItem(verticalSpacer_7, 3, 2, 1, 1);

        processTabWidget_2->addTab(altitudeDifferencesAnalisysTab_2, QString());

        gridLayout_11->addWidget(processTabWidget_2, 0, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 177, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_11->addItem(verticalSpacer_3, 1, 0, 1, 1);

        toolBox->addItem(manualEditingProcessesPage, QStringLiteral("Manual Editing Processes"));
        modelingObjectsProcessingPage = new QWidget();
        modelingObjectsProcessingPage->setObjectName(QStringLiteral("modelingObjectsProcessingPage"));
        modelingObjectsProcessingPage->setGeometry(QRect(0, 0, 440, 326));
        gridLayout_6 = new QGridLayout(modelingObjectsProcessingPage);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label = new QLabel(modelingObjectsProcessingPage);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(81, 0));
        label->setMaximumSize(QSize(81, 16777215));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        objectClassComboBox = new QComboBox(modelingObjectsProcessingPage);
        objectClassComboBox->setObjectName(QStringLiteral("objectClassComboBox"));

        gridLayout_3->addWidget(objectClassComboBox, 0, 1, 1, 1);

        addObjectClassPushButton = new QPushButton(modelingObjectsProcessingPage);
        addObjectClassPushButton->setObjectName(QStringLiteral("addObjectClassPushButton"));
        addObjectClassPushButton->setMinimumSize(QSize(45, 0));
        addObjectClassPushButton->setMaximumSize(QSize(45, 16777215));

        gridLayout_3->addWidget(addObjectClassPushButton, 0, 2, 1, 1);

        removeObjectClassPpushButton = new QPushButton(modelingObjectsProcessingPage);
        removeObjectClassPpushButton->setObjectName(QStringLiteral("removeObjectClassPpushButton"));
        removeObjectClassPpushButton->setMinimumSize(QSize(60, 0));
        removeObjectClassPpushButton->setMaximumSize(QSize(60, 16777215));

        gridLayout_3->addWidget(removeObjectClassPpushButton, 0, 3, 1, 1);

        editObjectClassPushButton = new QPushButton(modelingObjectsProcessingPage);
        editObjectClassPushButton->setObjectName(QStringLiteral("editObjectClassPushButton"));
        editObjectClassPushButton->setMinimumSize(QSize(45, 0));
        editObjectClassPushButton->setMaximumSize(QSize(45, 16777215));

        gridLayout_3->addWidget(editObjectClassPushButton, 0, 4, 1, 1);

        label_2 = new QLabel(modelingObjectsProcessingPage);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

        objectComboBox = new QComboBox(modelingObjectsProcessingPage);
        objectComboBox->setObjectName(QStringLiteral("objectComboBox"));

        gridLayout_3->addWidget(objectComboBox, 1, 1, 1, 1);

        addObjectPushButton = new QPushButton(modelingObjectsProcessingPage);
        addObjectPushButton->setObjectName(QStringLiteral("addObjectPushButton"));
        addObjectPushButton->setMinimumSize(QSize(45, 0));
        addObjectPushButton->setMaximumSize(QSize(45, 16777215));

        gridLayout_3->addWidget(addObjectPushButton, 1, 2, 1, 1);

        removeObjectPpushButton = new QPushButton(modelingObjectsProcessingPage);
        removeObjectPpushButton->setObjectName(QStringLiteral("removeObjectPpushButton"));
        removeObjectPpushButton->setMinimumSize(QSize(60, 0));
        removeObjectPpushButton->setMaximumSize(QSize(60, 16777215));

        gridLayout_3->addWidget(removeObjectPpushButton, 1, 3, 1, 1);

        editObjectPushButton = new QPushButton(modelingObjectsProcessingPage);
        editObjectPushButton->setObjectName(QStringLiteral("editObjectPushButton"));
        editObjectPushButton->setEnabled(false);
        editObjectPushButton->setMinimumSize(QSize(45, 0));
        editObjectPushButton->setMaximumSize(QSize(45, 16777215));

        gridLayout_3->addWidget(editObjectPushButton, 1, 4, 1, 1);


        gridLayout_6->addLayout(gridLayout_3, 0, 0, 1, 1);

        tabWidget = new QTabWidget(modelingObjectsProcessingPage);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        processWithSelectedPointsTab = new QWidget();
        processWithSelectedPointsTab->setObjectName(QStringLiteral("processWithSelectedPointsTab"));
        gridLayout_4 = new QGridLayout(processWithSelectedPointsTab);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        visibleObjectClassesFrame = new QFrame(processWithSelectedPointsTab);
        visibleObjectClassesFrame->setObjectName(QStringLiteral("visibleObjectClassesFrame"));
        visibleObjectClassesFrame->setMinimumSize(QSize(350, 25));
        visibleObjectClassesFrame->setFrameShape(QFrame::StyledPanel);
        visibleObjectClassesFrame->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(visibleObjectClassesFrame, 0, 0, 1, 1);

        visibleObjectsFrame = new QFrame(processWithSelectedPointsTab);
        visibleObjectsFrame->setObjectName(QStringLiteral("visibleObjectsFrame"));
        visibleObjectsFrame->setMinimumSize(QSize(350, 25));
        visibleObjectsFrame->setFrameShape(QFrame::StyledPanel);
        visibleObjectsFrame->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(visibleObjectsFrame, 1, 0, 1, 1);

        lockedObjectClassesFrame = new QFrame(processWithSelectedPointsTab);
        lockedObjectClassesFrame->setObjectName(QStringLiteral("lockedObjectClassesFrame"));
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
        lockedObjectsFrame->setObjectName(QStringLiteral("lockedObjectsFrame"));
        lockedObjectsFrame->setMinimumSize(QSize(350, 25));
        lockedObjectsFrame->setFrameShape(QFrame::StyledPanel);
        lockedObjectsFrame->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(lockedObjectsFrame, 3, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        assignToObjectRadioButton = new QRadioButton(processWithSelectedPointsTab);
        assignToObjectRadioButton->setObjectName(QStringLiteral("assignToObjectRadioButton"));
        assignToObjectRadioButton->setChecked(true);

        horizontalLayout_2->addWidget(assignToObjectRadioButton);

        unassignToObjectRadioButton = new QRadioButton(processWithSelectedPointsTab);
        unassignToObjectRadioButton->setObjectName(QStringLiteral("unassignToObjectRadioButton"));

        horizontalLayout_2->addWidget(unassignToObjectRadioButton);

        selectOnlyObjectRadioButton = new QRadioButton(processWithSelectedPointsTab);
        selectOnlyObjectRadioButton->setObjectName(QStringLiteral("selectOnlyObjectRadioButton"));

        horizontalLayout_2->addWidget(selectOnlyObjectRadioButton);

        unselectObjectRadioButton = new QRadioButton(processWithSelectedPointsTab);
        unselectObjectRadioButton->setObjectName(QStringLiteral("unselectObjectRadioButton"));

        horizontalLayout_2->addWidget(unselectObjectRadioButton);


        gridLayout_4->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(processWithSelectedPointsTab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(70, 0));
        label_3->setMaximumSize(QSize(70, 16777215));

        horizontalLayout->addWidget(label_3);

        selectObjectComboBox = new QComboBox(processWithSelectedPointsTab);
        selectObjectComboBox->setObjectName(QStringLiteral("selectObjectComboBox"));

        horizontalLayout->addWidget(selectObjectComboBox);

        processSelectedObjectPointsPushButton = new QPushButton(processWithSelectedPointsTab);
        processSelectedObjectPointsPushButton->setObjectName(QStringLiteral("processSelectedObjectPointsPushButton"));
        processSelectedObjectPointsPushButton->setMinimumSize(QSize(75, 0));
        processSelectedObjectPointsPushButton->setMaximumSize(QSize(75, 16777215));

        horizontalLayout->addWidget(processSelectedObjectPointsPushButton);


        gridLayout_4->addLayout(horizontalLayout, 2, 0, 1, 1);

        tabWidget->addTab(processWithSelectedPointsTab, QString());
        parametricGeometriesTab = new QWidget();
        parametricGeometriesTab->setObjectName(QStringLiteral("parametricGeometriesTab"));
        layoutWidget = new QWidget(parametricGeometriesTab);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 352, 120));
        gridLayout_7 = new QGridLayout(layoutWidget);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        visibleParametricGeometriesObjectClassesFrame = new QFrame(layoutWidget);
        visibleParametricGeometriesObjectClassesFrame->setObjectName(QStringLiteral("visibleParametricGeometriesObjectClassesFrame"));
        visibleParametricGeometriesObjectClassesFrame->setMinimumSize(QSize(350, 25));
        visibleParametricGeometriesObjectClassesFrame->setFrameShape(QFrame::StyledPanel);
        visibleParametricGeometriesObjectClassesFrame->setFrameShadow(QFrame::Raised);

        gridLayout_7->addWidget(visibleParametricGeometriesObjectClassesFrame, 0, 0, 1, 1);

        visibleParametricGeometriesObjectsFrame = new QFrame(layoutWidget);
        visibleParametricGeometriesObjectsFrame->setObjectName(QStringLiteral("visibleParametricGeometriesObjectsFrame"));
        visibleParametricGeometriesObjectsFrame->setMinimumSize(QSize(350, 25));
        visibleParametricGeometriesObjectsFrame->setFrameShape(QFrame::StyledPanel);
        visibleParametricGeometriesObjectsFrame->setFrameShadow(QFrame::Raised);

        gridLayout_7->addWidget(visibleParametricGeometriesObjectsFrame, 1, 0, 1, 1);

        lockedObjectClassesFrame_2 = new QFrame(layoutWidget);
        lockedObjectClassesFrame_2->setObjectName(QStringLiteral("lockedObjectClassesFrame_2"));
        sizePolicy.setHeightForWidth(lockedObjectClassesFrame_2->sizePolicy().hasHeightForWidth());
        lockedObjectClassesFrame_2->setSizePolicy(sizePolicy);
        lockedObjectClassesFrame_2->setMinimumSize(QSize(350, 25));
        lockedObjectClassesFrame_2->setFrameShape(QFrame::StyledPanel);
        lockedObjectClassesFrame_2->setFrameShadow(QFrame::Raised);

        gridLayout_7->addWidget(lockedObjectClassesFrame_2, 2, 0, 1, 1);

        lockedObjectsFrame_2 = new QFrame(layoutWidget);
        lockedObjectsFrame_2->setObjectName(QStringLiteral("lockedObjectsFrame_2"));
        lockedObjectsFrame_2->setMinimumSize(QSize(350, 25));
        lockedObjectsFrame_2->setFrameShape(QFrame::StyledPanel);
        lockedObjectsFrame_2->setFrameShadow(QFrame::Raised);

        gridLayout_7->addWidget(lockedObjectsFrame_2, 3, 0, 1, 1);

        tabWidget->addTab(parametricGeometriesTab, QString());

        gridLayout_6->addWidget(tabWidget, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 12, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer, 2, 0, 1, 1);

        toolBox->addItem(modelingObjectsProcessingPage, QStringLiteral("Modeling Objects Processing"));

        gridLayout_5->addWidget(toolBox, 0, 0, 1, 1);

        treeWidget = new QTreeWidget(dockWidgetContents);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(3, QStringLiteral("4"));
        __qtreewidgetitem->setText(2, QStringLiteral("3"));
        __qtreewidgetitem->setText(1, QStringLiteral("2"));
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
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
        treeWidget->header()->setDefaultSectionSize(95);
        treeWidget->header()->setMinimumSectionSize(30);

        gridLayout_5->addWidget(treeWidget, 1, 0, 1, 1);

        plainTextEditOutput = new QPlainTextEdit(dockWidgetContents);
        plainTextEditOutput->setObjectName(QStringLiteral("plainTextEditOutput"));
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
        PCDViewerMainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);
        toolBar = new QToolBar(PCDViewerMainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
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
        PCDViewerMainWindow->setWindowTitle(QApplication::translate("PCDViewerMainWindow", "MainWindow", Q_NULLPTR));
        actionFullScreen->setText(QApplication::translate("PCDViewerMainWindow", "Full Screen", Q_NULLPTR));
        actionFitWindow->setText(QApplication::translate("PCDViewerMainWindow", "Zoom Full Extent", Q_NULLPTR));
        actionSceneManipulation->setText(QApplication::translate("PCDViewerMainWindow", "Pan", Q_NULLPTR));
        actionPerspectiveOrthographic->setText(QApplication::translate("PCDViewerMainWindow", "Perspective/Orthographic", Q_NULLPTR));
        actionShowCoordinateSystem->setText(QApplication::translate("PCDViewerMainWindow", "Show Coordinate System", Q_NULLPTR));
        actionIncreasePointSize->setText(QApplication::translate("PCDViewerMainWindow", "Zoom In Point Size", Q_NULLPTR));
        actionIncreasePointSize->setIconText(QApplication::translate("PCDViewerMainWindow", "Zoom In Point Size", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionIncreasePointSize->setToolTip(QApplication::translate("PCDViewerMainWindow", "Zoom In Point Size", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionDecreasePointSize->setText(QApplication::translate("PCDViewerMainWindow", "Zoom Out Point Size", Q_NULLPTR));
        actionDecreasePointSize->setIconText(QApplication::translate("PCDViewerMainWindow", "Zoom Out Point Size", Q_NULLPTR));
        actionSelectPointsByRectangle->setText(QApplication::translate("PCDViewerMainWindow", "Select Points by Rectangle", Q_NULLPTR));
        actionSelectPointsByPolygon->setText(QApplication::translate("PCDViewerMainWindow", "Select Points by Polygon", Q_NULLPTR));
        actionSelectPointsByFreehand->setText(QApplication::translate("PCDViewerMainWindow", "Select Points by Freehand", Q_NULLPTR));
        actionUnselectPoints->setText(QApplication::translate("PCDViewerMainWindow", "Unselect Points", Q_NULLPTR));
        actionDeleteSelectedPoints->setText(QApplication::translate("PCDViewerMainWindow", "Delete Selected Points", Q_NULLPTR));
        actionAssignColorByHeight->setText(QApplication::translate("PCDViewerMainWindow", "Assign Color by Height", Q_NULLPTR));
        actionAssignColorByIntensity->setText(QApplication::translate("PCDViewerMainWindow", "Assign Color by Intensity", Q_NULLPTR));
        actionAssignColorByRGB->setText(QApplication::translate("PCDViewerMainWindow", "Assign Color by RGB", Q_NULLPTR));
        actionAssignColorByClassification->setText(QApplication::translate("PCDViewerMainWindow", "Assign Color by Classification", Q_NULLPTR));
        actionAssignColorByObjectClassification->setText(QApplication::translate("PCDViewerMainWindow", "Assign Color by Object Classification", Q_NULLPTR));
        actionActionAssignColorByObjectClassification->setText(QApplication::translate("PCDViewerMainWindow", "actionAssignColorByObjectClassification", Q_NULLPTR));
        menuView->setTitle(QApplication::translate("PCDViewerMainWindow", "View", Q_NULLPTR));
        menuSeelct->setTitle(QApplication::translate("PCDViewerMainWindow", "Seelct", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("PCDViewerMainWindow", "Help", Q_NULLPTR));
        selectOnlyRadioButton->setText(QApplication::translate("PCDViewerMainWindow", "Select only", Q_NULLPTR));
        changeClassRadioButton->setText(QApplication::translate("PCDViewerMainWindow", "Change class to", Q_NULLPTR));
        removeRadioButton->setText(QApplication::translate("PCDViewerMainWindow", "Remove", Q_NULLPTR));
        unselectRadioButton->setText(QApplication::translate("PCDViewerMainWindow", "Unselect", Q_NULLPTR));
        recoverRadioButton->setText(QApplication::translate("PCDViewerMainWindow", "Recover", Q_NULLPTR));
        toOriginalClassRadioButton->setText(QApplication::translate("PCDViewerMainWindow", "To Original Class", Q_NULLPTR));
        allClassesPushButton->setText(QApplication::translate("PCDViewerMainWindow", "All classes", Q_NULLPTR));
        toClass2PushButton->setText(QApplication::translate("PCDViewerMainWindow", "2 - Ground", Q_NULLPTR));
        toClass1PushButton->setText(QApplication::translate("PCDViewerMainWindow", "1 - Unclassified", Q_NULLPTR));
        toClass6PushButton->setText(QApplication::translate("PCDViewerMainWindow", "6 - Building", Q_NULLPTR));
        toClass7PushButton->setText(QApplication::translate("PCDViewerMainWindow", "7 - Low Point", Q_NULLPTR));
        toClass3PushButton->setText(QApplication::translate("PCDViewerMainWindow", "3 - Low", Q_NULLPTR));
        toClass5PushButton->setText(QApplication::translate("PCDViewerMainWindow", "5 - High", Q_NULLPTR));
        toClass4PushButton->setText(QApplication::translate("PCDViewerMainWindow", "4 - Medium", Q_NULLPTR));
        toClass9PushButton->setText(QApplication::translate("PCDViewerMainWindow", "9 - Water", Q_NULLPTR));
        label_6->setText(QApplication::translate("PCDViewerMainWindow", "Vegetation:", Q_NULLPTR));
        toClass0PushButton->setText(QApplication::translate("PCDViewerMainWindow", "0 - Created", Q_NULLPTR));
        toClass12PushButton->setText(QApplication::translate("PCDViewerMainWindow", "12 - Overlap", Q_NULLPTR));
        processSelectedPointsTabWidget_2->setTabText(processSelectedPointsTabWidget_2->indexOf(classesToProcessTab_2), QApplication::translate("PCDViewerMainWindow", "Classes to process", Q_NULLPTR));
        visibleClass0CheckBox->setText(QApplication::translate("PCDViewerMainWindow", "0-Created", Q_NULLPTR));
        visibleClass1CheckBox->setText(QApplication::translate("PCDViewerMainWindow", "1-Unclassified", Q_NULLPTR));
        visibleClass2CheckBox->setText(QApplication::translate("PCDViewerMainWindow", "2-Ground", Q_NULLPTR));
        visibleClass6CheckBox->setText(QApplication::translate("PCDViewerMainWindow", "6-Building", Q_NULLPTR));
        label_8->setText(QApplication::translate("PCDViewerMainWindow", "Vegetation:", Q_NULLPTR));
        visibleClass3CheckBox->setText(QApplication::translate("PCDViewerMainWindow", "3-Low", Q_NULLPTR));
        visibleClass4CheckBox->setText(QApplication::translate("PCDViewerMainWindow", "4-Medium", Q_NULLPTR));
        visibleClass5CheckBox->setText(QApplication::translate("PCDViewerMainWindow", "5-High", Q_NULLPTR));
        visibleClass7CheckBox->setText(QApplication::translate("PCDViewerMainWindow", "7-Low Point", Q_NULLPTR));
        visibleClass9CheckBox->setText(QApplication::translate("PCDViewerMainWindow", "9-Water", Q_NULLPTR));
        visibleClass12CheckBox->setText(QApplication::translate("PCDViewerMainWindow", "12-Overlap", Q_NULLPTR));
        processSelectedPointsTabWidget_2->setTabText(processSelectedPointsTabWidget_2->indexOf(tab), QApplication::translate("PCDViewerMainWindow", "Visible classes", Q_NULLPTR));
        lockedClass0CheckBox->setText(QApplication::translate("PCDViewerMainWindow", "0-Created", Q_NULLPTR));
        lockedClass1CheckBox->setText(QApplication::translate("PCDViewerMainWindow", "1-Unclassified", Q_NULLPTR));
        lockedClass2CheckBox->setText(QApplication::translate("PCDViewerMainWindow", "2-Ground", Q_NULLPTR));
        lockedClass6CheckBox->setText(QApplication::translate("PCDViewerMainWindow", "6-Building", Q_NULLPTR));
        label_7->setText(QApplication::translate("PCDViewerMainWindow", "Vegetation:", Q_NULLPTR));
        lockedClass3CheckBox->setText(QApplication::translate("PCDViewerMainWindow", "3-Low", Q_NULLPTR));
        lockedClass4CheckBox->setText(QApplication::translate("PCDViewerMainWindow", "4-Medium", Q_NULLPTR));
        lockedClass5CheckBox->setText(QApplication::translate("PCDViewerMainWindow", "5-High", Q_NULLPTR));
        lockedClass7CheckBox->setText(QApplication::translate("PCDViewerMainWindow", "7-Low Point", Q_NULLPTR));
        lockedClass9CheckBox->setText(QApplication::translate("PCDViewerMainWindow", "9-Water", Q_NULLPTR));
        lockedClass12CheckBox->setText(QApplication::translate("PCDViewerMainWindow", "12-Overlap", Q_NULLPTR));
        processSelectedPointsTabWidget_2->setTabText(processSelectedPointsTabWidget_2->indexOf(lockedClassesTab_2), QApplication::translate("PCDViewerMainWindow", "Locked classes", Q_NULLPTR));
        processTabWidget_2->setTabText(processTabWidget_2->indexOf(tab_2), QApplication::translate("PCDViewerMainWindow", "Process with selected points", Q_NULLPTR));
        getAltitudeStatisticsForSelectedPointsPushButton->setText(QApplication::translate("PCDViewerMainWindow", "Get altitude statistics for selected points", Q_NULLPTR));
        meanAltitudeLabel_2->setText(QApplication::translate("PCDViewerMainWindow", "Mean (m):", Q_NULLPTR));
        stdAltitudeLabel_2->setText(QApplication::translate("PCDViewerMainWindow", "Std (m):", Q_NULLPTR));
        getDifferencesAltitudeForSelectedPointsPushButton->setText(QApplication::translate("PCDViewerMainWindow", "Altitude - Mean, for selected point (m):", Q_NULLPTR));
        processTabWidget_2->setTabText(processTabWidget_2->indexOf(altitudeDifferencesAnalisysTab_2), QApplication::translate("PCDViewerMainWindow", "Altitudes differences analisys", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(manualEditingProcessesPage), QApplication::translate("PCDViewerMainWindow", "Manual Editing Processes", Q_NULLPTR));
        label->setText(QApplication::translate("PCDViewerMainWindow", "Objects classes:", Q_NULLPTR));
        addObjectClassPushButton->setText(QApplication::translate("PCDViewerMainWindow", "Add", Q_NULLPTR));
        removeObjectClassPpushButton->setText(QApplication::translate("PCDViewerMainWindow", "Remvoe", Q_NULLPTR));
        editObjectClassPushButton->setText(QApplication::translate("PCDViewerMainWindow", "Edit", Q_NULLPTR));
        label_2->setText(QApplication::translate("PCDViewerMainWindow", "Object:", Q_NULLPTR));
        addObjectPushButton->setText(QApplication::translate("PCDViewerMainWindow", "Add", Q_NULLPTR));
        removeObjectPpushButton->setText(QApplication::translate("PCDViewerMainWindow", "Remvoe", Q_NULLPTR));
        editObjectPushButton->setText(QApplication::translate("PCDViewerMainWindow", "Edit", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        tabWidget->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        assignToObjectRadioButton->setText(QApplication::translate("PCDViewerMainWindow", "Assign to object", Q_NULLPTR));
        unassignToObjectRadioButton->setText(QApplication::translate("PCDViewerMainWindow", "Unassign to object", Q_NULLPTR));
        selectOnlyObjectRadioButton->setText(QApplication::translate("PCDViewerMainWindow", "Select only", Q_NULLPTR));
        unselectObjectRadioButton->setText(QApplication::translate("PCDViewerMainWindow", "Unselect", Q_NULLPTR));
        label_3->setText(QApplication::translate("PCDViewerMainWindow", "Select Object:", Q_NULLPTR));
        processSelectedObjectPointsPushButton->setText(QApplication::translate("PCDViewerMainWindow", "Process", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(processWithSelectedPointsTab), QApplication::translate("PCDViewerMainWindow", "Process with selected points", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(parametricGeometriesTab), QApplication::translate("PCDViewerMainWindow", "Parametric geometries", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(modelingObjectsProcessingPage), QApplication::translate("PCDViewerMainWindow", "Modeling Objects Processing", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("PCDViewerMainWindow", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PCDViewerMainWindow: public Ui_PCDViewerMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PCDVIEWERMAINWINDOW_H
