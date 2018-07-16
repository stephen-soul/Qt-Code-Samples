#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "game.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void sendInput(const QString &); // Signal for sending input
private slots:
    void on_input_returnPressed(); // This slot handles enter being pressed
    void appendToConsole(QString text); // This slot appends to console
    void changeImage(QPixmap image); // This slot changes the current image
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
