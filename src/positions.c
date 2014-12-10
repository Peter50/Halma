#include <stdio.h>
#include <stdlib.h>

#include "liste.h"
#include "position.h"
#include "positions.h"


// Songer a implémenter un TAD liste commmun au type positions et pions

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
    return estDansListe(positions->liste,position,positionEgale());
}

Position positionCourant(Positions positions){
    return listeCourant(positions->liste);
}

void positionSuivant(Positions positions){
    elementSuivant(positions->liste);
}


