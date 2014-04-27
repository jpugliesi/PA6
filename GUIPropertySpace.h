#ifndef GUIPROPERTYSPACE_H
#define GUIPROPERTYSPACE_H

#include <QtGui>
#include "GUISpace.h"

class GUIPropertySpace : public GUISpace{
	Q_OBJECT

private:
	QLabel* upgradeLabel;
	QLabel* blankSpaceLabel;
	QString color;
	QGridLayout *grid;
	void drawSpace();

public:
	GUIPropertySpace(Space* s, QWidget *parent = 0, QString color = "#FFFFFF");
	void upgradeSpace();

};

#endif