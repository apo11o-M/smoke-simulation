#include <iostream>
#include <vector>
#include <string>

#include <SFML/Graphics.hpp>
#include "Fps.hpp"
#include "UIRenderer.hpp"
#include "Smoke.hpp"
#include "SmokeGroup.hpp"

using std::cout;
using std::endl;
using std::vector;
using sf::Color;

int main() {
    cout << "Program Start.." << endl;

    const int screenWidth = 1600, screenHeight = 1000;
    bool leftMouseDown = false;
    int spawnPosX = 130;
    int spawnPosY = 500;

    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Smoke Simulation");
    window.setFramerateLimit(144);

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    Fps fps;
    sf::Font font;
    if (!font.loadFromFile("assets/font/Roboto-Regular.ttf")) {
        std::cerr << "Failed to load Roboto Regular font" << std::endl;
    }
    UIRenderer UIR = UIRenderer(font, 15, Color::White, window);

    sf::Texture smokeTexture;
    if (!smokeTexture.loadFromFile("assets/textures/smoke.png")) {
// if (!smokeTexture.loadFromFile("assets/textures/white.png")) {
        std::cerr << "Failed to load image \"smoke.png\"" << std::endl;
    }
    
    SmokeGroup smokeGroup;

    Sprite spawnSq;
    spawnSq.setTexture(smokeTexture);
    spawnSq.setOrigin(smokeTexture.getSize().x / 2, smokeTexture.getSize().y / 2);
    spawnSq.setPosition(spawnPosX, spawnPosY);
    spawnSq.setScale(0.15, 0.15);
    spawnSq.setColor(Color(255, 255, 255, 64));

    // Game Loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case (sf::Event::Closed):
                window.close();
                break;
            case (sf::Event::MouseButtonPressed):
                if (event.mouseButton.button == sf::Mouse::Left) {
                    leftMouseDown = true;
                }
                break;
            case (sf::Event::MouseButtonReleased):
                if (event.mouseButton.button == sf::Mouse::Left) {
                    leftMouseDown = false;
                }
                break;
            default:
                break;
            }
        }
        mousePos = sf::Mouse::getPosition(window);
        fps.update();
        UIR.updateFPS(std::to_string(fps.getFps()));
        UIR.updateMouseCoord(mousePos.x, mousePos.y);
        UIR.updateSmokeGroup(smokeGroup);

        if (leftMouseDown) {
            smokeGroup.addSmoke(new Smoke(smokeTexture, spawnPosX, spawnPosY, mousePos));
        }
        smokeGroup.updateSmoke();


        window.clear(Color::Black);
        UIR.renderUI(window);
        if (leftMouseDown) { window.draw(spawnSq); }
        smokeGroup.renderSmoke(window);
        window.display();
    }

    cout << "..Finished" << endl;
    return EXIT_SUCCESS;
}