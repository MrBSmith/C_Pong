#include "rectangle.h"

// Set the attirbutes of the given rect to the given values
void SetRectAttributes(SDL_Rect* p_rect, int x, int y, int w, int h){
    p_rect -> x = x;
    p_rect -> y = y;
    p_rect -> w = w;
    p_rect -> h = h;
}
