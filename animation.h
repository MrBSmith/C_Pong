#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED

#include <SDL.h>
#include "tileset.h"

typedef struct SDL_animation{
    SDL_tileset* p_tileset;
    Uint32 current_frame;
    Uint32 max_frame;
} SDL_animation;

// Initialize the given animation with the given values
SDL_animation* SDL_InitAnimation(SDL_tileset* p_tileset, Uint32 current_frame, Uint32 max_frame);

// Draw an animation
void SDL_DrawAnimation(SDL_manager* p_SDL_manager, SDL_animation* p_animation, SDL_Rect* p_position);

// Increment a value and wrap it if it's over the given max_value
Uint32 SDL_loop_index(Uint32 current_value, Uint32 max_value, Uint32 increment_value);

#endif // ANIMATION_H_INCLUDED
