#ifndef DELTA_H_INCLUDED
#define DELTA_H_INCLUDED

#include <SDL.h>

// Wait the right time to set the FPS
void SDL_regulate_FPS(const int FPS, double delta);

// Compute the delta time between two frames
double SDL_GetDelta(Uint32 current_tick);

#endif // DELTA_H_INCLUDED
