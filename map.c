#include "map.h"

// Create a map out of a txt file
SDL_map* SDL_CreateMapFromFile(const char* file_path){

    SDL_map* p_new_map = malloc(sizeof(SDL_map));

    FILE *p_fichier = NULL;
    p_fichier = fopen(file_path, "r");
    int actual_char = 0;

    if(p_fichier != NULL){

        p_new_map -> w = get_file_width(p_fichier);
        p_new_map -> h = get_file_height(p_fichier);

        // Alloue dynamiquement la taille du tableau de caractères
        malloc_map_array(p_new_map);

        int i = 0;
        int j = 0;

        // replace le curseur au début du fichier
        fseek(p_fichier, 0, SEEK_SET);

        // Rempli le tableau avec les lettres contenues dans le fichier
        while(actual_char != EOF){
            actual_char = fgetc(p_fichier);
            if(actual_char == (int) '\n'){
                i++;
                j = 0;
            } else{
                p_new_map -> map_array[i][j] = actual_char;
                j++;
            }
        }

    } else {
        printf("L'ouverture du fichier a échouée\n");
    }

    fclose(p_fichier);
    return p_new_map;
}


// Alloue la memoire necessaire au tableau contenu dans la map passée en argument
void malloc_map_array(SDL_map* p_map){
    p_map -> map_array = (char**)malloc(sizeof(char*) * p_map -> w);
    for(int i = 0; i < p_map -> w; i++){
        p_map -> map_array[i] = (char *)malloc(sizeof(char) * p_map -> h);
    }
}


// Renvoie la largeur de la premiere ligne d'un fichier texte
int get_file_width(FILE* p_fichier){

    fseek(p_fichier, 0, SEEK_SET);
    int w = 0;
    int actual_char = 0;

    while(actual_char != (int) '\n' && actual_char != (int) '\r' && actual_char != EOF){
        actual_char = fgetc(p_fichier);
        w++;
    }
    return w - 1;
}


// Renvoie la nombre de lignes d'un fichier texte
int get_file_height(FILE* p_fichier){

    fseek(p_fichier, 0, SEEK_SET);
    int h = 0;
    int actual_char = 0;

    while(actual_char != EOF){
        actual_char = fgetc(p_fichier);
        if(actual_char == (int) '\n' || actual_char == (int) '\r' || actual_char == EOF){
            h++;
        }
    }

    return h;
}


// Dessine la map passé en argument avec les sprite du tileset
void SDL_DrawMap(SDL_manager* p_manager, SDL_map* p_map, SDL_tileset* p_tileset, SDL_camera* p_camera){

    SDL_Rect destRect;
    char current_char;
    int index = 0;

    SDL_Rect tile_size;
	tile_size.w = (p_tileset -> p_surface -> w) / p_tileset -> columns;
	tile_size.h = (p_tileset -> p_surface -> h) / p_tileset -> rows;

    for (int i = 0; i < p_map -> w; i++){
        for (int j = 0; j < p_map -> h; j++){

            // Reccupère l'index du sprite a déssiner dans la map
            current_char = p_map -> map_array[j][i];
            index = ((int) current_char) - 48;

            // Détermine a quel endroit le dessiner
            destRect.x = tile_size.w * i + (int) (p_camera -> position.x);
            destRect.y = tile_size.h * j + (int) (p_camera -> position.y);

            // Déssine le sprite
            SDL_DrawSpriteFromTileset(p_manager, p_tileset, index, &destRect);
        }
    }
}


// Ecrit le contenu de la map
void SDL_print_map_char(SDL_map* p_map){
    for (int i = 0; i < p_map -> w; i++){
        for (int j = 0; j < p_map -> h; j++){
            printf("%c", p_map -> map_array[j][i]);
        }
        printf("\n");
    }
}
