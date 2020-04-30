#ifndef INPUTKEY_H_INCLUDED
#define INPUTKEY_H_INCLUDED

#include <SDL.h>
#include "vector.h"

typedef enum input {UP, DOWN, RIGHT, LEFT, CONFIRM, CANCEL, NONE} input;
typedef enum input_state {RELEASED, PRESSED} input_state;
typedef enum move_flag {BOTH, VERTICAL, HORIZONTAL} move_flag;

typedef struct player_input_map{
    int up;
    int down;
    int right;
    int left;
    int confirm;
    int cancel;
} player_input_map;

typedef struct player_input_manager{
    input_state input_state_array[6];
    player_input_map input_map;
} player_input_manager;


// Procedure for input manager creation
player_input_manager* SDL_CreateInputManager(int up, int down, int left, int right, int confirm, int cancel);

// Get the input from the player, and return it
input get_player_input(int sym, player_input_map input_map);

// Print the given input in the console
void print_input(input inp);

// Move the given rect accordingly to the input of the player
void move_player(player_input_manager* p_player_input_manager, SDL_Rect* p_rect, int move_speed, move_flag flag);

#endif // INPUTKEY_H_INCLUDED
