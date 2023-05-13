#pragma once

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>

class PairMatch : public QWidget {

    Q_OBJECT

public:
    PairMatch(QWidget *parent = nullptr);

private slots:
    void Increment();
    void Decrement();
    void Refresh();

private:
    QLabel *scoreWrite;
    QLabel *remWrite;
    QLabel *scoreCount;
    QLabel *remCount;

    QString previousString;
    int pushOrder = 0;
    int textEqual = 0;
};
