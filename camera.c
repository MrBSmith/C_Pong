#include "camera.h"

SDL_camera* SDL_CreateCamera(int x, int y, int w, int h){

    SDL_camera* p_camera = malloc(sizeof(SDL_camera));
    p_camera -> position.x = x;
    p_camera -> position.y = y;
    p_camera -> view_size.x = w;
    p_camera -> view_size.y = h;

    return p_camera;
}
