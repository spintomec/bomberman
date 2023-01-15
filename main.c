
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

int main(int argc, char *argv[])
{
    SDL_Surface *ecran =NULL;
    SDL_Surface *menu =NULL;

    // Pour la position des x,y des objets
    SDL_Rect positionMenu;
    SDL_Event event;
    int continuer=3;

    SDL_Init(SDL_INIT_VIDEO);
        SDL_WM_SetIcon(IMG_Load("Sacha.bmp"), NULL);
        // On définit la taille de notre image et on empêche le clignotement
        ecran= SDL_SetVideoMode(760,465,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
        SDL_WM_SetCaption("Poké BOMBER", NULL);

        // On ajoute notre piste audio
        Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS,1024);
        Mix_Music *musique;
        musique=Mix_LoadMUS("pokemon.mp3");

    // On définit le menu et sa position
    menu = IMG_Load("menu.png");
    positionMenu.x=0;
    positionMenu.y=0;

    Mix_PlayMusic(musique, -1);

    while(continuer){
        SDL_WaitEvent(&event);
        switch(event.type){

            case SDL_QUIT:
            continuer=0;
            break;

            case SDL_KEYDOWN:
            switch(event.key.keysym.sym){

                case SDLK_ESCAPE:
                continuer=0;
                break;

                case SDLK_RETURN:
                jouer(ecran);
                break;

            }
            break;
        }
        // On rafraichit l'ecran
        SDL_BlitSurface(menu, NULL, ecran, &positionMenu);
        SDL_Flip(ecran);

    }
        // On arrête d'afficher l'image et on quite la SDL
        Mix_CloseAudio();
        SDL_FreeSurface(menu);
        SDL_Quit();
        return EXIT_SUCCESS;
}

