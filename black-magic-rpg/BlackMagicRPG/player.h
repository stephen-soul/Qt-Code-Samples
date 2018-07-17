#ifndef PLAYER_H
#define PLAYER_H
#include <QString>

class player {
public:
    player();
    player(int HP, int maxHP, int MP, int maxMP, QString name, QString role, int str, int dex, int magic, int defence, int luck);
    int getHP() const;
    void setHP(int value);
    int getMaxHP() const;
    void setMaxHP(int value);
    int getMp() const;
    void setMp(int value);
    int getMaxMP() const;
    void setMaxMP(int value);
    QString getName() const;
    void setName(const QString &value);
    QString getRole() const;
    void setRole(const QString &value);
    int getStr() const;
    void setStr(int value);
    int getDex() const;
    void setDex(int value);
    int getMagic() const;
    void setMagic(int value);
    int getDefence() const;
    void setDefence(int value);
    int getLuck() const;
    void setLuck(int value);

private:
    int HP;
    int maxHP;
    int mp;
    int maxMP;
    QString name;
    QString role;
    int str;
    int dex;
    int magic;
    int defence;
    int luck;
};

#endif // PLAYER_H
