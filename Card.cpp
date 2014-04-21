#include "Card.h"

	Card::Card(){
		name = "";
	}

	Card::Card(std::string newName, Action* a){
		name = newName;
		action = a;
	}

	std::string Card::getName(){
		return name;
	}

	Action* Card::getAction(){
		return action;
	}

	void Card::setAction(Action* a){
		action = a;
	}