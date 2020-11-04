#include <stdio.h>
#include <stdlib.h>
#define DIM 10
#define LUNG 100

typedef struct canzone{
    int num;
    char titolo[LUNG];
    char artista[LUNG];
}Canzone;

void caricaTab(Canzone vett[], int a, FILE *fp){
    char c;
    int cont=0;
    int j=0, k=0;
    
    while(fscanf(fp, "%c", &c)!= EOF){
        if(c=='\n'){
            cont=0;
            k++;
        }else{    
            if(c==','){
            cont++;
            j=0;            
            }else{
               
                switch (cont){
                    case 0:
                        
                        vett[k].num=c; 
                    break;
                    case 1:
                        vett[k].titolo[j]=c;
                        j++; //incremento il contatore dei caratteri   
                    break;
                    case 2:
                        vett[k].artista[j]=c;
                        j++; //incremento il contatore dei caratteri 
                    break;
                }

                
            }  

        }        
    }
        
        
    
}


void stampaTab(Canzone vett[], int a){
    for(int k=0; k<a; k++){
        printf("%c, %s, %s\n", vett[k].num, vett[k].titolo, vett[k].artista);
    }
}

void main(){
    FILE *fp;
    char nomeFile[]="canzoni.csv";
    Canzone vett[DIM];

    if((fp=fopen(nomeFile, "r"))==NULL){
        printf("il file non esiste");
    }else{
        caricaTab(vett, DIM, fp);
        stampaTab(vett, DIM);
    }
    
}