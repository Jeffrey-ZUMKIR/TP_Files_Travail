#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 780

typedef struct Element{
    SDL_Surface *p_surface;
    struct Element* p_suivant;
}Element;

typedef struct File{
    struct Element *p_debut;
    struct Element *p_fin;
    int n_taille;
}File;

extern File * init();
extern int insertFileVide(File* file, SDL_Surface* p_surface);
extern int insertFile(File* file, Element* courant, SDL_Surface* p_surface);
extern int supElement(File* file);
extern void afficheFile(File* file,SDL_Rect rectSource,SDL_Rect rectDest,SDL_Renderer* pRenderer);
extern int getTailleFile(File* file);
extern Element* getElementDebut(File* file);
extern Element* getElementFin(File* file);

extern void affiche(File* file);

extern int destructFile(File* file);


#endif // DEFINE_H_INCLUDED
