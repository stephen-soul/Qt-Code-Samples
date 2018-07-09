#ifndef NEWGAME_H
#define NEWGAME_H
#include <QString>

class NewGame
{
public:
    NewGame();
    QString returnIntro();
private:
    QString intro = "It's the year 856. Humans desire for greed throughout "
                    "time is the reason most of the world is corrupted. "
                    "After all, evil drives more evil... The fighting is "
                    "mostly between the royalty and the religion, but I'm "
                    "sure you will learn more about this when the time "
                    "comes. So anyway... Who are you?";
};

#endif // NEWGAME_H
