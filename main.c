#include <stdio.h>
#include <unistd.h>
#include "Librerie/libreria_principale.h"
#define MAX_SEQ_V 5
#define MAX_SEQ_N 20
#define MAX_RIGA 200


int main(){
    FILE *f1; FILE *f2;
    char riga[MAX_RIGA+2]={'\0'}; char parola[MAX_STR]={'\0'}; //+2 /r/n
    int n_seq=0; char seq[MAX_SEQ_N][MAX_SEQ_V+2]={'\0'}; //+2 /r/n
    int  x=0; char ch; int pos=0; int true=0;
    printf("Laboratorio 2 es 2:\n");
    //Apertura Files
    printf("Primo File:\n");
    f1=FILE_apri_file(FILENAME_MAX,"r");
    printf("Secondo file:\n");
    f2=FILE_apri_file(FILENAME_MAX,"r");
    fscanf(f1," %d ",&n_seq);
    printf("Ricorrenze:\n");
    for (int i = 0; i < n_seq; ++i) {
        fgets(seq[i],MAX_SEQ_V+2,f1); //+2 /r/n
        str_tolower(seq[i]); //Ora funge --->sbagliata toalnum
    }
    while (fgets(riga, MAX_RIGA+2, f2) != NULL) { //Fino alla fine del file //+2 /r/n
        for (int i = 0; riga[i] != '\n' && riga[i] != '\0'; ++i) { //Vai fino alla fine della riga o del testo...
            ch = riga[i];
            if (isalpha(ch)) { //creo la parola
                parola[x] = ch;
                x++;
            } else { //ho trovato una parola, eseguo le operazioni su di essa
                pos++; //Agg. la posizione
                if(strlen(parola)==1&&(ispunct(ch)||isspace(ch))) pos--; //Non se è un segno di punteggiatura o uno spazio agg.
                for (int k = 0; k < n_seq; ++k) {
                    str_tolower(parola);
                    if(!strncmp(seq[k],parola,strlen(seq[k]))){
                        printf("-[%s] %s %d\n",seq[k],parola,pos);
                    }
                }
                for (int j = 0; parola[j] != '\0'; ++j) { //Azzero la parola
                    parola[j] = '\0';
                }
                x=0;
            }
        }
        pos--; //Corr. /r
    }
#ifdef DEBUG
    printf("DEBUG:\n");
    printf("Non capisco perche' non 31 e si 32 non funzionino!")
#endif
    fclose(f1);
    fclose(f2);
    sleep(5);
    exit(EXIT_SUCCESS);
}