#include <stdio.h>
#include <stdlib.h>

#include "position.h"
#include "pion.h"

struct sPosition{

    unsigned int x;
    unsigned int y;
    Pion pPion;


};

sPosition initPosition(unsigned int abcisse, unsigned int ordonnee)
{
    sPosition newPosition;
    newPosition.x = abcisse;
    newPosition.y = ordonnee;
    pPion = NULL;
    return newPosition;
}

