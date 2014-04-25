#include "GUISpace.h"

GUISpace::GUISpace(Space* s, QWidget *p) : QWidget(p){
	setGeometry( 0, 0, 60, 60 );

	parent = p;
	space = s;
	nameLabel = new QLabel(this);
	nameLabel->setText(space->getName());
}

// void GUISpace::drawSpace(){
// 	// nameLabel->setAlignment(Qt::AlignCenter);
// 	// QFont font("Arial", 10, -1, false);
// 	// nameLabel->setFont(font);
// 	// nameLabel->setStyleSheet("QLabel{ background-color: white; border: 1px solid black;}");

// 	// QGridLayout *grid = new QGridLayout(parent);
// 	// grid->addWidget(nameLabel, 0, 0, 3, 3);
// 	// grid->setContentsMargins(0, 0, 0, 0); //get rid of margin around the grid
// 	// grid->setSpacing(0); //get rid of spacing between labels

// 	// setLayout(grid);
// }