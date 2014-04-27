
#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QtGui>
#include <vector>
#include "GUISpace.h"
#include "Deck.h"
#include "ConsoleWidget.h"
#include "GUIPlayer.h"

class GUISpace;
class ConsoleWidget;

class CentralWidget: public QWidget {
  Q_OBJECT

  private:

    int numPlayers;

    Space* spaces[40];
    GUISpace* guiSpaces[40];

    int turn;
    // Player** players;
    // GUIPlayer** guiPlayers;
    std::vector<Player*> *players;
    std::vector<GUIPlayer*> *guiPlayers;
    QIcon *icons[10];
    int availableIcons[10];
    QString colors[40];
    Deck* theManDeck;
    Deck* theChestDeck;

    QGridLayout *grid; //grid of the central area
    ConsoleWidget *consoleWidget; //console widget that resides in the central area

    void getPlayerInfo();
    void occupyPiecesIcons();
    void selectPieces();
    void occupyColorsArray();
    void createDecks();
    void createSpaces();
    void drawCenter();
    void drawConsole(QGridLayout *grid);
    void addPlayerIcons();

    void setupSpaceButtonActions(GUIPlayer *p);
    int advanceTurn();

public slots:
    void playGame();
    void movePlayerToSpace(GUIPlayer* p, GUISpace* gs);
  
 public:
    CentralWidget(std::vector<Player*> *a, std::vector<GUIPlayer*> *b, QWidget *parent = 0);
    int getNumPlayers();
    GUISpace* findSpaceByIndex(int i);

};

#endif
