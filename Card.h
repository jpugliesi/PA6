#ifndef CARD_H
#define CARD_H

#include <string>

class Card{

	private:
		std::string name;
		Action* action;
	public:
		Card();
		Card(std::string, Action*);
		std::string getName();
		Action* getAction();
		void setAction(Action* a);

	
};

#endif