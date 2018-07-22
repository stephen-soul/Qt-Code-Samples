#ifndef GAME_H
#define GAME_H
#include "gameimages.h"
#include "gameText.h"
#include "player.h"
#include <QKeyEvent>
#include <QApplication>
#include <QTimer>
#include <QWidget>
#include <QQueue>
#include <QRegularExpression>

enum gameState {
    GAME_STATE_MAINMENU,
    GAME_STATE_NEWGAME_GETNAME,
    GAME_STATE_NEWGAME_GETCLASS,
    GAME_STATE_NEWGAME_CONFIRMATION,
    GAME_STATE_CHAPTER1_PROCESS_ENTER,
    GAME_STATE_CHAPTER1,
    GAME_STATE_GAMEOVER
};

enum gameTextState {
    TEXT_STATE_NEWGAME_TEXT,
    TEXT_STATE_NEWGAME_NAMING,
    TEXT_STATE_NEWGAME_CLASS,
    TEXT_STATE_NEWGAME_CONFIRMATION,
    TEXT_STATE_NEWGAME_CHAPTER1_INTRO
};

class game : public QObject {
    Q_OBJECT
public:
    explicit game(QObject *parent = nullptr);
    virtual ~game();
    void initializeGame(); // Function to initialize some values
signals:
    void sendParsedInput(const QString &); // Signal to send input
    void sendImage(const QPixmap &); // Signal to send image
public slots:
    void advance(); // Advance the timer
    void acceptInput(const QString &); // Get the input from the gui
    void returnInput(const QString &); // Send the input to the gui
private slots:
    void returnImage(const QPixmap &); // Send an image to be displayed
private:
    gameText text; // Make an object for the text
    player newPlayer; // Make an object for player
    gameImages images; // Make an object for the game images
    int gameState; // Int to track game state
    int textState; // Int to track text state
    QString playerName; // QString for the player name
    QString playerClass; // QString for the player class
    QQueue<QString> userInput; // QQueue for the user input (in case we move to a game loop)
    void handleMainMenu(const QString &); // Function to handle the main menu
    void handleNewGameNaming(const QString &); // Function to handle the naming part of a new game
    void handleNewGameClass(const QString &); // Function to handle the class part of a new game & make player
    void handleConfirmingNameAndClass(const QString &); // Function to handle confirmation
    void handleNewGamePart1(); // Function to clear the screen and advance the game
};

#endif // GAME_H
