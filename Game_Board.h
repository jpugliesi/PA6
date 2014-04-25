//Game_Board.h
#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include <QString>
#include "Space.h"
#include "Deck.h"
#include "Bank.h"

class Game_Board{
	public:
		//variables
		const static int NUM_SPACES = 40;
		
		//constructors
		Game_Board(int, Bank*, Deck*, Deck*);
		~Game_Board();

		//functions
		void printBoard();
		Space* findSpaceByIndex(int index);
		Bank* getBank(); //returns a pointer to the Bank
		void updateNumPlayers(int);

	private:
		//variables
		int num_players; //number of players currently in the game
		Bank* theBank;
		Deck* theManDeck; //Deck of THE MAN cards
		Deck* theChestDeck; //Deck of Chest cards

		/*** functions ***/

		Space spaces[NUM_SPACES]; //array of spaces on the board
		void occupySpaces();	  //fills spaces array with predefined spaces
		
};
#endif