#include "PointsDrawer.h"
#include "Perceptron.h"
#include "map.h"

PointsDrawer::PointsDrawer(std::vector<Point> &points, sf::RenderWindow &window)
{
    circles.resize(points.size());

    for (unsigned int i = 0; i < points.size(); i++)
    {
        circles[i] = sf::CircleShape(3, 10);
    }
}

void PointsDrawer::drawPoints(std::vector<Point> &points, sf::RenderWindow &window, Neural::Perceptron &p)
{
    for (unsigned int i = 0; i < points.size(); i++)
    {
        float px = mapOneRangeToAnother(points[i].x, -1, 1, 0, window.getSize().x, 5);
        float py = mapOneRangeToAnother(points[i].y, -1, 1, window.getSize().y, 0, 5);

        circles[i].setPosition(px, py);
        circles[i].setOutlineThickness(1);
        circles[i].setOutlineColor(points[i].label == 1 ? sf::Color::Black : sf::Color::Green);
        circles[i].setFillColor(p.guess({points[i].x, points[i].y}) == points[i].label ? sf::Color(0, 125, 0) : sf::Color::Red);
        window.draw(circles[i]);
    }
}
