#include "Card.h"

	Card::Card(){
		name = "";
	}

	Card::Card(QString newName, Action* a){
		name = newName;
		action = a;
	}

	QString Card::getName(){
		return name;
	}

	Action* Card::getAction(){
		return action;
	}

	void Card::setAction(Action* a){
		action = a;
	}