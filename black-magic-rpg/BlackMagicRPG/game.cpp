#include "game.h"
#include "mainwindow.h"
#include <QTimer>

game::game(QObject *parent) : QObject(parent) {
    state = STATE_MAINMENU;
    textState = STATE_NEWGAME_TEXT;
    playerName = "";
}

game::~game() {
}

void game::initializeGame() {
    returnImage(images.getMainMenuLogo());
    returnInput(text.getMainMenuText());
}

void game::progressMainMenu(const QString &input) {
    returnInput(input);
}

void game::acceptInput(const QString &passedInput) {
    if(state == STATE_CHAPTER1_PROCESS_ENTER) {
        if(passedInput.isEmpty())
            userInput.enqueue("empty");
        else
            userInput.enqueue(passedInput);
    } else {
        if(!passedInput.isEmpty() && passedInput != "clear") {
            if (state != STATE_NEWGAME_GETNAME)
                userInput.enqueue(passedInput.toLower());
            else
                userInput.enqueue(passedInput);
        }
    }
    advance();
}

// This function handles the input and compares it against the current state
void game::advance() {
    switch (state) {
    case STATE_MAINMENU:
        if(!userInput.isEmpty()) {
            handleMainMenu(userInput.dequeue());
        }
        break;
    case STATE_NEWGAME_GETNAME:
        if(!userInput.isEmpty()) {
            handleNewGameNaming(userInput.dequeue());
        }
        break;
    case STATE_NEWGAME_GETCLASS:
        if(!userInput.isEmpty()) {
            handleNewGameClass(userInput.dequeue());
        }
        break;
    case STATE_CHAPTER1_PROCESS_ENTER:
        if(!userInput.isEmpty()) {
            handleNewGamePart1();
        }
        break;
    default:
        break;
    }
}

// This slot handles appending to a console
void game::returnInput(const QString &newInput) {
    emit sendParsedInput(newInput);
}

// This slot handles sending an image to the ui
void game::returnImage(const QPixmap &image) {
    emit sendImage(image);
}

void game::incrementGameAndText() {
    state++;
    textState++;
}

// Function to handle the main menu input
void game::handleMainMenu(const QString &mainMenuInput) {
    QString inputToSend;
    if(mainMenuInput == "1") {
        returnInput("clear");
        inputToSend = text.getGame(textState);
        returnImage(images.getNewGameImage());
        incrementGameAndText();
    }
    returnInput(inputToSend);
}

void game::handleNewGameNaming(const QString &nameInput) {
    playerName = nameInput;
    text.appendNameToGameText(playerName);
    returnInput("\n" + text.getGame(textState));
//    textState++;
//    returnInput("\n" + text.getGame(textState) + "\n" + text.getGame(textState+1) + "\n" + text.getGame(textState+2) + "\n" + text.getGame(textState+3));
//    for(int i = 0; i < 3; i++)
//        textState++;
    incrementGameAndText();
}

void game::handleNewGameClass(const QString &classPicker) {
    bool classMade = false;
    if(classPicker == "1") {
        // If they pick warrior
        newPlayer = *new player(100, 100, 60, 60, playerName, "Warrior", 10, 3, 0, 5, 5);
        classMade = true;
    } else if(classPicker == "2") {
        // If they pick mage
        newPlayer = *new player(80, 80, 100, 100, playerName, "Mage", 5, 5, 10, 3, 6);
        classMade = true;
    } else if(classPicker == "3") {
        // If they pick rogue
        newPlayer = *new player(90, 90, 80, 80, playerName, "Rogue", 5, 5, 10, 3, 6);
        classMade = true;
    }
    if(classMade) {
        returnInput("\n" + text.getGame(textState));
        incrementGameAndText();
        returnInput("\n" + text.getGame(textState));
    }
    // Now the player class is made
}

void game::handleNewGamePart1() {
    // Clear the screen and move the events forward
    returnInput("clear");
    returnInput(text.getMap("blkrock-cen") + "\n" + text.getMap("blkrock-cen-desc"));
}
