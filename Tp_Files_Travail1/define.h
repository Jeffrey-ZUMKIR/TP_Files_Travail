#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED

typedef struct Element{
    char* c_char;
    struct Element* p_suivant;
}Element;

typedef struct File{
    struct Element *p_debut;
    struct Element *p_fin;
    int n_taille;
}File;

extern File * init();
extern int insertFileVide(File* file,char* c_val);
extern int insertFile(File* file, Element* courant, char* c_val);
extern int supElement(File* file);
extern void afficheFile(File* file);
extern int getTailleFile(File* file);
extern Element* getElementDebut(File* file);
extern Element* getElementFin(File* file);

extern void affiche(File* file);

extern int destructFile(File* file);

#endif // DEFINE_H_INCLUDED
