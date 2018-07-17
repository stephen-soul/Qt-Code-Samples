#include "gameText.h"

gameText::gameText() {
    initialize();
}

gameText::~gameText() {
    if(!game.isEmpty())
        game.clear();
    if(!map.isEmpty())
        map.clear();
}

void gameText::initialize() {
    // On initialize, start by filling out the main menu
    readMainMenu();
    readGameText();
}

QString gameText::getMap(int line) const
{
    return map.at(line);
}

QString gameText::getGame(int line) const
{
    return game.at(line);
}

QString gameText::getMainMenuText() const {
    return mainMenuText;
}

void gameText::readMainMenu() {
    // Read from main menu and save it as a variable
    QFile mainMenuFile(":/text/mainmenu.inc");
    mainMenuFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&mainMenuFile);
    do {
        mainMenuText = in.readAll();
    } while (!in.atEnd());
    mainMenuFile.close();
}

void gameText::readGameText() {
    // Read from game.inc and stuff it into a QList like so <chapter1, chapter2, ..>
    QFile textFile(":/text/game.inc");
    textFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&textFile);
    QString line;
    QString lineToCopy;
    int lineNumber = 0;
    int pos;
    do {
        line = in.readLine();
        if (!line.contains("#"))
            lineToCopy.append(line);
        if (line.contains("@")) {
            pos = lineToCopy.lastIndexOf(QChar('@'));
            game.append(lineToCopy.left(pos));
        }
        if (line.contains("")) {}
        lineNumber++;
    } while (!in.atEnd());
    textFile.close();
}
