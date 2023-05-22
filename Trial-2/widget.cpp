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

    int size = sizeof(elements)/sizeof(elements[0]);
    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(elements, elements+size, rng);
    // Generate random numbers.

    for (int i = 1; i <= 5; i++){
        for (int j = 0; j <= 5; j++){
            QString randomString = elements[6*(i-1)+j];
            buttons[i - 1][j] = new QPushButton("?", this);
            buttons[i - 1][j]->setProperty("name", randomString);
            connect(buttons[i - 1][j], &QPushButton::clicked, this, &PairMatch::ClickedHandler);
            grid->addWidget(buttons[i - 1][j], i, j);
        }
    }
    // Set the thirty cards to the grid with their properties.

}

void PairMatch::ClickedHandler() {

    int score = scoreCount->text().toInt();
    int remaining = remCount->text().toInt();
    QString text = scoreCount->text();
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    if (previousButton != clickedButton){   // Pressing a button twice is illegal!
        clickedButton->setText(clickedButton->property("name").toString());
        if (pushOrder % 2 == 0){            // No cards are currently open.
            previousButton = clickedButton; // Open the card and store it.
        }
        else if (pushOrder % 2 == 1){
            textEqual = QString::compare(previousButton->property("name").toString(), clickedButton->property("name").toString(), Qt::CaseInsensitive);
            QEventLoop loop;    // Stop taking input for a while.
            QTimer::singleShot(350, &loop, &QEventLoop::quit);
            loop.exec();
            if (textEqual == 0){
                score++;    // Increase the score, and prevent clicking the buttons again.
                disconnect(previousButton, &QPushButton::clicked, this, &PairMatch::ClickedHandler);
                disconnect(clickedButton, &QPushButton::clicked, this, &PairMatch::ClickedHandler);                
                clickedButton->setText(" ");    // Indicate that the card is found.
                previousButton->setText(" ");   // Indicate that the card is found.
            }
            else{
                clickedButton->setText("?");    // Close the card.
                previousButton->setText("?");   // Close the card.
            }
            remaining--; // Decrease val if the two string are not the same.
        }
        pushOrder++;
    }
    remCount->setText(QString::number(remaining));
    scoreCount->setText(QString::number(score));
    if (score == 15){
        QMessageBox messageBox;
        messageBox.setText("YOU ARE A WINNER");
        messageBox.setStandardButtons(QMessageBox::Cancel);
        messageBox.exec();
        QApplication::quit(); // Exit the game if no tries left.
    }
    if (remaining == 0){
        QMessageBox messageBox;
        messageBox.setText("YOU ARE A LOSER");
        messageBox.setStandardButtons(QMessageBox::Cancel);
        messageBox.exec();
        QApplication::quit(); // Exit the game if no tries left.
    }
}

void PairMatch::Refresh() {

    int valScore = 0;
    int remScore = 50;
    scoreCount->setText(QString::number(valScore));
    remCount->setText(QString::number(remScore));
    int size = sizeof(elements)/sizeof(elements[0]);
    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(elements, elements+size, rng);
    for (int i = 1; i <= 5; i++){
        for (int j = 0; j <= 5; j++){
            QString randomString = elements[6*(i-1)+j];
            buttons[i - 1][j]->setText("?");
            buttons[i - 1][j]->setProperty("name", randomString);
            connect(buttons[i - 1][j], &QPushButton::clicked, this, &PairMatch::ClickedHandler);
        }
    }
    pushOrder = 0;
    textEqual = -5000;
    // Set everything to default.
}
