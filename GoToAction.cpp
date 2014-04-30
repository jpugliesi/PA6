#include <iostream>
#include "GoToAction.h"
#include "MoneyAction.h"

	GoToAction::GoToAction() : Action("GoToAction"){
		
	}
	GoToAction::GoToAction(Player* p, Bank* bank, Space* cs, 
							Space* space) : Action("GoToAction") {

		Action::setActingPlayer(p);
		theBank = bank;
		newSpace = space;
		currentSpace = cs;

	}
	GoToAction::GoToAction(Player* p, Bank* bank, Space* cs, 
							Space* space, QString desc) : Action("GoToAction", desc) {

		Action::setActingPlayer(p);
		theBank = bank;
		newSpace = space;
		currentSpace = cs;

	}

	void GoToAction::executeAction(){
		Player* player = Action::getActingPlayer();
		int index = player->getCurrentSpace();

		player->setPosition(newSpace->getSpaceIndex());
		if(description != ""){
			// std::cout << description << std::endl;
		}
		if(player->didPassGo()){
			MoneyAction passGo(player, 200, true, "You passed Go. Collect $200.");
			theBank->withdraw(200);
			passGo.executeAction();
		}
		newSpace->addPlayerToSpace(*player);
		// std::cout << player->getPiece() << " moved to " << newSpace->getName() << "!" << std::endl;
		
	}

	void GoToAction::executeAction(Player* p){
		Action::setActingPlayer(p);
		Player* player = Action::getActingPlayer();
		int index = player->getCurrentSpace();

		player->setPosition(newSpace->getSpaceIndex());
		if(description != ""){
			// std::cout << description << std::endl;
		}
		if(player->didPassGo()){
			MoneyAction passGo(player, 200, true, "You passed Go. Collect $200.");
			theBank->withdraw(200);
			passGo.executeAction();
		}
		//newSpace->addPlayerToSpace(*player);
		// std::cout << player->getPiece() << " moved to " << newSpace->getName() << "!" << std::endl;
		
	}
