#include "widget.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    PairMatch window;

    window.setWindowTitle("Card Pair Game");
    window.show();

    return app.exec();
}
