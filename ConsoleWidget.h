#ifndef CONSOLEWIDGET_H
#define CONSOLEWIDGET_H

#include <QtGui>
#include "Die.h"
#include "GUIPlayer.h"
#include <vector>

class ConsoleWidget : public QWidget{

	Q_OBJECT

private:
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

private slots:
	void buyProperty();
	void sellPropertyToBank();
	void sellPropertyToPlayer();
	void upgradeProperty();
	void rollDice();

public:
	ConsoleWidget(std::vector<GUIPlayer*>, QGridLayout *grid);
	void setCurrentPlayer(GUIPlayer *p);

};

#endif