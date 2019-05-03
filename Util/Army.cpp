#include "Army.hpp"
int Army::getNumSpear()
{
    return this->numSpearmen;
}

int Army::getNumSword()
{
    return this->numSwordsmen;
}

int Army::getNumArcher()
{
    return this->numArchers;
}

int Army::getNumHorse()
{
    return this->numHorsemen;
}

int Army::getStrenght()
{
    return this->strenght;
}

bool Army::addSpear()
{
    this->numSpearmen++;
}

bool Army::killSpear()
{
    this->numSpearmen--;
}

bool Army::killAllSpear()
{
    this->numSpearmen = 0;
}

bool Army::addSword()
{
    this->numSwordsmen++;
}

bool Army::killSword()
{
    this->numSwordsmen--;
}

bool Army::killAllSword()
{
    this->numSwordsmen = 0;
}

bool Army::addArch()
{
    this->numArchers++;
}

bool Army::killArch()
{
    this->numArchers--;
}

bool Army::killAllArch()
{
    this->numArchers = 0;
}

bool Army::addHorse()
{
    this->numHorsemen++;
}

bool Army::killHorse()
{
    this->numHorsemen--;
}

bool Army::killAllHorse()
{


    this->numHorsemen =0;
}
