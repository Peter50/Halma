#include <stdio.h>
#include <stdlib.h>

#include "pion.h"
#include "pions.h"
#include "plateau.h"
#include "position.h"
#include "positions.h"
#include "joueur.h"
#include "jeu.h"

struct sJeu{

    int tour;
    int nbJoueur;
    int nbIa;
    int taille;
    Pions * pionsJoueur;
    Pions pions;
    Plateau * plateau;
    int nbPlateau;
    Joueur * joueur;

};


Jeu initJeu(int joueur, int ia,int taille){

    int i,ordi;
    Jeu jeu=malloc(sizeof(struct sJeu));
    jeu->tour=0;
    jeu->nbJoueur=joueur;
    jeu->nbIa=ia;
    jeu->taille=taille;
    jeu->plateau=malloc(sizeof(Plateau*));
    jeu->plateau[0]=initPlateau(taille);
    jeu->nbPlateau=1;

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
    jeu->pionsJoueur=malloc(joueur*sizeof(Pions*));
    for(i=0;i<joueur;i++){
        jeu->pionsJoueur[i]=initPions();
    }
    jeu->pions=initPions();
    placerPion(jeu->plateau[0],jeu->nbJoueur,jeu->pionsJoueur,jeu->pions);

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

afficherPlateauCourant(Jeu jeu){
    afficherPlateau(jeu->plateau[jeu->tour]);
}

void lancerJeu(Jeu jeu){

    int fin=0,ligne;
    char colonne;
    Joueur joueur=NULL;
    Pion pion=NULL;
    Position position=NULL;
    Positions positions=NULL;
    Plateau plateau=NULL;

    while(fin==0){
        plateau=initPlateau(jeu->taille);
        joueur=jeu->joueur[jeu->tour%4];
        if(joueurEstIa(joueur)==0){
            pion==NULL;
            while(pion == NULL || getCouleurPion(pion) != getCouleurJoueur(joueur)){
                printf("Selectioner un pion parmis les pions que vous avez\n");
                scanf("%d %c",&ligne,&colonne);
                colonne=(int)colonne-'A';
                position=getPositionPlateau(jeu->plateau[jeu->tour]);
                pion=getPionPosition(position);
            }
            positions=positionsPossible(pion,jeu->plateau[jeu->tour]);
        }
        jeu->tour++;
    }
}
