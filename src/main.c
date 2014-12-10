#include <stdio.h>
#include <stdlib.h>

#include "jeu.h"

int main(void)
{

    int choix=0;
    int nombre=0;
    int ia=-1;

    Jeu jeu=NULL;

    while(choix!=4)
    {
        printf("Bonjour, bienvenue sur ce jeu de l'Halma.\n");
        printf("Selectioner une option :\n");
        printf("1. Jouer\n");
        printf("2. Option\n");
        printf("3. Tutoriel\n");
        printf("4. Quiter\n");

        scanf("%i",&choix);
        switch(choix)
        {
        case 1:
            while(nombre != 2 && nombre != 4){
                printf("Donner le nombre de joueur total (2 ou 4) ? ");
                scanf("%d",&nombre);
            }
            while(ia > nombre || ia < 0){
                printf("Donner le nombre d'IA (entre 0 et %d) ? ",nombre);
                scanf("%d",&ia);
            }
            jeu=initJeu(nombre,ia);
            infoJeu(jeu);

            detruireJeu(jeu);
            // lancerPartie()
            break;
        case 2:
            // afficher les options
            break;
        case 3:
            printf("Le je de l'Halma est un jeu de société pouvant se jouer à deux ou quatre joueur\n");

            break;
        case 4:
            printf("Bonne fin de journée, au revoir et merci d'avoir jouée");
        break;

        default:
            printf("Commande invalide\n");
        break;
        }
    }

    return 0;
}
