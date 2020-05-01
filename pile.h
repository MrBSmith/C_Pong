#ifndef PILE_H_INCLUDED
#define PILE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct Element Element;
struct Element{
    void* p_object;
    Element* next;
};

typedef struct elem_stack{
    Element* top;
} elem_stack;

//// PROTOTYPES ////
elem_stack* create_stack();
void add_to_stack(elem_stack* pile, void* p_object);
void* unstack(elem_stack* pile);

#endif // PILE_H_INCLUDED
