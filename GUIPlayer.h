#ifndef GUIPLAYER_H
#define GUIPLAYER_H

#include <QtGui>
#include "Player.h"
#include "GUISpace.h"
#include <vector>

class GUISpace;
class Player;
class GUIPlayer : public QWidget{

	Q_OBJECT

private:
	Player* player;
	QLabel *iconLabel;
	QLabel *playerName;
	QPixmap piecePixmap;

public:
	GUIPlayer(Player* p, int i);
	void setPieceImage(QIcon *i);
	QPixmap getPieceImage();
	QLabel* getIcon();
	QLabel* getNameLabel();
	QString getName();
	Player* getPlayer();

	int getMoney();

	void setPosition(int i);
	void setInitialPosition();
	int getPosition();
	int move(int);

	void addSpace(GUISpace* s);
	std::vector<Space*> getAllOwnedSpaces();
	int getNumOwnedSpaces();

	bool isInGame();
	void takeOutOfGame();

};

#endif