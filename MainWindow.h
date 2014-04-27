#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "CentralWidget.h"
#include "PlayerDock.h"
#include "GUIDockPlayer.h"
#include "Bank.h"

class CentralWidget;
class QWidget;
class MainWindow : public QMainWindow{

	Q_OBJECT

private:
	//QLabel *boardLabel;
	std::vector<Player*> players;
	std::vector<GUIPlayer*> guiPlayers;
	Bank* theBank;
	CentralWidget *centralWidget;
	int numPlayers;

	QDockWidget *pDockLeft;
	QDockWidget *pDockRight;
	GUIDockPlayer *bodyLeft;
	GUIDockPlayer *bodyRight;

	QMenu *simponopolyMenu;
	QAction *exitAct;

	std::vector<GUIPlayer*> pDockLeftPlayers;
	std::vector<GUIPlayer*> pDockRightPlayers;


	void createDockWindows();
	void createMenuBar();
public:
	MainWindow();
	void updateDockPlayers();


};

#endif