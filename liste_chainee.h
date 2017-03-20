#include "structures.h"
#ifndef LISTE_CHAINEE_H_INCLUDED
#define LISTE_CHAINEE_H_INCLUDED

typedef struct maillon{
    struct maillon * suivant;
    struct maillon * precedent;
    station* data;
}maillon;

typedef struct liste{
    maillon* debut;
    maillon * fin;
    int taille;
}liste;

void retirerMaillonCourant(liste* laliste,maillon* maillonAretire)
void ajoutmaillonDebut(liste* laliste, station *data);
void ajoutmaillonFin(liste* laliste, station *data);
void ajoutmaillonMilieu(liste* laliste, station *data, int index);
station * supprimerMaillon(liste* laliste, int index);
maillon * retirerMaillon(liste* laliste, int index);
station * getMaillon(liste* laliste, int index);
void viderListe(liste* laliste);

#endif // LISTE_CHAINEE_H_INCLUDED
