#include "paint_canvas.h"
#include "PCDViewerMainWindow.h"
#include "../widget/logger.h"
#include "../widget/message_box.h"
#include "../basic/stop_watch.h"
#include "../geometry/vertex_group.h"
#include "../geometry/point_set.h"
#include "../geometry/label_store.h"
#include "../geometry/compare.h"
#include "../basic/file_system.h"
#include "../QGLViewer/manipulatedCameraFrame.h"
#include "tool_manager3d.h"

#include <QFileDialog>
#include <QMouseEvent>
#include <QMessageBox>
#include <QColorMap>
#include <QColorDialog>
#include <cassert>
#include <fstream>


using namespace Tl;
using namespace std;
using namespace qglviewer;


#ifndef GL_MULTISAMPLE
#define GL_MULTISAMPLE 0x809D
#endif



PaintCanvas::PaintCanvas(const QGLFormat& format, QWidget *parent)
: QGLViewer(format, parent)
, coord_system_region_size_(150)
, point_set_(nil)
, show_coord_system_(true)
, show_normals_(false)
{
    main_window_ = dynamic_cast<PCDViewerMainWindow*>(parent);
	tool_manager_ = new ToolManager3D(this);

	//////////////////////////////////////////////////////////////////////////
//	camera()->setPosition(Vec(1.0,  1.0, 1.0));
    camera()->setPosition(Vec(0.0,  0.0, 1.0));
//    camera()->setPosition(sceneCenter());

	camera()->lookAt(sceneCenter());
	camera()->setType(Camera::PERSPECTIVE);
	camera()->showEntireScene();
}


PaintCanvas::~PaintCanvas() {
	if (tool_manager_) {
		delete tool_manager_;
		tool_manager_ = nil;
	}

	clearPointSet();
}


void PaintCanvas::setPerspectiveMode(bool b) {
	if (b) {
		if (camera()->type() != Camera::PERSPECTIVE)
			camera()->setType(Camera::PERSPECTIVE);
	} else {	
		if (camera()->type() != Camera::ORTHOGRAPHIC)
			camera()->setType(Camera::ORTHOGRAPHIC);
	}
	updateCanvas();
}

void PaintCanvas::sceneManipulation() {
	tool_manager_->set_tool(Tl::TOOL_EMPTY);
	tool_manager_->reset();
	setCursor(Qt::ArrowCursor);

	update();
}


void PaintCanvas::updateCanvas() { 
    main_window_->updateStatusBar();
    main_window_->updateAnnotationTable();
    if(point_set_!=NULL)
    {
        Vertex** vertices = pointSet()->vertices();
        int num = pointSet()->nb_vertices();
        int numberOfSelectedPoints=0;
        for (int i=0; i<num; ++i) {
            Vertex* v = vertices[i];
            if (v->is_selected()) numberOfSelectedPoints++;
        }

        Logger::output("[SelectTool]: ") << numberOfSelectedPoints << " points selected." << Logger::endl();
    //    if (b)
    //    else
    //        Logger::output("[SelectTool]: ") << selected_object_indices_.size() << " points deselected." << Logger::endl();
    }
    update();
}


void PaintCanvas::forceUpdate() {
	repaint();
	updateCanvas();
}


void PaintCanvas::init()
{
	setStateFileName("");

	glEnable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//////////////////////////////////////////////////////////////////////////

	QColor bkgrd_color = Qt::white;
	setBackgroundColor(bkgrd_color);

	//////////////////////////////////////////////////////////////////////////

	camera()->frame()->setSpinningSensitivity(/*1.0f*/100.0f);
	setMouseTracking(true);

	//setMouseBinding(Qt::ShiftModifier | Qt::LeftButton, CAMERA, SCREEN_ROTATE);
	//setHandlerKeyboardModifiers(QGLViewer::CAMERA, Qt::ControlModifier);

	//////////////////////////////////////////////////////////////////////////

	// light0
    GLfloat	light_position[] = { 1.0f, 1.0f, 1.0f, 1.0f };
//    GLfloat	light_position[] = { 0.0f, 0.0f, 1.0f, 0.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	// Setup light parameters
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE); /*GL_FALSE*/
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
//    glLightModeli(GL_LIGHT_MODEL_AMBIENT,GL_TRUE);

    glEnable(GL_LIGHT0);		// Enable Light 0
    glEnable(GL_LIGHTING);

	//////////////////////////////////////////////////////////////////////////

	/* to use facet color, the GL_COLOR_MATERIAL should be enabled */
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, 128);

	/* to use material color, the GL_COLOR_MATERIAL should be disabled */
	//glDisable(GL_COLOR_MATERIAL);
}


void PaintCanvas::draw()
{
	glEnable(GL_MULTISAMPLE);

	if (show_coord_system_)
		drawCornerAxis();		

	//////////////////////////////////////////////////////////////////////////

	if (pointSet()) {
		// for point cloud, we don't need anti-aliasing
		glDisable(GL_MULTISAMPLE);
		
		bool fast = camera()->frame()->isManipulated();
//		pointSet()->draw(show_normals_, 5, fast, 50000);
        pointSet()->draw(show_normals_, 5, fast);
    }

	glEnable(GL_MULTISAMPLE);

	//////////////////////////////////////////////////////////////////////////

	if (tool_manager_->current_tool_name() != Tl::TOOL_EMPTY)
		tool_manager_->current_tool()->draw();
}



void PaintCanvas::increasePointSize() {
	if (Global::point_size <= 9 && Global::point_size >= 1) {
		Global::point_size += 1.0f;
		updateCanvas();
	}
}

void PaintCanvas::decreasePointSize(){
	if (Global::point_size <= 10 && Global::point_size >= 2) {
		Global::point_size -= 1.0f;
		updateCanvas();
	}
}



void PaintCanvas::fitScreen() {
	if (pointSet())	{
		Bbox3f box = pointSet()->bbox();
		Vec vmin(box.xmin(), box.ymin(), box.zmin());
		Vec vmax(box.xmax(), box.ymax(), box.zmax());

		//Vec vmin(-2.0f, -2.0f, -2.0f);
		//Vec vmax(2.0f, 2.0f, 2.0f);

		//std::cout << "BBox: (" << box.xmax() - box.xmin() << ", " << box.ymax() - box.ymin() << ", " << box.zmax() - box.zmin() << ")" << std::endl;

		setSceneBoundingBox(vmin, vmax);
		camera()->lookAt(sceneCenter());
		showEntireScene();
	} 
} 

void PaintCanvas::clearPointSet() {
	if (point_set_ != nil) {
		delete point_set_;
		point_set_ = nil;
	}
}

bool PaintCanvas::getPointUnderMouse(const QPoint& pos, Point3f& p) const {
	bool found = false;
	Vec q = camera()->pointUnderPixel(pos, found);
	p = Point3f(q.x, q.y, q.z);
	return found;
}

void PaintCanvas::showCoordinateUnderPixel(const QPoint& pos) const {
	Point3f coord;
	bool found = getPointUnderMouse(pos, coord);
    mainWindow()->showCoordinateUnderMouse(coord, found);
}


//   Customized mouse events
void PaintCanvas::mousePressEvent(QMouseEvent* e)
{
	if (tool_manager_->current_tool_name() != Tl::TOOL_EMPTY) {
		tool_manager_->current_tool()->press(e); 
	}

	else 
		QGLViewer::mousePressEvent(e);
}


void PaintCanvas::mouseMoveEvent(QMouseEvent* e)
{	
	showCoordinateUnderPixel(e->pos());

	if (tool_manager_->current_tool_name() != Tl::TOOL_EMPTY) 
		tool_manager_->current_tool()->move(e);
	else 
		QGLViewer::mouseMoveEvent(e); 
}


void PaintCanvas::mouseReleaseEvent(QMouseEvent* e)
{
	if (tool_manager_->current_tool_name() != Tl::TOOL_EMPTY)
		tool_manager_->current_tool()->release(e); 
	else 	
		QGLViewer::mouseReleaseEvent(e);
}


void PaintCanvas::wheelEvent(QWheelEvent *e) {
	//if (tool_manager_->current_tool_name() != Tl::TOOL_SELECT_VERTEX_GROUP_BY_SCRIBER)
		QGLViewer::wheelEvent(e);
}

	
void PaintCanvas::keyPressEvent(QKeyEvent *e) {
	switch (e->key())
	{
	case Qt::Key_Escape: // I don't want to close the window
		break;
	case Qt::Key_A: // I don't want to show the axis
		break;
	case Qt::Key_G: // I don't want to show the ground plane
		break;
	case Qt::Key_H: // I don't want to show help dialog
		break;
	case Qt::Key_S: // I don't want to switch to stereo mode
		break;
	case Qt::Key_Space:
		break;

	default:
		QGLViewer::keyPressEvent(e);
	}
}


void PaintCanvas::drawCornerAxis()  
{
	int viewport[4];
	int scissor[4];

	glDisable(GL_LIGHTING);

	// The viewport and the scissor are changed to fit the lower left
	// corner. Original values are saved.
	glGetIntegerv(GL_VIEWPORT, viewport);
	glGetIntegerv(GL_SCISSOR_BOX, scissor);

	// Axis viewport size, in pixels
	glViewport(0, 0, coord_system_region_size_, coord_system_region_size_);
	glScissor(0, 0, coord_system_region_size_, coord_system_region_size_);

	// The Z-buffer is cleared to make the axis appear over the
	// original image.
	glClear(GL_DEPTH_BUFFER_BIT);

	// Tune for best line rendering
	glLineWidth(3.0);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(-1, 1, -1, 1, -1, 1);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glMultMatrixd(camera()->orientation().inverse().matrix());

	float axis_size = 0.9f; // other 0.2 space for drawing the x, y, z labels
	drawAxis(axis_size); 
	
	// Draw text id
	glDisable(GL_LIGHTING);
	glColor3f(0, 0, 0);
	renderText(axis_size, 0, 0, "X");
	renderText(0, axis_size, 0, "Y");
	renderText(0, 0, axis_size, "Z");

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	// The viewport and the scissor are restored.
	glScissor(scissor[0], scissor[1], scissor[2], scissor[3]);
	glViewport(viewport[0], viewport[1], viewport[2], viewport[3]);

	glEnable(GL_LIGHTING);
}

Point2f PaintCanvas::projectionOf(const Point3f& p) {    // point to screen
	Vec v = camera()->projectedCoordinatesOf(Vec(p.x(), p.y(), p.z()));
	return Point2f(v.x, v.y);
}

Point3f PaintCanvas::unProjectionOf(double winx, double winy, double winz) {  // screen to point	
	Vec v = camera()->unprojectedCoordinatesOf(Vec(winx, winy, winz));
	return Point3f(v.x, v.y, v.z);
}


PointSet*  PaintCanvas::pointSet() const { 
	return point_set_;
}

void PaintCanvas::setPointSet(PointSet* ptc)
{
	clearPointSet();
	point_set_ = ptc;
	ptc->set_scene_graph(this);

	fitScreen();
	updateCanvas();
}

SceneGraph* PaintCanvas::output(const std::string& msg) {
	mainWindow()->output(msg);
	return this;
}

SceneGraph* PaintCanvas::output(int v) {
	std::string msg = QString::number(v).toStdString();
	mainWindow()->output(msg);
	return this;
}

SceneGraph* PaintCanvas::output(double v) {
	std::string msg = QString::number(v).toStdString();
	mainWindow()->output(msg);
	return this;
}



void PaintCanvas::markPointForDesampling(float dist_thresh) {
	if (point_set_ == nil)
		return;

	Vertex** vertices = point_set_->vertices();
	unsigned int num = point_set_->nb_vertices();

	// clean
	for (unsigned int i=0; i<num; ++i) {
		vertices[i]->set_selected(false);
	}

	unsigned int dup = 0;
	Compare::VertexCmp cmp(dist_thresh);
	typedef std::map<Point3f, int, Compare::VertexCmp> VertexMap;
	VertexMap vMap(cmp);

	for (unsigned int i=0; i<num; ++i) {
		Vertex* v = vertices[i];
		VertexMap::iterator vMapIt = vMap.find(v->point());
		if ( vMapIt == vMap.end()) {
			vMap[v->point()] = i; // any value is ok
		} else {
			v->set_selected(true);
			++dup;
		}
	}

	Logger::output(title()) << dup << " points marked, " << num - dup << " will remain." << Logger::endl();
	updateCanvas();
}


void PaintCanvas::deleteSelectedPoints() {
	if (pointSet() == nil)
		return;

	Vertex** vertices = pointSet()->vertices();
	int num = pointSet()->nb_vertices();

	std::set<Vertex*> all;
	std::vector<Vertex*> to_delete;
	for (int i=0; i<num; ++i) {
		Vertex* v = vertices[i];
		all.insert(v);

		if (v->is_selected())
			to_delete.push_back(v);
	}

	if (to_delete.empty()) {
		Logger::output(title()) << "No points selected." << Logger::endl();
		return;
	}

	for (unsigned int i=0; i<to_delete.size(); ++i)	{
		Vertex* v = to_delete[i];
		all.erase(v);
	}

	Vertex** vts = new Vertex*[all.size()];
	int idx = 0;
	for (std::set<Vertex*>::iterator it=all.begin(); it!=all.end(); ++it) {
		vts[idx] = *it;
		++idx;
	}

	point_set_->set_vertices(vts, all.size());
	delete [] vertices;

	//////////////////////////////////////////////////////////////////////////

	std::vector<VertexGroup*> full_group_to_delete;

	std::vector<VertexGroup*>& groups = pointSet()->vertex_groups();
	for (unsigned int i=0; i<groups.size(); ++i) {
		VertexGroup* g = groups[i];

		std::vector<Vertex*> g_set;
		for (unsigned int j=0; j<g->size(); ++j) {
			Vertex* v = g->at(j);
			if (v->is_selected() == false)
				g_set.push_back(v);
		}

		if (g_set.empty())
			full_group_to_delete.push_back(g);
		else if (g_set.size() != g->size()) {
			g->clear();
			g->insert(g->end(), g_set.begin(), g_set.end());
		}

		// check children
		std::vector<VertexGroup*>& children = g->children();
		for (unsigned int j=0; j<children.size(); ++j) {
			VertexGroup* chld = children[j];
			std::vector<Vertex*> tmp;
			for (unsigned int k=0; k<chld->size(); ++k) {
				Vertex* v = chld->at(k);
				if (v->is_selected() == false)
					tmp.push_back(v);
			}

			if (tmp.empty()) {
				g->remove_child(chld);
				delete chld;
			}
			else if (tmp.size() != chld->size()) {
				chld->clear();
				chld->insert(chld->end(), tmp.begin(), tmp.end());
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////

	for (unsigned int j=0; j<full_group_to_delete.size(); ++j) {
		VertexGroup* g = full_group_to_delete[j];
		point_set_->delete_vertex_group(g);
	}

	for (unsigned int i=0; i<to_delete.size(); ++i)	{
		Vertex* v = to_delete[i];
		delete v;
	}	
	if (to_delete.size() > 0) {
		point_set_->changed();
	}

	updateCanvas();
}


void PaintCanvas::rotatePointCloud(float x, float y, float z) {
	PointSet* pointset = pointSet();
	if (pointset == nil) {
		Messagebox::warning(mainWindow(), "Warning!", "Point cloud does not exist.");
		return;
	}

	//////////////////////////////////////////////////////////////////////////

	Bbox3f box = pointSet()->bbox();
	float center_x = (box.xmin() + box.xmax()) * 0.5f;
	float center_y = (box.ymin() + box.ymax()) * 0.5f;
	float center_z = (box.zmin() + box.zmax()) * 0.5f;
	Point3f axis_pos(center_x, center_y, center_z);

	Vertex** vertices = pointSet()->vertices();
	int num = pointSet()->nb_vertices();

	if (std::abs(x) > 1e-6) {
		Vector3f x_axis(1.0f, 0.0f, 0.0f);
		for (int i=0; i<num; ++i) {
			Vertex* v = vertices[i];
			Point3f p = Global::rotate_in_degree(v->point(), axis_pos, x_axis, x);
			Vector3f n = Global::rotate_in_degree(CGAL::ORIGIN + v->normal(), CGAL::ORIGIN, x_axis, x) - CGAL::ORIGIN;
			Global::normalize(n);
			v->set_point(p);
			v->set_normal(n);
		}
	}

	if (std::abs(y) > 1e-6) {
		Vector3f y_axis(0.0f, 1.0f, 0.0f);
		for (int i=0; i<num; ++i) {
			Vertex* v = vertices[i];
			Point3f p = Global::rotate_in_degree(v->point(), axis_pos, y_axis, y);
			Vector3f n = Global::rotate_in_degree(CGAL::ORIGIN + v->normal(), CGAL::ORIGIN, y_axis, y) - CGAL::ORIGIN;
			Global::normalize(n);
			v->set_point(p);
			v->set_normal(n);
		}
	}

	if (std::abs(z) > 1e-6) {
		Vector3f z_axis(0.0f, 0.0f, 1.0f);
		for (int i=0; i<num; ++i) {
			Vertex* v = vertices[i];
			Point3f p = Global::rotate_in_degree(v->point(), axis_pos, z_axis, z);
			Vector3f n = Global::rotate_in_degree(CGAL::ORIGIN + v->normal(), CGAL::ORIGIN, z_axis, z) - CGAL::ORIGIN;
			Global::normalize(n);

			//std::cout << "before: " << v->normal() << "     after: " << n << std::endl;
 			v->set_point(p);
			v->set_normal(n);
		}
	}

	updateGL();
}


void PaintCanvas::setShowNormals(bool b) {
	show_normals_ = b;
	updateGL();
}


void PaintCanvas::setShowCoordinateSystem(bool b) { 
	show_coord_system_ = b; 

	updateCanvas();
}


void PaintCanvas::selectPointsByRectangle() {
	if (point_set_ == nil) {
		Messagebox::warning(main_window_, "Warning!", "Point cloud does not exist.");
		return;
	} 

	tool_manager_->set_tool(TOOL_SELECT_VERTEX_BY_RECTANGLE);
	tool_manager_->set_select_method(SM_RECTANGLE);
	setCursor(Qt::PointingHandCursor);
	update();
}

void PaintCanvas::selectPointsByLasso() {
	if (point_set_ == nil) {
		Messagebox::warning(main_window_, "Warning!", "Point cloud does not exist.");
		return;
	} 

	tool_manager_->set_tool(TOOL_SELECT_VERTEX_BY_LASSO);
	tool_manager_->set_select_method(SM_LASSO);
	setCursor(Qt::PointingHandCursor);
	update();
}


void PaintCanvas::assignColorByNormal() {
	if (pointSet()) {
		pointSet()->assign_color_by_normal();
		updateCanvas();
	}
}

void PaintCanvas::assignColorByHeight() {
	if (pointSet()) {
		pointSet()->assign_color_by_height();
		updateCanvas();
	}
}
