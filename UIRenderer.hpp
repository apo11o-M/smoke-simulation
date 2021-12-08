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

class UIRenderer {
    private:
        Font font;
        int size;
        sf::Color color;

    private:
        Text fpsText;
        Text mouseCoordText;

    public:
        UIRenderer();
        UIRenderer(Font defultFont, int defaultSize, sf::Color defaultColor);

        // void addUI(string, Font, int charSize, sf::Color, int posX, int posY);
        void updateFPS(string);

        void renderUI(sf::RenderWindow&);

};
#endif