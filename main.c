#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL.h>
#include <SDL_image.h>

#include "cercle.h"
#include "SDL_manager.h"
#include "tileset.h"
#include "animation.h"
#include "delta.h"
#include "camera.h"
#include "map.h"
#include "inputkey.h"
#include "SDL_event.h"

#include "paddle.h"
#include "PhysicsBody.h"
#include "pile.h"

int main(int argc, char *argv[])
{
    // The frames per seconds
    const int FPS = 60;

    SDL_manager* p_SDL_manager = SDL_InitManager();

    // Initialize the image loader
    // Enable the loading of png files
    int flag = IMG_INIT_PNG;
    int initted = IMG_Init(flag);

    if((initted & flag) != flag){ // handle error
        printf("IMG_Init: Failed to init required jpg and png support!\n");
        printf("IMG_Init: %s\n", IMG_GetError());
    }

    // Get the screen size, in order to manage the size & position of each bricks dynamicly
    int screen_width, screen_height;
    SDL_GetWindowSize(p_SDL_manager -> p_window, &screen_width, &screen_height);
    SDL_Rect screen_rect = {0, 0, screen_width, screen_height};

    int paddle_offset = 50;

    vector2 VECTOR_2_ZERO = {0, 0};
    vector2 ball_initial_velocity = {2, 2};

    // Initialize the paddles
    SDL_Rect paddle_rect1 = {paddle_offset + 5, (screen_height - 40) / 2, 10, 40};
    SDL_Rect paddle_rect2 = {screen_width - paddle_offset - 5, (screen_height - 40) / 2, 10, 40};
    physics_body* p_paddle1 = create_body(&paddle_rect1, VECTOR_2_ZERO);
    physics_body* p_paddle2 = create_body(&paddle_rect2, VECTOR_2_ZERO);

    // Initialize the ball
    SDL_Rect ball_rect = {(screen_width - 10) / 2, (screen_height - 10) / 2, 10, 10};
    physics_body* p_ball = create_body(&ball_rect, ball_initial_velocity);

    // Define the variable holding the state of the program
    int prog_finished = 0;

    // Define the two players input manager
    player_input_manager* p_input_manager_p1 = SDL_CreateInputManager(SDLK_z, SDLK_s, SDLK_q, SDLK_d, SDLK_SPACE, SDLK_ESCAPE);
    player_input_manager* p_input_manager_p2 = SDL_CreateInputManager(SDLK_o, SDLK_l, SDLK_k, SDLK_m, SDLK_p, SDLK_i);
    player_input_manager* players_input_manager_array[2] = {p_input_manager_p1, p_input_manager_p2};

    // Main loop
    while(prog_finished != 1)
    {
        // Check if an event has occured, exit the program if necesary
        if(events_manager(players_input_manager_array, 2) == 1){
            return EXIT_SUCCESS;
        }

        // Compute the delta time between two frames
        Uint32 current_tick = SDL_GetTicks();
        double delta = SDL_GetDelta(current_tick);

        // Wait enough time to regulate the display
        SDL_regulate_FPS(FPS, delta);

        //// PHYSICS ////

        // Move the ball
        apply_velocity(p_ball);

        // Move the players
        move_player(p_input_manager_p1, p_paddle1 -> p_shape, 10, VERTICAL);
        move_player(p_input_manager_p2, p_paddle2 -> p_shape, 10, VERTICAL);

        // Collision detection
        elem_stack* p_collision_stack = create_stack();

        collision* p_col1 = check_collision(p_ball -> p_shape, p_paddle1 -> p_shape, SDL_TRUE);
        if(p_col1 != NULL) { add_to_stack(p_collision_stack, p_col1); }

        collision* p_col2 = check_collision(p_ball -> p_shape, p_paddle2 -> p_shape, SDL_TRUE);
        if(p_col2 != NULL) { add_to_stack(p_collision_stack, p_col2); }

        collision* p_col3 = check_collision(p_ball -> p_shape, &screen_rect, SDL_FALSE);
        if(p_col3 != NULL) { add_to_stack(p_collision_stack, p_col3); }

        // Unstack every collision until there are all treated
        collision* p_col;
        do{
            p_col = (collision*) unstack(p_collision_stack);
            if(p_col != NULL){
                if(is_collision_lateral(p_col) == SDL_FALSE){
                    p_ball -> velocity.y *= -1;
                } else {
                    if (p_col -> external == SDL_FALSE){ // If the collider is a wall
                        p_ball -> p_shape -> x = (screen_width - 10) / 2;
                        p_ball -> p_shape -> y = (screen_height - 10) / 2;
                        p_paddle1 -> p_shape -> y = (screen_height - 40) / 2;
                        p_paddle2 -> p_shape -> y = (screen_height - 40) / 2;

                    } else {
                        p_ball -> velocity.x *= -1;
                    }
                }
            }
        } while(p_col != NULL);

        //// RENDERING ////

        // Refresh render
        SDL_SetRenderDrawColor(p_SDL_manager -> p_renderer, 0, 0, 0, 255);
        SDL_RenderClear(p_SDL_manager -> p_renderer);

        // Set the draw color to be white
        SDL_SetRenderDrawColor(p_SDL_manager -> p_renderer, 255, 255, 255, 255);

        // Draw the paddles
        SDL_RenderFillRect(p_SDL_manager -> p_renderer, p_paddle1 -> p_shape);
        SDL_RenderFillRect(p_SDL_manager -> p_renderer, p_paddle2 -> p_shape);

        // Draw the ball
        SDL_RenderFillRect(p_SDL_manager -> p_renderer, p_ball -> p_shape);

        // Render
        SDL_RenderPresent(p_SDL_manager -> p_renderer);
    }

    // Free from memory every elements of the manager
    SDL_FreeManager(p_SDL_manager);

    // Quit SDL before leaving th application
    IMG_Quit();
    SDL_Quit();
    return EXIT_SUCCESS;
}
