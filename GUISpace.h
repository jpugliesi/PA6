#ifndef GUISPACE_H
#define GUISPACE_H

#include <QtGui>
#include "Space.h"

class GUISpace : public QWidget{
	Q_OBJECT

protected:
	int row;
	int column;
	Space* space;
	QWidget* parent;
	QLabel* nameLabel;
	virtual void drawSpace() = 0;

public:
	GUISpace(Space* s, QWidget *parent = 0);
	QPoint pointForPlayers();
	void setPositionInGrid(int, int);
	QPoint getPositionInGrid();
	int getIndex();
};

#endif