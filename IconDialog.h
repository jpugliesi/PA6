#ifndef ICONDIALOG_H
#define ICONDIALOG_H

#include <QtGui>

class IconDialog : public QDialog{

	Q_OBJECT

private:
	void createIconSelectorGrid();
	QPushButton *iconButtons[10];
	QIcon **pieceIcons;
	int *availableIcons;
	int choice;

	QSignalMapper *signalMapper;

	QPushButton *reject;

signals:
	void clicked(int);

public slots:
	void setChoice(int);

public:
	IconDialog(QIcon **icons, int *available, QWidget *parent);
	int getChoice();

};

#endif