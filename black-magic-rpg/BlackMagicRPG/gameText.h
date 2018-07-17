#ifndef TEXT_H
#define TEXT_H
#include <QString>
#include <QList>
#include <QTextStream>
#include <QMap>

class gameText
{
public:
    gameText();
    ~gameText();
    QString getMainMenuText() const;
    QString getGame(int line) const;
    QString getMap(QString line) const;

private:
    void initialize();
    QString mainMenuText; // Private QString to store the main menu text
    QList<QString> game; // Private QList to store chapter text <chapter1, chapter2, ..>
    QMap<QString, QString> map; // Private QMap to store map text <Area1, Area1Description, Area2, ..>
    void readMainMenu();
    void readGameText();
    void readMapText();
};

#endif // TEXT_H
