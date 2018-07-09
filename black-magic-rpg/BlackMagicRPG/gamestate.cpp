#include "gamestate.h"

gameState::gameState()
{
    mainMenuState = true;
    newGameState = false;
    characterNamingState = false;
    chapter1State = false;
}

bool gameState::getCharacterClassState() const
{
    return characterClassState;
}

void gameState::setCharacterClassState(bool value)
{
    characterClassState = value;
}

bool gameState::getMainMenuState() const
{
    return mainMenuState;
}

void gameState::setMainMenuState(bool value)
{
    mainMenuState = value;
}

bool gameState::getNewGameState() const
{
    return newGameState;
}

void gameState::setNewGameState(bool value)
{
    newGameState = value;
}

bool gameState::getChapter1State() const
{
    return chapter1State;
}

void gameState::setChapter1State(bool value)
{
    chapter1State = value;
}

bool gameState::getCharacterNamingState() const
{
    return characterNamingState;
}

void gameState::setCharacterNamingState(bool value)
{
    characterNamingState = value;
}
