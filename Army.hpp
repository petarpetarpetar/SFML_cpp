#ifndef ARMY_HPP_INCLUDED
#define ARMY_HPP_INCLUDED

class Army
{
private:
    int numSpearmen;
    int numSwordsmen;
    int numArchers;
    int numHorsemen;

    int strenght;


public:
    int getNumSpear();
    int getNumSword();
    int getNumArcher();
    int getNumHorse();
    int getStrenght();

    bool addSpear();
    bool killSpear();
    bool killAllSpear();

    bool addSword();
    bool killSword();
    bool killAllSword();

    bool addArch();
    bool killArch();
    bool killAllArch();

    bool addHorse();
    bool killHorse();
    bool killAllHorse();

};

#endif // ARMY_HPP_INCLUDED
