#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QDir>

class GridWidget;
class GridData;

class QSignalMapper;
class QStringList;
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
	void trySave();
	void tryLoad();
	
private:
	
	QDir m_pixDir;
	QSignalMapper* m_mapper;
	QStringList m_pixList;
	
	GridData* m_gData;
	GridWidget* m_gWidget;
	
	QPushButton* m_createButton;
	QPushButton* m_saveButton;
	QPushButton* m_loadButton;
	QLineEdit* m_newWidth;
	QLineEdit* m_newHeight;
};

#endif // MAINWINDOW_H
