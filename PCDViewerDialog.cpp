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
#include <math.h>
#include "../PCDViewer/paint_canvas.h"
#include "../geometry/file_io.h"
#include "../geometry/point_set.h"
#include "../widget/logger.h"
#include "../widget/message_box.h"
#include "../geometry/vertex_group.h"
#include "../basic/file_system.h"
#include "../widget/logger.h"

#include "PCDViewerDialog.h"
#include "ui_PCDViewerDialog.h"

using namespace qglviewer;

PCDViewerDialog::PCDViewerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PCDViewerDialog)
{
    ui->setupUi(this);

    QGLFormat format = QGLFormat::defaultFormat();
    format.setSampleBuffers(true);
    format.setSamples(8);

    mMainCanvas = new PaintCanvas(format, this);
    mMainCanvas->setAttribute(Qt::WA_MouseTracking);

    ui->centralWidget=mMainCanvas;
    Logger::init(mMainCanvas);

    ui->dockWidget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    ui->centralWidget->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Expanding);

    setWindowState(Qt::WindowMaximized);

    setFocusPolicy(Qt::ClickFocus);

    mMainCanvas->camera()->setType(Camera::PERSPECTIVE);
    showMaximized();

//    this->exec();
}

PCDViewerDialog::~PCDViewerDialog()
{
    delete ui;
}

SceneGraph *PCDViewerDialog::output(const std::string &msg)
{
    std::cout << msg ;
    ui->infoPlainTextEdit->moveCursor(QTextCursor::End);
    ui->infoPlainTextEdit->insertPlainText(QString::fromStdString(msg));
    ui->infoPlainTextEdit->repaint();
    ui->infoPlainTextEdit->update();
    return mMainCanvas;
}
