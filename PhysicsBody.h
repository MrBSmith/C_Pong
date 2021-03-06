#ifndef PHYSICSBODY_H_INCLUDED
#define PHYSICSBODY_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL.h>
#include "vector.h"

typedef struct physics_body{
    SDL_Rect* p_shape;
    vector2 velocity;
} physics_body;

typedef struct collision{
    SDL_Rect* p_shape;
    SDL_bool external;
    physics_body* p_body1;
    physics_body* p_body2;
} collision;

physics_body* create_body(SDL_Rect* p_shape, vector2 initial_velocity);
void apply_velocity(physics_body* p_body);
collision* check_collision(SDL_Rect* p_shape1, SDL_Rect* p_shape2, SDL_bool extern_collision);
collision* create_collision(SDL_Rect* p_shape, SDL_bool external, physics_body* p_body1, physics_body* p_body2);
SDL_bool is_collision_lateral(collision* p_collision);

#endif // PHYSICSBODY_H_INCLUDED
