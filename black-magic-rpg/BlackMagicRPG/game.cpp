#include "game.h"
#include "mainwindow.h"
#include <QTimer>

enum gameState {
    STATE_MAINMENU,
    STATE_NEWGAME,
    STATE_NEWGAME_GETNAME1,
    STATE_NEWGAME_GETNAME2,
    STATE_NEWGAME_GETCLASS,
    STATE_GAMEOVER
};

enum gameTextState {
    STATE_NEWGAME_TEXT,
    STATE_NEWGAME_GETNAME_1_TEXT,
    STATE_NEWGAME_GETNAME_2_TEXT
};

game::game(QObject *parent) : QObject(parent) {
    state = STATE_MAINMENU;
    textState = STATE_NEWGAME_TEXT;
}

game::~game() {
}

void game::initializeGame() {
    returnImage(images.getMainMenuLogo());
    returnInput(text.getMainMenuText());
}

void game::acceptInput(const QString &passedInput) {
    if(!passedInput.isEmpty() && passedInput != "clear")
        userInput.enqueue(passedInput);
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
    case STATE_NEWGAME:
        if(!userInput.isEmpty()) {

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

// Function to handle the main menu input
void game::handleMainMenu(const QString &mainMenuInput) {
    QString inputToSend;
    if(mainMenuInput == "1") {
        returnInput("clear");
        inputToSend = text.getGame(textState);
        returnImage(images.getNewGameImage());
        state++;
    } else if(mainMenuInput == "clear") {
        inputToSend = "clear";
    }
    if(inputToSend != "")
        returnInput(inputToSend);
}
