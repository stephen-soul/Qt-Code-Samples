#ifndef IMAGES_H
#define IMAGES_H
#include <QPixmap>

class images
{
public:
    images();
    QPixmap getLogo() const;

    QPixmap getMainCity() const;

private:
    QPixmap logo;
    QPixmap mainCity;
};

#endif // IMAGES_H
