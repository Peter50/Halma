#include <stdio.h>
#include <stdlib.h>

#include "plateau.h"
#include "joueur.h"
#include "jeu.h"

struct sJeu{

    int tour;
    int nbJoueur;
    int nbIa;
    Plateau * plateau;
    int nbPlateau;
    Joueur * joueur;

};


Jeu initJeu(int joueur, int ia){

    int i,ordi;

    Jeu jeu=malloc(sizeof(struct sJeu));
    jeu->tour=0;
    jeu->nbJoueur=joueur;
    jeu->nbIa=ia;

    jeu->joueur=calloc(joueur,sizeof(Joueur));

    for(i=0;i<joueur;i++){
        if(i<ia){
            ordi=1;
        }
        else{
            ordi=0;
        }
        jeu->joueur[i]=initJoueur(i+1,ordi);
    }

    return jeu;
}

void infoJeu(Jeu jeu){

    int i;

    printf("Tour : %d\n",jeu->tour);
    printf("Nombre de joueur : %d\n",jeu->nbJoueur);
    printf("Nombre d'IA : %d\n",jeu->nbIa);
    for(i=0;i<jeu->nbJoueur;i++){
        printf("Joueur N°%d :\n",i);
        infoJoueur(jeu->joueur[i]);
    }
    printf("Nombre de plateaux : %d\n",jeu->nbPlateau);
    for(i=0;i<jeu->nbPlateau;i++){
        printf("Info Plateau N°%d :\n",i);
        infoPlateau(jeu->plateau[i]);
    }
}

void detruireJeu(Jeu jeu){

    int i;

    for(i=0;i<jeu->nbJoueur;i++){
        detruireJoueur(jeu->joueur[i]);
    }
    free(jeu);

}
