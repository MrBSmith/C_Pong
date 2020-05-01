#include "queue.h"

// Initization function for queues
Queue* queue_init(){
    Queue* p_new_queue = malloc(sizeof(Queue));

    // Error when loading the pile exit program
    if(p_new_queue == NULL){
        exit(EXIT_FAILURE);
    }

    // Setup the new pile to be empty
    p_new_queue -> first = NULL;

    return p_new_queue;
}


// Function to add an element to the queue
void add_to_queue(Queue* queue, GameObject* p_new_object){
    // Allocation on the size of an element in the pile
    Element *new_elem = malloc(sizeof(*new_elem));

    // Error when loading either the pile or the new element
    // Exit program
    if (queue == NULL || new_elem == NULL){
        exit(EXIT_FAILURE);
    }

    // Add an element to the queue
    new_elem -> object = p_new_object;
    new_elem -> next_elem = NULL;

    // In case the queue isn't empty
    if(queue -> first != NULL){
        Element* current_elem = queue -> first;
        // Loop through the entire queue, until we get the very last element
        while(current_elem -> next_elem != NULL){
            current_elem = current_elem -> next_elem;
        }

        // Give to the next element the reference to the new one
        current_elem -> next_elem = new_elem;
    } else {
        queue -> first = new_elem;
    }
}

// Remove the first element on the queue and returns it
GameObject* remove_from_queue(Queue* p_queue){
    // Error when loading the queue exit program
    if (p_queue == NULL){
        exit(EXIT_FAILURE);
    }

    GameObject* p_unqueue_object = NULL;
    Element* unqueue_elem = p_queue -> first;

    // Get the value of the element to unstack, if the queue is not empty
    if(p_queue -> first != NULL){
        p_unqueue_object = unqueue_elem -> object;
        p_queue -> first = unqueue_elem -> next_elem;
        free(unqueue_elem);
    }
    return p_unqueue_object;
}
