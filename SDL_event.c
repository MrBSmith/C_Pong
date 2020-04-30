#include "SDL_event.h"

// Loop reacting to SDL events
int events_manager(player_input_manager* input_manager_array[], int nb_players){
    SDL_Event event;
    input in;
    while(SDL_PollEvent(&event)){

        // Loop through every players to catch their input
        for(int i = 0; i < nb_players; i++){
            switch(event.type){
                case SDL_QUIT: // In case of quit event
                    return 1;
                    break;

                case SDL_KEYDOWN: // In case of a pressed input
                    in = get_player_input(event.key.keysym.sym, input_manager_array[i] -> input_map);
                    if (in != NONE){
                        input_manager_array[i] -> input_state_array[in] = PRESSED;
                    }
                    break;

                case SDL_KEYUP: // In case of a unpressed input
                    in = get_player_input(event.key.keysym.sym, input_manager_array[i] -> input_map);
                    if (in != NONE){
                        input_manager_array[i] -> input_state_array[in] = RELEASED;
                    }
                    break;
            }
        }
    }

    return 0;
}
