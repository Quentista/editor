#include "GridData.h"

GridData::GridData(int width, int height, QObject *parent)
{
	this->recreate(width, height);
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
}
