#ifndef CLOCK_HPP_INCLUDED
#define CLOCK_HPP_INCLUDED
#include <time.h>
class Clock
{
private:
    long int current_time;
    long int difference_time;

public:
    long int getTime();
    long int getTimeDiff();
    bool calcTimeDiff();
    bool updateTime();
    Clock();

};

#endif // CLOCK_HPP_INCLUDED
