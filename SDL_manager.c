#include "SDL_manager.h"

// Initialise la SDL et le SDL_Manager, renvoi EXIT_SUCCES
SDL_manager* SDL_InitManager(){

    SDL_manager* p_SDL_manager = malloc(sizeof(SDL_manager));

    // Initialisation de la SDL, de la fenêtre et du renderer associé
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != EXIT_SUCCESS){

        // Affiche un message d'erreur si l'initialisation de la SDL a échouée
        printf("Erreur d'initialisation de la SDL : %s", SDL_GetError());

    } else {

        // Creation d'une surface de 640*480 pixels, 32bits/pxl pour les couleurs, en utilisant la mémoire de la carte 3D
        p_SDL_manager -> p_window = SDL_CreateWindow("Ma fenetre de jeu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);

        // Creation du renderer associé a la fenêtre
        p_SDL_manager -> p_renderer = SDL_CreateRenderer(p_SDL_manager -> p_window, -1, SDL_RENDERER_ACCELERATED);

        // Creation de la surface de rendu
        p_SDL_manager -> p_surface = SDL_CreateRGBSurface(0, 640, 480, 32, 0, 0, 0, 0);

        // Verification d'une potentielle erreur lors de la création de la fenêtre
        if(p_SDL_manager -> p_window == NULL){
            printf("Impossble de creer la fenetre: %s\n", SDL_GetError());
        }

        // Verification d'une potentielle erreur lors de la création du renderer
        if(p_SDL_manager -> p_renderer == NULL){
            printf("Impossble de creer le renderer: %s\n", SDL_GetError());
        }
    }

    return p_SDL_manager;
}


// Procedure de rendu
void SDL_ManagerRender(SDL_manager* p_SDL_manager){
    // Crée une texture a partir de la surface
    p_SDL_manager -> p_texture = SDL_CreateTextureFromSurface(p_SDL_manager -> p_renderer, p_SDL_manager -> p_surface);

    // Définit la texture comme cible du renderer
    SDL_SetRenderTarget(p_SDL_manager -> p_renderer, p_SDL_manager -> p_texture);

    // Déssine la texture
    SDL_RenderCopy(p_SDL_manager -> p_renderer, p_SDL_manager -> p_texture, NULL, NULL);
    SDL_RenderPresent(p_SDL_manager -> p_renderer);

    // Rafraichit l'affichage
    SDL_RenderClear(p_SDL_manager -> p_renderer);
}


// Liberer de la memoire tous les elements du manager
void SDL_FreeManager(SDL_manager* p_SDL_manager){

    // Détruit la fenêtre et le renderer avant de quitter le programme
    SDL_DestroyRenderer(p_SDL_manager -> p_renderer);
    SDL_DestroyWindow(p_SDL_manager -> p_window);

    // Libere l'espace en memoire attribué a la surface
    SDL_FreeSurface(p_SDL_manager -> p_surface);

}
