#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>

#include "tileset.h"
#include "camera.h"

typedef struct SDL_map{
    int w;
    int h;
    char** map_array;
} SDL_map;

SDL_map* SDL_CreateMapFromFile(const char* file_path);
int get_file_width(FILE* p_fichier);
int get_file_height(FILE* p_fichier);
void SDL_DrawMap(SDL_manager* p_manager, SDL_map* p_map, SDL_tileset* p_tileset, SDL_camera* p_camera);
void SDL_print_map_char(SDL_map* p_map);
void malloc_map_array(SDL_map* p_map);

#endif // MAP_H_INCLUDED
