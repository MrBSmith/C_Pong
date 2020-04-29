#ifndef INPUTKEY_H_INCLUDED
#define INPUTKEY_H_INCLUDED

#include <SDL.h>
#include "vector.h"

typedef enum input {UP, DOWN, RIGHT, LEFT, CONFIRM, CANCEL} input;
typedef enum input_state {RELEASED, PRESSED} input_state;
typedef enum move_flag {BOTH, VERTICAL, HORIZONTAL} move_flag;

typedef struct input_manager {
    input_state input_state_array[6];
} input_manager;

// Get the input from the player, and return it
input get_input(int sym);

// Print the given input in the console
void print_input(input inp);

// Procedure for input manager creation
input_manager* SDL_CreateInputManager();

// Move the given rect accordingly to the input of the player
void move_player(input_manager* p_input_manager, SDL_Rect* p_rect, int move_speed, move_flag flag);

#endif // INPUTKEY_H_INCLUDED
