#include "IconDialog.h"
#include <QApplication>
#include <iostream>

IconDialog::IconDialog(QIcon **i, int *available, QWidget *parent): QDialog(parent){
	signalMapper = new QSignalMapper(this);
	connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(setChoice(int)));

	availableIcons = available;
	pieceIcons = i;
	choice = -1;
	createIconSelectorGrid();

	for(int i = 0; i < 10; i++){
		signalMapper->setMapping(iconButtons[i], i);
		connect(iconButtons[i], SIGNAL(clicked()), signalMapper, SLOT(map()));
	}
}

void IconDialog::createIconSelectorGrid(){
	QVBoxLayout *vbox = new QVBoxLayout;
	QHBoxLayout *iconBox = new QHBoxLayout;
	for(int i = 0; i < 10; i++){
		iconButtons[i] = new QPushButton(this);
		iconButtons[i]->setIcon(QIcon(*pieceIcons[i]));
		iconButtons[i]->setIconSize(QSize(25, 25));

		//disallow duplicate selection
		if(availableIcons[i] == 1){
			iconButtons[i]->setEnabled(false);
		}
		iconBox->addWidget(iconButtons[i]);
	}

	QHBoxLayout *accept = new QHBoxLayout;

	reject = new QPushButton("Choose for me");
	connect(reject, SIGNAL(clicked()), this, SLOT(reject()));

	accept->addWidget(reject);



	vbox->addLayout(iconBox);
	vbox->addLayout(accept);
	setLayout(vbox);

}

void IconDialog::setChoice(int x){
	std::cout << "Made it to choice" << std::endl;
	choice = x;
	this->QDialog::accept();
}

int IconDialog::getChoice(){
	return choice;
}