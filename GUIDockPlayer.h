#ifndef GUIDOCKPLAYER_H
#define GUIDOCKPLAYER_H

#include <QtGui>
#include <vector>
#include "GUIPlayer.h"

class GUIDockPlayer : public QWidget{

	Q_OBJECT

private:
	QDockWidget *parent;
	std::vector<GUIPlayer*> *dockPlayers;
	QLabel *icon;
	QLabel *money;
public:
	GUIDockPlayer(std::vector<GUIPlayer*> *dp, QDockWidget *p);
	void update();

};

#endif