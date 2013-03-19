#include "MainWindow.h"

#include "GridWidget.h"
#include "GridData.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent)
	: QWidget(parent)
	, m_gData(new GridData(55, 11, this))
	, m_gWidget(new GridWidget(m_gData))
	, m_createButton(new QPushButton("create"))
	, m_newWidth(new QLineEdit)
	, m_newHeight(new QLineEdit)
{
	this->connect(m_createButton, SIGNAL(clicked()), this, SLOT(createNew()));
	
	// Layout setup
	
	QVBoxLayout* mainLayout = new QVBoxLayout;
	mainLayout->setMargin(0);
	mainLayout->addWidget(m_gWidget);
	mainLayout->addWidget(m_newWidth);
	mainLayout->addWidget(m_newHeight);
	mainLayout->addWidget(m_createButton);
	this->setLayout(mainLayout);
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
}
