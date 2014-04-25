#ifndef GUIPLAYER_H
#define GUIPLAYER_H

#include <QtGui>
#include "Player.h"

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

	int getMoney();

};

#endif