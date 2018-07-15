#include "game.h"
#include "mainwindow.h"

#include <QTimer>

enum gameState {
    STATE_MAINMENU,
    STATE_NEWGAME,
    STATE_CHARACTERCREATION,
    STATE_GAMEOVER
};

game::game(QWidget *parent) : QWidget(parent) {
    state = STATE_MAINMENU;
}

game::~game() {

}

// This function handles the input and compares it
void game::acceptInput(const QString &passedInput) {
    switch (state) {
    case STATE_MAINMENU:
        handleMainMenu(passedInput);
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

// Function to handle the main menu input
void game::handleMainMenu(const QString &mainMenuInput) {
    if(mainMenuInput == "1") {
        returnInput("Welcome to a new game.");
        state = STATE_NEWGAME;
    }
}
