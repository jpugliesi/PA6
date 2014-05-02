#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "CentralWidget.h"
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

	QMenu *actionsMenu;
	QAction *resignAct;

	std::vector<GUIPlayer*> pDockLeftPlayers;
	std::vector<GUIPlayer*> pDockRightPlayers;

private slots:
	void resign();


	void createDockWindows();
	void createMenuBar();
public:
	MainWindow();
	void updateDockPlayers();


};

#endif