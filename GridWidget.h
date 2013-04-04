#ifndef GRIDWIDGET_H
#define GRIDWIDGET_H

#include <QWidget>

class GridData;

class GridWidget : public QWidget
{
	Q_OBJECT
public:
	explicit GridWidget(GridData* data, QWidget *parent = 0);
	
signals:
	
public slots:
	void setCurrentPix(int i);
	
protected:
	
	virtual void paintEvent(QPaintEvent *evt);
	virtual void wheelEvent(QWheelEvent *evt);
	virtual void mousePressEvent(QMouseEvent *evt);
	
private:
	void placePix(int x, int y);
	
	GridData* m_gData;
	int m_scale;
	int m_currentPix;
	
	QList <QString> m_pixList;
};

#endif // GRIDWIDGET_H
