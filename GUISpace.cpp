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

QString GUISpace::getName(){
	return space->getName();
}

Player* GUISpace::getOwnerReference(){
	return space->getOwnerReference();
}

void GUISpace::setOwner(GUIPlayer* p){
	space->setOwner(p->getPlayer());
}

bool GUISpace::isOwned(){
	return space->isOwned();
}

bool GUISpace::hasAction(){
	return space->hasAction();
}

int GUISpace::getIndex(){
	return space->getSpaceIndex();
}

Space* GUISpace::getSpace(){
	return space;
}

int GUISpace::getValue(){
	return space->getValue();
}

int GUISpace::getRent(){
	return space->getRent();
}

int GUISpace::getUpgradeValue(){
	return space->getUpgradeValue();
}

void GUISpace::upgradeSpace(){
	space->upgradeSpace();
}

bool GUISpace::isUpgraded(){
	return space->isUpgraded();
}

void GUISpace::setIsUpgraded(bool val){
	space->setIsUpgraded(val);
}



