#include <stdio.h>
#include <stdlib.h>

#include "position.h"

struct sPosition{

    unsigned int x;
    unsigned int y;

};

Position initPosition(void){

    Position position=malloc(sizeof(struct sPosition));
    position->x=0;
    position->y=0;

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
