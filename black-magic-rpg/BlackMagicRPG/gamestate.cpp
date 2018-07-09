#include "gamestate.h"

gameState::gameState()
{
    mainMenuState = true;
    newGameState = false;
    characterNamingState = false;
    chapter1State = false;
}

void gameState::changeMainMenuState() {
    if (mainMenuState)
        mainMenuState = false;
    else
        mainMenuState = true;
}

bool gameState::getMainMenuState() {
    return mainMenuState;
}

void gameState::changeCharacterNamingState() {
    if(characterNamingState)
        characterNamingState = false;
    else
        characterNamingState = true;
}

bool gameState::getCharacterNamingState() {
    return characterNamingState;
}

void gameState::changeNewGameState() {
    if(newGameState)
        newGameState = false;
    else
        newGameState = true;
}

bool gameState::getNewGameState() {
    return newGameState;
}

void gameState::changeChapter1State() {
    if (chapter1State)
        chapter1State = false;
    else
        chapter1State = true;
}

bool gameState::getChapter1State() {
    return chapter1State;
}

bool gameState::getCharacterClassState() const
{
    return characterClassState;
}

void gameState::setCharacterClassState(bool value)
{
    characterClassState = value;
}
