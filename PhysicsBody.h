#ifndef PHYSICSBODY_H_INCLUDED
#define PHYSICSBODY_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include "vector.h"

#define FALSE 0
#define TRUE 1

typedef struct physics_body{
    SDL_Rect* p_shape;
    vector2 velocity;
} physics_body;

physics_body* create_body(SDL_Rect* p_shape, vector2 initial_velocity);
void apply_velocity(physics_body* p_body);
int check_collision(SDL_Rect* p_shape1, SDL_Rect* p_shape2);

#endif // PHYSICSBODY_H_INCLUDED
