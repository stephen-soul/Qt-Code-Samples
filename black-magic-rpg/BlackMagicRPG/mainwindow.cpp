#include "mainwindow.h"
#include "ui_mainwindow.h"

// Constructor
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    // Remove resizability
    setFixedSize(QSize(640,480));
    setWindowFlags(Qt::WindowMinimizeButtonHint
            | Qt::WindowCloseButtonHint
            | Qt::CustomizeWindowHint);
    // Declare the new game logic for connecting signals and slots
    game *gameLogic = new game();
    // Handle connecting the input and console to the game logic class
    connect(this, &MainWindow::sendInput, gameLogic, &game::acceptInput);
    connect(gameLogic, &game::sendParsedInput, this, &MainWindow::appendToConsole);
    connect(gameLogic, &game::sendImage, this, &MainWindow::changeImage);
    // Set the 'console' to hide on startup
    ui->consoleScreen->hide();
    ui->input->hide();
    ui->chevronLineEdit->hide();
    // Set the fonts to variables
    QFontDatabase::addApplicationFont(":/font/:/font/ShareTechMono-Regular.ttf");
    QFont gameFont = QFont("Share Tech Mono", 11, 1);
    // Apply the font to the console and input
    ui->consoleScreen->setFont(gameFont);
    ui->input->setFont(gameFont);
    // Colour the 'start' to show that it's selected
    ui->startLabel->setStyleSheet("QLabel { color: yellow; font: 22pt 'Share Tech Mono'; }");
    ui->exitLabel->setStyleSheet("QLabel { color: white; font: 22pt 'Share Tech Mono'; }");
    // Default the selection to start
    startSelected = true;
    // Initialize on game logic
    gameLogic->initializeGame();
}

// Destructor
MainWindow::~MainWindow() {
    delete ui;
}

// This slot handles enter being pressed
void MainWindow::on_input_returnPressed() {
    // Make the lowercase text
    emit sendInput(ui->input->text());
    ui->input->clear();
}

// This slot handles appending text to the screen based on what's typed
void MainWindow::appendToConsole(QString text) {
    if(text == "clear")
        ui->consoleScreen->clear();
    else
        ui->consoleScreen->append(text);
}

void MainWindow::changeImage(QPixmap image) {
    ui->gameStatePic->setPixmap(image);
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    switch(event->key()) {
    case Qt::Key_W:
    case Qt::Key_Up:
        if(!startSelected) {
            startSelected = true;
            ui->startLabel->setStyleSheet("QLabel { color: yellow; font: 22pt 'Share Tech Mono'; }");
            ui->exitLabel->setStyleSheet("QLabel { color: white; font: 22pt 'Share Tech Mono'; }");
        }
        break;
    case Qt::Key_S:
    case Qt::Key_Down:
        if(startSelected) {
            startSelected = false;
            ui->startLabel->setStyleSheet("QLabel { color: white; font: 22pt 'Share Tech Mono'; }");
            ui->exitLabel->setStyleSheet("QLabel { color: yellow; font: 22pt 'Share Tech Mono'; }");
        }
        break;
    case Qt::Key_Enter:
    case Qt::Key_Return:
        if(startSelected) {
            ui->input->setText("1");
            on_input_returnPressed();
            ui->startLabel->hide();
            ui->exitLabel->hide();
            ui->consoleScreen->show();
            ui->input->show();
            ui->chevronLineEdit->show();
            // Focus the input
            ui->input->setFocus();
        }
        else {
            ui->input->setText("2");
            on_input_returnPressed();
            ui->startLabel->hide();
            ui->exitLabel->hide();
            ui->consoleScreen->show();
            ui->input->show();
            ui->chevronLineEdit->show();
        }
        break;
    default:
        break;
    }
}
