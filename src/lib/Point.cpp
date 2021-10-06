#include "Point.h"
#include "random.h"

Point::Point(float x, float y)
{
    this->x = x;
    this->y = y;

    if (this->x > this->y)
    {
        this->label = 1;
    }
    else
    {
        this->label = -1;
    }
}

Point::Point()
{
    this->x = utils::random();
    this->y = utils::random();

    if (this->x > this->y)
    {
        this->label = 1;
    }
    else
    {
        this->label = -1;
    }
}

Point::~Point()
{
}
