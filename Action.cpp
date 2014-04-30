#include "Action.h"
#include <iostream>
#include <QString>


	/***** Constructors *****/

	//Default Constructor creates action with name "Default"
	Action::Action(){
		name = "Action"; 
		description = "";
	}
	//Constructor that accepts a string to set as the action's name
	Action::Action(QString newName){
		name = newName;
		description = "";
	}
	Action::Action(QString newName, QString desc){
		name = newName;
		description = desc;
	}

	/***** Functions *****/

	//Prints out the name of the Action

	QString Action::getName(){
		return name;
	}

	void Action::setValue(int newValue){
		value = newValue;
	}

	bool Action::hasValue(){
		if(value != 0) return true;
		return false;
	}

	int Action::getValue(){
		return value;
	}

	void Action::setActingPlayer(Player* p){
		actingPlayer = p;
	}
	
	void Action::setRecievingPlayer(Player* p){
		recievingPlayer = p;
	}

	Player* Action::getActingPlayer(){
		return actingPlayer;
	}
	
	Player* Action::getRecievingPlayer(){
		return recievingPlayer;
	}

	void Action::setDescription(QString desc){
		description = desc;
	}

	QString Action::getDescription(){
		return description;
	}