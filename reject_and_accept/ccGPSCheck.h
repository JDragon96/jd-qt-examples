#pragma once

#ifndef CUSTOM_GPS_CHECK_H
#define CUSTOM_GPS_CHECK_H

#include <ui_custom_gps_checkDlg.h>
#include <ccHObject.h>

class ccGPSCheck: public Ui::dialog, public QDialog{

public:
	explicit ccGPSCheck(QWidget* parent);

private:
	void commandYES();
	void commandNO();

protected:

};

#endif // end GPS_MAPPING_DIALOG_H