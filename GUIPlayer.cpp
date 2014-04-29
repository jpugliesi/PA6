#include "GUIPlayer.h"

GUIPlayer::GUIPlayer(Player* p, int i){
	playerName = new QLabel("Player " + QString::number(i), this);
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
QLabel* GUIPlayer::getNameLabel(){
	return playerName;
}
QString GUIPlayer::getName(){
	return playerName->text();
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

int GUIPlayer::move(int num){
	return player->move(num);
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

void GUIPlayer::takeOutOfGame(){
	player->toggleInGame();
}

std::vector<Space*> GUIPlayer::getAllOwnedSpaces(){
	return player->getAllOwnedSpaces();
}

int GUIPlayer::getNumOwnedSpaces(){
	return player->getNumOwnedSpaces();
}

