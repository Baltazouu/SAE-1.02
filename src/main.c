#include "globale.h"
#include<stdio.h>
#include"struct.h"
#include<stdlib.h>
#include"part3.h"


int main(void)
{
    //FGlobale();
    Candidature **tcand;
    VilleIUT ville;
    int tlog,tphys;

    strcpy(ville.VilleDep,"Clermont-Ferrand");
    // faire la suite
    // inserer dans la liste informatique

    globalePart3(tcand,tlog,tphys,ville);
    return 0;
}