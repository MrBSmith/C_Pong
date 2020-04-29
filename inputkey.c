#include <stdio.h>
#include <stdlib.h>

#include "inputkey.h"

// Get the input from the player, and return it
input get_input(int sym){
    input control;
    switch(sym){
        case SDLK_z:
            control = UP; break;

        case SDLK_q:
            control = LEFT; break;

        case SDLK_d:
            control = RIGHT; break;

        case SDLK_s:
            control = DOWN; break;

        case SDLK_v:
            control = CONFIRM; break;

        case SDLK_n:
            control = CANCEL; break;

        default :
             break;
    }
    return control;
}


// Print the given input in the console
void print_input(input inp){
    switch(inp)
    {
        case UP:
            printf("UP\n"); break;
        case LEFT:
            printf("LEFT\n"); break;
        case RIGHT:
            printf("RIGHT\n"); break;
        case DOWN:
            printf("DOWN\n"); break;
        case CONFIRM:
            printf("CONFIRM\n"); break;
        case CANCEL:
            printf("CANCEL\n"); break;
        default :
            printf("ERROR\n"); break;
    }
}


// Procedure for input manager creation
input_manager* SDL_CreateInputManager(){

    input_manager* p_inp_manager = malloc(sizeof(input_manager));
    int input_nb = sizeof(p_inp_manager -> input_state_array) / sizeof(int);

    // Loop through the array of input and set them all to
    for (int i = 0; i < input_nb - 1; i++){
        p_inp_manager -> input_state_array[i] = RELEASED;
    }

    return p_inp_manager;
}


// Respond to the input of the player by moving the character
void move_character(input_manager* p_input_manager, SDL_Rect* p_rect, int move_speed){

    if(p_input_manager -> input_state_array[UP] == PRESSED){
        p_rect -> y -= move_speed;
    }

    if(p_input_manager -> input_state_array[DOWN] == PRESSED){
        p_rect -> y += move_speed;
    }

    if(p_input_manager -> input_state_array[LEFT] == PRESSED){
        p_rect -> x -= move_speed;
    }

    if(p_input_manager -> input_state_array[RIGHT] == PRESSED){
        p_rect -> x += move_speed;
    }
}

