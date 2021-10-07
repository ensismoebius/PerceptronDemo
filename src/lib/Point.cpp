#include "Point.h"
#include "random.h"
#include "functions.h"

Point::Point(float x, float y)
{
    this->x = x;
    this->y = y;

    if (this->y > f(this->x))
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

    if (this->y > f(this->x))
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
