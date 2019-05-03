#ifndef COORDS_HPP_INCLUDED
#define COORDS_HPP_INCLUDED

class Coords
{
private:
    int x;
    int y;

public:
    Coords();
    int getX();
    int getY();
    bool setX(int newX);
    bool setY(int newY);

};


#endif // COORDS_HPP_INCLUDED
