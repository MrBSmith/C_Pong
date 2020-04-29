#include "color.h"

// Set the attirbutes of the given rect to the given values
void SetColorAttributes(SDL_Color* p_color, Uint32 r, Uint32 g, Uint32 b, Uint32 a){
    p_color -> r = r;
    p_color -> g = g;
    p_color -> b = b;
    p_color -> a = a;
}
