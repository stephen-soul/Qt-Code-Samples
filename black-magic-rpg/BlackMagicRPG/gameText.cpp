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
    // On initialize, start by filling the main menu, game text and map text
    readMainMenu();
    readGameText();
    readMapText();
}

QString gameText::getMapText(int line) const
{
    return mapText.at(line);
}

QString gameText::getMap(QString line) const
{
    return map.value(line); // Return the value of the map
}

QString gameText::getGameText(int line) const
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
    QFile textFile(":/text/game.inc"); // Text file to open
    textFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&textFile);
    QString line;
    QString lineToCopy;
    int pos;
    do {
        line = in.readLine();
        if (!line.contains(QChar('#'))) // If comment, don't read
            lineToCopy.append(line);
        if (line.isEmpty()) // If empty line, add a line break
            lineToCopy.append("\n");
        if (line.contains(QChar('@'))) { // If we're at a @ then we're at the end of the specified text
            pos = lineToCopy.lastIndexOf(QChar('@'));
            game.append(lineToCopy.left(pos));
            lineToCopy = "";
        }
    } while (!in.atEnd());
    textFile.close();
}

void gameText::readMapText() {
    // Read from map and stuff into a QMap with value pairs <map-1 = 'map1'>, <map-1-desc 'map1description'>
    QFile textFile(":/text/map.inc");
    textFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&textFile);
    QString line;
    QString lineId;
    QString lineDescription;
    QString workingLine;
    int pos = 0;
    bool gettingDescription = false;
    do {
        line = in.readLine();
        if (!line.contains(QChar('#')))
            workingLine.append(line);
        if (line.contains(QChar('@'))) {
            pos = workingLine.lastIndexOf(QChar('@'));
            if(!gettingDescription) {
                lineId = workingLine.left(pos);
                gettingDescription = true;
            }
            else {
                lineDescription = workingLine.left(pos);
                gettingDescription = false;
            }
            if (lineId != "" && lineDescription != "") {
                map.insertMulti(lineId, lineDescription);
                lineId.clear();
                lineDescription.clear();
            }
            workingLine.clear();
        }
    } while (!in.atEnd());
}

// Change any instance of %n to the players name
void gameText::appendNameToGameText(const QString &playerName) {
    game.replaceInStrings("%n", playerName);
}

// Reset the name in the game text (if the user changes their mind)
void gameText::resetNameInGameText(const QString &playerName) {
    game.replaceInStrings(playerName, "%n");
}

// Change any instance of %c to the players class name
void gameText::appendClassToGameText(const QString &playerClass) {
    game.replaceInStrings("%c", playerClass);
}

// Reset the class in the game text (if the user changes their mind)
void gameText::resetClassInGameText(const QString &playerClass) {
    game.replaceInStrings(playerClass, "%c");
}
