//Deck.cpp
#include "Deck.h"
#include <algorithm>

	Deck::Deck(){
	}

	void Deck::shuffle(){
		std::random_shuffle(cards.begin(), cards.end());
	}

	QString Deck::getAndExecuteCard(){
		Action* tmp= cards.front();
		cards.front()->executeAction();
		cards.push_back(tmp);
		cards.erase(cards.begin());
	}

	QString Deck::getAndExecuteCard(Player* p){
		cards.front()->Action::setActingPlayer(p);
		Action* tmp= cards.front();
		qDebug() << tmp->getDescription();
		QString desc = tmp->getDescription();
		cards.front()->executeAction(p);
		tmp->setActingPlayer(NULL);
		cards.push_back(tmp);
		cards.erase(cards.begin());
		return desc;
	}

	void Deck::addCard(Action* newAction){
		cards.push_back(newAction);
	}

	QString Deck::getFrontDescription(){
		qDebug() << cards.front()->getDescription();
		return cards.front()->getDescription();
	}