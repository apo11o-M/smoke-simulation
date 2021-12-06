#include <iostream>
#include <vector>
#include <string>

#include <SFML/Graphics.hpp>
#include "Fps.hpp"

using std::cout;
using std::endl;
using std::vector;
using sf::Color;

int main() {
    cout << "Program Start.." << endl;

    const int screenWidth = 1000, screenHeight = 800;

    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Smoke Simulation");
    window.setFramerateLimit(144);

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    Fps fps;
    sf::Font font;
    // if (!font.loadFromFile("assets/font/CourierPrime-Regular.ttf")) {
    if (!font.loadFromFile("assets/font/Roboto-Regular.ttf")) {
        std::cerr << "Failed to load Courier font" << std::endl;
    }

    sf::Text fpsText;
    fpsText.setFont(font);
    fpsText.setCharacterSize(20);
    fpsText.setFillColor(Color::White);
    fpsText.setPosition(screenWidth - 120, 40);
    
    // Game Loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        fps.update();
        fpsText.setString("Fps: " + std::to_string(fps.getFps()));



        window.clear(Color::Black);
        window.draw(fpsText);
        window.display();
    }

    cout << "..Finished" << endl;
    return EXIT_SUCCESS;
}