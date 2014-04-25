#include "GUIPlayer.h"

GUIPlayer::GUIPlayer(Player* p){
	player = p;
	iconLabel = new QLabel( this );
	//define iconeLabel picture
}

void GUIPlayer::setPieceImage(QIcon *i){
	piecePixmap = i->pixmap(QSize(60, 60));
	iconLabel->setPixmap(piecePixmap);
}

QPixmap GUIPlayer::getPieceImage(){
	return piecePixmap;
}

int GUIPlayer::getMoney(){
	return player->getMoney();
}