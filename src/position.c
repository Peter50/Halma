#include <stdio.h>
#include <stdlib.h>

#include "couleur.h"
#include "pion.h"
#include "position.h"

struct sPosition{

    unsigned int x;
    unsigned int y;
    Couleur couleur;
    Pion pion;

};

Position initPosition(int x,int y){

    Position position=malloc(sizeof(struct sPosition));
    position->x=x;
    position->y=y;

    return position;
}

void infoPosition(Position position){

    if(position != NULL){
        printf("Position ligne : %d\n",position->x);
        printf("Position colonne : %d\n",position->y);
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

Pion getPionPosition(Position position){
    return position->pion;
}

void setPionPosition(Position position,Pion pion){
    position->pion=pion;
}

Couleur getCouleurPosition(Position position){
    return position->couleur;
}

void setCouleurPosition(Position position,Couleur couleur){
    position->couleur=couleur;
}
