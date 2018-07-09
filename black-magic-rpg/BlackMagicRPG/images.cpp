#include "images.h"

images::images()
{
    // Set the paths for the images
    logo.load(":/images/logoConverted.png"); // Main screen logo
    mainCity.load(":/images/city.png"); // Set the path for the city image in resources
}

QPixmap images::getLogo() const
{
    return logo;
}

QPixmap images::getMainCity() const
{
    return mainCity;
}
