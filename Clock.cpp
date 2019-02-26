#include "Clock.hpp"
#include <time.h>
#include <iostream>
//empty constr
Clock::Clock()
{
    current_time = (long int)time(0);
    difference_time = 0;
}

//returns the current_time
long int Clock::getTime()
{
    return this->current_time;
}

//Update the current_time var of Clock class.
bool Clock::updateTime()
{
    time(&current_time);
}

/*Will calculate time difference since last call of this function, and store it into
Clock::difference_time which is a private of Clock class.*/
bool Clock::calcTimeDiff()
{

    long int old = getTime();
    long int temp = (long int) time(NULL);
    difference_time = temp - old;
    //std::cout << "time dif_calc = " << difference_time<<std::endl;

}

//Will return time difference
long int Clock::getTimeDiff()
{
    return this->difference_time;
}
