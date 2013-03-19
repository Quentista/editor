#include "GridWidget.h"

#include "GridData.h"

#include <QWheelEvent>
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QColor>

GridWidget::GridWidget(GridData* data, QWidget *parent) :
	QWidget(parent)
  , m_gData(data)
  , m_scale(10)
{
}

/*virtual*/ void GridWidget::paintEvent(QPaintEvent *evt)
{
	QWidget::paintEvent(evt);
	
	QPainter painter(this);
	
	painter.setPen(QPen(QColor(0,0,0)));
	painter.setBrush(QBrush(QColor(0,100,0)));
	
	int width = m_gData->width();
	int height = m_gData->height();
	
	for(int i=0; i<width; ++i)
	{
		for(int j=0; j<height; ++j)
		{
			painter.drawRect(QRect(i*m_scale, j*m_scale, m_scale, m_scale));
		}
	}
}

/*virtual*/ void GridWidget::wheelEvent(QWheelEvent *evt)
{
	m_scale += evt->delta()/100;
	if (m_scale<1) m_scale = 1;
	this->repaint();
}
