#include <stdio.h> 
#include <stdlib.h> 
struct typedef El { 
    int valore; 
    struct El* next; 
}El; 
//esercizio 1
void push(struct El* l,int a){

    struct El* appoggio;
    appoggio = l;

    while(appoggio->next!=NULL){
        appoggio = appoggio->next;
    }

    appoggio->next = (struct El *)malloc(sizeof(struct El));
    appoggio->next->valore = a;
    appoggio->next->next = NULL;
}


//stampa lista ricorsiva
void stampaListaRico(El* l){
    if(l==NULL){
        printf("------\n"); //quando a finito
    }else {
        stampaListaRico(l->next);
    }
}

//stampa lista
void stampaLista(El* l){
    while (l != NULL){
        printf("%d - %p \n", l->valore, l->next);
        l = l->next; /* fa puntare all'offset la prossima struttura */
    }
    return;
}


//trovare la lunghezza lista normale
int lunghezzaLista(El* l){
    int cnt=0;
    while(l!=NULL){
        cnt++;
        l=l->next;
    }
    return cnt;
}

//trovare la lunghezza della lista ricorsiva
int lunghezzaListaRico(El* l){
    if(l==NULL){
        return 0;
    }else{
        return 1 + lunghezzaListaRico(l->next);
    }
}

//eserizio 4
void deAlloca(struct El* l){
    struct El* appoggio;
    appoggio = l;
    
    while (appoggio != NULL){
        free(appoggio);
        appoggio = appoggio->next;
    }   
}

//svuotare una lista in modo ricorsivo
void deAlloca(El *l){
    if(l!=NULL){
        deAllocaRico(l->next);
        free(l);
    }
}

//esercizio 5
void ordinaLista(struct El* l){
    struct El* appggio = l;
    int k;

    while(l->next != NULsL){
        if((l->valore)>(l->next->valore)){  
            k=l->next->valore;
            l->next->valore=l->valore;
            l->valore=k;
            l=appoggio;    
        }else{
            l=l->next;  
        }
    }
}





int main(){ 
    int n; 
    struct El* lista; 
    struct El* l; 
    lista=NULL; /*il puntatore della lista non punta a niente*/  
  
    do {
        printf("Inserisci un naturale o -1 per terminare\n");
        scanf("%d", &n);
        if (n >= 0){
            if (lista == NULL) {
                lista = (struct El *)malloc(sizeof(struct El));   
                lista->valore = n; /* il valore di "valore" della struttura(l), viene assegnato n(preso in input) */
                lista->next = NULL; /* cancella il contenuto del puntatore della prossima struttura (l->next) */  
            }else{  
                
                push(lista,n);
            }
            
        }
    } while (n>=0); 
    
    l=lista; /* fa puntare all'afoset la prima struttura*/  
    printf("numeri inseriti: "); 
    stampaLista(l);
    printf("\n"); 
    return 0; 
 } 
