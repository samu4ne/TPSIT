/*
Scrivere una funzione che inverta una coda, ovvero produca una coda invertendo l’ordine
degli elementi della coda di partenza. Suggerimento: utilizzare una pila.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue_node{
    struct queue_node *next;
    int val;
}Queue_node;

void push(struct queue_node** head, struct queue_node* element){
	if (&head==NULL){
		*head = element;
		element->next = NULL;
	}else{
		element->next = *head;
		*head = element;
	}
}

struct queue_node* pop(struct queue_node** head){
	struct queue_node *ret = *head;
	if(&head==NULL){
		return NULL;
	}else{
		*head = ret->next;
	}
	return ret;
}


int isEmpty(struct queue_node *head){
    if(head == NULL)
        return 1;
    else
        return 0;   
}


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

void invertiCoda(struct queue_node **head, struct queue_node **tail){
    struct queue_node* pila= (struct queue_node*) malloc(sizeof(struct queue_node));
    struct queue_node* tempCoda;
    bool fatto= false;

    while(isEmpty(*head)!=1){
        push(&pila, dequeue(head, tail));
        if(fatto==false){
            fatto=true;
            tempCoda=pila;
        }
       
    }

    

    *head= pila;
    *tail=tempCoda; 
    (*tail)->next=NULL; 

}


void stampaCoda(struct queue_node **head, struct queue_node **tail){
    while(isEmpty(*head)==0){
        printf("%d", (dequeue(head, tail))->val);   
    }
}


void main(){
    struct queue_node *head;
    struct queue_node *tail;
    struct queue_node *element;

    
    
    int ancora;

    do{
       
        element= (struct queue_node*) malloc(sizeof(struct queue_node));
        printf("inserire il valore da aggiungere: ");
        fflush(stdin);
        scanf("%d", &element->val);
        enqueue(&head, &tail, element);


        printf("vuoi ancora inserire valore (1=si): ");
        fflush(stdin);
        scanf("%d",&ancora);
    }while(ancora==1);

    invertiCoda(&head, &tail);
    
    stampaCoda(&head, &tail);
    
}