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
        printf("Joueur No%d :\n",i);
        infoJoueur(jeu->joueur[i]);
    }
    printf("Nombre de plateaux : %d\n",jeu->nbPlateau);
    for(i=0;i<jeu->nbPlateau;i++){
        printf("Info Plateau No%d :\n",i);
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

    int fin=0,ligne=0;
    char colonne=0;
    jeu->tour=0;
    Joueur joueur=NULL;
    Pion pion=NULL;
    Position position=NULL;
    Positions positions=NULL;
    Plateau plateau=NULL;

    while(fin==0){
        plateau=initPlateau(jeu->taille);
        joueur=jeu->joueur[jeu->tour%jeu->nbJoueur];
        printf("Au tour de %s\n",getJoueurNom(joueur));
        do{
            if(joueurEstIa(joueur)==0){
                pion==NULL;
                while(pion == NULL || getCouleurPion(pion) != getCouleurJoueur(joueur)){
                    ligne=0;
                    colonne=0;
                    pion==NULL;
                    afficherPlateau(jeu->plateau[0]);
                    printf("Selectioner un pion parmis les pions que vous avez :\n");
                    viderBuffer();
                    scanf("%c %d",&colonne,&ligne); // TODO pouvoir renter la lettre de la colonne
                    colonne--;
                    ligne--;
                    position=getPositionPlateau(jeu->plateau[0],ligne,(int)((colonne)-64));
                    pion=getPionPosition(position);
                    if(pion == NULL){
                        printf("Emplacement invalide\n");
                    }
                }
                positions=positionsPossible(pion,jeu->plateau[0]);
                if(positionEstVide(positions)){
                    printf("Ce pion n'a aucun coup possible\n");
                }
            }
        }while(positionEstVide(positions));
        do{
            if(joueurEstIa(joueur)==0){
                ligne=0;
                colonne=0;
                afficherPlateauPosition(jeu->plateau[0],positions);
                printf("Selectioner une destination:\n");
                viderBuffer();
                scanf("%c %d",&colonne,&ligne); // TODO pouvoir renter la lettre de la colonne
                colonne--;
                ligne--;
                position=getPositionPlateau(jeu->plateau[0],ligne,(int)((colonne)-64));
            }
        }while(!(positionEstDansPositions(positions,position)));
        setPionPosition(getPositionPion(pion),NULL);
        setPionPosition(position,pion);
        setPositionPion(pion,position);
        jeu->tour++;
    }
    fin=1;
}
