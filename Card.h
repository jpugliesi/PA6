#ifndef CARD_H
#define CARD_H

#include <QString>
#include "Action.h"

class Card{

	private:
		QString name;
		Action* action;
	public:
		Card();
		Card(QString, Action*);
		QString getName();
		Action* getAction();
		void setAction(Action* a);

	
};

#endif