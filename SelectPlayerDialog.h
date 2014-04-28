#ifndef SELECTPLAYERDIALOG_H
#define SELECTPLAYERDIALOG_H

#include <QtGui>
#include <vector>

class SelectPlayerDialog : public QDialog{

	Q_OBJECT

private:
	void createIconSelectorGrid();
	QPushButton **iconButtons;
	std::vector<QIcon*> pieceIcons;
	int choice;

	QSignalMapper *signalMapper;

signals:
	void clicked(int);

public slots:
	void setChoice(int);

public:
	SelectPlayerDialog(std::vector<QIcon*> i, QWidget *parent);
	int getChoice();
};

#endif