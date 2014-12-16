#include <stdio.h>
#include <stdlib.h>

#include "couleur.h"

#define clrscr() printf("\033[H\033[2J")

#define couleur(param) printf("\033[%sm",param)

void texteCouleur(char * texte,Couleur fond,Couleur police){

    if(police==fond){
        police=5;
    }
    switch(fond){
        case ROUGE:
            couleur("41");
        break;
        case BLEU:
            couleur("43");
        break;
        case VERT:
            couleur("44");
        break;
        case JAUNE:
            couleur("42");
        break;
    }
    switch(police){
        case INCOLORE:
            couleur("30");
        break;
        case ROUGE:
            couleur("31");
        break;
        case BLEU:
            couleur("33");
        break;
        case VERT:
            couleur("34");
        break;
        case JAUNE:
            couleur("32");
        break;
    }
    printf(texte);
    couleur("0");
}
