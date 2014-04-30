//Deck.h
#ifndef DECK_H
#define DECK_H
#include "Action.h"
#include <vector>
#include <QString>

#include <QtGui>
class Deck{

	private:
		std::vector<Action*> cards;

	public:
		Deck();
		void shuffle();
		QString getAndExecuteCard();
		QString getAndExecuteCard(Player* p);
		void addCard(Action* newAction);
		QString getFrontDescription();


};

#endif