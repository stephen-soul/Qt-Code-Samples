#ifndef GAMEMESSAGES_H
#define GAMEMESSAGES_H
#include <QString>

class gameMessages
{
public:
    gameMessages();
    QString getMainMenu();
private:
    QString mainMenu = "Welcome to Black Magic RPG. Please answer the "
                       "following with the number beside it, or the "
                       "actual text.\n(1) New Game\n(2) Load Game\n(3) Exit";
};

#endif // GAMEMESSAGES_H
