#ifndef MAP_H
#define MAP_H
#include <QStringList>
#include <QVector>
#include <QTextStream>

class Map {

public:
    Map();
private:
    int width;
    int height;
    QVector< QVector<QString> > blackRock;
    void readMapIntoVector();
};

#endif // MAP_H
