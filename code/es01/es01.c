/*
Implementare i metodi enqueue() e dequeue()  e creare un programma che permetta
all’utente di riempire una coda di numeri interi di lunghezza arbitraria. Successivamente
testare la funzione dequeue per svuotare la coda.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct queue_node{
    struct queue_node *next;
    int val;
}queue_node;


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


    while(isEmpty(head)==0){
        printf("%d\n", dequeue(&head, &tail)->val);
    }

    

}