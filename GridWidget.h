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
	
protected:
	
	virtual void paintEvent(QPaintEvent *evt);
	virtual void wheelEvent(QWheelEvent *evt);
	
private:
	
	GridData* m_gData;
	int m_scale;
};

#endif // GRIDWIDGET_H
