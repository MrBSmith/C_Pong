#include "pile.h"

// Pile initialization function
elem_stack* create_stack(){
    elem_stack* p_new_stack = malloc(sizeof(elem_stack));

    // Error when loading the pile exit program
    if(p_new_stack == NULL){
        exit(EXIT_FAILURE);
    }

    // Setup the new pile to be empty
    p_new_stack -> top = NULL;

    return p_new_stack;
}


// Function to stack a new element on top of a stack
void add_to_stack(elem_stack* p_stack, void* p_new_object){
    // Allocation on the size of an element in the stack
    Element *new_elem = malloc(sizeof(Element));

    // Error when loading either the stack or the new element
    // Exit program
    if (p_stack == NULL || new_elem == NULL){
        exit(EXIT_FAILURE);
    }

    // Add an element to the top of the stack
    new_elem -> p_object = p_new_object;
    new_elem -> next = p_stack -> top;
    p_stack -> top = new_elem;
}


// Function to remove the top element of the stack and return its value
void* unstack(elem_stack* p_stack){
    // Error when loading the stack exit program
    if (p_stack == NULL){
        exit(EXIT_FAILURE);
    }

    void* p_unstack_object = NULL;
    Element* unstack_elem = p_stack -> top;

    // Get the value of the element to unstack, if the stack is not empty
    if(p_stack -> top != NULL){
        p_unstack_object = unstack_elem -> p_object;
        p_stack -> top = unstack_elem -> next;
        free(unstack_elem);
    }
    return p_unstack_object;
}

