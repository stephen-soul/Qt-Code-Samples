#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "game.h"

#include <QMainWindow>
#include <QFontDatabase>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void keyPressEvent(QKeyEvent *event); // Handle the main menu input
signals:
    void sendInput(const QString &); // Signal for sending input
private slots:
    void on_input_returnPressed(); // This slot handles enter being pressed
    void appendToConsole(QString gameText); // This slot appends to console
    void changeImage(QPixmap image); // This slot changes the current image
private:
    Ui::MainWindow *ui;
    bool startSelected; // Bool to handle main menu placement
    bool gameStarted;
};

#endif // MAINWINDOW_H
