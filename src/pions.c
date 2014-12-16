#include <stdio.h>
#include <stdlib.h>

#include "pion.h"
#include "liste.h"
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

Pion pionCourant(Pions pions){
    return listeCourant(pions->liste);
}

void pionSuivant(Pions pions){
    elementSuivant(pions->liste);
}

void ajouterPion(Pions pions,Pion pion){
    ajouterTete(pions->liste,pion);
}

int pionEstDansPions(Pions pions,Pion pion){
    return estDansListe(pions,pion,pionEstEgale());
}
