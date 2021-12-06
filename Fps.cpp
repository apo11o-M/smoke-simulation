#include "Fps.hpp"

Fps::Fps() : mFrame(0), mFps(0) {}

unsigned int Fps::getFps() const {
    return mFps;
}

void Fps::update() {
    if (mClock.getElapsedTime().asSeconds() >= 0.5f) {
        mFps = mFrame * 2;
        mFrame = 0;
        mClock.restart();
    }    
    mFrame++;
}