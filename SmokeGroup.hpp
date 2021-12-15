#ifndef __SMOKEGROUP_HPP__
#define __SMOKEGROUP_HPP__

#include <cmath>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Smoke.hpp"

using std::vector;
using std::string;
using std::cout;
using std::endl;

class SmokeGroup {
    private:
        vector<Smoke*> smokeGroup;

    public:
        SmokeGroup();
        void updateSmoke();
        void addSmoke(Smoke*);
        void renderSmoke(sf::RenderWindow& window);

};
#endif