#include "GridData.h"

#include <QFile>

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

void GridData::saveToFile(QString fileName)
{
	QFile file;
	file.setFileName(fileName);
	if(file.open(QFile::WriteOnly))
	{
		file.write((char*)&m_width,sizeof(int));
		file.write((char*)&m_height,sizeof(int));
		file.write((char*)m_array,sizeof(int)*m_width*m_height);
	}
	else
	{
		qDebug("Editor::saveToFile can't save to file %s",
			   fileName.toStdString().data());
	}
}

void GridData::loadFromFile(QString fileName)
{
	QFile file;
	file.setFileName(fileName);
	if(file.open(QFile::ReadOnly))
	{
		file.read((char*)&m_width,sizeof(int));
		file.read((char*)&m_height,sizeof(int));
		delete m_array;
		m_array = new int[m_width*m_height];
		file.read((char*)m_array,sizeof(int)*m_width*m_height);
		emit updated();
	}
	else
	{
		qDebug("Editor::loadToFile can't load to file %s",
			   fileName.toStdString().data());
	}
}


