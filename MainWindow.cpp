#include "MainWindow.h"
#include <QtDebug>
#include <iostream>

MainWindow::MainWindow() {
  setGeometry( 0, 0, 800, 800 );

  setFixedSize(sizeHint());

  theBank = new Bank;
  //Display the board in the central widget
  centralWidget = new CentralWidget(&players, &guiPlayers, theBank, this);
  setCentralWidget( centralWidget );
  numPlayers = centralWidget->getNumPlayers();
  std::cout << guiPlayers.size() << std::endl;

  createDockWindows();
  createMenuBar();
}

void MainWindow::createMenuBar(){

}

void MainWindow::createDockWindows(){
  //createDockWindows();
  std::vector<GUIPlayer*> pDockLeftPlayers;
  std::vector<GUIPlayer*> pDockRightPlayers;

  for(int i = 0; i < guiPlayers.size(); i++){
    if(i % 2 == 0){
      pDockLeftPlayers.push_back(guiPlayers[i]);
    }else{
      pDockRightPlayers.push_back(guiPlayers[i]);
    }
  }

  pDockLeft = new QDockWidget;
  pDockRight = new QDockWidget;
  pDockLeft->setFeatures(QDockWidget::NoDockWidgetFeatures);
  pDockRight->setFeatures(QDockWidget::NoDockWidgetFeatures);

  bodyLeft = new QWidget(pDockLeft);
  QVBoxLayout *vMain = new QVBoxLayout(pDockLeft);
  for(int i = 0; i < pDockLeftPlayers.size(); i++){
    QVBoxLayout *vbox = new QVBoxLayout;
    QPixmap image = pDockLeftPlayers[i]->getPieceImage();
    QPixmap imageScaled = image.scaled(60, 60);
    QLabel *icon = new QLabel(pDockLeft);
    icon->setPixmap(imageScaled);
    QString playersMoney = "$";
    playersMoney.append(QString::number(pDockLeftPlayers[i]->getMoney()));
    QLabel *money = new QLabel(playersMoney);
    money->setFont(QFont("Arial", 18));
    vbox->addWidget(icon);
    vbox->addWidget(money);
    vMain->addLayout(vbox);
  }
  bodyLeft->setLayout(vMain);

  pDockLeft->setWidget(bodyLeft);

  bodyRight = new QWidget(pDockRight);
  QVBoxLayout *vMain2 = new QVBoxLayout(pDockRight);
  for(int i = 0; i < pDockRightPlayers.size(); i++){
    QVBoxLayout *vbox = new QVBoxLayout;
    QPixmap image = pDockRightPlayers[i]->getPieceImage();
    QPixmap imageScaled = image.scaled(60, 60);
    QLabel *icon = new QLabel(pDockRight);
    icon->setPixmap(imageScaled);
    QString playersMoney = "$";
    playersMoney.append(QString::number(pDockRightPlayers[i]->getMoney()));
    QLabel *money = new QLabel(playersMoney);
    money->setFont(QFont("Arial", 18));
    vbox->addWidget(icon);
    vbox->addWidget(money);
    vMain2->addLayout(vbox);
  }
  bodyRight->setLayout(vMain2);

  pDockRight->setWidget(bodyRight);

  addDockWidget( Qt::LeftDockWidgetArea, pDockLeft );
  addDockWidget( Qt::RightDockWidgetArea, pDockRight );
}