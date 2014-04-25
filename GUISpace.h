#ifndef GUISPACE_H
#define GUISPACE_H

#include <QtGui>
#include "Space.h"

class GUISpace : public QWidget{
	Q_OBJECT

protected:
	Space* space;
	QWidget* parent;
	QLabel* nameLabel;
	virtual void drawSpace() = 0;

public:
	GUISpace(Space* s, QWidget *parent = 0);
};

#endif