#include <stdio.h>
#include <stdlib.h>

#include "couleur.h"
#include "pion.h"
#include "position.h"

struct sPosition{

    unsigned int x;
    unsigned int y;
    Couleur couleur;
    Couleur oppose;
    Pion pion;

};

Position initPosition(int x,int y){

    Position position=malloc(sizeof(struct sPosition));
    position->x=x;
    position->y=y;
    position->pion=NULL;
    position->couleur=INCOLORE;
    position->oppose=INCOLORE;

    return position;
}

void infoPosition(Position position){

    if(position != NULL){
        printf("Position ligne : %d\n",position->x+1);
        printf("Position colonne : %d\n",position->y+1);
    }
}

void detruirePosition(Position position){
    free(position);
}

int positionEgale(Position position,Position position2){
    if(position->x == position2->x && position2->y==position->y){
        return 1;
    }
    return 0;
}

unsigned int getXPosition(Position position){
    return position->x;
}

unsigned int getYPosition(Position position){
    return position->y;
}


Pion getPionPosition(Position position){
    if(position!=NULL){
        return position->pion;
    }
    return NULL;
}

void setPionPosition(Position position,Pion pion){
    position->pion=pion;
}

Couleur getCouleurPosition(Position position){
    return position->couleur;
}

Couleur getCouleurPositionOppose(Position position){
    return position->oppose;
}

void setCouleurPosition(Position position,Couleur couleur){
    position->couleur=couleur;
    if(couleur%2==1){
        couleur--;
    }
    else{
        couleur++;
    }
    position->oppose=couleur;
}
