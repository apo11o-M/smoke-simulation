#include "Smoke.hpp"

Smoke::Smoke(sf::Texture& t, int xPos, int yPos, sf::Vector2i mousePos) {
    smokeSprite.setTexture(t);
    smokeSprite.setOrigin(t.getSize().x / 2, t.getSize().y / 2);
    smokeSprite.setPosition(xPos, yPos);
    smokeSprite.setScale(0.15, 0.15);

    maxLife = 540 + rand() / (RAND_MAX / 50);
    currLife = maxLife;
    deprecateRate = -1;
    isAlive = true;
    randSpeed = 4;
    maxSpeed = 4.5 + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / randSpeed));
    speed = maxSpeed;
    randAngle = 10;
    vertAngle = this->calcVertAngle(mousePos);
}

void Smoke::updateSmoke() {
    if (currLife < 0) {
        isAlive = false;
    } else {
        this->decreaseLifeSpan();
        this->move();
        this->updateSpeed();
        this->updateAlpha();
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
    smokeSprite.move(speed * cos(vertAngle * PI / 180.0), speed * sin(vertAngle * PI / 180.0));
}

float Smoke::calcVertAngle(sf::Vector2i mousePos) {
    int xPos = smokeSprite.getPosition().x;
    int yPos = smokeSprite.getPosition().y;
    float v1;
    if (mousePos.x < xPos) {
        v1 = atan(static_cast<float>(mousePos.y - yPos) / static_cast<float>(xPos - mousePos.x)) * 180 / PI;
    } else {
        v1 = atan(static_cast<float>(mousePos.y - yPos) / static_cast<float>(mousePos.x - xPos)) * 180 / PI;
    }
    // Add random angles to the current angle
    float r2 = -randAngle + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (2 * randAngle)));
    v1 += r2;
    return v1;
}

void Smoke::updateSpeed() {
    speed = maxSpeed * exp(-(1.0 / (static_cast<double>(maxLife) / 3.9)) * (maxLife - currLife));
}

void Smoke::updateAlpha() {
    int ratio = 128 * (static_cast<float>(currLife) / static_cast<float>(maxLife));
    smokeSprite.setColor(Color(255, 255, 255, ratio));
}