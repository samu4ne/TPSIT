#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//data,stato,codice_regione,denominazione_regione,lat,long,ricoverati_con_sintomi,terapia_intensiva,totale_ospedalizzati,isolamento_domiciliare,totale_positivi,varia
//variazione_totale_positivi,nuovi_positivi,dimessi_guariti,deceduti,casi_da_sospetto_diagnostico,casi_da_screening,totale_casi,tamponi,casi_testati
#define DIM 200


typedef struct contagi{
    char *data;
    char *stato;
    int codReg;
    char *reg;
    float lat;
    float longi;
    int ricoSintomi;
    int terIntens;
    int ricoverati;
    int isolamenti;
    int positivi;
    int variazionePos;
    int nuoviPos;
    int dimessiGuariti;
    int deceduti;
    int sospettoDiagnostico;
    int casiScreening;
    int otaleCasi;
    int tamponi;
    int casiTestati;
    bool preso; 
}Contagi;

int contaRegioni(FILE *fp){
    int cnt=0;
    char *riga;
    riga = (char*)malloc(200*sizeof(char));
    while(fgets(riga, 200, fp)){
        cnt++;
    }
    free(riga);
    return cnt;
}

void settaRegioni(Contagi* regioni,int cnt){
    for(int i=0;i<cnt;i++){
        (regioni+i)->data = (char*) malloc(sizeof(char)*19);
        (regioni+i)->stato = (char*) malloc(sizeof(char)*19);
        (regioni+i)->reg = (char*) malloc(sizeof(char)*19);
    }
    return;
}

/*
int contaColon(FILE *fp, int k){
    char s[DIM];
    int cnt, max;
    for(int i=0; i<k; i++){
        while(fscanf(fp, "%c",& s[cnt])!='\n'){
            cnt++;
        }
        if(max<cnt){
            max=cnt;
        }
    }
    
    return max;
}
*/

void leggiFile(FILE *fp,Contagi *tab,int n, int k){
    char* reg = (char*) malloc(sizeof(char)*k );
    int cnt=0;
    while(fgets(reg, k, fp)){    //prende tutta la righa di lung k nella variabile riga  
        strcpy((tab+cnt)->data, strtok(reg, ","));
        strcpy((tab+cnt)->stato, strtok(NULL, ","));
        (tab+cnt)->codReg = atoi(strtok(NULL,","));
        strcpy((tab+cnt)->reg , strtok(NULL, ","));
        (tab+cnt)->lat= atof(strtok(NULL, ","));
        (tab+cnt)->longi= atof(strtok(NULL, ","));
        (tab+cnt)->ricoSintomi= atoi(strtok(NULL, ","));
        (tab+cnt)->terIntens= atoi(strtok(NULL, ","));
        (tab+cnt)->ricoverati= atoi(strtok(NULL, ","));
        (tab+cnt)->isolamenti= atoi(strtok(NULL, ","));
        (tab+cnt)->positivi= atoi(strtok(NULL, ","));
        (tab+cnt)->variazionePos= atoi(strtok(NULL, ","));
        (tab+cnt)->nuoviPos= atoi(strtok(NULL, ","));
        (tab+cnt)->dimessiGuariti= atoi(strtok(NULL, ","));
        (tab+cnt)->deceduti= atoi(strtok(NULL, ","));
        (tab+cnt)->sospettoDiagnostico= atoi(strtok(NULL, ","));
        (tab+cnt)->casiScreening= atoi(strtok(NULL, ","));;
        (tab+cnt)->otaleCasi= atoi(strtok(NULL, ","));
        (tab+cnt)->tamponi= atoi(strtok(NULL, ","));
        (tab+cnt)->casiTestati= atoi(strtok(NULL, ","));
        (tab+cnt)->preso= false; 
        cnt=cnt+1;
    }
    return; 
}

void assegnaFalse(Contagi *tab, int n){
    for(int k=0; k<n; k++){
        (tab+k)->preso=false;
    }
    return;
}

void terapiaIntensiva(Contagi *tab, int n){
    int temp=0;
    for(int j=0; j<3; j++){
        temp=0;
        for(int k=0; k<n; k++){
            if(temp<(tab+k)->terIntens && (tab+k)->preso==false){
               temp=(tab+k)->terIntens;
               (tab+k)->preso=true; 
            }
        }
        for(int i=0; i<n;i++){
            if((tab+i)->terIntens==temp){
                printf("la %d regione che ha terapia intensiva= %s \n", j+1, (tab+i)->reg);
            }
        }
        
    }
    assegnaFalse(tab, n);
    return;
}



void totRico(Contagi *tab, int n){
    int tot=0;
    for(int k=0; k<n; k++){
        tot=tot+(tab+k)->terIntens;
    }
    printf("il numero di terapie intensivi in italia e'= %d", tot);
    return;
}

void menoCont(Contagi *tab, int n){
    int min=0;
    int temp=0;
    for(int j=0; j<n; j++){
        if(min<(tab+j)->positivi && (tab+j)->preso==false){
            min=(tab+j)->positivi;          //setta il minimo al 
        }
    }

    for(int k=0; k<3; k++){
        for(int j=0; j<n; j++){
            if((min>(tab+j)->positivi) && ((tab+j)->preso==false)){
                min=(tab+j)->positivi;
                (tab+j)->preso=true;
                temp=j;
            }
        }
        
        printf("\nla %d con meno contagi e'= %s", k+1, (tab+temp)->reg);
        
    
    }
    return;
}

void main(){
    FILE *fp;
    int colonne, righe;
    Contagi *tab;

    if((fp=fopen("dati.csv", "r"))==NULL){
        printf("il file non esiste");
    }else{
        tab= (Contagi*)malloc(righe*sizeof(Contagi));
        righe=contaRegioni(fp);
        settaRegioni(tab, righe);
        fclose(fp);
        fp=fopen("dati.csv", "r");
        //colonne=contaColon(fp, righe);
        leggiFile(fp, tab, righe, DIM);
        terapiaIntensiva(tab, righe);
        totRico(tab, righe);
        menoCont(tab, righe);
        fclose(fp);
    }
    
}