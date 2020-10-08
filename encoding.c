/* Samuele Forneris
   es:
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define width 120
#define height 30
#define LUNG 50

//il menù serve per far scegliere all'utente cosa vuole fare
int menu(){
    int scelta;
    printf("0-esci\n");
    printf("1-decoding\n");
    printf("2-encoding\n");
    scanf("%d",& scelta);
    return (scelta);
}

//questa funzione serve per comprimere un stringa data in input dall'utente
void encoding(){
    char string[LUNG];
    int k=0;
    int cnt=1;
    int a=0;
    printf("inserire la stringa per la quale si vuole fare decoding ");
    scanf("%s",& string);

    a=strlen(string);

    while(k<a){
        while(string[k]==string[k+1]){
                cnt++;
                k++;
        }
        if(cnt!=1){
            printf("%d%c", cnt, string[k]);
            cnt=1;
        }else{
            k++;
        }


    }

    return 0;
}

//questa funzione serve per decoprimere un stringa inserita dall'utente
void decoding(){
    char string[LUNG];
    int a=0;
    int temp;
    int k=0;
    printf("inserire la stringa per la quale si vuole fare decoding ");
    scanf("%s",& string);
    a=strlen(string);
    for(int k=0; k<a; k++){
        temp=string[k]-48;
        if(temp<9&&temp>0){
            //allora � un numero
            for(int i=1; i<temp; i++){
                printf("%c", string[k+1]);
            }
        }else{
            printf("%c", string[k]);
        }

    }
}

main(){

    int scelta;

    scelta= menu();

    if(scelta==2){
        encoding();
    }else{
        decoding();
    }



	printf("\npremere il tasto INVIO per chiudere");
	getch();
}
