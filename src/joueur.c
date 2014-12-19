#include <stdio.h>
#include <stdlib.h>

#include "couleur.h"
#include "pion.h"
#include "pions.h"
#include "joueur.h"

struct sJoueur{

    char * nom;
    int tailleNom;
    Couleur couleur;
    Pions pions;
    int ia;

};

Joueur initJoueur(int numero, int ia){

    Joueur joueur=malloc(sizeof(struct sJoueur));
    joueur->pions=initPions();
    joueur->couleur=numero-1;
    joueur->ia=ia;

    switch(numero){
        case 1:
            joueur->nom="Alice";
            joueur->tailleNom=5;
        break;
        case 2:
            joueur->nom="Bob";
            joueur->tailleNom=3;
        break;
        case 3:
            joueur->nom="Charlote";
            joueur->tailleNom=8;
        break;
        default:
            joueur->nom="David";
            joueur->tailleNom=5;
        break;
    }

    return joueur;
}

void infoJoueur(Joueur joueur){

    printf("Nom du joueur %s\n",joueur->nom);
    printf("Nombre de caractere du nom du joueur : %d\n",joueur->tailleNom);
    if(joueur->ia){
        printf("Ce joueur est une IA\n");
    }
    else{
        printf("Ce joueur est humain\n");
    }
    printf("La couleur du joueur est : ");
    infoCouleur(joueur->couleur);
    printf("\n");
}

void detruireJoueur(Joueur joueur){
    detruirePions(joueur->pions);
    free(joueur);
}

int joueurEstIa(Joueur joueur){
    return joueur->ia;
}

Couleur getCouleurJoueur(Joueur joueur){
    return joueur->couleur;
}

void ajouterPionJoueur(Joueur joueur, Pion pion){
    ajouterPion(joueur->pions,pion);
}

Pions getPionsJoueur(Joueur joueur){
    return joueur->pions;
}

char * getJoueurNom(Joueur joueur){
    return joueur->nom;
}

