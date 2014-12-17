#include <stdio.h>
#include <stdlib.h>

#include "liste.h"
#include "position.h"
#include "positions.h"

struct sPositions{
    Liste liste;
};

Positions initPositions(void){

    Positions positions=malloc(sizeof(struct sPositions));
    positions->liste=initListe();

    return positions;
}

void detruirePositions(Positions positions){
    detruireListe(positions->liste);
    free(positions);
}

void ajouterPosition(Positions positions, Position position){
    ajouterTete(positions->liste,position);
}

int positionEstDansPositions(Positions positions, Position position){
    if(positions != NULL){
        return estDansListe(positions->liste,position,positionEgale);
    }
    return 0;
}

Position positionTete(Positions positions){
    return listeTete(positions->liste);
}

Position positionCourant(Positions positions){
    return listeCourant(positions->liste);
}

void positionSuivant(Positions positions){
    elementSuivant(positions->liste);
}
void resetPosition(Positions positions){
    if(positions != NULL){
        resetListe(positions->liste);
    }
}

int positionEstVide(Positions positions){
    if(positions == NULL != positionTete(positions) == NULL){
        return 1;
    }
    return 0;
}

void infoPositions(Positions positions){

    if(!(positionEstVide(positions))){
        Position position;
        resetPosition(positions);
        do{
            infoPosition(positionCourant(positions));
            positionSuivant(positions);
        }while(positionCourant(positions)!=positionTete(positions));
    }
}


