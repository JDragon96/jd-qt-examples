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

// QDialog�� m_mainWindow�� �Ѱ��־� parent window�� �����Ѵ�.
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
	// GPS Mapping flag True�� ��ȯ�ϱ�
	MainWindow::TheInstance()->HUB->hubFlag.gps_mapping_flag = true;
	this->accept();
}
void
ccGPSCheck::commandNO() {
	MainWindow::TheInstance()->HUB->hubFlag.gps_mapping_flag = false;
	this->accept();

	// accept() : �������� �̺�Ʈ ���Ḧ �ǹ��Ѵ�.
	// exec() ruturn���� true

	// reject() : ���۽��� �̺�Ʈ ���Ḧ �ǹ��Ѵ�.
	// exec() return���� false
	//this->reject();
}