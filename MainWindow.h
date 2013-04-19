#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class GridWidget;
class GridData;

class QSignalMapper;
class QDir;
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
	
	QDir* m_texturesDir;
	QSignalMapper* m_mapper;
	QStringList m_pixList;
	
	QPushButton* m_createButton;
	QPushButton* m_saveButton;
	QPushButton* m_loadButton;
	QLineEdit* m_newWidth;
	QLineEdit* m_newHeight;
	
	GridData* m_gData;
	GridWidget* m_gWidget;
};

#endif // MAINWINDOW_H
