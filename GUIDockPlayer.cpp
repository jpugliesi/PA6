#include "GUIDockPlayer.h"

GUIDockPlayer::GUIDockPlayer(std::vector<GUIPlayer*> *dp, QDockWidget *p) : QWidget(p){
	  parent = p;
	  dockPlayers = dp;

	  moneyLabels = new QLabel*[dockPlayers->size()];
	  names = new QLabel*[dockPlayers->size()];
	  icons = new QLabel*[dockPlayers->size()];
	  subVLayouts = new QVBoxLayout*[dockPlayers->size()];
	  spaceLayouts = new QVBoxLayout*[dockPlayers->size()];

	  vMain = new QVBoxLayout(parent);
	  for(int i = 0; i < dockPlayers->size(); i++){
	    subVLayouts[i] = new QVBoxLayout;
	    spaceLayouts[i] = new QVBoxLayout;
	    QPixmap image = dockPlayers->at(i)->getPieceImage();
	    QPixmap imageScaled = image.scaled(60, 60);
	    icons[i] = new QLabel(parent);
	    icons[i]->setPixmap(imageScaled);
	    names[i] = dockPlayers->at(i)->getNameLabel();
	    names[i]->setFont(QFont("Arial",18));
	    QString playersMoney = "$";
	    playersMoney.append(QString::number(dockPlayers->at(i)->getMoney()));
	    moneyLabels[i] = new QLabel(playersMoney);
	    moneyLabels[i]->setFont(QFont("Arial", 18));

	    subVLayouts[i]->addWidget(names[i]);
	    subVLayouts[i]->addWidget(icons[i]);
	    subVLayouts[i]->addWidget(moneyLabels[i]);
	    subVLayouts[i]->addLayout(spaceLayouts[i]);

	    vMain->addLayout(subVLayouts[i]);
	  }
	  setLayout(vMain);

}

void GUIDockPlayer::update(){
	for(int i = 0; i < dockPlayers->size(); i++){
		qDebug() << dockPlayers->at(i)->getName() + " updated\n";
		qDebug() << "has " << QString::number(dockPlayers->at(i)->getMoney()) << ".\n";
		QString playersMoney = "$";
		playersMoney.append(QString::number(dockPlayers->at(i)->getMoney()));
		moneyLabels[i]->setText(playersMoney);

		if(dockPlayers->at(i)->isInGame() && dockPlayers->at(i)->getNumOwnedSpaces() != 0){
			QLayoutItem* item;
		    while ( ( item = spaceLayouts[i]->takeAt( 0 ) ) != NULL )
		    {
		        delete item->widget();
		        delete item;
		    }
			delete spaceLayouts[i];
			spaceLayouts[i] = new QVBoxLayout;
			qDebug() << "Madesdfasdf";
			std::vector<Space*> spaces = dockPlayers->at(i)->getAllOwnedSpaces();
		    qDebug() << "Create spaces vector";
				
		    for(int j = 0; j < spaces.size(); j++){
		    	
		    	spaceLayouts[i]->addWidget(new QLabel(spaces.at(j)->getName(), this));
		    }
		    subVLayouts[i]->addLayout(spaceLayouts[i]);
		}else{
			QLayoutItem* item;
		    while ( ( item = spaceLayouts[i]->takeAt( 0 ) ) != NULL )
		    {
		        delete item->widget();
		        delete item;
		    }
		    delete spaceLayouts[i];
		    spaceLayouts[i] = new QVBoxLayout;
		}
		
	}
}