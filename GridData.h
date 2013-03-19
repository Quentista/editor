#ifndef GRIDDATA_H
#define GRIDDATA_H

#include <QObject>

class GridData : public QObject
{
	Q_OBJECT
public:
	explicit GridData(int width, int height, QObject *parent = 0);

	void recreate(int width, int height);
	
	int width();
	int height();
	
signals:
	
public slots:
	
private:
	int m_width;
	int m_height;
};

#endif // GRIDDATA_H
