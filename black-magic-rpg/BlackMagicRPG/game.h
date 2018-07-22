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
    bool getRunning() const; // Getter for the game state
    void progressMainMenu(const QString &);
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
    // Make an object for the text
    gameText text;
    // Make an object for player
    player newPlayer;
    int gameState; // Int to track game state
    int textState; // Int to track text state
    void incrementGameAndText(); // Function to increment the state
    // Make a value for the player name and class
    QString playerName;
    QString playerClass;
    // Functions for handling different things
    void handleMainMenu(const QString &); // Handle the main menu
    void handleNewGameNaming(const QString &); // Handle the naming part of a new game
    void handleNewGameClass(const QString &); // Handle the class part of a new game & make player
    void handleConfirmingNameAndClass(const QString &); // Handle confirmation
    void handleNewGamePart1(); // Clear the screen and advance the game
    gameImages images;
    bool running; // Bool for the game loop to run on
    QQueue<QString> userInput;
};

#endif // GAME_H
