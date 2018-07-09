#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    // Set a fixed size for the ui
    this->setFixedSize(QSize(640,480));
    // Initialize variables for ui elements
    input = ui->input;
    console = ui->consoleScreen;
    enemiesPic = ui->enemyPic;
    gamePic = ui->gameStatePic;
    // Set the paths for the images
    QPixmap logo (":/images/logoConverted.png");
    // Set the main game logo on game start (From resources)
    gamePic->setPixmap(logo);
    // Set the default main menu text at start up
    console->append(game.getMainMenu());
}

MainWindow::~MainWindow() {
    delete ui;
}

// When enter is hit, check the state of the game and go from there
void MainWindow::on_input_returnPressed() {
    // Handle the typed input and make it lowercase to compare it
    QString typedInput = input->text().toLower();
    // If we're on the main menu, pass the input to the main menu handler
    if (state.getMainMenuState()) {
        handleMainMenuInput(typedInput);
    }
    // Else if we're directly after a new game making a character
    else if (state.getCharacterNamingState()) {

    }
    // Clear the input line after something is typed
    input->clear();
}

// Function for the main menu input
void MainWindow::handleMainMenuInput(QString typedInput) {
    if (typedInput == "1" || typedInput == "new game" || typedInput == "new") {
        // Start the game
        state.setMainMenuState(false); // We're no longer in the main menu
        console->clear(); // Clear the console since we changed screens
        QPixmap mainCity (":/images/city.png"); // Set the path for the city image in resources
        gamePic->setPixmap(mainCity); // Change the game pic to a city
        console->append(newGame.returnIntro()); // Output the intro and ask the user for their name
        state.setCharacterNamingState(true);
    } else if (typedInput == "2" || typedInput == "load") {
        // Load the game
        console->append("This is still in development!");
    } else if (typedInput == "3" || typedInput == "exit") {
        // Exit
        QApplication::quit();
    } else {
        console->append("That entry doesn't match the options available.");
    }
}
