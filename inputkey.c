#include <stdio.h>
#include <stdlib.h>

#include "inputkey.h"

// Get the input from the player, and return it
input get_player_input(int sym, player_input_map input_map){
    input control;
    if (sym == input_map.up){
        control = UP;

    } else if (sym == input_map.left){
        control = LEFT;

    } else if (sym == input_map.right){
        control = RIGHT;

    } else if (sym == input_map.down){
        control = DOWN;

    } else if (sym == input_map.confirm){
        control = CONFIRM;

    } else if (sym == input_map.cancel){
        control = CANCEL;

    } else {
        control = NONE;
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
player_input_manager* SDL_CreateInputManager(int up, int down, int left, int right, int confirm, int cancel){

    player_input_manager* p_inp_manager = malloc(sizeof(player_input_manager));
    int input_nb = sizeof(p_inp_manager -> input_state_array) / sizeof(int);

    // Loop through the array of input and set them all to
    for (int i = 0; i < input_nb - 1; i++){
        p_inp_manager -> input_state_array[i] = RELEASED;
    }

    p_inp_manager -> input_map.up = up;
    p_inp_manager -> input_map.down = down;
    p_inp_manager -> input_map.left = left;
    p_inp_manager -> input_map.right = right;
    p_inp_manager -> input_map.confirm = confirm;
    p_inp_manager -> input_map.cancel = cancel;

    return p_inp_manager;
}


// Respond to the input of the player by moving the character
void move_player(player_input_manager* p_player_input_manager, SDL_Rect* p_rect, int move_speed, move_flag flag){

    if(flag != HORIZONTAL){
        if(p_player_input_manager -> input_state_array[UP] == PRESSED){
            p_rect -> y -= move_speed;
        }

        if(p_player_input_manager -> input_state_array[DOWN] == PRESSED){
            p_rect -> y += move_speed;
        }
    }

    if(flag != VERTICAL){
        if(p_player_input_manager -> input_state_array[LEFT] == PRESSED){
            p_rect -> x -= move_speed;
        }

        if(p_player_input_manager -> input_state_array[RIGHT] == PRESSED){
            p_rect -> x += move_speed;
        }
    }
}
