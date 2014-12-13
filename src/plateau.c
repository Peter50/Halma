#include <stdio.h>
#include <stdlib.h>

#include "pions.h"
#include "position.h"

#include "plateau.h"

struct sPlateau{

    Pions * pions;
    Position position[16][16];
    Joueur * joueur;

};

sPlateau initPlateau()
{
    unsigned int i, j;
    sPlateau newPlateau;
    for(i=0; i<16; i++)
        for(j=0; j<16;j++)
        {
            newPlateau.position = initPosition(j, i);
        }
}
