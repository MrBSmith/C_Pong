#ifndef SDL_EVENT_H_INCLUDED
#define SDL_EVENT_H_INCLUDED

#include <SDL.h>
#include "inputkey.h"

int events_manager(player_input_manager* input_manager_array[], int nb_players);

#endif // SDL_EVENT_H_INCLUDED
