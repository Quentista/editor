#include "MainWindow.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QSignalMapper>
#include <QFileDialog>
#include <QStringList>
#include <QDebug>

#include "GridWidget.h"
#include "GridData.h"

MainWindow::MainWindow(QWidget *parent)
	: QWidget(parent)
	, m_pixDir("textures_src")
	, m_gData(new GridData(10, 10, this))
	, m_mapper(new QSignalMapper(this))
	, m_createButton(new QPushButton("create"))
	, m_saveButton(new QPushButton("Save"))
	, m_loadButton(new QPushButton("Load"))
	, m_newWidth(new QLineEdit)
	, m_newHeight(new QLineEdit)
{
	qDebug()<<m_pixDir.entryList(QDir::Files);
	m_pixList.append( m_pixDir.entryList(QDir::Files));
	m_gWidget = new GridWidget(m_gData, m_pixList);
	
	this->connect(m_createButton, SIGNAL(clicked()), this, SLOT(createNew()));
	this->connect(m_mapper, SIGNAL(mapped(int)),
				  m_gWidget, SLOT(setCurrentPix(int)));
	this->connect(m_saveButton, SIGNAL(clicked()), this, SLOT(trySave()));
	this->connect(m_loadButton, SIGNAL(clicked()), this, SLOT(tryLoad()));
	
	// Layout setup
	
	QHBoxLayout* mainLayout = new QHBoxLayout;
	mainLayout->setMargin(0);
	mainLayout->addWidget(m_gWidget);
	
	QVBoxLayout* buttonsLayout = new QVBoxLayout;
	
	buttonsLayout->addWidget(m_newWidth);
	m_newWidth->setSizePolicy(QSizePolicy::Fixed , QSizePolicy::Fixed);
	buttonsLayout->addWidget(m_newHeight);
	m_newHeight->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	buttonsLayout->addWidget(m_createButton);
	m_createButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	buttonsLayout->addWidget(m_saveButton);
	m_saveButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	buttonsLayout->addWidget(m_loadButton);
	m_loadButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	
	mainLayout->addLayout(buttonsLayout, 0);
	this->setLayout(mainLayout);
	
	for (int i=0; i<m_pixList.size(); ++i)
	{
		QPushButton* button = new QPushButton(QString::number(i));
		buttonsLayout->addWidget(button);
		button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
		m_mapper->setMapping(button,i);
		connect(button,SIGNAL(clicked()),m_mapper,SLOT(map()));
	}
	
//	QVBoxLayout* mainLayout = new QVBoxLayout;
//	mainLayout->setMargin(0);
//	mainLayout->addWidget(m_gWidget);
//	mainLayout->addWidget(m_newWidth);
//	mainLayout->addWidget(m_newHeight);
//	mainLayout->addWidget(m_createButton);
//	this->setLayout(mainLayout);
	
//	for (int i=0; i<m_pixList.size(); ++i)
//	{
//		QPushButton* button = new QPushButton(QString::number(i));
//		mainLayout->addWidget(button);
//		m_mapper->setMapping(button,i);
//		connect(button,SIGNAL(clicked()),m_mapper,SLOT(map()));
//	}
}

MainWindow::~MainWindow()
{
	
}

void MainWindow::createNew()
{
	bool ok = false;
	
	int width = m_newWidth->text().toInt(&ok);
	if(!ok) return;
	
	int height = m_newHeight->text().toInt(&ok);
	if(!ok) return;
	
	m_gData->recreate(width,height);
	m_gWidget->repaint();
}

void MainWindow::trySave()
{
	QFileDialog dialog;
	dialog.setModal(true);
	dialog.setConfirmOverwrite(true);
	dialog.setNameFilters(QStringList() << "Editor files (*.edf)");
	dialog.setAcceptMode(QFileDialog::AcceptSave);
	if(dialog.exec())
	{
		m_gData->saveToFile(dialog.selectedFiles().first());
	}
}

void MainWindow::tryLoad()
{
	QFileDialog dialog;
	dialog.setModal(true);
	dialog.setNameFilters(QStringList() << "Editor files (*.edf)");
	dialog.setAcceptMode(QFileDialog::AcceptOpen);
	if(dialog.exec())
	{
		m_gData->loadFromFile(dialog.selectedFiles().first());
	}
}
