#ifndef _SINGLE_PLOT_WINDOW_H
#define _SINGLE_PLOT_WINDOW_H
#include <qapplication.h>
#include <qmainwindow.h>
#include <qwt_counter.h>
#include <qtoolbar.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qwt_scale_engine.h>

#include "SinglePlot.h"

class SinglePlotWindow : public QMainWindow
{
	Q_OBJECT
public:
    SinglePlotWindow(const QString& pvname,const int periodic = 1);
	void setRangeEnable(const bool);

public slots:
	void setLogScale(int check);
	void setAutoScale(int check);

protected:
	void closeEvent (QCloseEvent *);
private:
	//QDoubleSpinBox *mymin, *mymax;
	QLineEdit *mymin, *mymax;
	SinglePlot *mplot;
	const int mperiodic;
};

#endif
