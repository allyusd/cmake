#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "tools/tool.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


	Tool tool;
	int result = tool.add(1, 2);

	this->setWindowTitle(QString("1 + 2 = %1").arg(result));
}

MainWindow::~MainWindow()
{
    delete ui;
}
