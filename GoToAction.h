#ifndef GOTOACTION_H
#define GOTOACTION_H
#include "Action.h"
#include "Space.h"
#include "Game_Board.h"
#include "Player.h"
#include "Bank.h"
#include <QString>

class GoToAction : public Action{

	private:
		Space* currentSpace;
		Space* newSpace;
		Game_Board* theBoard;
		Bank* theBank;
	public:
		GoToAction();
		GoToAction(Player*, Game_Board*, Space*);
		GoToAction(Player*, Game_Board*, Space*, QString desc);
		void executeAction();
		void executeAction(Player* p);


};

#endif
