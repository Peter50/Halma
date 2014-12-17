#include <stdio.h>
#include <stdlib.h>

#include "position.h"
#include "couleur.h"
#include "pion.h"

struct sPion{

    Position position;
    Couleur couleur;
};

Pion initPion(void){
    Pion pion=malloc(sizeof(struct sPion));

    return pion;
}

void detruirePion(Pion pion){
    free(pion);
}

void setPositionPion(Pion pion, Position position){
    pion->position=position;
}

void setCouleurPion(Pion pion, Couleur couleur){
    pion->couleur=couleur;
}

Couleur getCouleurPion(Pion pion){
    if(pion != NULL){
        return pion->couleur;
    }
    return INCOLORE;
}

Position getPositionPion(Pion pion){

    return pion->position;
}

int pionEstEgale(Pion pion1,Pion pion2){
    if(positionEgale(pion1->position,pion2->position) && pion1->couleur == pion2->couleur){
        return 1;
    }
    return 0;
}
