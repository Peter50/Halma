#include <stdio.h>
#include <stdlib.h>


#include "pion.h"
#include "pions.h"
#include "plateau.h"
#include "position.h"
#include "positions.h"
#include "joueur.h"
#include "jeu.h"

void viderBuffer(void){
    char i=0;
    while (i != '\n' && i != EOF){
        i = getchar();
    }
}

struct sJeu{

    int tour;
    int nbJoueur;
    int nbIa;
    int taille;
    Pions * pionsJoueur;
    Pions pions;
    Plateau plateau;
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
    jeu->plateau=initPlateau(taille);
    jeu->nbPlateau=1;

    jeu->joueur=malloc(joueur*sizeof(Joueur));

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
    placerPion(jeu->plateau,jeu->nbJoueur,jeu->pionsJoueur,jeu->pions);

    return jeu;
}

void detruireJeu(Jeu jeu){

    int i;

    detruirePlateau(jeu->plateau);
    for(i=0;i<jeu->nbJoueur;i++){
        detruireJoueur(jeu->joueur[i]);
    }
    free(jeu->joueur);
    for(i=0;i<jeu->nbJoueur;i++){
        detruirePions(jeu->pionsJoueur[i]);
    }
    free(jeu->pionsJoueur);
    detruirePions(jeu->pions);
    free(jeu);
}

void infoJeu(Jeu jeu){

    int i;

    printf("Tour : %d\n",jeu->tour);
    printf("Nombre de joueur : %d\n",jeu->nbJoueur);
    printf("Nombre d'IA : %d\n",jeu->nbIa);
    for(i=0;i<jeu->nbJoueur;i++){
        printf("Joueur No%d :\n",i);
        infoJoueur(jeu->joueur[i]);
    }
    printf("Nombre de plateaux : %d\n",jeu->nbPlateau);
    for(i=0;i<jeu->nbPlateau;i++){
        printf("Info Plateau No%d :\n",i);
        infoPlateau(jeu->plateau);
    }
}

afficherPlateauCourant(Jeu jeu){
    afficherPlateau(jeu->plateau);
}

void lancerJeu(Jeu jeu){

    int fin=0,ligne=0;
    char colonne=0;
    jeu->tour=0;
    Joueur joueur=jeu->joueur[0];
    Pion pion=NULL;
    Position position=NULL;
    Positions positions=NULL;
    Plateau plateau=jeu->plateau;
    effacerEcran();
    srand(time(NULL));

    while(!(fin)){
        joueur=jeu->joueur[jeu->tour%jeu->nbJoueur];
        if(joueurEstIa(joueur)==0){
        effacerEcran();
        }
        printf("\033[0;0H");
        printf("Tour %d:\n",(jeu->tour/jeu->nbJoueur)+1);
        printf("Au tour de %s (",getJoueurNom(joueur));
        infoCouleur(getCouleurJoueur(joueur));
        printf(")");
        printf("\033[K\n");
        afficherPlateau(jeu->plateau);
        do{
            if(joueurEstIa(joueur)==0){
                pion==NULL;
                while(pion == NULL || getCouleurPion(pion) != getCouleurJoueur(joueur)){
                    ligne=0;
                    colonne=0;
                    pion==NULL;
                    positions=NULL;
                    printf("Selectioner un pion parmis les pions que vous avez :\n");
                    viderBuffer();
                    scanf("%c %d",&colonne,&ligne);
                    colonne--;
                    ligne--;
                    position=getPositionPlateau(jeu->plateau,ligne,(int)((colonne)-64));
                    pion=getPionPosition(position);
                    if(pion == NULL){
                        printf("Emplacement invalide\n");
                    }
                    else if(getCouleurPion(pion) != getCouleurJoueur(joueur)){
                        printf("Ce n'est pas votre pion.\n");
                    }
                }
                positions=positionsPossible(pion,jeu->plateau);
                if(positionEstVide(positions)){
                    printf("Ce pion n'a aucun coup possible\n");
                }
            }
            else{
                do{
                pion=pionAleatoire(jeu->pionsJoueur[jeu->tour%jeu->nbJoueur]);
                positions=positionsPossible(pion,jeu->plateau);
                }while(positionEstVide(positions));
            }
        }while(positionEstVide(positions));
        do{
            if(joueurEstIa(joueur)==0){
                ligne=0;
                colonne=0;
                effacerEcran();
                printf("Tour %d:\n",(jeu->tour/jeu->nbJoueur)+1);
                printf("Au tour de %s (",getJoueurNom(joueur));
                infoCouleur(getCouleurJoueur(joueur));
                printf(")\n");
                afficherPlateauPosition(jeu->plateau,positions);
                printf("Selectioner une destination:\n");
                viderBuffer();
                scanf("%c %d",&colonne,&ligne); // TODO pouvoir renter la lettre de la colonne
                colonne--;
                ligne--;
                position=getPositionPlateau(jeu->plateau,ligne,(int)((colonne)-64));
            }
            else{
                position=positionAleatoire(positions);
            }
        }while(position == NULL || !(positionEstDansPositions(positions,position)));
        setPionPosition(getPositionPion(pion),NULL);
        setPionPosition(position,pion);
        setPositionPion(pion,position);
        jeu->tour++;
        fin=CDV(jeu);
    }
    printf("Le joueur %s est déclaré vanqueur !!!\nFélicitation\n",getJoueurNom(jeu->joueur[fin-1]));
}

int CDV(Jeu jeu){

    int i;
    Positions positions=NULL;
    Pions pions=NULL;
    Pion pion=NULL;
    int fin;

    for(i=0;i<jeu->nbJoueur;i++){
        pions=jeu->pionsJoueur[i];
        resetPions(pions);
        pion=pionTete(pions);
        fin=i;
        do{
            if(getCouleurPion(pion) != getCouleurPositionOppose(getPositionPion(pion))){
                    fin=-1;
            }
            pionSuivant(pions);
            pion=pionCourant(pions);
        }while(pion!=pionTete(pions));
        if(fin!= -1){
            return fin;
        }
    }
    return 0;
}

void effacerEcran(void){
    printf("%c[2J", 0x1B);
    printf("\033[0;0H");
}
