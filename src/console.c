#include <stdio.h>
#include <stdlib.h>

#include "couleur.h"

#define clrscr() printf("\033[H\033[2J")

#define couleur(param) printf("\033[%sm",param)

void texteCouleur(char * texte,Couleur fond,Couleur police)
{

    #ifdef __linux
    if(police==fond)
    {
        police=5;
    }
    switch(fond)
    {
    case ROUGE:
        couleur("41");
        break;
    case BLEU:
        couleur("44");
        break;
    case VERT:
        couleur("42");
        break;
    case JAUNE:
        couleur("43");
        break;
    case  MAGENTA:
        couleur("45");
    break;
    }
    switch(police)
    {
    case INCOLORE:
        break;
    case ROUGE:
        couleur("31");
        break;
    case BLEU:
        couleur("34");
        break;
    case VERT:
        couleur("32");
        break;
    case JAUNE:
        couleur("33");
        break;
    }
    printf(texte);
    couleur("0");
    #else
    printf("%d ",police);
    #endif
}
