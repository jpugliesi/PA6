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

QLabel* GUIPlayer::getIcon(){
	return iconLabel;
}

QPixmap GUIPlayer::getPieceImage(){
	return piecePixmap;
}

int GUIPlayer::getMoney(){
	return player->getMoney();
}

void GUIPlayer::setPosition(int i){
	player->setPosition(i);
}

void GUIPlayer::setInitialPosition(){
	player->setInitialPosition();
}

int GUIPlayer::getPosition(){
	return player->getCurrentSpace();
}

Player* GUIPlayer::getPlayer(){
	return player;
}

void GUIPlayer::addSpace(GUISpace *s){
	player->addSpace(s->getSpace());
}

bool GUIPlayer::isInGame(){
	return player->getInGame();
}

void GUIPlayer::quitGame(){
	player->toggleInGame();
}

