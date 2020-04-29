#include "SDL_event.h"

// Boucle attendant des evenements SDL
int events_manager(input_manager* p_input_manager){
    SDL_Event event;
    input in;
    while(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_QUIT: // En cas d'event quit
                return 1;
                break;

            case SDL_KEYDOWN: // En cas d'input clavier pressé
                in = get_input(event.key.keysym.sym);
                p_input_manager -> input_state_array[in] = PRESSED;
                break;

            case SDL_KEYUP: // En cas d'input clavier relaché
                in = get_input(event.key.keysym.sym);
                p_input_manager -> input_state_array[in] = RELEASED;
                break;
        }
    }

    return 0;
}
