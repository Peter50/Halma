#include <stdio.h>
#include <stdlib.h>

#include "pions.h"
#include "position.h"

#include "plateau.h"

struct sPlateau{

    Pions * pions;
    Position ** position;
    int nbLigne;
    int nbColonne;
    int nbPions;

};


Plateau initPlateau(void){

    Plateau plateau=malloc(sizeof(struct sPlateau));
    plateau->pions=NULL;
    plateau->position=NULL;

    return plateau;

}

void infoPlateau(Plateau plateau){

    int i,j;

    if(plateau!=NULL){
        printf("Nombre de ligne : %d\n",plateau->nbLigne);
        printf("Nombre de colonne : %d\n",plateau->nbColonne);
        for(i=0;i<plateau->nbLigne;i++){
            for(j=0;j<plateau->nbColonne;j++){
                infoPosition(plateau->position[i][j]);
            }
        }
    }
}
