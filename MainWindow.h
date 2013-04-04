#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class GridWidget;
class GridData;

class QSignalMapper;
class QPushButton;
class QLineEdit;

class MainWindow : public QWidget
{
	Q_OBJECT
	
public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();
	
private slots:
	void createNew();
	
private:
	
	GridData* m_gData;
	GridWidget* m_gWidget;
	
	QSignalMapper* m_mapper;
	QPushButton* m_createButton;
	QLineEdit* m_newWidth;
	QLineEdit* m_newHeight;
};

#endif // MAINWINDOW_H
