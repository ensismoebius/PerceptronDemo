#include <ctime>
#include <random>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "lib/map.h"
#include "lib/Point.h"
#include "lib/functions.h"
#include "lib/Perceptron.h"
#include "lib/PointsDrawer.h"

const float WINDOW_WIDTH = 800;
const float WINDOW_HEIGHT = 800;

void createLine(sf::Vertex *line, std::vector<float> &weights, sf::RenderWindow &window)
{
    float x1 = -1;
    float x2 = 1;

    float y1 = -(weights[1] / weights[2]) * x1 - (weights[0] / weights[2]);
    float y2 = -(weights[1] / weights[2]) * x2 - (weights[0] / weights[2]);

    x1 = mapOneRangeToAnother(x1, -1, 1, 0, window.getSize().x, 5);
    x2 = mapOneRangeToAnother(x2, -1, 1, 0, window.getSize().x, 5);

    y1 = mapOneRangeToAnother(y1, -1, 1, window.getSize().y, 0, 5);
    y2 = mapOneRangeToAnother(y2, -1, 1, window.getSize().y, 0, 5);

    line[0].position.x = x1;
    line[0].position.y = y1;
    line[0].color = sf::Color::Black;

    line[1].position.x = x2;
    line[1].position.y = y2;
    line[1].color = sf::Color::Black;
}

int main(int argc, char const *argv[])
{

    /////////////////////////////
    // Window creation - BEGIN //
    /////////////////////////////

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    int32_t windowStyle = sf::Style::Default;

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Neural Network - float", windowStyle, settings);
    window.setFramerateLimit(24);

    // Puts the orign at the center
    sf::Vector2u size = window.getSize();
    sf::View view(sf::Vector2f(size.x / 2, size.y / 2), sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    window.setView(view);

    ///////////////////////////
    // Window creation - END //
    ///////////////////////////

    // Ensuring that the random numbers are going to honor its names
    std::srand(std::time(nullptr));

    // Percepetron and the data to be classified
    Neural::Perceptron p(2);
    std::vector<Point> points(5000);

    // Draw a line defined by the function f(x)
    float x1 = -1;
    float y1 = f(x1);

    float x2 = 1;
    float y2 = f(x2);

    x1 = mapOneRangeToAnother(x1, -1, 1, 0, window.getSize().x, 5);
    y1 = mapOneRangeToAnother(y1, -1, 1, window.getSize().y, 0, 5);

    x2 = mapOneRangeToAnother(x2, -1, 1, 0, window.getSize().x, 5);
    y2 = mapOneRangeToAnother(y2, -1, 1, window.getSize().y, 0, 5);

    sf::Vertex line[] = {sf::Vertex(sf::Vector2f(x1, y1)), sf::Vertex(sf::Vector2f(x2, y2))};

    sf::Vertex line2[2];
    createLine(line2, p.weights, window);

    // Draw the points
    PointsDrawer pd(points, window);

    // Mouse pressed flag used to detect ther mouse click event
    bool mp = false;

    // Aplication main loop
    while (window.isOpen())
    {

        // Perceptron tranning
        for (auto &&pt : points)
        {
            p.train({pt.x, pt.y}, pt.label);
        }

        // Mouse clicked event
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !mp)
        {
            std::cout << "Mouse clicked!" << std::endl;
            mp = true;
        }
        if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            mp = false;
        }

        // Window and keyboard events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q)
                window.close();
        }

        // Drawing the data
        window.clear(sf::Color::Magenta);
        pd.drawPoints(points, window, p);
        window.draw(line, 2, sf::Lines);
        createLine(line2, p.weights, window);
        window.draw(line2, 2, sf::Lines);
        window.display();
    }

    return 0;
}
