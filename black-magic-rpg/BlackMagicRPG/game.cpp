#include "game.h"
#include "mainwindow.h"
#include <QTimer>

enum gameState {
    STATE_MAINMENU,
    STATE_NEWGAME,
    STATE_CHARACTERCREATION,
    STATE_GAMEOVER
};

game::game(QObject *parent) : QObject(parent) {
    state = STATE_MAINMENU;
}

game::~game() {
}

void game::initializeGame() {
    returnImage(images.getMainMenuLogo());
}

void game::acceptInput(const QString &passedInput) {
    userInput.enqueue(passedInput);
    advance();
}

// This function handles the input and compares it
void game::advance() {
    switch (state) {
    case STATE_MAINMENU:
        if(!userInput.isEmpty()) {
            handleMainMenu(userInput.dequeue());
        }
        break;
    case STATE_NEWGAME:
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
        inputToSend = "New game selected";
        //state = STATE_NEWGAME;
    } else if(mainMenuInput == "clear") {
        inputToSend = "clear";
    }
    if(inputToSend != "")
        returnInput(inputToSend);
}
