#ifndef CONSOLEWIDGET_H
#define CONSOLEWIDGET_H

#include <QtGui>
#include "Die.h"
#include "GUIPlayer.h"
#include <vector>
#include "CentralWidget.h"

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

private slots:
	void buyProperty();
	void sellPropertyToBank();
	void sellPropertyToPlayer();
	void upgradeProperty();
	void rollDice();

public:
	ConsoleWidget(CentralWidget*, std::vector<GUIPlayer*>, QGridLayout *grid);
	void setCurrentPlayer(GUIPlayer *p);
	int* getDiceValues();

};

#endif