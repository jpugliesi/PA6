#ifndef GUICHESTSPACE_H
#define GUICHESTSPACE_H

#include "Deck.h"
#include "GUISpace.h"

class GUIChestSpace : public GUISpace{

private:
	Deck* deck;
	QString color;
	void drawSpace();
public:
	GUIChestSpace(Space* s, QWidget* p, Deck* theDeck, QString color);
};

#endif