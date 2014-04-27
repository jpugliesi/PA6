#include "GUISpace.h"

GUISpace::GUISpace(Space* s, QWidget *p) : QWidget(p){
	setGeometry( 0, 0, 60, 60 );

	parent = p;
	space = s;
	row = 0;
	column = 0;
	nameLabel = new QLabel(this);
	nameLabel->setText(space->getName());
}

QPoint GUISpace::pointForPlayers(){
	QPoint currentPoint((x() + (geometry().height()/4)), (y() + (geometry().width()/4)));
	return currentPoint;
}

void GUISpace::setPositionInGrid(int r, int c){
	row = r;
	column = c;
}

QPoint GUISpace::getPositionInGrid(){
	QPoint p(row, column);
	return p;
}

int GUISpace::getIndex(){
	return space->getSpaceIndex();
}