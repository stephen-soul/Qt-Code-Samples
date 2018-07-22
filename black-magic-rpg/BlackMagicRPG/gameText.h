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
    QString getGameText(int line) const;
    QString getMap(QString line) const;
    QString getMapText(int line) const;
    void appendNameToGameText(const QString &);
    void resetNameInGameText(const QString &);
    void appendClassToGameText(const QString &);
    void resetClassInGameText(const QString &);
private:
    QString mainMenuText; // Private QString to store the main menu text
    QList<QString> game; // Private QList to store chapter text <chapter1, chapter2, ..>
    QMap<QString, QString> map; // Private QMap to store map text <Area1, Area1Description, Area2, ..>
    QList<QString> mapText;
    void initialize(); // Initialize the lists and maps
    void readMainMenu(); // Read the main menu from resources and dump it into mainMenuText
    void readGameText(); // Read the game text and dump it into the game QList
    void readMapText(); // Read the map text and dump it into the QMap
};

#endif // TEXT_H
