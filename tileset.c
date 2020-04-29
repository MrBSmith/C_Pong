#include "tileset.h"

// Crée un tileset a partir du nom d'un ficher d'image, du nombre de rows et de colomns dans ce tileset
SDL_tileset* SDL_CreateTilesetFromPNG(const char* file, int rows, int columns){

    SDL_tileset* p_tileset = malloc(sizeof(SDL_tileset));

    p_tileset -> p_surface = IMG_Load(file);
    p_tileset -> rows = rows;
    p_tileset -> columns = columns;

    return p_tileset;
}


// Dessine un sprite a partir d'un tileset, du nombre de rangés et de lignes dans ce tileset et de sa position dans celui-ci
// Stock le dit sprite dans la surface du SDL_Manager
void SDL_DrawSpriteFromTileset(SDL_manager* p_SDL_manager, SDL_tileset* p_tileset, int frame_id, SDL_Rect* p_screen_pos){

	SDL_Rect Rect_tile;
	Rect_tile.w = (p_tileset -> p_surface -> w) / p_tileset -> columns;
	Rect_tile.h = (p_tileset -> p_surface -> h) / p_tileset -> rows;

	// Va chercher le sprite dans la ligne. Ne fonctionne qu'avec un tileset de une ligne pour le moment: a faire évoluer
    Rect_tile.x = frame_id * Rect_tile.w;
    Rect_tile.y = 0;

    SDL_BlitSurface(p_tileset -> p_surface, &Rect_tile, p_SDL_manager -> p_surface, p_screen_pos);
}
