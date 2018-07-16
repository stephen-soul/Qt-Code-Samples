#include "gameimages.h"

gameImages::gameImages() {
    mainMenuLogo.load(":/images/logoConverted.png"); // Main screen logo
    newGameImage.load(":/images/city.png"); // Set the path for the city image in resources
}

QPixmap gameImages::getMainMenuLogo() const
{
    return mainMenuLogo;
}

QPixmap gameImages::getNewGameImage() const
{
    return newGameImage;
}
