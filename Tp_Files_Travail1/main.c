#include <stdio.h>
#include <stdlib.h>
#include "define.h"

int main()
{
    File* file=init();


    if(insertFileVide(file,"cc"));

    if(insertFile(file, file->p_fin,"cc2"));

    //affiche(file);

    if(supElement(file));

    //affiche(file);
    afficheFile(file);

    Element* element1=getElementDebut(file);
    Element* element2=getElementFin(file);

    destructFile(file);

    free(file);

    return 0;
}


