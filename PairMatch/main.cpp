#include <QApplication>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>

/*void setLines(QApplication app){
    QWidget *window = new QWidget;
    window->setWindowTitle("Card Pair Game");
    QPushButton *newGameButton = new QPushButton("New Game");
    QObject::connect(newGameButton, SIGNAL(clicked()),
                     &app, SLOT(quit()));       // TODO: Don't quit, restart!
    QLabel *scoreWrite = new QLabel("Score ");
    QLabel *scoreCount = new QLabel;      // TODO: It has to be changed when necessary!
    int initialScore = 0;
    scoreCount->setNum(initialScore);
    QLabel *remWrite = new QLabel("Remaining ");
    QLabel *remCount = new QLabel;       // TODO: It has to be changed when necessary!
    int initialCount = 50;
    remCount->setNum(initialCount);
    QGridLayout	*layout	=	new	QGridLayout;
    layout->addWidget(scoreWrite, 0, 0);
    layout->addWidget(scoreCount, 0, 1);
    layout->addWidget(remWrite, 0, 2);
    layout->addWidget(remCount, 0 , 3);
    layout->addWidget(newGameButton,0 , 4, 1, 2);
    for (int i = 1; i <= 5; i++){
        for (int j = 0; j <= 5; j++){
            QPushButton *questionMark = new QPushButton("?");
            QObject::connect(questionMark, SIGNAL(clicked()),
                             &app, SLOT(quit()));  // TODO: Don't quit, give another slots!
            layout->addWidget(questionMark, i, j);
        }
    }
    window->setLayout(layout);
    window->show();
}*/


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //setLines(app);
    QWidget *window = new QWidget;
    window->setWindowTitle("Card Pair Game");
    QPushButton *newGameButton = new QPushButton("New Game");
    QObject::connect(newGameButton, SIGNAL(clicked()),
                     &app, SLOT(quit()));       // TODO: Don't quit, restart!
    QLabel *scoreWrite = new QLabel("Score ");
    QLabel *scoreCount = new QLabel;      // TODO: It has to be changed when necessary!
    int initialScore = 0;
    scoreCount->setNum(initialScore);
    QLabel *remWrite = new QLabel("Remaining ");
    QLabel *remCount = new QLabel;       // TODO: It has to be changed when necessary!
    int initialCount = 50;
    remCount->setNum(initialCount);
    QGridLayout	*layout	= new QGridLayout;
    layout->addWidget(scoreWrite, 0, 0); // Args: label, column, row
    layout->addWidget(scoreCount, 0, 1);
    layout->addWidget(remWrite, 0, 2);
    layout->addWidget(remCount, 0 , 3);
    layout->addWidget(newGameButton,0 , 4, 1, 2);
    for (int i = 1; i <= 5; i++){
        for (int j = 0; j <= 5; j++){
            QPushButton *questionMark = new QPushButton("?");
            QObject::connect(questionMark, SIGNAL(clicked()),
                             &app, SLOT(quit()));  // TODO: Don't quit, do something else!
            layout->addWidget(questionMark, i, j);
        }
    }
    window->setLayout(layout);
    window->show();


    return app.exec();
}


