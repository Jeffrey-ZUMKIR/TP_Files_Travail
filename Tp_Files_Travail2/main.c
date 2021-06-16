#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "define.h"


int main(int argc, char *argv[])
{
    SDL_Window *pWindow=NULL;
    SDL_Renderer *pRenderer=NULL;

    SDL_Surface *pSurface;
    SDL_Texture *pTexture;

    if(SDL_Init(SDL_INIT_EVERYTHING)!=0){
        SDL_Log("Unbale to initialize SDL: %s", SDL_GetError());
        return 1;
    }else{
        pWindow=SDL_CreateWindow("An SDL2 window",200,100,WINDOW_WIDTH,WINDOW_HEIGHT,SDL_WINDOW_SHOWN);

        if(pWindow){
            pRenderer=SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_PRESENTVSYNC);
        }

        //Set img flags
        int flags=IMG_INIT_JPG|IMG_INIT_PNG;
        int initted=IMG_Init(flags);
        if((initted&flags)!=flags){
             SDL_Log("IMG_Init:Failed to init required jpg and png support !\n");
             SDL_Log("IMG_Init: %s\n", IMG_GetError());

             return 1;
        }
    }

    SDL_Rect rectSource={0,0,0,0};
    SDL_Rect rectDest={0,0,0,0};

    SDL_Event events;
    SDL_bool isOpen = SDL_TRUE;

    File* file=init();

    if(pRenderer){
        //Set Color
        SDL_SetRenderDrawColor(pRenderer,205,92,92,SDL_ALPHA_OPAQUE);
        //Clear Render
        SDL_RenderClear(pRenderer);

        //Ajout image dans la liste
        pSurface=IMG_Load("./assets/Cyberdrunk pnj.png");
        pTexture=SDL_CreateTextureFromSurface(pRenderer,pSurface);
        if(insertFile(file,file->p_fin,pTexture));

        pSurface=IMG_Load("./assets/Cyberdrunk pnj dwerk.png");
        pTexture=SDL_CreateTextureFromSurface(pRenderer,pSurface);
        if(insertFile(file,file->p_fin,pTexture));

        pSurface=IMG_Load("./assets/Cyberdrunk pnj 5.png");
        pTexture=SDL_CreateTextureFromSurface(pRenderer,pSurface);
        if(insertFile(file,file->p_fin,pTexture));
    }

     while (isOpen)
    {
         while (SDL_PollEvent(&events))
        {
            switch (events.type)
            {
            case SDL_QUIT:
                isOpen = SDL_FALSE ;
                break;
            }
        }

        //Affiche les images
        afficheFile(file,rectSource,rectDest,pRenderer);

        //Update render
        SDL_RenderPresent(pRenderer);

    }

    if(destructFile(file));

    //SDL_Delay(1000);
    if(pRenderer){
        SDL_DestroyRenderer(pRenderer);
    }
    if(pWindow){
       SDL_DestroyWindow(pWindow);
    }

    SDL_Quit();

    return 0;
}
