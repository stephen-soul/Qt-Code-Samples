#include "game.h"
#include "mainwindow.h"

game::game(QObject *parent) : QObject(parent) {
    gameState = GAME_STATE_MAINMENU;
    textState = TEXT_STATE_NEWGAME_TEXT;
    playerName = "";
}

// Moving the destructor to default until we can include something to do during destructing
game::~game()=default;

// Constructor
void game::initializeGame() {
    returnImage(images.getMainMenuLogo());
    returnInput(text.getMainMenuText());
}

// This function handles taking the input from the gui and sending it to advance()
void game::acceptInput(const QString &passedInput) {
    if(gameState == GAME_STATE_CHAPTER1_PROCESS_ENTER) {
        if(passedInput.isEmpty())
            userInput.enqueue("empty");
        else
            userInput.enqueue(passedInput);
    } else {
        if(!passedInput.isEmpty() && passedInput != "clear") {
            if (gameState != GAME_STATE_NEWGAME_GETNAME)
                userInput.enqueue(passedInput.toLower());
            else
                userInput.enqueue(passedInput);
        }
    }
    advance();
}

// This function handles the input and compares it against the current state
void game::advance() {
    switch (gameState) {
    case GAME_STATE_MAINMENU:
        if(!userInput.isEmpty()) {
            handleMainMenu(userInput.dequeue());
        }
        break;
    case GAME_STATE_NEWGAME_GETNAME:
        if(!userInput.isEmpty()) {
            handleNewGameNaming(userInput.dequeue());
        }
        break;
    case GAME_STATE_NEWGAME_GETCLASS:
        if(!userInput.isEmpty()) {
            handleNewGameClass(userInput.dequeue());
        }
        break;
    case GAME_STATE_NEWGAME_CONFIRMATION:
        if(!userInput.isEmpty()) {
            handleConfirmingNameAndClass(userInput.dequeue());
        }
        break;
    case GAME_STATE_CHAPTER1_PROCESS_ENTER:
        if(!userInput.isEmpty()) {
            handleNewGamePart1();
        }
        break;
    default:
        break;
    }
    // Then update the variables for the gui
    returnHealth(player.getHealth(), player.getMaxHP());
    sendMagic(player.getMp(), player.);
}

// This slot handles appending to a console
void game::returnInput(const QString &newInput) {
    emit sendParsedInput(newInput);
}

// This slot handles returning the name
void game::returnName(const QString &name) {
    emit sendName(name);
}

// This slot handles returning the current health
void game::returnHealth(int &health, int &maxHealth) {
    QString currentHealth = QString::number(health);
    QString currentMaxHealth = QString::number(maxHealth);
    emit sendHealth("HP: " + currentHealth + "/" + currentMaxHealth);
}

// This slot handles returning the current MP
void game::returnMagic(int &mp, int &maxMp) {
    QString currentMagic = QString::number(mp);
    QString currentMaxMagic = QString::number(maxMp);
    emit sendMagic("MP: " + currentMagic + "/" + currentMaxMagic);
}

// This slot handles returning the current gold
void game::returnGold(int &gold) {
    QString currentGold = QString::number(gold);
    emit sendGold(currentGold + "G");
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
        inputToSend = text.getGameText(textState);
        returnImage(images.getNewGameImage());
        gameState = GAME_STATE_NEWGAME_GETNAME;
        textState = TEXT_STATE_NEWGAME_NAMING;
    }
    if(mainMenuInput == "2")
        inputToSend = "quit";
    returnInput(inputToSend);
}

// Function to handle naming your character
void game::handleNewGameNaming(const QString &nameInput) {
    playerName = nameInput;
    sendName(playerName);
    text.appendNameToGameText(playerName);
    returnInput("\n" + text.getGameText(textState));
    gameState = GAME_STATE_NEWGAME_GETCLASS;
    textState = TEXT_STATE_NEWGAME_CLASS;
    returnInput("\n" + text.getGameText(textState));
}

// Function to handle picking your class
void game::handleNewGameClass(const QString &classPicker) {
    int classNumber = 0;
    QRegularExpression inputCheck("^[1-3]*");
    bool classMade = false;
    if(classPicker.contains(inputCheck)) {
        classNumber = classPicker.toInt();
        switch(classNumber) {
        case 1:
            playerClass = "warrior";
            text.appendClassToGameText(playerClass);
            classMade = true;
            break;
        case 2:
            playerClass = "mage";
            text.appendClassToGameText(playerClass);
            classMade = true;
            break;
        case 3:
            playerClass = "rogue";
            text.appendClassToGameText(playerClass);
            classMade = true;
        }
        if(classMade) {
            gameState = GAME_STATE_NEWGAME_CONFIRMATION;
            textState = TEXT_STATE_NEWGAME_CONFIRMATION;
            returnInput(text.getGameText(textState));
        }
    }
}

// Function to handle confirmation If 1 continue else
void game::handleConfirmingNameAndClass(const QString &input) {
    QRegularExpression inputCheck("^[1-3]*");
    if(input.contains(inputCheck)) {
        int choice = input.toInt();
        switch(choice) {
        case 1: // If 1 (yes) then continue
            textState = TEXT_STATE_NEWGAME_CHAPTER1_INTRO;
            if(playerClass == "warrior")
                newPlayer = *new player(100, 100, 60, 60, playerName, playerClass, 10, 3, 1, 6, 5, 0);
            if(playerClass == "mage")
                newPlayer = *new player(60, 60, 100, 100, playerName, playerClass, 1, 3, 10, 3, 6, 0);
            if(playerClass == "rogue")
                newPlayer = *new player(80, 80, 60, 60, playerName, playerClass, 3, 10, 1, 5, 10, 0);
            // Now the player class is made
            gameState = GAME_STATE_CHAPTER1_PROCESS_ENTER;
            break;
        case 2: // If 2 (no) then go back
            returnInput("clear");
            gameState = GAME_STATE_NEWGAME_GETNAME;
            textState = TEXT_STATE_NEWGAME_TEXT;
            text.resetNameInGameText(playerName);
            text.resetClassInGameText(playerClass);
            playerName.clear();
            break;
        }
        // Afterwards return the input and advance the game state
        returnInput(text.getGameText(textState));
    }
}

void game::handleNewGamePart1() {
    // Clear the screen and move the events forward
    returnInput("clear");
    returnInput(text.getMap("blkrock-cen") + "\n" + text.getMap("blkrock-cen-desc"));
}
