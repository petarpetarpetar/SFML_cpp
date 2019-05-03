#ifndef EVENTHANDLER_HPP_INCLUDED
#define EVENTHANDLER_HPP_INCLUDED
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Game.hpp"
class eventHandler
{
    //handle player inputs such as mouse movement and clicks

public:
    //handle game events
    eventHandler();
    ~eventHandler();
    void handle(sf::Event event, sf::RenderWindow& window,sf::Sprite sprites[10][2][10],Game g);

};


#endif // EVENTHANDLER_HPP_INCLUDED
