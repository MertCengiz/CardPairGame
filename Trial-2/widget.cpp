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

    QPushButton *buttons[5][6];   // Store the buttons in order to change it when necessary.
    QString randomNames[5][6];

    for (int i = 1; i <= 5; i++){
        for (int j = 0; j <= 5; j++){
            QString randomString = GenerateRandomMatrices(used, elements);
            randomNames[i - 1][j] = randomString;
            buttons[i - 1][j] = new QPushButton("?", this);
            connect(buttons[i - 1][j], &QPushButton::clicked, this, &PairMatch::Increment);
            connect(buttons[i - 1][j], &QPushButton::clicked, this, &PairMatch::Decrement);
            grid->addWidget(buttons[i - 1][j], i, j);
        }
    }

    // TODO: When pressed, change the button with its version containing name from its index.
    // TODO: Make refresh every button question mark.

    /*buttons[2][1] = new QPushButton(randomNames[2][1], this);     // TESTING STUFF, NOT IMPORTANT!
    connect(buttons[2][1], &QPushButton::clicked, this, &PairMatch::Increment);
    connect(buttons[2][1], &QPushButton::clicked, this, &PairMatch::Decrement);
    grid->addWidget(buttons[2][1], 2, 1);*/
}

void PairMatch::Increment() {

    int val = scoreCount->text().toInt();
    QString text = scoreCount->text();
    if (pushOrder % 2 == 0){
        previousString = text;
    }
    else if (pushOrder % 2 == 1){
        textEqual = QString::compare(previousString, text, Qt::CaseInsensitive);
        if (textEqual == 0) // TODO: Fix the bug in comparing (Always executes this if block)
            val++;
    }
    scoreCount->setText(QString::number(val));
}

void PairMatch::Decrement() {

    int val = remCount->text().toInt();
    if (pushOrder % 2 == 1 && pushOrder > 0)
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

QString PairMatch:: GenerateRandomMatrices(int *used, QString *elements){
    quint32 randIndex = QRandomGenerator::global()->bounded(15);
    QString stringToWrite;
    while (used[randIndex] >= 2){
       randIndex = QRandomGenerator::global()->bounded(16);
    }
    stringToWrite = elements[randIndex];
    return stringToWrite;
}
