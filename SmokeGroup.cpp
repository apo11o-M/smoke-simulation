#include "SmokeGroup.hpp"

SmokeGroup::SmokeGroup() {}

void SmokeGroup::addSmoke(Smoke* s) {
    smokeGroup.push_back(s);
}

void SmokeGroup::updateSmoke() {
    for (unsigned int i = 0; i < smokeGroup.size(); ) {
        if (smokeGroup[i]->getIsAlive()) {
            smokeGroup[i]->updateSmoke();
            i++;
        } else {
            delete smokeGroup[i];
            smokeGroup.erase(smokeGroup.begin() + i);
        }
    }
}

void SmokeGroup::renderSmoke(sf::RenderWindow& window) {
    for (unsigned int i = 0; i < smokeGroup.size(); i++) {
        smokeGroup[i]->renderSmoke(window);
    }
}

unsigned int SmokeGroup::getSize() {
    return smokeGroup.size();
}