#include "GridData.h"

GridData::GridData(int width, int height, QObject *parent)
{
	this->recreate(width, height);
}

GridData::~GridData()
{
	delete [] m_array;
}

int GridData::width()
{
	return m_width;
}
int GridData::height()
{
	return m_height;
}

void GridData::recreate(int width, int height)
{
	m_width = width;
	m_height = height;
	m_array = new int [m_width*m_height];
	
	for (int z=0; z <(m_width*m_height); ++z)
	{
		m_array[z]=0;
	}
}

int GridData::getCellData(int x, int y)
{
	return m_array[x* m_height +y];
}

void GridData::setCellData(int x, int y, int pix)
{
	m_array[m_height* x +y] = pix;
	emit updated();
}


