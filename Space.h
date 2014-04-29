//Space.h
#ifndef SPACE_H
#define SPACE_H

#include <QString>
#include "Action.h"
#include "Player.h"

class Player;
class Action;

class Space{

	private:
		QString name; //name of the space
		QString upgrade;
		int index;
		int nextSpace; //index of space that comes after
		bool ownable; //whether or not the space is able to be owned
		int value;
		int rent;
		bool upgraded;
		Player* owner; //owner of the space
		Player* currentPlayers; //array of players currently on the space
		int numPlayersOnSpace; //number of players currently on the space

		Action* action;	

		//functions

	public:
		//constructors
		Space(); //creates ownable space with no players on it
		Space(QString name, int nextSpace, bool canOwn, int newValue);

		//functions
		bool isOwnable(); //returns whether or not a space can be owned

		void addPlayerToSpace(Player aPlayer); //adds a player to the currentPlayers array
		Player* getPlayersOnSpace(); //returns array of players currently on the space
		void removePlayerFromSpace(Player aPlayer); //removes a player from the space

		void setName(QString newName);
		QString getName();

		int getSpaceIndex();
		int getValue();
		int getRent();

		void setAction(Action* anAction);
		Action* getAction();
		bool hasAction();
		void executeAction();

		void upgradeSpace();
		bool isUpgraded();
		void setIsUpgraded(bool val);
		int getUpgradeValue();

		//may not be useful, currenty unimplemented
		QString getOwner();
		bool isOwned();
		Player* getOwnerReference();
		void setOwner(Player* newOwner);
		void setNextSpace(int newNextspace);

		
};

#endif