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
    void Increment();
    void Decrement();
    void Refresh();
    QString GenerateRandomMatrices(int*, QString *);

private:
    QLabel *scoreWrite;
    QLabel *remWrite;
    QLabel *scoreCount;
    QLabel *remCount;

    QString previousString;
    int pushOrder = 0;
    int textEqual = -5000;

    QString elements[15] = {"Kamilkoc", "Pamukkale", "Varan", "Metro", "Luks Artvin", "Suha",
    "Nestle", "Ferrero", "Torku", "Ulker", "Eti", "Pasta of Noah's Ankara", "Coca Cola", "Pepsi", "Cola Turka"};
    int used[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
};
