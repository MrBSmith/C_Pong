#include "delta.h"

// Wait the right time to set the FPS
void SDL_regulate_FPS(const int FPS, double delta){
    // Calculate the time of each frame
    double timePerFrame = 1000 / FPS;

    // if less than 16ms, delay
    if (delta < timePerFrame) {
        SDL_Delay(timePerFrame - delta);
    }
}


// Compute the delta time between two frames
double SDL_GetDelta(Uint32 current_tick){
    Uint32 new_tick = SDL_GetTicks();
    return new_tick - current_tick;
}
