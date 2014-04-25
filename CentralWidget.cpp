#include "CentralWidget.h"
#include "GUIPropertySpace.h"
#include "GUIChestSpace.h"
#include "CardAction.h"
#include "MoneyAction.h"
#include "Deck.h"
#include "GUIPlayer.h"
#include "IconDialog.h"

CentralWidget::CentralWidget(std::vector<Player*> *ps, std::vector<GUIPlayer*> *gs, QWidget *parent): QWidget(parent) {
  setGeometry( 0, 0, 600, 600 );

  players = ps;
  guiPlayers = gs;

  getPlayerInfo();
  occupyPiecesIcons();
  selectPieces();
  occupyColorsArray();
  createDecks();
  createSpaces();
  drawCenter();

}

void CentralWidget::occupyPiecesIcons(){
  //define icons that a player can select from
  icons[0] = new QIcon(QPixmap(":/images/airplane9.png"));

  icons[1] = new QIcon(QPixmap(":/images/clip5.png"));

  icons[2] = new QIcon(QPixmap(":/images/closed18.png"));

  icons[3] = new QIcon(QPixmap(":/images/coliseum1.png"));

  icons[4] = new QIcon(QPixmap(":/images/cup18.png"));

  icons[5] = new QIcon(QPixmap(":/images/detailed.png"));

  icons[6] = new QIcon(QPixmap(":/images/flag20.png"));

  icons[7] = new QIcon(QPixmap(":/images/message3.png"));

  icons[8] = new QIcon(QPixmap(":/images/shopping29.png"));

  icons[9] = new QIcon(QPixmap(":/images/user56.png"));

}

void CentralWidget::selectPieces(){
  for(int i = 0; i < 10; i++){
    availableIcons[i] = 0;
  }

  int selection;

  for(int i = 0; i< numPlayers; i++){
    IconDialog iconDialog(icons, availableIcons, this);
    iconDialog.exec();
    selection = iconDialog.getChoice();
    if(selection == -1){
      for(int i = 0; i < 10; i++){
        if(availableIcons[i] == 0){
          selection = i;
          availableIcons[i] = 1;
          break;
        }
      }
    }else{
      availableIcons[selection] = 1;
    }

    //store icon as player's piece icon
    guiPlayers->at(i)->setPieceImage(icons[selection]);
  }
  
}

void CentralWidget::getPlayerInfo(){
  //Prompt for number of player
  bool ok;
  QStringList playerChoices;
  playerChoices << "2" << "3" << "4";
  int numPlayersChosen = 0;
  QString item = QInputDialog::getItem(this, "Players", tr("Choose the number of players: "), playerChoices, 0, false, &ok);
  numPlayersChosen = item.toInt();

  if(ok && numPlayersChosen != 0){
    numPlayers = numPlayersChosen;
  }else{
    numPlayers = 2;
  }

  // players = new Player*[numPlayers];
  for(int i = 0; i < numPlayers; i++){
    players->push_back(new Player());
  }

  //guiPlayers = new GUIPlayer*[numPlayers];
  for(int i = 0; i < numPlayers; i++){
    guiPlayers->push_back(new GUIPlayer(players->at(i)));
  }
}

void CentralWidget::createDecks(){

  theManDeck = new Deck();
  theChestDeck = new Deck();

  // QString description = "You didn't file your damn taxes. Pay THE MAN a fine of $100";
  // theManDeck->addCard(new MoneyAction(NULL, 100, false, description));
  // description = "You were caught J-walking. Pay ticket of $200.";
  // theManDeck->addCard(new MoneyAction(NULL, 200, false, description));
  // description = "You made a citizen's arrest! Collect reward of $200.";
  // theManDeck->addCard(new MoneyAction(NULL, 200, true, description));
  // description = "You became a high ranking government official. Collect salary of $150.";
  // theManDeck->addCard(new MoneyAction(NULL, 150, true, description));
  // description = "You jeopordized a top-secret mission. Pay fine of $500";
  // theManDeck->addCard(new MoneyAction(NULL, 500, false, description));
  // description = "THE MAN is watching you. Pay $150 for tin-foil hat.";
  // theManDeck->addCard(new MoneyAction(NULL, 150, false, description));
  // description = "You get a tax write-off. Collect $50.";
  // theManDeck->addCard(new MoneyAction(NULL, 50, true, description));
  // description = "You were caught speeding. Pay ticket of $350.";
  // theManDeck->addCard(new MoneyAction(NULL, 350, false, description));
  // description = "You littered! How dare you!. Pay fine of $500.";
  // theManDeck->addCard(new MoneyAction(NULL, 500, false, description));
  // description = "You won Ms. America! Collect $400.";
  // theManDeck->addCard(new MoneyAction(NULL, 400, true, description));
  // description = "You got a fat research stipend! Collect $300.";
  // theManDeck->addCard(new MoneyAction(NULL, 300, true, description));
  // description = "You are disliked. Pay $50.";
  // theManDeck->addCard(new MoneyAction(NULL, 50, false, description));
  // description = "You skipped jury duty. Pay fine of $450.";
  // theManDeck->addCard(new MoneyAction(NULL, 450, false, description));
  // description = "You attended jury duty. Collect compensation of $100.";
  // theManDeck->addCard(new MoneyAction(NULL, 100, true, description));
  // description = "THE MAN is poor. Give him $150.";
  // theManDeck->addCard(new MoneyAction(NULL, 150, false, description));
  // description = "You are poor. Collect handout of $100.";
  // theManDeck->addCard(new MoneyAction(NULL, 100, true, description));
  // description = "You are a menace to society. Pay $250!";
  // theManDeck->addCard(new MoneyAction(NULL, 250, false, description));
  // description = "You know too much. Here. Take this and shut up.";
  // theManDeck->addCard(new MoneyAction(NULL, 200, true, description));
  // description = "You are an oil mongol. Respect us! Here's $200";
  // theManDeck->addCard(new MoneyAction(NULL, 200, true, description));
  // description = "You are a good person. Here is $50.";
  // theManDeck->addCard(new MoneyAction(NULL, 50, true, description));
  // description = "You have been exiled to Siberia.";
  // //14 is siberia's index in the gameboard spaces array
  // theManDeck->addCard(new GoToAction(NULL, theBoard, theBoard->findSpaceByIndex(14), description));

  // //cards for chest deck
  // description = "Advance 3 spaces.";
  // theChestDeck->addCard(new MoveAction(NULL, theBoard, 3, description));
  // description = "Advance 20 spaces.";
  // theChestDeck->addCard(new MoveAction(NULL, theBoard, 20, description));
  // description = "You won the ugly pagent. Collect $50";
  // theChestDeck->addCard(new MoneyAction(NULL, 50, true, description));
  // description = "You won a trip to Las Vegas!";
  // theChestDeck->addCard(new GoToAction(NULL, theBoard, theBoard->findSpaceByIndex(25), description));
  // description = "Pack up and move to El Sob.";
  // theChestDeck->addCard(new GoToAction(NULL, theBoard, theBoard->findSpaceByIndex(5), description));
  // description = "Meet THE MAN";
  // theChestDeck->addCard(new GoToAction(NULL, theBoard, theBoard->findSpaceByIndex(13), description));
  // description = "They call it Debt Row...";
  // theChestDeck->addCard(new GoToAction(NULL, theBoard, theBoard->findSpaceByIndex(31), description));
  // description = "They call it Debt Row...";
  // theChestDeck->addCard(new GoToAction(NULL, theBoard, theBoard->findSpaceByIndex(31), description));
  // description = "Pack up and move to Brooklyn.";
  // theChestDeck->addCard(new GoToAction(NULL, theBoard, theBoard->findSpaceByIndex(12), description));

  // //shuffle dem decks
  // theManDeck->shuffle();
  // theChestDeck->shuffle();

}

void CentralWidget::createSpaces(){

  //occupy the spaces array with appropriate spaces
  spaces[0] = new Space("Go", 1, false, 0);
  spaces[1] = new Space("Glassell", 2, true, 50);
  spaces[2] = new Space("*Chest*", 3, false, 60);   
  spaces[3] = new Space("Richmond", 4, true, 70);
  spaces[4] = new Space("TAX", 5, false, 0); 
  spaces[5] = new Space("El Sob", 6, true, 100);
  spaces[6] = new Space("*THE  MAN*", 7, false, 0); 
  spaces[7] = new Space("Terrace", 8, true, 110);
  spaces[8] = new Space("El Cerrito", 9, true, 120); 
  spaces[9] = new Space("Pinole", 10, true, 130);
  spaces[10] = new Space("", 11, false, 0); 

  spaces[11] = new Space("*Chest*", 12, false, 0); 
  spaces[12] = new Space("Brooklyn", 13, true, 150);
  spaces[13] = new Space("*THE  MAN*", 14, false, 0); 
  spaces[14] = new Space("Siberia", 15, true, 150);
  spaces[15] = new Space("", 16, false, 0);     
  spaces[16] = new Space("Austin", 17, true, 170);
  spaces[17] = new Space("Memphis", 18, true, 170); 
  spaces[18] = new Space("Wichita", 19, true, 180);
  spaces[19] = new Space("*Chest*", 20, false, 0);

  spaces[20] = new Space("", 21, false, 0); 
  spaces[21] = new Space("Atlanta", 22, true, 200);
  spaces[22] = new Space("", 23, false, 0);     
  spaces[23] = new Space("Tahoe", 24, true, 210);
  spaces[24] = new Space("*Chest*", 25, false, 0); 
  spaces[25] = new Space("Las Vegas", 26, true, 250);
  spaces[26] = new Space("*THE  MAN*", 27, false, 0); 
  spaces[27] = new Space("*Chest*", 28, false, 0);
  spaces[28] = new Space("Chicago", 29, true, 270); 
  spaces[29] = new Space("Seattle", 30, true, 300);
  spaces[30] = new Space("", 31, false, 0);

  spaces[31] = new Space("*THE  MAN*", 32, false, 0); 
  spaces[32] = new Space("TAX", 33, false, 0);
  spaces[33] = new Space("*THE  MAN*", 34, false, 0); 
  spaces[34] = new Space("New York", 35, true, 400);
  spaces[35] = new Space("*THE  MAN*", 36, false, 0); 
  spaces[36] = new Space("TAX", 37, false, 0);
  spaces[37] = new Space("*THE  MAN*", 38, false, 0); 
  spaces[38] = new Space("TAX", 39, false, 0);
  spaces[39] = new Space("San Fran", 0, true, 500);

  int propertyCount = 0;
  for(int i = 0; i < 40; i++){
    if(spaces[i]->isOwnable()){
      spaces[i]->setAction(NULL);
      guiSpaces[i] = new GUIPropertySpace(spaces[i], this, colors[propertyCount++]);
    }else if(spaces[i]->getName() == ""){
      spaces[i]->setAction(NULL);
      guiSpaces[i] = new GUIChestSpace(spaces[i], this, new Deck(), "#FFFFFF");
    }
    //else for THE MAN and TAX, and GO, and SPACE
    else if(spaces[i]->getName() == "*THE  MAN*"){
      spaces[i]->setAction(new CardAction(theManDeck));
      guiSpaces[i] = new GUIChestSpace(spaces[i], this, new Deck(), "#5100BA");
    }else if(spaces[i]->getName() == "TAX"){
      spaces[i]->setAction(new MoneyAction(NULL, 100, false, "Woops! Pay tax of $100."));
      guiSpaces[i] = new GUIChestSpace(spaces[i], this, new Deck(), "#FFFFFF");
    }else if(spaces[i]->getName() == "*Chest*"){
      spaces[i]->setAction(new CardAction(theChestDeck));
      guiSpaces[i] = new GUIChestSpace(spaces[i], this, new Deck(), "#FFBB00");
    }else if(spaces[i]->getName() == "Go"){
      spaces[i]->setAction(NULL);
      guiSpaces[i] = new GUIChestSpace(spaces[i], this, new Deck(), "#00B00F");
    }else{
      guiSpaces[i] = new GUIChestSpace(spaces[i], this, new Deck(), "#FFFFFF");

    }
  }
}

//draw the spaces to the CentralWidget
void CentralWidget::drawCenter(){

  //fills the screen with the appropriate squares in a box
  QGridLayout *grid = new QGridLayout(this->parentWidget());
  int row = 0, column = 0, diff1 = 12, diff2 = 22;
  for(int i = 0; i < 40; i++){
    GUISpace *aSpace = guiSpaces[i];
    aSpace->setFixedSize(60, 60);
    if(i < 11){
      row = 0;
      column = i;
    }else if(i >= 11 && i < 21){
      row = i - 10;
      column = 10;
    }else if(i >= 21 && i < 31){
      row = 10;
      column = i - diff1;
      diff1 += 2;
    }else if(i < 40){
      row = i - diff2;
      column = 0;
      diff2 += 2;
    }
    grid->addWidget(guiSpaces[i], row, column, 1, 1);
  }

  drawConsole(grid);

  grid->setSpacing(0); //get rid of spacing between labels
  //grid->setContentsMargins(0, 0, 0, 0); //get rid of margin around the grid
  setLayout(grid);

}

void CentralWidget::drawConsole(QGridLayout *grid){
  consoleWidget = new ConsoleWidget(*guiPlayers, grid);

  //a test, fix for dynamic play!
  consoleWidget->setCurrentPlayer(guiPlayers->at(0));

}

//fill up array of unique colors for spaces
void CentralWidget::occupyColorsArray(){
  colors[0] = "#0000FF";
  colors[1] = "#FF0000";
  colors[2] = "#01FFFE";
  colors[3] = "#FFA6FE";
  colors[4] = "#FFDB66";
  colors[5] = "#006401";
  colors[6] = "#010067";
  colors[7] = "#95003A";
  colors[8] = "#007DB5";
  colors[9] = "#FF00F6";
  colors[10] = "#FFEEE8";
  colors[11] = "#774D00";
  colors[12] = "#90FB92";
  colors[13] = "#0076FF";
  colors[14] = "#D5FF00";
  colors[15] = "#FF937E";
  colors[16] = "#6A826C";
  colors[17] = "#FF029D";
  colors[18] = "#FE8900";

}


int CentralWidget::getNumPlayers(){
  return numPlayers;
}
