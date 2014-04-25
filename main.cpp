#include <QApplication>

#include "MainWindow.h"

class MainWindow;

int main( int argv, char* argc[] ) {
  QApplication app( argv, argc );

  MainWindow mw;
  mw.show();


  return app.exec();
}
