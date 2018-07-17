#ifndef GAME_H
#define GAME_H
#include "gameimages.h"
#include "gameText.h"
#include "player.h"
#include <QApplication>
#include <QTimer>
#include <QWidget>
#include <QQueue>

enum gameState {
    STATE_MAINMENU,
    STATE_NEWGAME_GETNAME,
    STATE_NEWGAME_GETCLASS,
    STATE_CHAPTER1_PROCESS_ENTER,
    STATE_CHAPTER1_PART1,
    STATE_GAMEOVER
};

enum gameTextState {
    STATE_NEWGAME_TEXT,
    STATE_NEWGAME_GETNAME_1_TEXT,
    STATE_NEWGAME_GETNAME_2_TEXT,
    STATE_NEWGAME_GETCLASS_WARRIOR,
    STATE_NEWGAME_GETCLASS_MAGE,
    STATE_NEWGAME_GETCLASS_ROGUE,
    STATE_NEWGAME_CHAPTER1_S
};

class game : public QObject
{
    Q_OBJECT
public:
    explicit game(QObject *parent = nullptr);
    virtual ~game();
    void initializeGame();
    bool getRunning() const; // Getter for the game state
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
    int state; // Int to track game state
    int textState; // Int to track text state
    void incrementGameAndText(); // Function to increment the state
    // Make a value for the player name
    QString playerName;
    // Functions for handling different things
    void handleMainMenu(const QString &); // Handle the main menu
    void handleNewGameNaming(const QString &); // Handle the naming part of a new game
    void handleNewGameClass(const QString &); // Handle the class part of a new game & make player
    void handleNewGamePart1(); // Clear the screen and advance the game
    gameImages images;
    bool running; // Bool for the game loop to run on
    QQueue<QString> userInput;
};

#endif // GAME_H
