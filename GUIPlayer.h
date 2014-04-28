#ifndef GUIPLAYER_H
#define GUIPLAYER_H

#include <QtGui>
#include "Player.h"
#include "GUISpace.h"

class GUISpace;
class Player;
class GUIPlayer : public QWidget{

	Q_OBJECT

private:
	Player* player;
	QLabel *iconLabel;
	QPixmap piecePixmap;

public:
	GUIPlayer(Player* p);
	void setPieceImage(QIcon *i);
	QPixmap getPieceImage();
	QLabel* getIcon();
	Player* getPlayer();

	int getMoney();

	void setPosition(int i);
	void setInitialPosition();
	int getPosition();
	int move(int);

	void addSpace(GUISpace* s);

	bool isInGame();
	void quitGame();

};

#endif