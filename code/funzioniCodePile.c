#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>



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
    if(head == NULL){
        return 1;
    }else{
        return 0;   
    }
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



//funzione per invertire l'ordine degli elementi di una coda
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



void stampaPila(struct queue_node **head){
    while(isEmpty(*head)==0){
        printf("%d", (pop(head))->val);
    }
}



void leggiFile(Canzone playlist[],FILE *fp,int cnt){//cnt il numero di canzoni
    char song[100]; // stringa che legge nel file tutta la riga
    int k=0; // indice che serve a capire qiale riga sto leggendo
    while(fgets(song, LUNGHEZZARIGA, fp)!=NULL){//legge canzone
        playlist[k].numero = atoi(strtok(song, ","));
        strcpy(playlist[k].autore, strtok(NULL, ","));
        strcpy(playlist[k].nome, strtok(NULL, ","));
        k++;
    }
    printf("\nElenco canzoni in ordine\n");
    for(int k=0; k<N_CANZONI; k++){
        printf("\n%d %s %s",playlist[k].numero,playlist[k].nome,playlist[k].autore);
    }
    return;
}



/*
es: Implementare le funzioni pop e push usando la enqueue e la dequeue.
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

typedef struct el{
    int campo1;
    float campo2;
    struct el *next;
}El;

void enqueue(El **head, El **tail, El *element){
    if(isEmpty(*head))
        *head = element;
    else
        (*tail)->next = element;

    *tail = element;
    element->next = NULL;
}

void leggiFileVolo(FILE *f, El **head, El **tail, El *element){
    char *riga = (char*) malloc(200 * sizeof(char));    //puntatore per le righe del file

    printf("LISTA VOLO:\n");

    while(fgets(riga, 200, f)){ //legge una riga intera del file
        element = (El*) malloc(sizeof(El));
        
        element->campo1 = atoi(strtok(riga, ",\n")); //atoi permette di convertire una stringa in un intero
        element->campo2 = atof(strtok(NULL, ",\n"));   //atof permette di convertire una stringa in un float

        enqueue(&head, &tail, element);
    }
    free(riga); //disalloca lo spazio per la riga
}