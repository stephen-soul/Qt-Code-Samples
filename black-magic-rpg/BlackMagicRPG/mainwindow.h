#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "storytext.h"
#include "gamemessages.h"
#include "gamestate.h"
#include "newgame.h"
#include <QMainWindow>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QPixmap>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_input_returnPressed();

private:
    Ui::MainWindow *ui;
    // Make variables to make ui elements easier to work with
    QLineEdit *input;
    QTextEdit *console;
    QLabel *enemiesPic;
    QLabel *gamePic;
    // Make an object for game messages
    gameMessages game;
    // Make an object for the story text
    storyText story;
    // Make an object to track game state
    gameState state;
    // Make an object for the new game text
    NewGame newGame;
    // Make a function to handle the different events
    void handleMainMenuInput(QString typedInput);
};

#endif // MAINWINDOW_H
