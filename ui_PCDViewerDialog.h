/********************************************************************************
** Form generated from reading UI file 'PCDViewerDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PCDVIEWERDIALOG_H
#define UI_PCDVIEWERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PCDViewerDialog
{
public:
    QGridLayout *gridLayout_2;
    QWidget *centralWidget;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout;
    QToolBox *toolBox;
    QWidget *manualEditingProcessesPage;
    QGridLayout *gridLayout_11;
    QHBoxLayout *horizontalLayout_6;
    QToolButton *toolButton_SelectByRectangle;
    QToolButton *toolButton_SelectByPolygon;
    QToolButton *toolButton_SelectByFreehand;
    QSpacerItem *horizontalSpacer_3;
    QTabWidget *processTabWidget_2;
    QWidget *tab_2;
    QGridLayout *gridLayout_14;
    QTabWidget *processSelectedPointsTabWidget_2;
    QWidget *classesToProcessTab_2;
    QGridLayout *gridLayout_15;
    QPushButton *allClassesPushButton_2;
    QPushButton *toClass1PushButton_2;
    QPushButton *toClass2PushButton_2;
    QPushButton *toClass6PushButton_2;
    QLabel *label_6;
    QPushButton *toClass3PushButton_2;
    QPushButton *toClass4PushButton_2;
    QPushButton *toClass5PushButton_2;
    QSpacerItem *horizontalSpacer_17;
    QPushButton *toClass7PushButton_2;
    QPushButton *toClass9PushButton_2;
    QPushButton *toClass0PushButton_2;
    QWidget *lockedClassesTab_2;
    QGridLayout *gridLayout_16;
    QGridLayout *gridLayout_17;
    QCheckBox *lockedClass0CheckBox_2;
    QCheckBox *lockedClass1CheckBox_2;
    QCheckBox *lockedClass2CheckBox_2;
    QCheckBox *lockedClass6CheckBox_2;
    QLabel *label_7;
    QCheckBox *lockedClass3CheckBox_2;
    QCheckBox *lockedClass4CheckBox_2;
    QCheckBox *lockedClass5CheckBox_2;
    QSpacerItem *horizontalSpacer_18;
    QCheckBox *lockedClass7CheckBox_2;
    QCheckBox *lockedClass9CheckBox_2;
    QSpacerItem *horizontalSpacer_19;
    QRadioButton *removeRadioButton_2;
    QRadioButton *changeClassRadioButton_2;
    QRadioButton *selectOnlyRadioButton_2;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *horizontalSpacer_16;
    QRadioButton *unselectRadioButton_2;
    QRadioButton *toOriginalClassRadioButton_2;
    QRadioButton *recoverRadioButton_2;
    QWidget *altitudeDifferencesAnalisysTab_2;
    QGridLayout *gridLayout_18;
    QSpacerItem *horizontalSpacer_21;
    QPushButton *getAltitudeStatisticsForSelectedPointsPushButton_2;
    QSpacerItem *horizontalSpacer_22;
    QLabel *meanAltitudeLabel_2;
    QLineEdit *meanAltitudeLineEdit_2;
    QLabel *stdAltitudeLabel_2;
    QLineEdit *stdAltitudeLineEdit_2;
    QPushButton *getDifferencesAltitudeForSelectedPointsPushButton_2;
    QLineEdit *altitudeDifferenceLineEdit_2;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *verticalSpacer_3;
    QWidget *page_3;
    QPlainTextEdit *infoPlainTextEdit;

    void setupUi(QDialog *PCDViewerDialog)
    {
        if (PCDViewerDialog->objectName().isEmpty())
            PCDViewerDialog->setObjectName(QStringLiteral("PCDViewerDialog"));
        PCDViewerDialog->resize(1082, 712);
        gridLayout_2 = new QGridLayout(PCDViewerDialog);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        centralWidget = new QWidget(PCDViewerDialog);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(600, 600));

        gridLayout_2->addWidget(centralWidget, 0, 0, 1, 1);

        dockWidget = new QDockWidget(PCDViewerDialog);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        gridLayout = new QGridLayout(dockWidgetContents);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        toolBox = new QToolBox(dockWidgetContents);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setMinimumSize(QSize(440, 300));
        manualEditingProcessesPage = new QWidget();
        manualEditingProcessesPage->setObjectName(QStringLiteral("manualEditingProcessesPage"));
        manualEditingProcessesPage->setGeometry(QRect(0, 0, 440, 312));
        gridLayout_11 = new QGridLayout(manualEditingProcessesPage);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        toolButton_SelectByRectangle = new QToolButton(manualEditingProcessesPage);
        toolButton_SelectByRectangle->setObjectName(QStringLiteral("toolButton_SelectByRectangle"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/plugins/point_cloud_tools/icons/mActionSelectRectangle.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_SelectByRectangle->setIcon(icon);
        toolButton_SelectByRectangle->setIconSize(QSize(24, 24));

        horizontalLayout_6->addWidget(toolButton_SelectByRectangle);

        toolButton_SelectByPolygon = new QToolButton(manualEditingProcessesPage);
        toolButton_SelectByPolygon->setObjectName(QStringLiteral("toolButton_SelectByPolygon"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/plugins/point_cloud_tools/icons/mActionSelectPolygon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_SelectByPolygon->setIcon(icon1);
        toolButton_SelectByPolygon->setIconSize(QSize(24, 24));

        horizontalLayout_6->addWidget(toolButton_SelectByPolygon);

        toolButton_SelectByFreehand = new QToolButton(manualEditingProcessesPage);
        toolButton_SelectByFreehand->setObjectName(QStringLiteral("toolButton_SelectByFreehand"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/plugins/point_cloud_tools/icons/mActionSelectFreehand.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_SelectByFreehand->setIcon(icon2);
        toolButton_SelectByFreehand->setIconSize(QSize(24, 24));

        horizontalLayout_6->addWidget(toolButton_SelectByFreehand);

        horizontalSpacer_3 = new QSpacerItem(78, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);


        gridLayout_11->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        processTabWidget_2 = new QTabWidget(manualEditingProcessesPage);
        processTabWidget_2->setObjectName(QStringLiteral("processTabWidget_2"));
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_14 = new QGridLayout(tab_2);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        processSelectedPointsTabWidget_2 = new QTabWidget(tab_2);
        processSelectedPointsTabWidget_2->setObjectName(QStringLiteral("processSelectedPointsTabWidget_2"));
        classesToProcessTab_2 = new QWidget();
        classesToProcessTab_2->setObjectName(QStringLiteral("classesToProcessTab_2"));
        gridLayout_15 = new QGridLayout(classesToProcessTab_2);
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        allClassesPushButton_2 = new QPushButton(classesToProcessTab_2);
        allClassesPushButton_2->setObjectName(QStringLiteral("allClassesPushButton_2"));

        gridLayout_15->addWidget(allClassesPushButton_2, 0, 0, 1, 1);

        toClass1PushButton_2 = new QPushButton(classesToProcessTab_2);
        toClass1PushButton_2->setObjectName(QStringLiteral("toClass1PushButton_2"));

        gridLayout_15->addWidget(toClass1PushButton_2, 0, 1, 1, 1);

        toClass2PushButton_2 = new QPushButton(classesToProcessTab_2);
        toClass2PushButton_2->setObjectName(QStringLiteral("toClass2PushButton_2"));

        gridLayout_15->addWidget(toClass2PushButton_2, 0, 2, 1, 1);

        toClass6PushButton_2 = new QPushButton(classesToProcessTab_2);
        toClass6PushButton_2->setObjectName(QStringLiteral("toClass6PushButton_2"));

        gridLayout_15->addWidget(toClass6PushButton_2, 0, 3, 1, 1);

        label_6 = new QLabel(classesToProcessTab_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_15->addWidget(label_6, 1, 0, 1, 1);

        toClass3PushButton_2 = new QPushButton(classesToProcessTab_2);
        toClass3PushButton_2->setObjectName(QStringLiteral("toClass3PushButton_2"));

        gridLayout_15->addWidget(toClass3PushButton_2, 1, 1, 1, 1);

        toClass4PushButton_2 = new QPushButton(classesToProcessTab_2);
        toClass4PushButton_2->setObjectName(QStringLiteral("toClass4PushButton_2"));

        gridLayout_15->addWidget(toClass4PushButton_2, 1, 2, 1, 1);

        toClass5PushButton_2 = new QPushButton(classesToProcessTab_2);
        toClass5PushButton_2->setObjectName(QStringLiteral("toClass5PushButton_2"));

        gridLayout_15->addWidget(toClass5PushButton_2, 1, 3, 1, 1);

        horizontalSpacer_17 = new QSpacerItem(91, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_15->addItem(horizontalSpacer_17, 2, 0, 1, 1);

        toClass7PushButton_2 = new QPushButton(classesToProcessTab_2);
        toClass7PushButton_2->setObjectName(QStringLiteral("toClass7PushButton_2"));

        gridLayout_15->addWidget(toClass7PushButton_2, 2, 1, 1, 1);

        toClass9PushButton_2 = new QPushButton(classesToProcessTab_2);
        toClass9PushButton_2->setObjectName(QStringLiteral("toClass9PushButton_2"));

        gridLayout_15->addWidget(toClass9PushButton_2, 2, 2, 1, 1);

        toClass0PushButton_2 = new QPushButton(classesToProcessTab_2);
        toClass0PushButton_2->setObjectName(QStringLiteral("toClass0PushButton_2"));

        gridLayout_15->addWidget(toClass0PushButton_2, 2, 3, 1, 1);

        processSelectedPointsTabWidget_2->addTab(classesToProcessTab_2, QString());
        lockedClassesTab_2 = new QWidget();
        lockedClassesTab_2->setObjectName(QStringLiteral("lockedClassesTab_2"));
        gridLayout_16 = new QGridLayout(lockedClassesTab_2);
        gridLayout_16->setObjectName(QStringLiteral("gridLayout_16"));
        gridLayout_17 = new QGridLayout();
        gridLayout_17->setObjectName(QStringLiteral("gridLayout_17"));
        lockedClass0CheckBox_2 = new QCheckBox(lockedClassesTab_2);
        lockedClass0CheckBox_2->setObjectName(QStringLiteral("lockedClass0CheckBox_2"));

        gridLayout_17->addWidget(lockedClass0CheckBox_2, 0, 0, 1, 1);

        lockedClass1CheckBox_2 = new QCheckBox(lockedClassesTab_2);
        lockedClass1CheckBox_2->setObjectName(QStringLiteral("lockedClass1CheckBox_2"));

        gridLayout_17->addWidget(lockedClass1CheckBox_2, 0, 1, 1, 1);

        lockedClass2CheckBox_2 = new QCheckBox(lockedClassesTab_2);
        lockedClass2CheckBox_2->setObjectName(QStringLiteral("lockedClass2CheckBox_2"));

        gridLayout_17->addWidget(lockedClass2CheckBox_2, 0, 2, 1, 1);

        lockedClass6CheckBox_2 = new QCheckBox(lockedClassesTab_2);
        lockedClass6CheckBox_2->setObjectName(QStringLiteral("lockedClass6CheckBox_2"));

        gridLayout_17->addWidget(lockedClass6CheckBox_2, 0, 3, 1, 1);

        label_7 = new QLabel(lockedClassesTab_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_17->addWidget(label_7, 1, 0, 1, 1);

        lockedClass3CheckBox_2 = new QCheckBox(lockedClassesTab_2);
        lockedClass3CheckBox_2->setObjectName(QStringLiteral("lockedClass3CheckBox_2"));

        gridLayout_17->addWidget(lockedClass3CheckBox_2, 1, 1, 1, 1);

        lockedClass4CheckBox_2 = new QCheckBox(lockedClassesTab_2);
        lockedClass4CheckBox_2->setObjectName(QStringLiteral("lockedClass4CheckBox_2"));

        gridLayout_17->addWidget(lockedClass4CheckBox_2, 1, 2, 1, 1);

        lockedClass5CheckBox_2 = new QCheckBox(lockedClassesTab_2);
        lockedClass5CheckBox_2->setObjectName(QStringLiteral("lockedClass5CheckBox_2"));

        gridLayout_17->addWidget(lockedClass5CheckBox_2, 1, 3, 1, 1);

        horizontalSpacer_18 = new QSpacerItem(70, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_17->addItem(horizontalSpacer_18, 2, 0, 1, 1);

        lockedClass7CheckBox_2 = new QCheckBox(lockedClassesTab_2);
        lockedClass7CheckBox_2->setObjectName(QStringLiteral("lockedClass7CheckBox_2"));

        gridLayout_17->addWidget(lockedClass7CheckBox_2, 2, 1, 1, 1);

        lockedClass9CheckBox_2 = new QCheckBox(lockedClassesTab_2);
        lockedClass9CheckBox_2->setObjectName(QStringLiteral("lockedClass9CheckBox_2"));

        gridLayout_17->addWidget(lockedClass9CheckBox_2, 2, 2, 1, 1);

        horizontalSpacer_19 = new QSpacerItem(69, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_17->addItem(horizontalSpacer_19, 2, 3, 1, 1);


        gridLayout_16->addLayout(gridLayout_17, 0, 0, 1, 1);

        processSelectedPointsTabWidget_2->addTab(lockedClassesTab_2, QString());

        gridLayout_14->addWidget(processSelectedPointsTabWidget_2, 2, 0, 1, 5);

        removeRadioButton_2 = new QRadioButton(tab_2);
        removeRadioButton_2->setObjectName(QStringLiteral("removeRadioButton_2"));

        gridLayout_14->addWidget(removeRadioButton_2, 0, 2, 1, 1);

        changeClassRadioButton_2 = new QRadioButton(tab_2);
        changeClassRadioButton_2->setObjectName(QStringLiteral("changeClassRadioButton_2"));
        changeClassRadioButton_2->setChecked(true);

        gridLayout_14->addWidget(changeClassRadioButton_2, 0, 0, 1, 1);

        selectOnlyRadioButton_2 = new QRadioButton(tab_2);
        selectOnlyRadioButton_2->setObjectName(QStringLiteral("selectOnlyRadioButton_2"));

        gridLayout_14->addWidget(selectOnlyRadioButton_2, 0, 1, 1, 1);

        horizontalSpacer_14 = new QSpacerItem(106, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_14->addItem(horizontalSpacer_14, 0, 3, 1, 2);

        horizontalSpacer_16 = new QSpacerItem(106, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_14->addItem(horizontalSpacer_16, 1, 3, 1, 2);

        unselectRadioButton_2 = new QRadioButton(tab_2);
        unselectRadioButton_2->setObjectName(QStringLiteral("unselectRadioButton_2"));

        gridLayout_14->addWidget(unselectRadioButton_2, 1, 1, 1, 1);

        toOriginalClassRadioButton_2 = new QRadioButton(tab_2);
        toOriginalClassRadioButton_2->setObjectName(QStringLiteral("toOriginalClassRadioButton_2"));

        gridLayout_14->addWidget(toOriginalClassRadioButton_2, 1, 0, 1, 1);

        recoverRadioButton_2 = new QRadioButton(tab_2);
        recoverRadioButton_2->setObjectName(QStringLiteral("recoverRadioButton_2"));

        gridLayout_14->addWidget(recoverRadioButton_2, 1, 2, 1, 1);

        processTabWidget_2->addTab(tab_2, QString());
        altitudeDifferencesAnalisysTab_2 = new QWidget();
        altitudeDifferencesAnalisysTab_2->setObjectName(QStringLiteral("altitudeDifferencesAnalisysTab_2"));
        gridLayout_18 = new QGridLayout(altitudeDifferencesAnalisysTab_2);
        gridLayout_18->setObjectName(QStringLiteral("gridLayout_18"));
        horizontalSpacer_21 = new QSpacerItem(116, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_18->addItem(horizontalSpacer_21, 0, 0, 1, 2);

        getAltitudeStatisticsForSelectedPointsPushButton_2 = new QPushButton(altitudeDifferencesAnalisysTab_2);
        getAltitudeStatisticsForSelectedPointsPushButton_2->setObjectName(QStringLiteral("getAltitudeStatisticsForSelectedPointsPushButton_2"));

        gridLayout_18->addWidget(getAltitudeStatisticsForSelectedPointsPushButton_2, 0, 2, 1, 3);

        horizontalSpacer_22 = new QSpacerItem(89, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_18->addItem(horizontalSpacer_22, 0, 5, 1, 1);

        meanAltitudeLabel_2 = new QLabel(altitudeDifferencesAnalisysTab_2);
        meanAltitudeLabel_2->setObjectName(QStringLiteral("meanAltitudeLabel_2"));

        gridLayout_18->addWidget(meanAltitudeLabel_2, 1, 0, 1, 1);

        meanAltitudeLineEdit_2 = new QLineEdit(altitudeDifferencesAnalisysTab_2);
        meanAltitudeLineEdit_2->setObjectName(QStringLiteral("meanAltitudeLineEdit_2"));
        meanAltitudeLineEdit_2->setReadOnly(true);

        gridLayout_18->addWidget(meanAltitudeLineEdit_2, 1, 1, 1, 2);

        stdAltitudeLabel_2 = new QLabel(altitudeDifferencesAnalisysTab_2);
        stdAltitudeLabel_2->setObjectName(QStringLiteral("stdAltitudeLabel_2"));

        gridLayout_18->addWidget(stdAltitudeLabel_2, 1, 3, 1, 1);

        stdAltitudeLineEdit_2 = new QLineEdit(altitudeDifferencesAnalisysTab_2);
        stdAltitudeLineEdit_2->setObjectName(QStringLiteral("stdAltitudeLineEdit_2"));
        stdAltitudeLineEdit_2->setReadOnly(true);

        gridLayout_18->addWidget(stdAltitudeLineEdit_2, 1, 4, 1, 2);

        getDifferencesAltitudeForSelectedPointsPushButton_2 = new QPushButton(altitudeDifferencesAnalisysTab_2);
        getDifferencesAltitudeForSelectedPointsPushButton_2->setObjectName(QStringLiteral("getDifferencesAltitudeForSelectedPointsPushButton_2"));
        getDifferencesAltitudeForSelectedPointsPushButton_2->setMinimumSize(QSize(170, 0));

        gridLayout_18->addWidget(getDifferencesAltitudeForSelectedPointsPushButton_2, 2, 0, 1, 4);

        altitudeDifferenceLineEdit_2 = new QLineEdit(altitudeDifferencesAnalisysTab_2);
        altitudeDifferenceLineEdit_2->setObjectName(QStringLiteral("altitudeDifferenceLineEdit_2"));
        altitudeDifferenceLineEdit_2->setReadOnly(true);

        gridLayout_18->addWidget(altitudeDifferenceLineEdit_2, 2, 4, 1, 2);

        verticalSpacer_7 = new QSpacerItem(20, 121, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_18->addItem(verticalSpacer_7, 3, 2, 1, 1);

        processTabWidget_2->addTab(altitudeDifferencesAnalisysTab_2, QString());

        gridLayout_11->addWidget(processTabWidget_2, 1, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 177, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_11->addItem(verticalSpacer_3, 2, 0, 1, 1);

        toolBox->addItem(manualEditingProcessesPage, QStringLiteral("Manual Editing Processes"));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        page_3->setGeometry(QRect(0, 0, 440, 270));
        toolBox->addItem(page_3, QString::fromUtf8("P\303\241gina"));

        gridLayout->addWidget(toolBox, 0, 0, 1, 1);

        infoPlainTextEdit = new QPlainTextEdit(dockWidgetContents);
        infoPlainTextEdit->setObjectName(QStringLiteral("infoPlainTextEdit"));

        gridLayout->addWidget(infoPlainTextEdit, 1, 0, 1, 1);

        dockWidget->setWidget(dockWidgetContents);

        gridLayout_2->addWidget(dockWidget, 0, 1, 1, 1);


        retranslateUi(PCDViewerDialog);

        toolBox->setCurrentIndex(0);
        processTabWidget_2->setCurrentIndex(0);
        processSelectedPointsTabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PCDViewerDialog);
    } // setupUi

    void retranslateUi(QDialog *PCDViewerDialog)
    {
        PCDViewerDialog->setWindowTitle(QApplication::translate("PCDViewerDialog", "Dialog", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        toolButton_SelectByRectangle->setToolTip(QApplication::translate("PCDViewerDialog", "Select by rectangle", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolButton_SelectByRectangle->setText(QApplication::translate("PCDViewerDialog", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        toolButton_SelectByPolygon->setToolTip(QApplication::translate("PCDViewerDialog", "Select by polygon", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolButton_SelectByPolygon->setText(QApplication::translate("PCDViewerDialog", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        toolButton_SelectByFreehand->setToolTip(QApplication::translate("PCDViewerDialog", "Select by freehand", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolButton_SelectByFreehand->setText(QApplication::translate("PCDViewerDialog", "...", Q_NULLPTR));
        allClassesPushButton_2->setText(QApplication::translate("PCDViewerDialog", "All classes", Q_NULLPTR));
        toClass1PushButton_2->setText(QApplication::translate("PCDViewerDialog", "1 - Unclassified", Q_NULLPTR));
        toClass2PushButton_2->setText(QApplication::translate("PCDViewerDialog", "2 - Ground", Q_NULLPTR));
        toClass6PushButton_2->setText(QApplication::translate("PCDViewerDialog", "6 - Building", Q_NULLPTR));
        label_6->setText(QApplication::translate("PCDViewerDialog", "Vegetation:", Q_NULLPTR));
        toClass3PushButton_2->setText(QApplication::translate("PCDViewerDialog", "3 - Low", Q_NULLPTR));
        toClass4PushButton_2->setText(QApplication::translate("PCDViewerDialog", "4 - Medium", Q_NULLPTR));
        toClass5PushButton_2->setText(QApplication::translate("PCDViewerDialog", "5 - High", Q_NULLPTR));
        toClass7PushButton_2->setText(QApplication::translate("PCDViewerDialog", "7 - Low Point", Q_NULLPTR));
        toClass9PushButton_2->setText(QApplication::translate("PCDViewerDialog", "9 - Water", Q_NULLPTR));
        toClass0PushButton_2->setText(QApplication::translate("PCDViewerDialog", "0 - Created", Q_NULLPTR));
        processSelectedPointsTabWidget_2->setTabText(processSelectedPointsTabWidget_2->indexOf(classesToProcessTab_2), QApplication::translate("PCDViewerDialog", "Classes to process", Q_NULLPTR));
        lockedClass0CheckBox_2->setText(QApplication::translate("PCDViewerDialog", "0-Created", Q_NULLPTR));
        lockedClass1CheckBox_2->setText(QApplication::translate("PCDViewerDialog", "1-Unclassified", Q_NULLPTR));
        lockedClass2CheckBox_2->setText(QApplication::translate("PCDViewerDialog", "2-Ground", Q_NULLPTR));
        lockedClass6CheckBox_2->setText(QApplication::translate("PCDViewerDialog", "6-Building", Q_NULLPTR));
        label_7->setText(QApplication::translate("PCDViewerDialog", "Vegetation:", Q_NULLPTR));
        lockedClass3CheckBox_2->setText(QApplication::translate("PCDViewerDialog", "3-Low", Q_NULLPTR));
        lockedClass4CheckBox_2->setText(QApplication::translate("PCDViewerDialog", "4-Medium", Q_NULLPTR));
        lockedClass5CheckBox_2->setText(QApplication::translate("PCDViewerDialog", "5-High", Q_NULLPTR));
        lockedClass7CheckBox_2->setText(QApplication::translate("PCDViewerDialog", "7-Low Point", Q_NULLPTR));
        lockedClass9CheckBox_2->setText(QApplication::translate("PCDViewerDialog", "9-Water", Q_NULLPTR));
        processSelectedPointsTabWidget_2->setTabText(processSelectedPointsTabWidget_2->indexOf(lockedClassesTab_2), QApplication::translate("PCDViewerDialog", "Locked classes", Q_NULLPTR));
        removeRadioButton_2->setText(QApplication::translate("PCDViewerDialog", "Remove", Q_NULLPTR));
        changeClassRadioButton_2->setText(QApplication::translate("PCDViewerDialog", "Change class to", Q_NULLPTR));
        selectOnlyRadioButton_2->setText(QApplication::translate("PCDViewerDialog", "Select only", Q_NULLPTR));
        unselectRadioButton_2->setText(QApplication::translate("PCDViewerDialog", "Unselect", Q_NULLPTR));
        toOriginalClassRadioButton_2->setText(QApplication::translate("PCDViewerDialog", "To Original Class", Q_NULLPTR));
        recoverRadioButton_2->setText(QApplication::translate("PCDViewerDialog", "Recover", Q_NULLPTR));
        processTabWidget_2->setTabText(processTabWidget_2->indexOf(tab_2), QApplication::translate("PCDViewerDialog", "Process with selected points", Q_NULLPTR));
        getAltitudeStatisticsForSelectedPointsPushButton_2->setText(QApplication::translate("PCDViewerDialog", "Get altitude statistics for selected points", Q_NULLPTR));
        meanAltitudeLabel_2->setText(QApplication::translate("PCDViewerDialog", "Mean (m):", Q_NULLPTR));
        stdAltitudeLabel_2->setText(QApplication::translate("PCDViewerDialog", "Std (m):", Q_NULLPTR));
        getDifferencesAltitudeForSelectedPointsPushButton_2->setText(QApplication::translate("PCDViewerDialog", "Mean - altitude, for selected point (m):", Q_NULLPTR));
        processTabWidget_2->setTabText(processTabWidget_2->indexOf(altitudeDifferencesAnalisysTab_2), QApplication::translate("PCDViewerDialog", "Altitudes differences analisys", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(manualEditingProcessesPage), QApplication::translate("PCDViewerDialog", "Manual Editing Processes", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_3), QApplication::translate("PCDViewerDialog", "P\303\241gina", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PCDViewerDialog: public Ui_PCDViewerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PCDVIEWERDIALOG_H
