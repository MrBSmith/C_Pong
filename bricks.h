#ifndef BRICKS_H_INCLUDED
#define BRICKS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>

SDL_Rect** initialize_brick_array(SDL_Window* p_window, Uint16 nb_lines, Uint16 bricks_per_lines);

#endif // BRICKS_H_INCLUDED
