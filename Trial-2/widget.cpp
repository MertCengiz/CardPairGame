#include "widget.h"

PairMatch::PairMatch(QWidget *parent) : QWidget(parent) {

    auto *newGameButton = new QPushButton("New Game", this);
    scoreWrite = new QLabel("Score ");
    remWrite = new QLabel("Remaining ");
    scoreCount = new QLabel("0", this);
    remCount = new QLabel("50", this);

    auto *grid = new QGridLayout(this);
    grid->addWidget(scoreWrite, 0, 0);  // Args: label, column, row
    grid->addWidget(scoreCount, 0, 1);  // Args: label, column, row
    grid->addWidget(remWrite, 0, 2);    // Args: label, column, row
    grid->addWidget(remCount, 0 , 3);   // Args: label, column, row
    grid->addWidget(newGameButton,0 , 4, 1, 2); // Last two arguments make it cover two button places.

    setLayout(grid); // Set a grid layout. Makes the same job with QGridLayout object.

    connect(newGameButton, &QPushButton::clicked, this, &PairMatch::Refresh);
    // Refresh everything (Restart the game)

    for (int i = 1; i <= 5; i++){
        for (int j = 0; j <= 5; j++){
            // TODO: Give random texts to each pair of buttons
            auto *questionMark = new QPushButton("?", this);
            connect(questionMark, &QPushButton::clicked, this, &PairMatch::Increment);
            connect(questionMark, &QPushButton::clicked, this, &PairMatch::Decrement);
            grid->addWidget(questionMark, i, j);
        }
    }
}

void PairMatch::Increment() {

    int val = scoreCount->text().toInt();
    val++;  // TODO: Increment only when textEqual == 1
    scoreCount->setText(QString::number(val));
    // TODO: If previousString and current text are the same, make textEqual == 1
}

void PairMatch::Decrement() {

    int val = remCount->text().toInt();
    if (pushOrder % 2 == 1 && textEqual == 0)
        val--;  // Decrease val if the two string are not the same.
    pushOrder++;
    remCount->setText(QString::number(val));
    if (val == 0)
        QApplication::quit(); // Exit the game if no tries left.
}

void PairMatch::Refresh() {

    int valScore = 0;
    int remScore = 50;
    scoreCount->setText(QString::number(valScore));
    remCount->setText(QString::number(remScore));
    // TODO: Refresh the question marks.
}
