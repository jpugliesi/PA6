#include "ConsoleWidget.h"
#include "PropertyAction.h"
#include "MoneyAction.h"
#include <iostream>
#include "GUIPropertySpace.h"
#include "SelectPlayerDialog.h"

ConsoleWidget::ConsoleWidget(CentralWidget* cc, std::vector<GUIPlayer*> gs, QGridLayout *grid){

	centralController = cc;
	guiPlayers = gs;

	die1 = new Die();
	die2 = new Die();

	//widgets for current player with turn
	playerIcon = new QLabel( this );
	upNextPlayerIcon = new QLabel( this );
	playerWithTurn = new QLabel("Current Player", this );
	playerWithTurn->setFont(QFont("Arial", 18));
	playerWithTurn->setAlignment(Qt::AlignHCenter);


	outputWindow = new QLabel ("Game output will go here. It will provide the player instructions on how to procede!", this );
	outputWindow->setWordWrap(true);
	outputWindow->setAlignment(Qt::AlignCenter);
	outputWindow->setFont(QFont("Arial", 18));
	outputWindow->setStyleSheet("QLabel { border: 1px solid black;}");
	QLabel *upNextPlayerLabel = new QLabel("Up Next: ");
	upNextPlayerLabel->setFont(QFont("Arial", 18));
	upNextPlayerLabel->setAlignment(Qt::AlignCenter);

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
	grid->addWidget(upNextPlayerLabel, 4, 1, 1, 3);
	grid->addWidget(upNextPlayerIcon, 5, 2, 1, 1);
	grid->addWidget(outputWindow, 1, 4, 5, 6);
	grid->addLayout(dieHBox, 7, 1, 3, 3);
	grid->addLayout(buttonsBox, 7, 4, 4, 6);

	setLayout(grid);

}

void ConsoleWidget::buyProperty(){
	GUISpace *currentSpace = centralController->findSpaceByIndex(player->getPosition());
	PropertyAction buyProperty(player->getPlayer(), NULL, currentSpace->getSpace(), centralController->getBank(), true, true, false);
	buyProperty.executeAction();
	QString output = "You just bought " + currentSpace->getName() + " for $" + QString::number(currentSpace->getValue());
	QPushButton** buttons = getPropertyTransactionButtons();
	for(int i = 0; i< 4; i++){
		buttons[i]->setEnabled(false);
	} 
	updateDisplay(output);
}

void ConsoleWidget::sellPropertyToBank(){
	GUISpace *currentSpace = centralController->findSpaceByIndex(player->getPosition());
	PropertyAction sellBankProperty(player->getPlayer(), NULL, currentSpace->getSpace(), centralController->getBank(), false, true, false);
	sellBankProperty.executeAction();
	QString output = "You just sold " + currentSpace->getName() + " to the Bank for $" + QString::number(currentSpace->getValue() * (3./4));
	QPushButton** buttons = getPropertyTransactionButtons();
	for(int i = 0; i< 4; i++){
		buttons[i]->setEnabled(false);
	} 
	updateDisplay(output);
}

void ConsoleWidget::sellPropertyToPlayer(){
	GUISpace *currentSpace = centralController->findSpaceByIndex(player->getPosition());
	QString csName(currentSpace->getName());
	std::vector<QIcon*> icons;
	std::vector<GUIPlayer*> gp;
	for(int i = 0; i < guiPlayers.size(); i++){
		if((guiPlayers.at(i)->isInGame()) && (guiPlayers.at(i) != player)){
			gp.push_back(guiPlayers.at(i));
		 	icons.push_back(new QIcon(guiPlayers.at(i)->getPieceImage()));
		}
	}
	SelectPlayerDialog playersToSelect(icons, this);
	playersToSelect.exec();
	int selection = playersToSelect.getChoice();
	qDebug() << selection + " is the selection for " + gp[selection]->getName();


	QMessageBox::StandardButton confirm;
	confirm = QMessageBox::question(this, "Do you want to Buy", csName + " for " + QString::number(currentSpace->getValue()) + "?", QMessageBox::Yes|QMessageBox::No);
	if (confirm == QMessageBox::Yes) {
	   PropertyAction sellPropertyToPlayer(player->getPlayer(), gp[selection]->getPlayer(), currentSpace->getSpace(), centralController->getBank(), false, false, false);
	   sellPropertyToPlayer.executeAction();
	   QString output("Just sold " + csName + " for $" + QString::number(currentSpace->getValue()));
	   updateDisplay(output);
	}else{
	   updateDisplay("Trade denied.");
	}

	QPushButton** buttons = getPropertyTransactionButtons();
	for(int i = 0; i< 4; i++){
		buttons[i]->setEnabled(false);
	}

}

void ConsoleWidget::upgradeProperty(){
	GUISpace *currentSpace = centralController->findSpaceByIndex(player->getPosition());
	int index = currentSpace->getIndex();
	GUIPropertySpace *ps = dynamic_cast<GUIPropertySpace*>(centralController->findSpaceByIndex(index));
	ps->upgradeSpace();
	MoneyAction transaction(player->getPlayer(), currentSpace->getUpgradeValue(), false);
	transaction.executeAction();
	centralController->getBank()->deposit(currentSpace->getUpgradeValue());
	QPushButton** buttons = getPropertyTransactionButtons();
	for(int i = 0; i< 4; i++){
		buttons[i]->setEnabled(false);
	}
	QString output(player->getName() + " upgraded " + currentSpace->getName() + "!");
	updateDisplay(output);
	
}

void ConsoleWidget::payRent(){
	GUISpace *currentSpace = centralController->findSpaceByIndex(player->getPosition());
	Player* owner = currentSpace->getOwnerReference();
	MoneyAction transaction(owner, currentSpace->getRent(), true);
	int amount = transaction.getAmount();
	transaction.executeAction();
	transaction.takeMoney(player->getPlayer(), amount);
	transaction.executeAction();

	QString output = "Darn, you have to pay a rent of $";
	output.append(QString::number(currentSpace->getRent()));
	updateDisplay(output);
}

void ConsoleWidget::updateDisplay(QString output){
	outputWindow->setText(output);
	centralController->updateDocks();
}

void ConsoleWidget::appendOutput(QString toAppend)
{
	QString old = outputWindow->text();
	outputWindow->setText(old + "\n" + toAppend);
	centralController->updateDocks();
}
int* ConsoleWidget::getDiceValues(){
	int* dice = new int[2];
	dice[0] = dice1value;
	dice[1] = dice2value;
	return dice;
}

void ConsoleWidget::rollDice(){
	dice1value = die1->rollDie();
	dice2value = die2->rollDie();
	int value = dice1value + dice2value;

	QString dieImageName, dieImageName2;
	QString path1(":/images/");
	QString path2(":/images/");

	switch(dice1value){
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

	switch(dice2value){
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

	centralController->playGame();
}

void ConsoleWidget::setCurrentPlayer(GUIPlayer *p){
	player = p;
	QPixmap a = player->getPieceImage();
	QPixmap aScaled = a.scaled(60, 60);
	playerIcon->setPixmap(aScaled);

}
void ConsoleWidget::setNextPlayer(GUIPlayer *p){
	player = p;
	QPixmap a = player->getPieceImage();
	QPixmap aScaled = a.scaled(60, 60);
	upNextPlayerIcon->setPixmap(aScaled);

}
QPushButton** ConsoleWidget::getPropertyTransactionButtons(){
	QPushButton **buttons = new QPushButton*[4];
	buttons[0] = buyButton;
	buttons[1] = sellToBankButton;
	buttons[2] = sellToPlayerButton;
	buttons[3] = upgradeButton;
	return buttons;
}

QPushButton* ConsoleWidget::getRollDiceButton(){
	return rollDiceButton;
}