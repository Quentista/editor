#ifndef GRIDWIDGET_H
#define GRIDWIDGET_H

#include <QWidget>
#include <QStringList>

class GridData;
class QStringList;

class GridWidget : public QWidget
{
	Q_OBJECT
public:
	explicit GridWidget(GridData* data, QStringList pixList,
						QWidget *parent = 0);
	
signals:
	
public slots:
	void setCurrentPix(int i);
	
protected:
	
	virtual void paintEvent(QPaintEvent *evt);
	virtual void wheelEvent(QWheelEvent *evt);
	virtual void mousePressEvent(QMouseEvent *evt);
	virtual void mouseMoveEvent(QMouseEvent *evt);
	
private:
	void placePix(int x, int y);
	
	GridData* m_gData;
	int m_scale;
	int m_currentPix;
	
	QStringList m_pixList;
};

#endif // GRIDWIDGET_H
