#include <stdio.h>
#include <stdlib.h>

#include "couleur.h"
#include "console.h"
#include "pion.h"
#include "pions.h"
#include "position.h"
#include "positions.h"

#include "plateau.h"

struct sPlateau{

    Position ** position;
    int nbLigne;
    int nbColonne;
};


Plateau initPlateau(int taille){

    int i,j;
    Plateau plateau=malloc(sizeof(struct sPlateau));
    plateau->nbLigne=taille;
    plateau->nbColonne=taille;
    plateau->position=malloc(taille*sizeof(Position*));
    for(i=0;i<taille;i++){
        plateau->position[i]=malloc(taille*sizeof(Position));
        for(j=0;j<taille;j++){
            plateau->position[i][j]=initPosition(i,j);
        }
    }
    return plateau;

}

void infoPlateau(Plateau plateau){

    int i,j;

    if(plateau!=NULL){
        printf("Nombre de ligne : %d\n",plateau->nbLigne);
        printf("Nombre de colonne : %d\n",plateau->nbColonne);
        afficherPlateau(plateau);
    }
}

void placerPion(Plateau plateau, int nbJoueur,Pions * joueurs, Pions liste){

    int i,j;
    int place2[5]={5,5,4,3,2};
    int place4[4]={4,4,3,2};
    Pion pion;

    if(nbJoueur == 2){
        for(i=0;i<5;i++){
            for(j=0;j<place2[i];j++){
                pion=initPion();
                setPositionPion(pion,plateau->position[plateau->nbLigne-i-1][j]);
                setPionPosition(plateau->position[plateau->nbLigne-i-1][j],pion);
                ajouterPion(liste,pion);
                ajouterPion(joueurs[0],pion);
                setCouleurPion(pion,0);
                setCouleurPosition(plateau->position[plateau->nbLigne-i-1][j],0);
                pion=initPion();
                setPositionPion(pion,plateau->position[i][plateau->nbColonne-j-1]);
                setPionPosition(plateau->position[i][plateau->nbColonne-j-1],pion);
                ajouterPion(liste,pion);
                ajouterPion(joueurs[1],pion);
                setCouleurPion(pion,1);
                setCouleurPosition(plateau->position[i][plateau->nbColonne-j-1],1);
            }
        }
    }
    if(nbJoueur == 4){
        for(i=0;i<4;i++){
            for(j=0;j<place4[i];j++){
                pion=initPion();
                setPositionPion(pion,plateau->position[i][j]);
                setPionPosition(plateau->position[i][j],pion);
                ajouterPion(liste,pion);
                ajouterPion(joueurs[0],pion);
                setCouleurPion(pion,0);
                setCouleurPosition(plateau->position[i][j],0);
                pion=initPion();
                setPositionPion(pion,plateau->position[i][plateau->nbColonne-j-1]);
                setPionPosition(plateau->position[i][plateau->nbColonne-j-1],pion);
                ajouterPion(liste,pion);
                ajouterPion(joueurs[3],pion);
                setCouleurPion(pion,3);
                setCouleurPosition(plateau->position[i][plateau->nbColonne-j-1],3);
                pion=initPion();
                setPositionPion(pion,plateau->position[plateau->nbLigne-i-1][j]);
                setPionPosition(plateau->position[plateau->nbLigne-i-1][j],pion);
                ajouterPion(liste,pion);
                ajouterPion(joueurs[2],pion);
                setCouleurPion(pion,2);
                setCouleurPosition(plateau->position[plateau->nbLigne-i-1][j],2);
                pion=initPion();
                setPositionPion(pion,plateau->position[plateau->nbLigne-i-1][plateau->nbColonne-j-1]);
                setPionPosition(plateau->position[plateau->nbLigne-i-1][plateau->nbColonne-j-1],pion);
                ajouterPion(liste,pion);
                ajouterPion(joueurs[1],pion);
                setCouleurPion(pion,1);
                setCouleurPosition(plateau->position[plateau->nbLigne-i-1][plateau->nbColonne-j-1],1);
            }
        }
    }
}

Position getPositionPlateau(Plateau plateau, int x, int y){

    if(x>=0 && y>=0 && x<plateau->nbLigne && y<plateau->nbColonne){
        return plateau->position[x][y];
    }

    return NULL;
}

void afficherPlateau(Plateau plateau){

    int i,j;
    Pion pion;
    Couleur couleur,couleurCase;
    printf(" \t");
    for(i=0;i<plateau->nbColonne;i++){
        printf("%c ",'A'+i);
    }
    printf("\n");
    for(i=0;i<plateau->nbLigne;i++){
        printf("%d\t",i+1);
        for(j=0;j<plateau->nbColonne;j++){
            pion=getPionPosition(plateau->position[i][j]);
            if(pion == NULL){
                printf(". ");
            }
            else{
                couleur=getCouleurPion(pion);
                couleurCase=getCouleurPosition(plateau->position[i][j]);
                texteCouleur("o ",couleurCase,couleur);
            }
        }
        printf("\n");
    }
}

Positions positionsPossible(Pion pion, Plateau plateau){

    Position position=getPositionPion(pion),position1=NULL;
    Positions positions=initPositions();
    int x=getXPosition(position),y=getYPosition(position),i,j;

    for(i=-1;i<=1;i++){
        for(j=-1;j<=1;j++){
            position1=getPositionPlateau(plateau,x+i,y+j);
            if(position){
                if(getPionPosition(position)==NULL){
                    ajouterPosition(positions,position);
                }
                else{
                    position1=getPositionPlateau(plateau,x+(2*i),y+(2*j));
                    if(position1 && !(getPionPosition(position1)) && !(positionEstDansPositions(positions,position))){
                        ajouterPosition(positions,position1);
                        positionRecursif(plateau,position1,positions);
                    }
                }
            }
        }
    }
    return positions;
}

void positionRecursif(Plateau plateau,Position position,Positions positions){

    int x=getXPosition(position),y=getYPosition(position),i,j;
    Position position1;

    for(i=-1;i<=1;i++){
        for(j=-1;j<=1;j++){
            position1=getPositionPlateau(plateau,x+i,y+j);
            if(position){
                if(getPionPosition(position)==NULL){
                    ajouterPosition(positions,position);
                }
                else{
                    position1=getPositionPlateau(plateau,x+(2*i),y+(2*j));
                    if(position1 && !(getPionPosition(position1)) && !(positionEstDansPositions(positions,position))){
                        ajouterPosition(positions,position1);
                        positionRecursif(plateau,position1,positions);
                    }
                }
            }
        }
    }
}
