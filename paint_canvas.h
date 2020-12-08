#ifndef PAINTCANVAS_H
#define PAINTCANVAS_H

#include "../qglviewer/qglviewer.h"
#include "../basic/scene_graph.h"
#include "../geometry/color.h"
#include "../geometry/geometry_types.h"
#include "../geometry/point_set.h"


class PCDViewerMainWindow;
class ToolManager3D;
class PointSet;
class PolyMesh;
class VertexGroup;


class PaintCanvas : public QGLViewer, public SceneGraph
{
	Q_OBJECT

public:
	PaintCanvas(const QGLFormat& format, QWidget *parent);
	~PaintCanvas();

public:
	std::string title() const { return "[PaintCanvas]: "; }

	SceneGraph* output(const std::string& msg) ;
	SceneGraph* output(int v) ;
	SceneGraph* output(double v) ;

	void forceUpdate() ;
	void updateCanvas() ; 

    PCDViewerMainWindow* mainWindow() const { return main_window_; }

	Point2f projectionOf(const Point3f& p);          // point to screen
	Point3f unProjectionOf(double winx, double winy, double winz);  // screen to point

	PointSet*  pointSet() const ;
	void setPointSet(PointSet* ptc);

	bool getPointUnderMouse(const QPoint& pos, Point3f& p) const ;

	void markPointForDesampling(float dist_thresh);

	void rotatePointCloud(float x, float y, float z);

	void sceneManipulation() ;
	void selectPointsByRectangle();
	void selectPointsByLasso();

protected:
	virtual void draw();
	virtual void init();

	// Mouse events functions
	virtual void mousePressEvent(QMouseEvent *e);
	virtual void mouseMoveEvent(QMouseEvent *e);
	virtual void mouseReleaseEvent(QMouseEvent *e);

	virtual void keyPressEvent(QKeyEvent *e);

	// wheel event
	virtual void wheelEvent(QWheelEvent *e);
	
public slots:
	void fitScreen() ;

	void increasePointSize();
	void decreasePointSize();

	void setPerspectiveMode(bool b);
	void setShowCoordinateSystem(bool b);

	void deleteSelectedPoints();
	
	void assignColorByHeight();
	void assignColorByNormal();

	void setShowNormals(bool b);

private :
	void showCoordinateUnderPixel(const QPoint& p) const; 

	void drawCornerAxis() ;

	void clearPointSet();

protected:
    PCDViewerMainWindow*		main_window_;
	ToolManager3D*  tool_manager_;

private:
	PointSet*	point_set_;
	int			coord_system_region_size_;
	bool		show_coord_system_;
	bool		show_normals_;
};


#endif // PAINTCANVAS_H
