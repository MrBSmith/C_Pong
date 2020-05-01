#include "PhysicsBody.h"

// Create a body with the given shape and the given velocity
physics_body* create_body(SDL_Rect* p_shape, vector2 initial_velocity){

    physics_body* p_new_body = malloc(sizeof(physics_body));

    p_new_body -> p_shape = p_shape;
    p_new_body -> velocity = initial_velocity;

    return p_new_body;
}


// Creation a collision with the two given colliders
collision* create_collision(SDL_Rect* p_shape, SDL_bool external, physics_body* p_body1, physics_body* p_body2){
    collision* p_collision = malloc(sizeof(collision));
    p_collision -> p_shape = p_shape;
    p_collision -> external = external;
    p_collision -> p_body1 = p_body1;
    p_collision -> p_body2 = p_body2;
    return p_collision;
}


// Return SDL_TRUE if the given collision is lateral, SDL_FALSE if it is vertical
SDL_bool is_collision_lateral(collision* p_collision){

    SDL_Rect* p_shape = p_collision -> p_shape;
    SDL_bool lateral = SDL_FALSE;

    if(p_shape -> w <= p_shape -> h){
        lateral = SDL_TRUE;
    }

    return lateral;
}


// Move the given body, based on his velocity
void apply_velocity(physics_body* p_body){
    p_body -> p_shape -> x += p_body -> velocity.x;
    p_body -> p_shape -> y += p_body -> velocity.y;
}



// Check for a collision between the p_shape1 and the p_shape2
// Create a collision entity if a collision happens, containing a shape that describe the shape of the collision
collision* check_collision(SDL_Rect* p_shape1, SDL_Rect* p_shape2, SDL_bool extern_collision){
    SDL_bool result = SDL_TRUE;
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
        if(bottom1 <= top2 || top1 >= bottom2 || right1 <= left2 || left1 >= right2){
            result = SDL_FALSE;
        }
    } else { // intern collision (When you want to know when p_shape1 is colliding with the border of p_shape2 from within)
        if(top1 > top2 && bottom1 < bottom2 && left1 > left2 && right1 < right2){
            result = SDL_FALSE;
        }
    }

    // Create the collision entity if their was a collision
    if(result == SDL_TRUE){

        // Compute the shape of the collision
        int x1 = (int) fmax((float)left1, (float)left2);
        int y1 = (int) fmax((float)top1, (float)top2);
        int x2 = (int) fmin((float)right1, (float)right2);
        int y2 = (int) fmin((float)bottom1, (float)bottom2);

        SDL_Rect* p_shape = malloc(sizeof(SDL_Rect));
        p_shape -> x = x1;
        p_shape -> y = y1;
        p_shape -> w = x2 - x1;
        p_shape -> h = y2 - y1;

        // Construct a collider
        p_collision = create_collision(p_shape, extern_collision, NULL, NULL);
    }

    return p_collision;
}
