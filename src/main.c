#include <stdio.h>
#include <stdlib.h>

#include "jeu.h"

int main(void)
{

    int choix=0;
    int nombre=0;
    int ia=-1;

    Jeu jeu=NULL;

    while(choix!=3)
    {
        nombre=0;
        ia=-1;
        printf("Bonjour, bienvenue sur ce jeu de l'Halma.\n");
        printf("Selectioner une option :\n");
        printf("1. Jouer\n");
        printf("2. Tutoriel\n");
        printf("3. Quiter\n");

        scanf("%i",&choix);
        switch(choix)
        {
        case 1:
            while(nombre != 2 && nombre != 4){
                printf("Donner le nombre de joueur total (2 ou 4) ? ");
                viderBuffer();
                scanf("%d",&nombre);
            }
            while(ia > nombre || ia < 0){
                printf("Donner le nombre d'IA (entre 0 et %d) ? ",nombre);
                viderBuffer();
                scanf("%d",&ia);
            }
            jeu=initJeu(nombre,ia,16);
            lancerJeu(jeu);
            detruireJeu(jeu);
            break;
        case 2:
            printf("Le jeu de l'Halma est un jeu de société pouvant se jouer à deux ou quatre joueur\n");
            // TODO Faire le tutoriel avec des plateaux pré-enregistré dans les fichier du jeu
            break;
        case 3:
            printf("Bonne fin de journée, au revoir et merci d'avoir jouée\n");
        break;
        default:
            printf("Commande invalide\n");
        break;
        }
    }

    return 0;
}
