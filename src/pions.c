#include <stdio.h>
#include <stdlib.h>

#include "pion.h"
#include "pions.h"

struct sPions{
    Liste liste;
};

Pions initPions(void){

    Pions pions=malloc(sizeof(struct sPions));
    pions->liste=initListe();
}

void detruirePions(Pions pions){
    detruireListe(pions->liste);
    free(pions);
}

void ajouterPion(Pions pions,Pion pion){
    ajouterTete(pions->liste,pion);
}

int pionEstDansPions(Pions pions,Pion pion){
    return estDansListe(pions,pion,)
}
