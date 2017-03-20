#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "liste_chainee.h"


void ajoutmaillonDebut(liste* laliste, station *data)
{
    laliste->taille++;
    if(laliste->debut==NULL)
    {
        laliste->debut=malloc(sizeof(maillon));
        laliste->fin=laliste->debut;
        laliste->debut->suivant=NULL;
        laliste->debut->precedent=NULL;
    }
    else
    {
        maillon* tmp=NULL;
        tmp=malloc(sizeof(maillon));
        tmp->suivant=laliste->debut;
        laliste->debut->precedent=tmp;
        tmp->precedent=laliste->debut->precedent;
        laliste->debut=tmp;
    }
    laliste->debut->data=data;
}


void ajoutmaillonFin(liste* laliste, station *data)
{
    laliste->taille++;
    if(laliste->debut==NULL)
    {
        laliste->debut=malloc(sizeof(maillon));
        laliste->fin=laliste->debut;
        laliste->debut->suivant=laliste->debut;
        laliste->debut->precedent=laliste->debut;
    }
    else
    {
        maillon* tmp=NULL;
        tmp=malloc(sizeof(maillon));
        tmp->precedent=laliste->fin;
        laliste->fin->suivant=tmp;
        tmp->suivant=laliste->debut->suivant;
        laliste->fin=tmp;
    }
    laliste->fin->data=data;
}
void ajoutmaillonMilieu(liste* laliste, station *data, int index)
{
    if (index<=laliste->taille &&index>=0)
    {
        if (index==0)
        {
            ajoutmaillonDebut(laliste,data);
        }
        else if(index==laliste->taille)
        {
            ajoutmaillonFin(laliste, data);
        }
        else
        {
            maillon* tmp=NULL;
            maillon* nouveau=NULL;
            nouveau=malloc(sizeof(maillon));
            nouveau->data=data;
            if(index>laliste->taille/2)
            {
                tmp=laliste->fin;
                index= laliste->taille-index;
                for (int i=0; i<index; i++)tmp=tmp->precedent;
            }
            else
            {
                tmp=laliste->debut;
                for (int i=0; i<index; i++)tmp=tmp->suivant;
            }
            nouveau->suivant=tmp->suivant;
            nouveau->precedent=tmp;
            tmp->suivant=nouveau;
            nouveau->suivant->precedent=nouveau;
            laliste->taille++;
        }
    }
    else
    {
        fprintf(stderr, "idnex incorect pour l'ajout de l'élement dans la liste");
    }
}


maillon * retirerMaillon(liste* laliste, int index)
{
    if (index<=laliste->taille-1 && index>=0)
    {
        maillon* maillonARetirer=NULL;
        if(index>laliste->taille/2)
        {
            maillonARetirer=laliste->fin;
            index= laliste->taille-index;
            for (int i=0; i<index; i++)maillonARetirer=maillonARetirer->precedent;
        }
        else
        {
            maillonARetirer=laliste->debut;
            for (int i=0; i<index; i++)maillonARetirer=maillonARetirer->suivant;
        }
        if(index==0)
        {
            laliste->debut=maillonARetirer->suivant;
        }
        else
        {
            maillonARetirer->precedent->suivant=maillonARetirer->suivant;
        }
        if(index==laliste->taille-1)
        {
            laliste->fin=maillonARetirer->precedent;
        }
        else
        {
            maillonARetirer->suivant->precedent=maillonARetirer->precedent;
        }
        laliste->taille--;
        return maillonARetirer;
    }
    else
    {
        fprintf(stderr, "idnex incorect pour l'ajout de l'élement dans la liste");
    }
    return NULL;
}

station * supprimerMaillon(liste* laliste, int index)
{
    station* stationdata=NULL;
    maillon* maillonASupprimer=NULL;
    maillonASupprimer=retirerMaillon(laliste,index);
    if(maillonASupprimer!=NULL)
    {
        stationdata=maillonASupprimer->data;
        free(maillonASupprimer);
    }
    return stationdata;
}

station * getMaillon(liste* laliste, int index)
{
    if (index<=laliste->taille-1 && index>=0)
    {
        maillon* maillonATraiter=NULL;
        if(index>laliste->taille/2)
        {
            maillonATraiter=laliste->fin;
            index= laliste->taille-index;
            for (int i=0; i<index; i++)maillonATraiter=maillonATraiter->precedent;
        }
        else
        {
            maillonATraiter=laliste->debut;
            for (int i=0; i<index; i++)maillonATraiter=maillonATraiter->suivant;
        }
        return maillonATraiter->data;
    }
    else
    {
        fprintf(stderr, "idnex incorect pour l'ajout de l'élement dans la liste");
    }
    return NULL;
}

void viderListe(liste* laliste)
{
    while(laliste->debut!=NULL)supprimerMaillon(laliste,0);
}
