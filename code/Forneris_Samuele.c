/*
Un mazzo di carte da gioco è costituito da 52 carte: 13 carte per ogni seme. Realizzare un programma in linguaggio C in cui ogni seme è rappresentato da un char :
‘C’: cuori
‘P’: picche
‘D’: denari
‘F’: fiori
mentre ogni carta di un seme è rappresentata da un numero intero compreso tra 1 e 13.

All’interno del programma:

Realizzate una struttura auto-referenziata opportuna che permetta di memorizzare l’intero mazzo di carte sotto forma di pila. 

All’interno del main(), riempire il mazzo di carte, utilizzando l’opportuno metodo delle pile. (BONUS: riempire il mazzo con le carte in ordine casuale)

Successivamente all’interno del main() realizzate la distribuzione di tutte le carte del mazzo a 2 giocatori: Alice e Bob. 
Ad ogni turno sono distribuite due carte: una ad Alice ed una a Bob e l’ordine tra i due viene scelto ogni volta a caso.
I turni finiscono quando il mazzo è esaurito.
Le carte distribuite ad ogni giocatore vengono salvate in una pila per ciascun giocatore. La funzione da voi implementata deve invocare solo i metodi push() e pop(). 
Stampate le carte in mano ad Alice.
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define N 4
#define NUMCARTE 13

typedef struct queue_node{
    struct queue_node *next;
    char seme;
    int valore;
}Queue_node;

//carica un elemento in una lista
void push(struct queue_node** head, struct queue_node* element){
	if (&head==NULL){
		*head = element;
		element->next = NULL;
	}else{
		element->next = *head;
		*head = element;
	}
}


//toglie un elemento di una lista e lo returna
struct queue_node* pop(struct queue_node** head){
	struct queue_node *ret = *head;
	if(&head==NULL){
		return NULL;
	}else{
		*head = ret->next;
	}
	return ret;
}


//vede se una lista è vuota
int isEmpty(struct queue_node *head){
    if(head == NULL){
        return 1;
    }else{
        return 0;   
    }
}

//stampa una pila
void stampaPila(struct queue_node **head){
    
    while(isEmpty(*head)==0){
       
        printf("%c %d", *head->seme, *head->valore);
        pop(head);
        
    }
}


void main(){
    struct queue_node* carta= NULL;  //lista carte iniziali
    struct queue_node* alice= NULL; //lista carte alice
    struct queue_node* bob= NULL;   //lista carte bob
    struct queue_node* element= NULL;

    char semi[N];
    semi[0]='C';
    semi[1]='P';
    semi[2]='D';
    semi[3]='F';


    //carica il mazzo di carte
    for(int k=0;k<N; k++){
        element= (struct queue_node*) malloc(sizeof(struct queue_node));
        element->seme= semi[k];
        for(int j=0; j<NUMCARTE; j++){
            element->valore=j;
            push(&carta,element);
            
        }
        
    }

    //distribuisci carte
    while(isEmpty(carta)==0){
        int numeroRand= rand()%2;
        if(numeroRand==0){
            push(&alice, pop(&carta));
            push(&bob, pop(&carta));
        }else{
            push(&bob, pop(&carta));
            push(&alice, pop(&carta));
        }
    }

    
    stampaPila(&alice);
    
}
    



