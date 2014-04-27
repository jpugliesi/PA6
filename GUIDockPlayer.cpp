#include "GUIDockPlayer.h"

GUIDockPlayer::GUIDockPlayer(std::vector<GUIPlayer*> *dp, QDockWidget *p) : QWidget(p){
	  parent = p;
	  dockPlayers = dp;
	  QVBoxLayout *vMain = new QVBoxLayout(parent);
	  for(int i = 0; i < dockPlayers->size(); i++){
	    QVBoxLayout *vbox = new QVBoxLayout;
	    QPixmap image = dockPlayers->at(i)->getPieceImage();
	    QPixmap imageScaled = image.scaled(60, 60);
	    icon = new QLabel(parent);
	    icon->setPixmap(imageScaled);
	    QString playersMoney = "$";
	    playersMoney.append(QString::number(dockPlayers->at(i)->getMoney()));
	    money = new QLabel(playersMoney);
	    money->setFont(QFont("Arial", 18));
	    vbox->addWidget(icon);
	    vbox->addWidget(money);
	    vMain->addLayout(vbox);
	  }
	  setLayout(vMain);

}

void GUIDockPlayer::update(){
	for(int i = 0; i < dockPlayers->size(); i++){
		QString playersMoney = "$";
		playersMoney.append(QString::number(dockPlayers->at(i)->getMoney()));
		money->setText(playersMoney);
	}
}