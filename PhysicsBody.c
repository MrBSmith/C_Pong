#include "PhysicsBody.h"

// Create a body with the given shape and the given velocity
physics_body* create_body(SDL_Rect* p_shape, vector2 initial_velocity){

    physics_body* p_new_body = malloc(sizeof(physics_body));

    p_new_body -> p_shape = p_shape;
    p_new_body -> velocity = initial_velocity;

    return p_new_body;
}

// Move the given body, based on his velocity
void apply_velocity(physics_body* p_body){
    p_body -> p_shape -> x += p_body -> velocity.x;
    p_body -> p_shape -> y += p_body -> velocity.y;
}

// Check for a collision between the p_shape1 and the p_shape2, return true if there is a collision
int check_collision(SDL_Rect* p_shape1, SDL_Rect* p_shape2){
    int result = FALSE;

    int top1, left1, right1, bottom1;
    int top2, left2, right2, bottom2;

    left1 = p_shape1 -> x;
    left2 = p_shape2 -> x;
    right1 = left1 + p_shape1 -> w;
    right2 = left2 + p_shape2 -> w;
    top1 = p_shape1 -> y;
    top2 = p_shape2 -> y;
    bottom1 = top1 + p_shape1 -> h;
    bottom2 = top2 + p_shape2 -> h;

    if(right1 > left2 && left1 < right2 && bottom1 > top2 && top1 < bottom2){
        result = TRUE;
    }
    return result;
}
