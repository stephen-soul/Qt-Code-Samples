#ifndef GAME_H
#define GAME_H
#include <QString>
#include <QTimer>
#include <QWidget>

class game : public QWidget
{
    Q_OBJECT
public:
    explicit game(QWidget *parent = nullptr);
    virtual ~game();
signals:
    void sendParsedInput(const QString &); // Signal to send input
public slots:
    void acceptInput(const QString &); // Get input from gui
private slots:
    void returnInput(const QString &); // Send the input to the gui
private:
    int state;
    void handleMainMenu(const QString &);
};

#endif // GAME_H
