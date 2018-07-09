#ifndef GAMESTATE_H
#define GAMESTATE_H


class gameState
{
public:
    gameState();
    void changeMainMenuState();
    bool getMainMenuState();
    void changeNewGameState();
    bool getNewGameState();
    void changeCharacterNamingState();
    bool getCharacterNamingState();
    void changeChapter1State();
    bool getChapter1State();
    bool getCharacterClassState() const;
    void setCharacterClassState(bool value);

private:
    bool mainMenuState;
    bool newGameState;
    bool chapter1State;
    bool characterNamingState;
    bool characterClassState;
};

#endif // GAMESTATE_H
