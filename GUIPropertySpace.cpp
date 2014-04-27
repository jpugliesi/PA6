#include "GUIPropertySpace.h"

GUIPropertySpace::GUIPropertySpace(Space* s, QWidget *parent, QString c) : GUISpace(s, parent){
	color = c;
	drawSpace();
}

void GUIPropertySpace::drawSpace(){
	nameLabel->setAlignment(Qt::AlignCenter);
	QFont font("Arial", 10, -1, false);
	nameLabel->setFont(font);
	QString style = "QLabel { background-color : ";
	style.append(color);
	style.append("; border-top: 1px solid black; border-right: 1px solid black; border-left: 1px solid black;}");
	nameLabel->setStyleSheet(style);

	style = "QLabel { background-color : ";
	style.append(color);
	style.append("; border-top: 1px solid black; border-right: 1px solid black;}");
	upgradeLabel = new QLabel(this);
	upgradeLabel->setStyleSheet(style);

	blankSpaceLabel = new QLabel(this);
	blankSpaceLabel->setStyleSheet("QLabel { background-color : white; border:1px solid black;}");

	grid = new QGridLayout(parent);
	grid->addWidget(nameLabel, 0, 0, 1, 2);
	grid->addWidget(upgradeLabel, 0, 2, 1, 1);
	grid->addWidget(blankSpaceLabel, 1, 0, 2, 3);
	grid->setContentsMargins(0, 0, 0, 0); //get rid of margin around the grid
	grid->setSpacing(0); //get rid of spacing between labels

	setLayout(grid);
}

void GUIPropertySpace::upgradeSpace(){
	GUISpace::upgradeSpace();
	QPixmap house = QPixmap(":/images/upgradeHouse.png");
	QRect box = grid->cellRect(0, 2);
	QPixmap houseScaled = house.scaled(box.width(), box.height());
	upgradeLabel->setPixmap(houseScaled);
}