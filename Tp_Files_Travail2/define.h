#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 780

typedef struct Element{
    SDL_Texture *p_texture;
    struct Element* p_suivant;
}Element;

typedef struct File{
    struct Element *p_debut;
    struct Element *p_fin;
    int n_taille;
}File;

extern File * init();
extern int insertFile(File* file, Element* courant, SDL_Texture* p_texture);
extern int supElement(File* file);
extern void afficheFile(File* file,SDL_Rect rectSource,SDL_Rect rectDest,SDL_Renderer* pRenderer);
extern int getTailleFile(File* file);
extern Element* getElementDebut(File* file);
extern Element* getElementFin(File* file);

extern int destructFile(File* file);


#endif // DEFINE_H_INCLUDED
