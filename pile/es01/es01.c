/*
Creare un programma che dato un numero intero, avente un numero arbitrario di cifre inserite
dall’utente, lo scriva in output con le cifre in ordine inverso. Utilizzare una pila e le implementazioni
dei metodi push e pop.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct queue_node{
    struct queue_node *next;
    int val;
}queue_node;

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
    if(head == NULL){
        return 1;
    }else{
        return 0;   
    }
}



void main(){
    struct queue_node* head= NULL;
    struct queue_node* element= NULL;
    
    int ancora;

    do{
       
        element= (struct queue_node*) malloc(sizeof(struct queue_node));
        printf("inserire il valore da aggiungere: ");
        fflush(stdin);
        scanf("%d", &element->val);
        push(&head, element);


        printf("vuoi ancora inserire valore (1=si): ");
        fflush(stdin);
        scanf("%d",&ancora);
    }while(ancora==1);


    while(isEmpty(head)==0){
        printf("%d", (pop(&head))->val);
    }    
}