#include "UIRenderer.hpp"

UIRenderer::UIRenderer(Font& font, int size, sf::Color color, sf::RenderWindow& w) : window(w) {
    createFpsText(font, size, color, 30, 30);
    createMouseCoordText(font, size, color, 30, 30 + size + 5);
    screenWidth = w.getSize().x;
    screenHeight = w.getSize().y;
}

void UIRenderer::updateFPS(string str) {
    fpsText.setString("Fps: " + str);
}

void UIRenderer::updateMouseCoord(int x, int y) {
    mouseCoordTextX.setString("X: " + std::to_string(std::clamp(x, 0, screenWidth)));
    mouseCoordTextY.setString("Y: " + std::to_string(std::clamp(screenHeight - y, 0, screenHeight)));

}

void UIRenderer::renderUI(sf::RenderWindow& window) {
    window.draw(fpsText);
    window.draw(mouseCoordTextX);
    window.draw(mouseCoordTextY);
}

void UIRenderer::createFpsText(Font& f, int s, sf::Color c, int x, int y) {
    fpsText.setString("Fps: ");
    fpsText.setFont(f);
    fpsText.setCharacterSize(s);
    fpsText.setFillColor(c);
    fpsText.setPosition(x, y);
}

void UIRenderer::createMouseCoordText(Font& f, int s, sf::Color c, int x, int y) {
    mouseCoordTextX.setString("X: ");
    mouseCoordTextX.setFont(f);
    mouseCoordTextX.setCharacterSize(s);
    mouseCoordTextX.setColor(c);
    mouseCoordTextX.setPosition(x, y);

    mouseCoordTextY.setString("Y: ");
    mouseCoordTextY.setFont(f);
    mouseCoordTextY.setCharacterSize(s);
    mouseCoordTextY.setColor(c);
    mouseCoordTextY.setPosition(x, y + s + 5);
}