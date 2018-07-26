#include "player.h"

player::player() {
    gold = 0;
}

player::player(int playerHP, int playerMaxHP, int playerMP, int playerMaxMP, QString playerName, QString playerRole, int playerStr, int playerDex, int playerMagic, int playerDefence, int playerLuck, int playerGold) {
    HP = playerHP;
    maxHP = playerMaxHP;
    mp = playerMP;
    maxMP = playerMaxMP;
    name = playerName;
    role = playerRole;
    str = playerStr;
    dex = playerDex;
    magic = playerMagic;
    defence = playerDefence;
    luck = playerLuck;
    gold = playerGold;
}

int player::getHP() const
{
    return HP;
}

void player::setHP(int value)
{
    HP = value;
}

int player::getMaxHP() const
{
    return maxHP;
}

void player::setMaxHP(int value)
{
    maxHP = value;
}

QString player::getName() const
{
    return name;
}

void player::setName(const QString &value)
{
    name = value;
}

QString player::getRole() const
{
    return role;
}

void player::setRole(const QString &value)
{
    role = value;
}

int player::getStr() const
{
    return str;
}

void player::setStr(int value)
{
    str = value;
}

int player::getDex() const
{
    return dex;
}

void player::setDex(int value)
{
    dex = value;
}

int player::getMagic() const
{
    return magic;
}

void player::setMagic(int value)
{
    magic = value;
}

int player::getDefence() const
{
    return defence;
}

void player::setDefence(int value)
{
    defence = value;
}

int player::getLuck() const
{
    return luck;
}

void player::setLuck(int value)
{
    luck = value;
}

int player::getGold() const
{
    return gold;
}

void player::setGold(int value)
{
    gold = value;
}

void player::addGold(int value)
{
    gold += value;
}

void player::removeGold(int value)
{
    gold -= value;
}

int player::getMp() const
{
    return mp;
}

void player::setMp(int value)
{
    mp = value;
}

int player::getMaxMP() const
{
    return maxMP;
}

void player::setMaxMP(int value)
{
    maxMP = value;
}
