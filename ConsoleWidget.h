#ifndef CONSOLEWIDGET_H
#define CONSOLEWIDGET_H

#include <QtGui>
#include "Die.h"
#include "GUIPlayer.h"
#include <vector>
#include "CentralWidget.h"

class Bank;
class CentralWidget;

class ConsoleWidget : public QWidget{

	Q_OBJECT

private:

	CentralWidget* centralController;

	QLabel *playerIcon;
	QLabel *playerWithTurn;
	QLabel *outputWindow;
	QPushButton *actionButtons;

	QPushButton *buyButton;
	QPushButton *sellToBankButton;
	QPushButton *sellToPlayerButton;
	QPushButton *upgradeButton;
	QPushButton *rollDiceButton;

	QLabel *die1Label;
	QLabel *die2Label;

	GUIPlayer *player;

	std::vector<GUIPlayer*> guiPlayers;


	Die *die1;
	Die *die2;
	int dice1value;
	int dice2value;

public slots:
	void buyProperty();
	void sellPropertyToBank();
	void sellPropertyToPlayer();
	void upgradeProperty();
	void payRent();
	void rollDice();


public:
	ConsoleWidget(CentralWidget* w, std::vector<GUIPlayer*> gs, QGridLayout *grid);
	void setCurrentPlayer(GUIPlayer *p);
	int* getDiceValues();
	QPushButton** getPropertyTransactionButtons();
	QPushButton* getRollDiceButton();
	void updateDisplay(QString s);

};

#endif