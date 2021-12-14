#include <iostream>
#include <vector>
#include <string>

#include <SFML/Graphics.hpp>
#include "Fps.hpp"
#include "UIRenderer.hpp"

using std::cout;
using std::endl;
using std::vector;
using sf::Color;

int main() {
    cout << "Program Start.." << endl;

    const int screenWidth = 1600, screenHeight = 1000;

    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Smoke Simulation");
    window.setFramerateLimit(144);

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    Fps fps;
    sf::Font font;
    // if (!font.loadFromFile("assets/font/CourierPrime-Regular.ttf")) {
    if (!font.loadFromFile("assets/font/Roboto-Regular.ttf")) {
        std::cerr << "Failed to load Roboto Regular font" << std::endl;
    }

    UIRenderer UIR = UIRenderer(font, 15, Color::White, window);

    // Game Loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        fps.update();
        UIR.updateFPS(std::to_string(fps.getFps()));
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        UIR.updateMouseCoord(mousePos.x, mousePos.y);





        window.clear(Color::Black);
        UIR.renderUI(window);
        window.display();
    }

    cout << "..Finished" << endl;
    return EXIT_SUCCESS;
}