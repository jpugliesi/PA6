#include "SelectPlayerDialog.h"

SelectPlayerDialog::SelectPlayerDialog(std::vector<QIcon*> i, QWidget *p) : QDialog(p){
	signalMapper = new QSignalMapper(this);
	connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(setChoice(int)));

	pieceIcons = i;
	choice = -1;
	iconButtons = new QPushButton*[pieceIcons.size()];
	createIconSelectorGrid();

	for(int i = 0; i < pieceIcons.size(); i++){
		signalMapper->setMapping(iconButtons[i], i);
		connect(iconButtons[i], SIGNAL(clicked()), signalMapper, SLOT(map()));
	}
}

void SelectPlayerDialog::createIconSelectorGrid(){
	QVBoxLayout *vbox = new QVBoxLayout;
	QHBoxLayout *iconBox = new QHBoxLayout;
	for(int i = 0; i < pieceIcons.size(); i++){
		iconButtons[i] = new QPushButton(this);
		iconButtons[i]->setIcon(QIcon(*pieceIcons[i]));
		iconButtons[i]->setIconSize(QSize(25, 25));

		iconBox->addWidget(iconButtons[i]);
	}

	vbox->addLayout(iconBox);
	setLayout(vbox);

}

void SelectPlayerDialog::setChoice(int x){
	choice = x;
	this->QDialog::accept();
}

int SelectPlayerDialog::getChoice(){
	return choice;
}