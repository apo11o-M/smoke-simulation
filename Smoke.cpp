#include "Smoke.hpp"

Smoke::Smoke(sf::Texture& t, int xPos, int yPos, sf::Vector2i mousePos) {
    smokeSprite.setTexture(t);
    smokeSprite.setOrigin(t.getSize().x / 2, t.getSize().y / 2);
    smokeSprite.setPosition(xPos, yPos);
    maxSpriteScale = 0.9;
    minSpriteScale = 0.15;
    smokeSprite.setScale(minSpriteScale, minSpriteScale);

    maxLife = 540 + rand() / (RAND_MAX / 50);
    currLife = maxLife;
    deprecateRate = -1;
    isAlive = true;

    randSpeed = 4;
    maxSpeed = 5 + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / randSpeed));
    currSpeed = maxSpeed;
    resistance = 3.9;

    randSpriteMouseAngle = 10;
    spriteMouseAngle = this->calcSpriteMouseAngle(mousePos);

    maxAlpha = 50 + rand() / (RAND_MAX / 20);
    currAlpha = maxAlpha;
}

void Smoke::updateSmoke() {
    if (currLife < 0) {
        isAlive = false;
    } else {
        this->decreaseLifeSpan();
        this->move(); 
        this->updateSpeed();
        this->updateAlpha();
        this->updateSize();
        
    }
}

void Smoke::renderSmoke(sf::RenderWindow& window) {
    window.draw(smokeSprite);
}

bool Smoke::getIsAlive() {
    return isAlive;
}

sf::Vector2f Smoke::getSpritePos() {
    return smokeSprite.getPosition();
}

void Smoke::decreaseLifeSpan() {
    currLife += deprecateRate;
}

void Smoke::move() {
    smokeSprite.move(currSpeed * cos(spriteMouseAngle * PI / 180.0), currSpeed * sin(spriteMouseAngle * PI / 180.0));
}

float Smoke::calcSpriteMouseAngle(sf::Vector2i mousePos) {
    int xPos = smokeSprite.getPosition().x;
    int yPos = smokeSprite.getPosition().y;
    float v1;
    if (mousePos.x < xPos) {
        v1 = atan(static_cast<float>(mousePos.y - yPos) / static_cast<float>(xPos - mousePos.x)) * 180 / PI;
    } else {
        v1 = atan(static_cast<float>(mousePos.y - yPos) / static_cast<float>(mousePos.x - xPos)) * 180 / PI;
    }
    // Add random angles to the current angle
    float r2 = -randSpriteMouseAngle + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (2 * randSpriteMouseAngle)));
    v1 += r2;
    return v1;
}

void Smoke::updateSpeed() {
    currSpeed = maxSpeed * exp(-(1.0 / (static_cast<double>(maxLife) / resistance)) * (maxLife - currLife));
}

void Smoke::updateAlpha() {
    currAlpha = maxAlpha * (static_cast<float>(currLife) / static_cast<float>(maxLife));
    smokeSprite.setColor(Color(255, 255, 255, currAlpha));
}

void Smoke::updateSize() {
    // Linear
    // currSpriteScale = minSpriteScale * (2 - (static_cast<float>(currLife) / static_cast<float>(maxLife)));
    // Exponentional
    // currSpriteScale = 0.05 * exp(0.005 * (maxLife - currLife) + 1);
    // currSpriteScale = 0.9 / (1.0 + exp(-0.009 * (maxLife - currLife - maxLife / 2))) + 0.077;
    // Logistic Function
    currSpriteScale = maxSpriteScale / (1.0 + exp(-0.02 * (maxLife - currLife - 150))) + 0.107;
    cout << "curr " << currSpriteScale << " ";
    smokeSprite.setScale(currSpriteScale, currSpriteScale);
}
