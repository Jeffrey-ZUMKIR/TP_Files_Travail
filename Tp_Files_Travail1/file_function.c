#include <stdio.h>
#include <stdlib.h>
#include "define.h"

//Initialisation de la file
File * init(){
    File* my_file=NULL;
    my_file = (File*)malloc(sizeof(*my_file));

    if(my_file){
        my_file->p_debut=NULL;
        my_file->p_fin=NULL;
        my_file->n_taille=0;
    }

    return my_file;
}

//Insertion élément dans file vide
int insertFileVide(File* file, char* c_val){
    Element* element=NULL;
    element=(Element*)malloc(sizeof(*element));

    if(element==NULL){
        return 0;
    }

    element->c_char=c_val;
    element->p_suivant=NULL;

    file->p_debut=element;
    file->p_fin=element;
    file->n_taille++;
    return 1;

}

//Insertion élément dans file
int insertFile(File* file, Element* courant, char* c_val){
    Element* element=NULL;
    element=(Element*)malloc(sizeof(*element));

    if(element==NULL){
        return 0;
    }

    element->c_char=c_val;
    element->p_suivant=NULL;

    courant->p_suivant=element;
    file->p_fin=element;
    file->n_taille++;


    return 1;

}

//Suppression élément
int supElement(File* file){
    if(file->n_taille==0){
        return 0;
    }

    Element* supp=NULL;
    supp=file->p_debut;
    file->p_debut=file->p_debut->p_suivant;

    if(file->n_taille==1){
        file->p_fin=NULL;
    }
    free(supp);

    file->n_taille--;

    return 1;
}

void afficheFile(File* file){
    Element* courant;
    courant= file->p_debut;

    while(courant!=NULL){
        printf("%s\n",courant->c_char);
        courant=courant->p_suivant;
    }
}

int getTailleFile(File* file){
    return file->n_taille;
}

Element* getElementDebut(File* file){
    Element* courant;
    courant=file->p_debut;

    return courant;
}

Element* getElementFin(File* file){
    Element* courant;
    courant=file->p_fin;

    return courant;
}


void affiche(File* file){
    printf("%d\n",file->n_taille);
    printf("%d\n",file->p_debut);
    printf("%d\n",file->p_fin);
}

int destructFile(File* file){
    if(file->n_taille==0){
        return 0;
    }

    while(file->n_taille>0){
        supElement(file);
    }

    return 1;
}
