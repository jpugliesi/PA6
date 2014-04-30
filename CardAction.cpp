//CardAction.cpp
#include "CardAction.h"

	CardAction::CardAction() : Action("CardAction"){}
	CardAction::CardAction(Deck* theDeck) : Action("CardAction"){
		deck = theDeck;
	}

	void CardAction::executeAction(){
		Action::setDescription(deck->getAndExecuteCard());
	}

	void CardAction::executeAction(Player* p){
		Action::setDescription(deck->getAndExecuteCard(p));
	}