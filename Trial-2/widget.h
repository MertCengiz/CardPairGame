#pragma once

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QRandomGenerator>
#include <QTimer>
#include <QEventLoop>
#include <QMessageBox>

class PairMatch : public QWidget {

    Q_OBJECT

public:
    PairMatch(QWidget *parent = nullptr);

private slots:
    void ClickedHandler();
    void Refresh();

private:
    QLabel *scoreWrite; // Label that writes "Score"
    QLabel *remWrite;   // Label that writes "Remaining"
    QLabel *scoreCount; // Label that writes the score
    QLabel *remCount;   // Label that writes remaining attempts.

    QPushButton *previousButton;    // Stores previous button to compare strings.
    int pushOrder = 0;
    int textEqual = -5000;

    QString elements[30] = {"Kamilkoc", "Pamukkale", "Varan", "Metro", "Luks Artvin", "Suha",
    "Nestle", "Ferrero", "Torku", "Ulker", "Eti", "Pasta of Noah's Ankara", "Coca Cola", "Pepsi", "Cola Turka",
    "Kamilkoc", "Pamukkale", "Varan", "Metro", "Luks Artvin", "Suha",
     "Nestle", "Ferrero", "Torku", "Ulker", "Eti", "Pasta of Noah's Ankara", "Coca Cola", "Pepsi", "Cola Turka"};
    QPushButton *buttons[5][6];   // Store the buttons in order to change it when necessary.
};
