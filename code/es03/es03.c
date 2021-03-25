/*Implementare le pile e i metodi pop() e push() utilizzando una coda con i suoi metodi
enqueue() and dequeue().*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue_node{
    struct queue_node *next;
    int val;
}Queue_node;

void enqueue(struct queue_node **head, struct queue_node **tail, struct queue_node *element){
    if(isEmpty(*head))
        *head = element;
    else
        (*tail)->next = element;

    *tail = element;
    element->next = NULL;
}

struct queue_node * dequeue(struct queue_node **head, struct queue_node **tail){
    struct queue_node *ret = *head;

    if(isEmpty(*head))
        return NULL;
    else
        *head = ret->next;

    if(*head==NULL)
        *tail = NULL;

    return ret;
}

void push(struct queue_node** pila, struct queue_node* element){

}

struct queue_node* pop(struct queue_node** pila){
    return dequeue(pila, pila);
}

void main(){
    struct queue_node* head;
    struct queue_node* tail;
    struct queue_node* element;



    push(&head, element);

    pop(&head);

    
    
    
}

