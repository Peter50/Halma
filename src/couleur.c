#include <stdio.h>
#include <stdlib.h>

#include "couleur.h"

void infoCouleur(Couleur couleur){

    switch(couleur){
        case ROUGE:
        printf("ROUGE");
        break;
        case BLEU:
        printf("BLEU");
        break;
        case VERT:
        printf("VERT");
        break;
        case JAUNE:
        printf("JAUNE");
        break;
    }

}
