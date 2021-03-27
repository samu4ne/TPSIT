
#include <stdio.h>
#include <stdlib.h>



typedef struct canzone{
    int num;
    char *titolo;
    char *artista;
}Canzone;

int leggiRighe(FILE *fp){
    
}

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
    int r;
    for(int k=0; k<a; k++){
        r=rand()%10+0;
        printf("%c, %s, %s\n", vett[r].num, vett[r].titolo, vett[r].artista);
    }
}



void main(){
    FILE *fp;
    char nomeFile[]="canzoni.csv";
    Canzone *vett;
    int dim;    //numero di righe

    vett=(Canzone *)malloc(sizeof(Canzone));

    if((fp=fopen(nomeFile, "r"))==NULL){
        printf("il file non esiste");
    }else{
        dim = leggiRighe(fp);
        caricaTab(vett, fp);
        stampaTab(vett);
    }
    
}


/*
eserizio conn la malloc

typedef struct canzone{
    int numero;
    char autore[100];
    char nome[100];
    int val;
}Canzone;

void leggiFile(Canzone* playlist,FILE *fp){//*cnt è il numero di canzoni 
    char lettera; // lettera che legge nel file (lettera per lettera)
    char* parola; //parola completa (successione di tutte le lettere prima della ',')
    parola = (char*) malloc(100*sizeof(char));
    int indice=0; // indice che serve a capire cosa sto leggendo
    int j=0;
    int cntLettera=0;
    while(fscanf(fp,"%c",&lettera)!=EOF){//legge lettera
        if(lettera==','){// se è arrivata alla fine della parola
            *(parola+cntLettera)='\0';//aggiunge alla fine della parola completa '0'
            /*
            INDICE:
            0-> numero della canzone
            1-> titolo della canzone
            2-> autore della canzone
            
            switch (indice){
                case 0:
                    (playlist+j)->numero=j+1;
                    break;
                case 1:
                    strcpy((playlist+j)->nome,parola);
                break;
                case 2:
                    strcpy((playlist+j)->autore,parola);
                break;
            }
            indice=(indice+1)%3;//incremento indice
            //printf("%s\n",parola);
            cntLettera=0;
            free(parola);
            parola = (char*) malloc(100*sizeof(char));
            if(indice==0)//se ho finito di leggere la canzone
                j++;//incremento contatore canzone
        }else{
            *(parola+cntLettera)=lettera;//aggiunge alla fine della parola l'ultima lettera letta
            cntLettera++;
        }
    }
    return;
}

void canzoniRandom(Canzone* playlist,int cnt){
    srand(time(NULL));
    for(int i=0;i< cnt;i++)
        (playlist+i)->val=rand()%10000000;
    int max=0;
    for(int i=0;i<cnt;i++){
        max=i;
        for(int j=0;j<cnt;j++){
            if((playlist+max)->val<(playlist+j)->val){
                max=j;
            }
        }
        printf("%d %s %s %d\n",(playlist+max)->numero,(playlist+max)->nome,(playlist+max)->autore,(playlist+max)->val);
        (playlist+max)->val=-100+i;
    }
    return;
}

void contaElementi(FILE *fp,int *cnt){
    char* riga = (char*) malloc(200);
    
    while(fgets(riga,100,fp)){
        *cnt += 1;
    }
    *cnt-=1;
    fclose(fp);
    fp=fopen("spotify.csv","r");
    free(riga);
    return;
}

void main(){
    FILE *fp;
    int cnt=0;
    if((fp=fopen("spotify.csv","r"))==NULL){
        printf("il file non esiste");
    }else{
        contaElementi(fp,&cnt);
        Canzone* playlist;
        playlist = (Canzone*) malloc((cnt)*sizeof(Canzone));
        leggiFile(playlist,fp);
        canzoniRandom(playlist,cnt);
        for(Canzone* i=playlist;i-playlist<cnt;i++){
            //printf("numero: %d nome: %s autore: %s\n",i->numero,i->nome,i->autore);
        }
    }
    
    
    return;
}
*/


typedef struct canzone{
    int num;
    char *titolo;
    char *artista;
    struct canzone *next;   
}Canzone;

void main(){
    Canzone *playlist;
    playlist= (Canzone*) malloc (sizeof(Canzone));
    playlist->ind= ....

}
