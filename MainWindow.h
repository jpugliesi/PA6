#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "CentralWidget.h"
#include "PlayerDock.h"
#include "Bank.h"
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
	QWidget *bodyLeft;
	QWidget *bodyRight;

	QMenu *simponopolyMenu;
	QAction *exitAct;


	void createDockWindows();
	void createMenuBar();
public:
	MainWindow();


};

#endif