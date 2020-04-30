#include "PhysicsBody.h"

// Create a body with the given shape and the given velocity
physics_body* create_body(SDL_Rect* p_shape, vector2 initial_velocity){

    physics_body* p_new_body = malloc(sizeof(physics_body));

    p_new_body -> p_shape = p_shape;
    p_new_body -> velocity = initial_velocity;

    return p_new_body;
}

// Creation a collision with the two given colliders
collision* create_collision(SDL_bool lateral, physics_body* p_body1, physics_body* p_body2){
    collision* p_collision = malloc(sizeof(collision));
    p_collision -> lateral = lateral;
    p_collision -> p_body1 = p_body1;
    p_collision -> p_body2 = p_body2;

    return p_collision;
}



// Move the given body, based on his velocity
void apply_velocity(physics_body* p_body){
    p_body -> p_shape -> x += p_body -> velocity.x;
    p_body -> p_shape -> y += p_body -> velocity.y;
}



// Check for a collision between the p_shape1 and the p_shape2, return true if there is a collision
collision* check_collision(SDL_Rect* p_shape1, SDL_Rect* p_shape2, SDL_bool extern_collision){
    SDL_bool result = SDL_TRUE;
    SDL_bool lateral = SDL_FALSE;
    collision* p_collision = NULL;

    // define each border of the two shapes
    int left1 = p_shape1 -> x;
    int left2 = p_shape2 -> x;
    int right1 = left1 + p_shape1 -> w;
    int right2 = left2 + p_shape2 -> w;
    int top1 = p_shape1 -> y;
    int top2 = p_shape2 -> y;
    int bottom1 = top1 + p_shape1 -> h;
    int bottom2 = top2 + p_shape2 -> h;

    // Check for a collision
    if(extern_collision == SDL_TRUE){ // extern collision
        if(bottom1 <= top2){
            result = SDL_FALSE;
        }
        if(top1 >= bottom2){
            result = SDL_FALSE;
        }
        if(right1 <= left2){
            result = SDL_FALSE;
        }
        if(left1 >= right2){
            result = SDL_FALSE;
        }
    } else { // extern collision (When you want to know when p_shape1 is colliding with the border of p_shape2 from within)
        if(top1 > top2 && bottom1 < bottom2 && left1 > left2 && right1 < right2){
            result = SDL_FALSE;
        }
    }

    // Construct a collider
    if(result == SDL_TRUE){
        // Compute the shape of the collision
        int b_collision = bottom2 - top1;
        int t_collision = bottom1 - top2;
        int l_collision = right1 - left2;
        int r_collision = right2 - left1;

        if (t_collision < b_collision && t_collision < l_collision && t_collision < r_collision){
            //Top collision
        }
        if (b_collision < t_collision && b_collision < l_collision && b_collision < r_collision){
            //bottom collision
        }
        if (l_collision < r_collision && l_collision < t_collision && l_collision < b_collision){
            lateral = SDL_TRUE;
        }
        if (r_collision < l_collision && r_collision < t_collision && r_collision < b_collision){
            lateral = SDL_TRUE;
        }

        p_collision = create_collision(lateral, NULL, NULL);
    }

    return p_collision;
}
