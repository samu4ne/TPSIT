//Autore Forneris Samuele 4Arob

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define DIM 100

typedef struct volo{
    int tempo;
    float lat;
    float longi;
}Volo;


int contaRighe(FILE *fd){
    int cnt=0;
    char *riga;
    riga = (char*)malloc(100*sizeof(char));
    while(fgets(riga, 100, fd)){
        cnt++;
    }
    free(riga);
    return cnt;
}

void caricaTab(Volo *tab, FILE *fd, int n){     //leggo il file
    char* riga = (char*) malloc(sizeof(char)*DIM );         //alloco lo spazio del vettore nel quale verrà caricata l'intera riga letta
    int cnt=0;
    int temp=0;
    
    while(fgets(riga, DIM, fd)){  
        if(temp>0){     //serve per vedere se quello che ho letto è la prima riga 
            (tab+cnt)->tempo= atoi(strtok(riga, ","));
            (tab+cnt)->lat= atof(strtok(NULL, ","));
            (tab+cnt)->longi= atof(strtok(NULL, ","));
            cnt=cnt+1;
        }
        temp=temp+1;
    }
    free(riga);
    return;
}

void errori(Volo *tab, FILE *fa, int n){
    char* riga = (char*) malloc(sizeof(char)*DIM );
    char *errore=(char*) malloc(sizeof(char)*DIM );     //serve per leggere nel file l'errore
    int cnt=0;
    int temp=0;
    int primaRig=0;
    while(fgets(riga, DIM, fa)){
        if(primaRig>0){ 
            temp=atoi(strtok(riga, ","));
            strcpy(errore, strtok(NULL, ","));
            for(int k=0; k<n; k++){
                if((tab+k)->tempo==temp){
                    printf("L'errore :%s e' successo in %f , %f \n", errore, (tab+k)->lat, (tab+k)->longi);
                }
            }    
        }
        primaRig=primaRig+1;
    }
    free(riga);
    free(errore);
    return;
}



void main(){
    Volo *tab;
    FILE *fd, *fa;
    int cnt;
    if((fd=fopen("Volo_drone.csv", "r"))==NULL){
        printf("il file non esiste");
    }else{
        fa=fopen("Anomalie_drone.csv", "r");
        cnt=contaRighe(fd);
        tab= (Volo*)malloc(cnt*sizeof(Volo));  //alloco lo spazio per la tabella
        fclose(fd);
        fd=fopen("Volo_drone.csv", "r");
        caricaTab(tab, fd, cnt);
        int k=contaRighe(fa);
        fclose(fa);
        fa=fopen("Anomalie_drone.csv", "r");
        errori(tab, fa, k);
        free(tab);
        fclose(fa);
        fclose(fd);
    }

}