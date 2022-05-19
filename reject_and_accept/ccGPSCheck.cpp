#include "ccGPSCheck.h"

//Qt
#include <QApplication>
#include <QClipboard>
#include <QFileDialog>
#include <QMenu>
#include <QMessageBox>
#include <QSettings>

//local
#include "mainwindow.h"
#include "db_tree/ccDBRoot.h"

//system
#include <cassert>

// QDialog에 m_mainWindow를 넘겨주어 parent window를 정의한다.
ccGPSCheck::ccGPSCheck(QWidget* parent)
	: QDialog(parent, Qt::Tool)
	, Ui::dialog()
{
	setupUi(this);

	//! Button Binding 
	connect(buttonYes, &QAbstractButton::clicked, this, &ccGPSCheck::commandYES);
	connect(buttonNo, &QAbstractButton::clicked, this, &ccGPSCheck::commandNO);
}
void
ccGPSCheck::commandYES() {
	// GPS Mapping flag True로 변환하기
	MainWindow::TheInstance()->HUB->hubFlag.gps_mapping_flag = true;
	this->accept();
}
void
ccGPSCheck::commandNO() {
	MainWindow::TheInstance()->HUB->hubFlag.gps_mapping_flag = false;
	this->accept();

	// accept() : 정상적인 이벤트 종료를 의미한다.
	// exec() ruturn값이 true

	// reject() : 갑작스런 이벤트 종료를 의미한다.
	// exec() return값이 false
	//this->reject();
}