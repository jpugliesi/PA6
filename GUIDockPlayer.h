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
	QLabel **names;
	QLabel **icons;
	QLabel **moneyLabels;
	std::vector<std::vector<QLabel*> > propertyLabels;
	QVBoxLayout *vMain;
	QVBoxLayout **subVLayouts;
	QVBoxLayout **spaceLayouts;
public:
	GUIDockPlayer(std::vector<GUIPlayer*> *dp, QDockWidget *p);
	void update();

};

#endif