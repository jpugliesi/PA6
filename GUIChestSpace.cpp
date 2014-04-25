#include "GUIChestSpace.h"

GUIChestSpace::GUIChestSpace(Space* s, QWidget* p, Deck* theDeck, QString c) : GUISpace(s, p){
	deck = theDeck;
	color = c;
	drawSpace();
}

void GUIChestSpace::drawSpace(){
	nameLabel->setAlignment(Qt::AlignCenter);
	QFont font("Arial", 10, -1, false);
	nameLabel->setFont(font);
	QString style = "QLabel { background-color : ";
	style.append(color);
	style.append("; border: 1px solid black;}");
	nameLabel->setStyleSheet(style);

	QGridLayout *grid = new QGridLayout(parent);
	grid->addWidget(nameLabel, 0, 0, 3, 3);

	grid->setContentsMargins(0, 0, 0, 0); //get rid of margin around the grid
	grid->setSpacing(0); //get rid of spacing between labels

	setLayout(grid);
}