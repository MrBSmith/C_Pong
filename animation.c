#include "animation.h"

// Set the attributes of the given animation to the given values
SDL_animation* SDL_InitAnimation(SDL_tileset* p_tileset, Uint32 current_frame, Uint32 max_frame){

    SDL_animation* p_animation = malloc(sizeof(SDL_animation));

    p_animation -> p_tileset = p_tileset;
    p_animation -> current_frame = current_frame;
    p_animation -> max_frame = max_frame;

    return p_animation;
}


// Draw the given animation
void SDL_DrawAnimation(SDL_manager* p_SDL_manager, SDL_animation* p_animation, SDL_Rect* p_position){
    // Increment the current frame and wrap its value if neccessary
    p_animation -> current_frame = SDL_loop_index(p_animation -> current_frame, p_animation -> max_frame - 1, 1);

    // Draw the animation
    SDL_DrawSpriteFromTileset(p_SDL_manager, p_animation -> p_tileset, p_animation -> current_frame, p_position);
}


// Increment a value and wrap it if it's over the given max_value
Uint32 SDL_loop_index(Uint32 current_value, Uint32 max_value, Uint32 increment_value){
    current_value += increment_value;
    if(current_value > max_value){
        current_value = 0;
    }
    return current_value;
}
