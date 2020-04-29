#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

typedef struct SDL_camera {
    vector2 position;
    vector2 view_size;
} SDL_camera;

//// PROTOTYPES ////

// Create a camera with the given position and dimensions
SDL_camera* SDL_CreateCamera(int x, int y, int w, int h);

#endif // CAMERA_H_INCLUDED
