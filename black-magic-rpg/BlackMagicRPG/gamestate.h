#ifndef GAMESTATE_H
#define GAMESTATE_H


class gameState
{
public:
    gameState();

    bool getCharacterClassState() const;
    void setCharacterClassState(bool value);

    bool getMainMenuState() const;
    void setMainMenuState(bool value);

    bool getNewGameState() const;
    void setNewGameState(bool value);

    bool getChapter1State() const;
    void setChapter1State(bool value);

    bool getCharacterNamingState() const;
    void setCharacterNamingState(bool value);

private:
    bool mainMenuState;
    bool newGameState;
    bool chapter1State;
    bool characterNamingState;
    bool characterClassState;
};

#endif // GAMESTATE_H
