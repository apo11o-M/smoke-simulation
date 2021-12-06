#ifndef __FPS_HPP__
#define __FPS_HPP__

#include <SFML/Graphics.hpp>

class Fps {
    private:
        unsigned int mFrame;
        unsigned int mFps;
        sf::Clock mClock;

    public:
        Fps();
        unsigned int getFps() const;
        void update();
};
#endif