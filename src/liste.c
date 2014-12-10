#include <stdio.h>
#include <stdlib.h>

#include "liste.h"

struct sListe
{
    Element tete;
    Element courant;

};

struct sElement
{
    void * contenu;
    Element suivant;
    Element precedent;

};

Liste initListe(void)
{

    Liste liste=malloc(sizeof(struct sListe));
    liste->tete=NULL;
    liste->courant=NULL;

    return liste;
}

void detruireListe(Liste liste)
{

    Element element=NULL;
    liste->courant=liste->tete;
    while(liste->courant!=NULL)
    {
        element=liste->courant->suivant;
        detruireElement(liste->courant);
        liste->courant=element;
    }

    free(liste);
}
Element initElement(void * contenu)
{

    Element element=malloc(sizeof(struct sElement));
    element->contenu=contenu;
    element->suivant=NULL;
    element->precedent;

}

void detruireElement(Element element)
{
    free(element);
}

void ajouterTete(Liste liste,void * contenu)
{

    Element element=initElement(contenu);

    if(liste->tete != NULL)
    {
        element->suivant=liste->tete;
        element->precedent=liste->tete->precedent;
        element->precedent->suivant=element;
        element->suivant->precedent=element;
        liste->tete=element;
    }
    else
    {
        liste->tete=element;
        element->suivant=element;
        element->precedent=element;
        liste->courant=element;
    }
}

int estDansListe(Liste liste,void * contenu,int (*egal)(void * element1,void * element2))
{
    liste->courant=liste->tete;

    do{
        if(egal(contenu,liste->courant->contenu)){
            return 1;
        }
        liste->courant=liste->courant->suivant;
    }while(liste->courant!=liste->tete);

    return 0;
}

int listeEstVide(Liste liste){
    if(liste->tete==NULL){
        return 1;
    }
    return 0;
}

void * listeCourant(Liste liste){
    if(!(listeEstVide(liste))){
        return liste->tete->contenu;
    }

    return NULL;
}


void elementSuivant(Liste liste){
    liste->courant=liste->courant->suivant;
}

