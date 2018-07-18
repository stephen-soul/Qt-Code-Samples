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
        if (!line.contains(QChar('#')))
            lineToCopy.append(line);
        if (line.contains(QChar('@'))) {
            pos = lineToCopy.lastIndexOf(QChar('@'));
            game.append(lineToCopy.left(pos));
            lineToCopy = "";
        }
        lineNumber++;
    } while (!in.atEnd());
    textFile.close();
}

void gameText::readMapText() {
    // Read from map and stuff into a QMap with value pairs
    QFile textFile(":/text/map.inc");
    textFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&textFile);
    QString line;
    QString lineToCopy;
    int lineNumber = 0;
    int pos;
    do {
        line = in.readLine();
        if (!line.contains(QChar('#')))
            lineToCopy.append(line);
        if (line.contains(QChar('@'))) {
            pos = lineToCopy.lastIndexOf(QChar('@'));
            mapText.append(lineToCopy.left(pos));
            lineToCopy = "";
        }
        lineNumber++;
    } while (!in.atEnd());
//    QString lineDescription;
//    QString workingLine;
//    int pos = 0;
//    bool gettingDescription = false;
//    do {
//        line = in.readLine();
//        if (!line.contains(QChar('#')))
//            workingLine.append(line);
//        if (line.contains(QChar('@'))) {
//            pos = workingLine.lastIndexOf(QChar('@'));
//            if(!gettingDescription) {
//                lineId = workingLine.left(pos);
//                gettingDescription = true;
//            }
//            else {
//                lineDescription = workingLine.left(pos);
//                gettingDescription = false;
//            }
//            if (lineId.isEmpty() && lineDescription.isEmpty()) {
//                map.insertMulti(lineId, lineDescription);
//                lineId.clear();
//                lineDescription.clear();
//            }
//            workingLine.clear();
//        }
//    } while (!in.atEnd());
    textFile.close();
}
