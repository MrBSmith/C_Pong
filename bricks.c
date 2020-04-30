
#include "bricks.h"

SDL_Rect** initialize_brick_array(SDL_Window* p_window, Uint16 nb_lines, Uint16 bricks_per_lines){

    SDL_Rect** bricks_array = malloc(sizeof(SDL_Rect) * bricks_per_lines * nb_lines);

    // Define the offset between each bricks
    int offset = 10;

    // Get the screen size, in order to manage the size & position of each bricks dynamicly
    int screen_width = 0;
    int screen_height = 0;
    SDL_GetWindowSize(p_window, &screen_width, &screen_height);

    // Compute the size of one brick
    int brick_w = (screen_width - (offset * (bricks_per_lines + 1))) / bricks_per_lines;
    int brick_h = 10;

    for(int i = 0; i < nb_lines; i++){
        for(int j = 0; j < bricks_per_lines; j++){

            SDL_Rect* p_new_brick = malloc(sizeof(SDL_Rect));
            p_new_brick -> w = brick_w;
            p_new_brick -> h = brick_h;
            p_new_brick -> x = (offset * (j + 1)) + (brick_w * j);
            p_new_brick -> y = (offset * (i + 1)) + (brick_h * i);

            bricks_array[(i * bricks_per_lines) + j] = p_new_brick;
        }
    }

    return bricks_array;
}
