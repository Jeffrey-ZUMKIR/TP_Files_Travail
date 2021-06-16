#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

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
int insertFileVide(File* file, SDL_Texture* p_texture){
    Element* element=NULL;
    element=(Element*)malloc(sizeof(*element));

    if(element==NULL){
        return 0;
    }

    element->p_texture=p_texture;
    element->p_suivant=NULL;

    file->p_debut=element;
    file->p_fin=element;
    file->n_taille++;
    return 1;

}

//Insertion élément dans file
int insertFile(File* file, Element* courant, SDL_Texture* p_texture){
    Element* element=NULL;
    element=(Element*)malloc(sizeof(*element));

    if(element==NULL){
        return 0;
    }

    element->p_texture=p_texture;
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

//Affiche les différentes images
void afficheFile(File* file,SDL_Rect rectSource,SDL_Rect rectDest,SDL_Renderer* pRenderer){
    Element* courant;
    courant= file->p_debut;

    int i=0;
    int j=0;

    while(courant!=NULL){
        //Si pas de reference
        if(!courant->p_texture){
            SDL_Log("Unable to set texture: %s", SDL_GetError());
        }else{
            rectSource.x=0;
            rectSource.y=0;
            rectSource.w=160;
            rectSource.h=160;

            rectDest.x=50*j;
            rectDest.y=50*i;
            rectDest.w=rectSource.w;
            rectDest.h=rectSource.h;

            SDL_RenderCopy(pRenderer,courant->p_texture,&rectSource,&rectDest);
        }
        i+=2;
    courant=courant->p_suivant;
    }
}

//Obtenir taille file
int getTailleFile(File* file){
    return file->n_taille;
}

//Obtenir premier élément de la file
Element* getElementDebut(File* file){
    Element* courant;
    courant=file->p_debut;

    return courant;
}

//Obtenir dernier élément de la file
Element* getElementFin(File* file){
    Element* courant;
    courant=file->p_fin;

    return courant;
}

//Détruire la file
int destructFile(File* file){
    if(file->n_taille==0){
        return 0;
    }

    while(file->n_taille>0){
        supElement(file);
    }

    return 1;
}
