#pragma once

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QRandomGenerator>

class PairMatch : public QWidget {

    Q_OBJECT

public:
    PairMatch(QWidget *parent = nullptr);

private slots:
    void ClickedHandler();
    void Refresh();

private:
    QLabel *scoreWrite;
    QLabel *remWrite;
    QLabel *scoreCount;
    QLabel *remCount;

    QPushButton *previousButton;
    int pushOrder = 0;
    int textEqual = -5000;

    QString elements[30] = {"Kamilkoc", "Pamukkale", "Varan", "Metro", "Luks Artvin", "Suha",
    "Nestle", "Ferrero", "Torku", "Ulker", "Eti", "Pasta of Noah's Ankara", "Coca Cola", "Pepsi", "Cola Turka",
    "Kamilkoc", "Pamukkale", "Varan", "Metro", "Luks Artvin", "Suha",
     "Nestle", "Ferrero", "Torku", "Ulker", "Eti", "Pasta of Noah's Ankara", "Coca Cola", "Pepsi", "Cola Turka"};
    QPushButton *buttons[5][6];   // Store the buttons in order to change it when necessary.
};
