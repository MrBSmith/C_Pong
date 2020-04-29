#include <stdio.h>
#include <stdlib.h>
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

int main(int argc, char *argv[])
{
    // The frames per second
    const int FPS = 20;

    SDL_manager* p_SDL_manager = SDL_InitManager();

    // Initialize the image loader
    // Enable the loading of png files
    int flag = IMG_INIT_PNG;
    int initted = IMG_Init(flag);

    if((initted & flag) != flag){ // handle error
        printf("IMG_Init: Failed to init required jpg and png support!\n");
        printf("IMG_Init: %s\n", IMG_GetError());
    }

    // Initialize the paddle
    SDL_Rect paddle = {300, 400, 40, 10};

    // Definit les variables necessaires a la boucle principale
    int prog_finished = 0;
    input_manager* p_input_manager = SDL_CreateInputManager();

    // Boucle principale du programme
    while(prog_finished != 1)
    {
        // Verifie qu'un evenement a eu lieu, si l'evenement est quit, sort du programme
        if(events_manager(p_input_manager) == 1){
            return EXIT_SUCCESS;
        }

        // Calcule le delta entre deux frames
        Uint32 current_tick = SDL_GetTicks();
        double delta = SDL_GetDelta(current_tick);

        // Attend la bonne quantité de temps pour que le frame rate soit régulier
        SDL_regulate_FPS(FPS, delta);

        // Refresh render
        SDL_SetRenderDrawColor(p_SDL_manager -> p_renderer, 0, 0, 0, 255);
        SDL_RenderClear(p_SDL_manager -> p_renderer);

        // Set the draw color to be white
        SDL_SetRenderDrawColor(p_SDL_manager -> p_renderer, 255, 0, 0, 255);

        // Draw the paddle
        SDL_RenderFillRect(p_SDL_manager -> p_renderer, &paddle);

        // Move the player
        move_player(p_input_manager, &paddle, 10, HORIZONTAL);

        // Render
        SDL_RenderPresent(p_SDL_manager -> p_renderer);
    }

    // Libère de la mémoire tous les éléments du manager (Fenètre, renderer, texture)
    SDL_FreeManager(p_SDL_manager);

    // On quitte la SDL avant de quitter le programme
    IMG_Quit();
    SDL_Quit();
    return EXIT_SUCCESS;
}
