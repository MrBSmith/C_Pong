#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "gameobject.h"
#include "element.h"

typedef struct Queue{
    Element* first;
} Queue;


//// PROTOTYPES ////
Queue* queue_init();
void add_to_queue(Queue* p_queue, GameObject* p_new_object);
GameObject* remove_from_queue(Queue* p_queue);
void print_queue(Queue* p_queue);

#endif // QUEUE_H_INCLUDED
