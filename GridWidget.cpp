#include "GridWidget.h"

#include "GridData.h"

#include <QWheelEvent>
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QColor>
#include <QList>
#include <QPixmap>

GridWidget::GridWidget(GridData* data, QStringList strList, QWidget *parent) :
	QWidget(parent)
  , m_gData(data)
  , m_scale(20)
  , m_currentPix(0)
{
	m_pixList.append(strList);
}

/*virtual*/ void GridWidget::paintEvent(QPaintEvent *evt)
{
	QWidget::paintEvent(evt);
	
	QPainter painter(this);
	
	painter.setPen(QPen(QColor(0,0,0)));
	
	int width = m_gData->width();
	int height = m_gData->height();
	
	for(int i=0; i<width; ++i)
	{
		for(int j=0; j<height; ++j)
		{
			int PixId = m_gData->getCellData(i,j);
			painter.drawPixmap(i*m_scale, j*m_scale, m_scale, m_scale,
							   QPixmap(m_pixList[PixId]));
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

/*virtual*/ void GridWidget::mousePressEvent(QMouseEvent *evt)
{
	int cellX = evt->x() / m_scale;
	int cellY = evt->y() / m_scale;
	
	if (cellX < m_gData->width() && cellY < m_gData->height())
	{
		m_gData->setCellData(cellX, cellY, m_currentPix);
		this->repaint();
	}
}

void GridWidget::mouseMoveEvent(QMouseEvent *evt)
{
	int cellX = evt->x() / m_scale;
	int cellY = evt->y() / m_scale;
	
	if (cellX < m_gData->width() && cellY < m_gData->height())
	{
		m_gData->setCellData(cellX, cellY, m_currentPix);
		this->repaint();
	}
}

void GridWidget::setCurrentPix(int i)
{
	m_currentPix = i;
}
