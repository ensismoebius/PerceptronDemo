/**
 * @author André Furlan
 * @email ensismoebius@gmail.com
 * This whole project are under GPLv3, for
 * more information read the license file
 *
 * @date 2021-10-05
*/

#ifndef src_lib_PointsDrawer_h
#define src_lib_PointsDrawer_h

#include <vector>
#include <SFML/Graphics.hpp>

#include "Point.h"
#include "Perceptron.h"

class PointsDrawer
{
private:
    std::vector<sf::CircleShape> circles;

public:
    PointsDrawer(std::vector<Point> &points, sf::RenderWindow &window);
    void drawPoints(std::vector<Point> &points, sf::RenderWindow &window, Neural::Perceptron &p);
    ~PointsDrawer();
};

#endif