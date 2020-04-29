#include "cercle.h"

// Dessine le cercle donné
void DrawCircle(SDL_Renderer *p_renderer, circle* p_circle, SDL_Color color)
{
    int new_x = 0;
    int new_y = 0;
    int old_x = p_circle -> x + p_circle -> radius;
    int old_y = p_circle -> y;
    float step = (M_PI * 2) / 50;

    SDL_SetRenderDrawColor(p_renderer, color.r, color.g, color.b, 255);

    for(float theta = 0; theta <= (M_PI * 2); theta += step){
        new_x = p_circle -> x + (p_circle -> radius * cos(theta));
        new_y = p_circle -> y - (p_circle -> radius * sin(theta));

        SDL_RenderDrawLine(p_renderer, old_x, old_y, new_x, new_y);

        old_x = new_x;
        old_y = new_y;
    }

    new_x = p_circle -> x + p_circle -> radius;
    new_y = p_circle -> y ;
    SDL_RenderDrawLine(p_renderer, old_x, old_y, new_x, new_y);

}


// Dessine le cercle donné, rempli
void DrawFilledCircle(SDL_Renderer *p_renderer, circle* p_circle, SDL_Color color)
{
    int origin_x = p_circle -> x;
    int origin_y = p_circle -> y;
    int radius = p_circle -> radius;

	for(double dy = 1; dy <= radius; dy += 1.0){

		double dx = floor(sqrt((2.0 * radius * dy) - (dy * dy)));

		SDL_SetRenderDrawColor(p_renderer, color.r, color.g, color.b, color.a);
		SDL_RenderDrawLine(p_renderer, origin_x - dx, origin_y + dy - radius, origin_x + dx, origin_y + dy - radius);
		SDL_RenderDrawLine(p_renderer, origin_x - dx, origin_y - dy + radius, origin_x + dx, origin_y - dy + radius);

	}
}
