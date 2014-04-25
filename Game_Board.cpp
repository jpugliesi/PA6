//Game_Board.cpp
#include <iostream>
#include <iomanip>
#include <QString>
#include <cmath>
#include <sstream>
#include "Game_Board.h"
#include "CardAction.h"
#include "MoneyAction.h"

	/***** Constructors *****/

	//Creates a game board with number of players playing, and occupies the spaces
	Game_Board::Game_Board(int numPlayers, Bank* bank, Deck* theMan, Deck* chestDeck){
		num_players = numPlayers;
		theBank = bank;
		theManDeck = theMan;
		theChestDeck = chestDeck;
		occupySpaces();
	}

	Game_Board::~Game_Board(){
		
	}

	//occupies the spaces array with predefined spaces, as follows:
	void Game_Board::occupySpaces(){

		spaces[0] = Space("Go", 1, false, 0); 	//give GoAction		
		spaces[1] = Space("Glassell", 2, true, 50);
		spaces[2] = Space("*Chest*", 3, false, 60);	 	
		spaces[3] = Space("Richmond", 4, true, 70);
		spaces[4] = Space("TAX", 5, false, 0); 
		spaces[5] = Space("El Sob", 6, true, 100);
		spaces[6] = Space("*THE  MAN*", 7, false, 0); 
		spaces[7] = Space("Terrace", 8, true, 110);
		spaces[8] = Space("El Cerrito", 9, true, 120); 
		spaces[9] = Space("Pinole", 10, true, 130);
		spaces[10] = Space("", 11, false, 0); 

		spaces[11] = Space("*Chest*", 12, false, 0); 
		spaces[12] = Space("Brooklyn", 13, true, 150);
		spaces[13] = Space("*THE  MAN*", 14, false, 0); 
		spaces[14] = Space("Siberia", 15, true, 150);
		spaces[15] = Space("", 16, false, 0); 		
		spaces[16] = Space("Austin", 17, true, 170);
		spaces[17] = Space("Memphis", 18, true, 170); 
		spaces[18] = Space("Wichita", 19, true, 180);
		spaces[19] = Space("*Chest*", 20, false, 0);

		spaces[20] = Space("", 21, false, 0); 
		spaces[21] = Space("Atlanta", 22, true, 200);
		spaces[22] = Space("", 23, false, 0); 		
		spaces[23] = Space("Tahoe", 24, true, 210);
		spaces[24] = Space("*Chest*", 25, false, 0); 
		spaces[25] = Space("Las Vegas", 26, true, 250);
		spaces[26] = Space("*THE  MAN*", 27, false, 0); 
		spaces[27] = Space("*Chest*", 28, false, 0);
		spaces[28] = Space("Chicago", 29, true, 270); 
		spaces[29] = Space("Seattle", 30, true, 300);
		spaces[30] = Space("", 31, false, 0);

		spaces[31] = Space("*THE  MAN*", 32, false, 0); 
		spaces[32] = Space("TAX", 33, false, 0);
		spaces[33] = Space("*THE  MAN*", 34, false, 0); 
		spaces[34] = Space("New York", 35, true, 400);
		spaces[35] = Space("*THE  MAN*", 36, false, 0); 
		spaces[36] = Space("TAX", 37, false, 0);
		spaces[37] = Space("*THE  MAN*", 38, false, 0); 
		spaces[38] = Space("TAX", 39, false, 0);
		spaces[39] = Space("San Fran", 0, true, 500);

		for(int i = 0; i < NUM_SPACES; i++){
			if(spaces[i].isOwnable() || spaces[i].getName() == ""){
				spaces[i].setAction(NULL);
			}
			//else for THE MAN and TAX, and GO, and SPACE
			else if(spaces[i].getName() == "*THE  MAN*"){
				spaces[i].setAction(new CardAction(theManDeck));
			}else if(spaces[i].getName() == "TAX"){
				spaces[i].setAction(new MoneyAction(NULL, 100, false, "Woops! Pay tax of $100."));
			}else if(spaces[i].getName() == "*Chest*"){
				spaces[i].setAction(new CardAction(theChestDeck));
			}else if(spaces[i].getName() == "Go"){
				spaces[i].setAction(NULL);
			}
		}
	}

	//finds and returns a pointer to a Space object at a provided index
	Space* Game_Board::findSpaceByIndex(int index){
		return &(spaces[index]);
	}

	Bank* Game_Board::getBank(){
		return theBank;
	}

	void Game_Board::updateNumPlayers(int n){
		num_players = n;
	}