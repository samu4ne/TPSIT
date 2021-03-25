/* Samuele Forneris
   es:
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define width 120
#define height 30

main(){
    int n,giorni;
    int DIM=100;
    float r, contagiati;
    bool a=true;
    int cnt=0;
    float v[DIM];

    giorni=0;
    contagiati=1;

    printf("inserire il numero di alunni ");
    scanf("%d",& n);
    printf("inserire i numeri di contagi giornalieri ");
    scanf("%f",& r);

    do{
        if(contagiati<n){
            v[cnt]=contagiati;
            contagiati=contagiati*r;
            giorni++;
            cnt++;

        }else{
            a=false;
        }
    }while(a==true);

    v[cnt]=contagiati;

    printf("i numeri di giorni e' %d\n", giorni);

    for(int k=0; k<cnt;k++){
        printf("%f\n", v[k]);
    }

	printf("\npremere il tasto INVIO per chiudere");
	getch();
}
