#ifndef ACTION_H
#define ACTION_H
#include <QString>
#include "Player.h"

class Player;

class Action{

	protected:
		QString name; //name of the action
		QString description;
		int value;
		Player* actingPlayer;
		Player* recievingPlayer;
	public:

		//constructors
		Action();
		Action(QString newName);
		Action(QString newName, QString desc);

		//functions
		QString getName();
		virtual void executeAction() = 0;
		virtual void executeAction(Player*) = 0;

		void setValue(int);
		bool hasValue();
		int getValue();

		void setActingPlayer(Player*);
		void setRecievingPlayer(Player*);
		Player* getActingPlayer();
		Player* getRecievingPlayer();

		void setDescription(QString);
		QString getDescription();

};

#endif