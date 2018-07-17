#ifndef TEXT_H
#define TEXT_H
#include <QString>
#include <QList>
#include <QTextStream>

class gameText
{
public:
    gameText();
    ~gameText();
    QString getMainMenuText() const;
    QString getGame(int line) const;
    QString getMap(int line) const;

private:
    void initialize();
    QString mainMenuText; // Private QString to store the main menu text
    QList<QString> game; // Private QList to store chapter text <chapter1, chapter2, ..>
    QList<QString> map; // Private QList to store map text <Area1, Area1Description, Area2, ..>
    void readMainMenu();
    void readGameText();
};

#endif // TEXT_H
