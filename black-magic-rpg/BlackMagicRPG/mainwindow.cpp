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
    // Set the logo path
    QPixmap logo (":/images/logoConverted.png");
    // Set the main game logo on game start (From resources)
    gamePic->setPixmap(logo);
    // Set the default main menu text at start up
    console->append(game.getMainMenu());
}

MainWindow::~MainWindow() {
    delete ui;
}
