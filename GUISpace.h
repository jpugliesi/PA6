#ifndef GUISPACE_H
#define GUISPACE_H

#include <QtGui>
#include "Space.h"
#include "GUIPlayer.h"

class GUIPlayer;

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
	Space* getSpace();

	QPoint pointForPlayers();
	void setPositionInGrid(int, int);
	QPoint getPositionInGrid();

	QString getName();
	bool hasAction();
	int getIndex();

	Player* getOwnerReference();
	void setOwner(GUIPlayer *p);
	bool isOwned();

	int getValue();
	int getRent();
	void upgradeSpace();
	int getUpgradeValue();
};

#endif