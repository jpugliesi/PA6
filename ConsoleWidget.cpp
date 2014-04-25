#include "ConsoleWidget.h"
#include <iostream>

ConsoleWidget::ConsoleWidget(std::vector<GUIPlayer*> gs, QGridLayout *grid){

	guiPlayers = gs;

	die1 = new Die();
	die2 = new Die();

	//widgets for current player with turn
	playerIcon = new QLabel( this );
	playerWithTurn = new QLabel("Current Player", this );
	playerWithTurn->setFont(QFont("Arial", 18));
	playerWithTurn->setAlignment(Qt::AlignHCenter);


	outputWindow = new QLabel ("Game output will go here. It will provide the player instructions on how to procede!", this );
	outputWindow->setWordWrap(true);
	outputWindow->setAlignment(Qt::AlignCenter);
	outputWindow->setFont(QFont("Arial", 18));
	outputWindow->setStyleSheet("QLabel { border: 1px solid black;}");
	QLabel *propertyName = new QLabel("Space: ");
	propertyName->setFont(QFont("Arial", 18));
	propertyName->setAlignment(Qt::AlignCenter);

	//add buttons here
	QVBoxLayout *buttonsBox = new QVBoxLayout;
	QHBoxLayout *row1 = new QHBoxLayout;
	QHBoxLayout *row2 = new QHBoxLayout;

	buyButton = new QPushButton("Buy Property");
	connect(buyButton, SIGNAL(clicked()), this, SLOT(buyProperty()));
	sellToBankButton = new QPushButton("Sell Property to Bank");
	connect(sellToBankButton, SIGNAL(clicked()), this, SLOT(sellPropertyToBank()));
	sellToPlayerButton = new QPushButton("Sell Property to Player");
	connect(sellToPlayerButton, SIGNAL(clicked()), this, SLOT(sellPropertyToPlayer()));
	upgradeButton = new QPushButton("Upgrade Property");
	connect(upgradeButton, SIGNAL(clicked()), this, SLOT(upgradeProperty()));

	row1->addWidget(buyButton);
	row1->addWidget(upgradeButton);
	row2->addWidget(sellToPlayerButton);
	row2->addWidget(sellToBankButton);

	buttonsBox->addLayout(row1);
	buttonsBox->addLayout(row2);

	//create die section
	QHBoxLayout *dieHBox = new QHBoxLayout;
	QGridLayout *dieGrid = new QGridLayout;

	rollDiceButton = new QPushButton("Roll Dice");
	connect(rollDiceButton, SIGNAL(clicked()), this, SLOT(rollDice()));

	die1Label = new QLabel(this);
	QPixmap dieImage1(":/images/die1.png");
	QPixmap dieImage1Scaled = dieImage1.scaled(30, 30);
	die1Label->setPixmap(dieImage1Scaled);

	die2Label = new QLabel(this);
	QPixmap dieImage2(":/images/die1.png");
	QPixmap dieImage2Scaled =dieImage2.scaled(30, 30);
	die2Label->setPixmap(dieImage2Scaled);

	dieGrid->addWidget(rollDiceButton, 0, 0, 1, 3);
	dieGrid->addWidget(die1Label, 2, 1, 1, 1);
	dieGrid->addWidget(die2Label, 2, 2, 1, 1);

	dieHBox->addLayout(dieGrid);

	//add widgets and layouts to main grid
	grid->addWidget(playerWithTurn, 1, 1, 1, 3);
	grid->addWidget(playerIcon, 2, 2, 1, 1);
	grid->addWidget(propertyName, 4, 1, 1, 3);
	grid->addWidget(outputWindow, 1, 4, 5, 6);
	grid->addLayout(dieHBox, 7, 1, 3, 3);
	grid->addLayout(buttonsBox, 7, 4, 4, 6);

	setLayout(grid);

}

void ConsoleWidget::buyProperty(){

}

void ConsoleWidget::sellPropertyToBank(){
	
}

void ConsoleWidget::sellPropertyToPlayer(){
	
}

void ConsoleWidget::upgradeProperty(){
	
}

void ConsoleWidget::rollDice(){
	int v1 = die1->rollDie();
	int v2 = die2->rollDie();
	int value = v1 + v2;

	QString dieImageName, dieImageName2;
	QString path1(":/images/");
	QString path2(":/images/");

	switch(v1){
		case 1: dieImageName = "die1.png";
				break;
		case 2: dieImageName = "die2.png";
				break;
		case 3: dieImageName = "die3.png";
				break;
		case 4: dieImageName = "die4.png";
				break;
		case 5: dieImageName = "die5.png";
				break;
		case 6: dieImageName = "die6.png";
				break;
	}

	switch(v2){
		case 1: dieImageName2 = "die1.png";
				break;
		case 2: dieImageName2 = "die2.png";
				break;
		case 3: dieImageName2 = "die3.png";
				break;
		case 4: dieImageName2 = "die4.png";
				break;
		case 5: dieImageName2 = "die5.png";
				break;
		case 6: dieImageName2 = "die6.png";
				break;
	}
	path1.append(dieImageName);
	path2.append(dieImageName2);

	QPixmap dieImage1(path1);
	QPixmap dieImage1Scaled = dieImage1.scaled(30, 30);
	die1Label->setPixmap(dieImage1Scaled);

	QPixmap dieImage2(path2);
	QPixmap dieImage2Scaled = dieImage2.scaled(30, 30);
	die2Label->setPixmap(dieImage2Scaled);
}

void ConsoleWidget::setCurrentPlayer(GUIPlayer *p){
	player = p;
	QPixmap a = player->getPieceImage();
	QPixmap aScaled = a.scaled(60, 60);
	playerIcon->setPixmap(aScaled);

}