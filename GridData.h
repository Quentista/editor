#ifndef GRIDDATA_H
#define GRIDDATA_H

#include <QObject>

class GridData : public QObject
{
	Q_OBJECT
public:
	explicit GridData(int width, int height, QObject *parent = 0);
	~GridData();

	void recreate(int width, int height);
	void saveToFile(QString fileName);
	void loadFromFile(QString fileName);
	
	void setCellData(int x, int y, int pix);
	int getCellData(int x, int y);
	
	int width();
	int height();
	
signals:
	void updated();
	
public slots:
	
private:
	int m_width;
	int m_height;
	int* m_array;
};

#endif // GRIDDATA_H
