#include "widget.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    PairMatch window;

    //window.resize(300, 190);
    window.setWindowTitle("Card Pair Game");
    window.show();

    return app.exec();
}
