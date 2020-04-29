#ifndef CERCLE_H_INCLUDED
#define CERCLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL.h>

typedef struct circle{
    int x;
    int y;
    int radius;
} circle;

extern void DrawCircle(SDL_Renderer *p_renderer, circle* p_circle, SDL_Color color);
extern void DrawFilledCircle(SDL_Renderer *p_renderer, circle* p_circle, SDL_Color color);

#endif // CERCLE_H_INCLUDED
