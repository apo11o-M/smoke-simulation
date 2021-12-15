#ifndef __SMOKE_HPP__
#define __SMOKE_HPP__

#include <cmath>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

#define PI 3.14159265

using sf::Sprite;
using sf::Text;
using sf::Color;
using std::string;
using std::cout;
using std::endl;

class Smoke {
    private:
        Sprite smokeSprite;

        // The maximum speed of the smoke particle
        double maxSpeed;
        // The moving speed of the smoke particle
        double currSpeed;
        // Some speed variations to offset the speed
        double randSpeed;
        // How fast does the speed decrease
        double resistance;

        // The maximum alpha value of the smokesprite
        int maxAlpha;
        // The current alpha value of the smoke sprite 
        int currAlpha;
        // The maximum/ending size of the sprite
        float maxSpriteScale;
        // the minimum/starting size of the sprite
        float minSpriteScale;
        // the current size of the sprite
        float currSpriteScale;
        // The angle (degree) between the starting position and the mouse position relative to the x axis
        float spriteMouseAngle;
        // Some angle (degree) variations to offset the spriteMouseAngle
        float randSpriteMouseAngle;

        // The maximum life of the smoke particle
        int maxLife;
        // How long does the smoke particle exist
        int currLife;
        // How fast does the smoke particle dies
        int deprecateRate;
        // True if the smoke particle is alive, if not alive then will be deleted
        bool isAlive;

    public:
        Smoke(sf::Texture&, int xPos, int yPos, sf::Vector2i mousePos);
        // Update the smoke particle, called every frame
        void updateSmoke();
        // Draw the smoke sprite onto the screen
        void renderSmoke(sf::RenderWindow& window);
        
        // return whether the smoke particle is still alive
        bool getIsAlive();
        // return the position of the smoke sprite
        sf::Vector2f getSpritePos();

    private:
        // decrease the life value of the object
        void decreaseLifeSpan();
        // update the sprite's position
        void move();
        // calculate the angle between the starting position and the mouse position relative to the 
        // x axis, also consider the random offsets
        float calcSpriteMouseAngle(sf::Vector2i);
        // randomize the rotation of the sprite
        void randRotAngle();
        // update the current speed of the smoke particle
        void updateSpeed();
        // update the alpha of the sprite
        void updateAlpha();


};
#endif