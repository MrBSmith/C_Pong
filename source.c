#include "cercle.h"



int main(int argc, char *argv[])
{

    SDL_Window* p_window = NULL;
    SDL_Renderer* p_renderer = NULL;

    // Initialisation d'une couleur
    SDL_Color red;

    // Définition de la couleur contenue dans notre element de type SDL_Color fraichement initialisé
    red.r = 255;
    red.g = 0;
    red.b = 0;
    red.a = 255;

    DrawCircle(p_renderer, 0, 0 , 10, red);



return 0;
}
