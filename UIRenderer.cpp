#include "UIRenderer.hpp"

UIRenderer::UIRenderer() {
    sf::Font f;
    if (!f.loadFromFile("assets/font/Roboto-Regular.ttf")) {
        std::cerr << "Failed to load Courier font" << std::endl;
    }
    font = f;
    size = 20;
    color = sf::Color::White;
}

UIRenderer::UIRenderer(Font defaultFont, int defaultSize, sf::Color defaultColor) {
    font = defaultFont;
    size = defaultSize;
    color = defaultColor;
}