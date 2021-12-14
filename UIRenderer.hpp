#ifndef __UIRENDERER_HPP__
#define __UIRENDERER_HPP__

#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

using std::vector;
using sf::Text;
using sf::Font;
using std::string;
using std::cout;
using std::endl;

class UIRenderer {
    private:
        sf::RenderWindow& window;
        int screenWidth;
        int screenHeight;
        
        Text fpsText;
        Text mouseCoordTextX;
        Text mouseCoordTextY;

    public:
        UIRenderer(Font&, int, sf::Color, sf::RenderWindow&);

        void updateFPS(string fps);
        void updateMouseCoord(int x, int y);

        void renderUI(sf::RenderWindow&);

    private:
        void createFpsText(Font&, int, sf::Color, int x, int y);
        void createMouseCoordText(Font&, int, sf::Color, int x, int y);

};
#endif