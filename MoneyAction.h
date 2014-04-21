#ifndef MONEYACTION_H
#define MONEYACTION_H
#include "Action.h"
#include "Player.h"
#include <string>

class MoneyAction : public Action{

	protected:
		//int money; 
		int amount;//money for working with
		bool pay;
	public:	

		//constructors
		MoneyAction(); //create MoneyAction with name "Default"
		MoneyAction(Player* p, int amount, bool paying);
		MoneyAction(Player* p, int amount, bool paying, std::string desc);

		//functions
		int payMoney(Player* p, int amount); //pay p amount sum of money
		int takeMoney(Player* p, int amount); //take amount sum of money from player p
		int getAmount(); //get the amount to be transacted

		void executeAction();
		void executeAction(Player*);
};
#endif