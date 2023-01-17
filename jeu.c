
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "jeu.h"
#include "constantes.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

// void UpdateClavier(Touches* etat_clavier){
void UpdateClavier(Touches* etat_clavier){
   SDL_Event event;
   // Récupère le keycode de la touche enfoncée
   while(SDL_PollEvent(&event)){
       switch(event.type){
           case SDL_KEYDOWN:
           etat_clavier->key[event.key.keysym.sym]=1;
           break;

           case SDL_KEYUP:
           etat_clavier->key[event.key.keysym.sym]=0;
           break;
           
           default:
           break;
       }

   }
}


// Position de objets et du joueur
SDL_Rect position, positionJoueur;
SDL_Rect positionVilain, positionJoueurVilain;

void jouer(SDL_Surface* ecran){

    // Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS,1024);
    // Mix_Music *musique2;
    // musique2=Mix_LoadMUS("copy.mp3");

    Touches etat_clavier;
    memset(&etat_clavier, 0, sizeof(etat_clavier));


    // On crée un tableau pour les 4 position des joueurs
    SDL_Surface *sacha[4]={NULL};
    SDL_Surface *sachaActuel=NULL;
    SDL_Surface *vilain[4]={NULL};
    SDL_Surface *vilainActuel=NULL;
    SDL_Surface *mur=NULL;
    SDL_Surface *rocher=NULL;

    SDL_Rect positionFond;
    SDL_Surface *fond=NULL;

    SDL_Event event;

    int continuer=1;
    int i=0, j=0;

    // On alloue de la mémoire dynamiquement pour chaque bloc de nos colonnes et rangées
    int **carte=(int**)malloc(11*sizeof(int*));
    for(i=0; i<11; i++){
        carte[i] = (int*)malloc(21*sizeof(int));
    }

    // On positionne les murs sur la carte
    carte[1][0]=0;
    carte[1][1]=0;
    carte[1][2]=1;
    carte[1][3]=1;
    carte[1][4]=1;
    carte[1][5]=1;
    carte[1][6]=1;
    carte[1][7]=1;
    carte[1][8]=1;
    carte[1][9]=1;
    carte[1][10]=1;
    carte[1][11]=1;
    carte[1][12]=1;
    carte[1][13]=1;
    carte[1][14]=1;
    carte[1][15]=1;
    carte[1][16]=1;
    carte[1][17]=1;
    carte[1][18]=1;
    carte[1][19]=1;
    carte[1][21]=0;
    carte[2][2]=1;
    carte[2][20]=1;
    carte[3][2]=1;
    carte[3][3]=1;
    carte[3][11]=1;
    carte[3][20]=1;
    carte[4][2]=1;
    carte[4][11]=1;
    carte[4][20]=1;
    carte[5][2]=1;
    carte[5][6]=1;
    carte[5][7]=1;
    carte[5][8]=1;
    carte[5][9]=1;
    carte[5][10]=1;
    carte[5][11]=1;
    carte[6][1]=999;
    carte[6][11]=1;
    carte[6][12]=1;
    carte[6][13]=1;
    carte[6][14]=1;
    carte[6][15]=1;
    carte[6][16]=1;
    carte[6][20]=1;
    carte[7][2]=1;
    carte[7][11]=1;
    carte[7][20]=1;
    carte[8][2]=1;
    carte[8][11]=1;
    carte[8][20]=1;
    carte[9][2]=1;
    carte[9][20]=1;
    carte[10][2]=1;
    carte[10][3]=1;
    carte[10][4]=1;
    carte[10][5]=1;
    carte[10][6]=1;
    carte[10][7]=1;
    carte[10][8]=1;
    carte[10][9]=1;
    carte[10][10]=1;
    carte[10][11]=1;
    carte[10][12]=1;
    carte[10][13]=1;
    carte[10][14]=1;
    carte[10][15]=1;
    carte[10][16]=1;
    carte[10][17]=1;
    carte[10][18]=1;
    carte[10][19]=1;
    carte[10][20]=1;

    fond=IMG_Load("background5.bmp");
    mur=IMG_Load("arbre.bmp");
    rocher=IMG_Load("obstacle.bmp");
    sacha[BAS]=IMG_Load("bas.bmp");
    sacha[HAUT]=IMG_Load("haut.bmp");
    sacha[GAUCHE]=IMG_Load("gauche.bmp");
    sacha[DROITE]=IMG_Load("droite.bmp");
    vilain[BAS]=IMG_Load("bas2.bmp");
    vilain[HAUT]=IMG_Load("haut2.bmp");
    vilain[GAUCHE]=IMG_Load("gauche2.bmp");
    vilain[DROITE]=IMG_Load("droite2.bmp");


    // On affiche sacha en position "BAS" au lancement de la partie
    sachaActuel=sacha[BAS];
    positionJoueur.x=3;
    positionJoueur.y=3;
    carte[3][3]=SACHA;

    vilainActuel=vilain[BAS];
    positionJoueurVilain.x=17;
    positionJoueurVilain.y=8;
    carte[3][5]=VILAIN;


    placementAleatoireMur(carte);

    // On veut que le mouvement se répète
    SDL_EnableKeyRepeat(90,90);

    while(continuer) {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
            continuer=0;
            break;

            case SDL_KEYDOWN:
            switch(event.key.keysym.sym) {

                case SDLK_ESCAPE:
                continuer=0;
                break;
            // Déplacements sacha
                case SDLK_z:
                sachaActuel=sacha[HAUT];
                deplacerJoueur(carte, &positionJoueur, HAUT);
                break;

                case SDLK_s:
                sachaActuel=sacha[BAS];
                deplacerJoueur(carte, &positionJoueur, BAS);
                break;

                case SDLK_q:
                sachaActuel=sacha[GAUCHE];
                deplacerJoueur(carte, &positionJoueur, GAUCHE);
                break;

                case SDLK_d:
                sachaActuel=sacha[DROITE];
                deplacerJoueur(carte, &positionJoueur, DROITE);
                break;
             // Déplacements Vilain
                case SDLK_UP:
                vilainActuel=vilain[HAUT];
                deplacerJoueur(carte, &positionJoueurVilain, HAUT);
                break;

                case SDLK_DOWN:
                vilainActuel=vilain[BAS];
                deplacerJoueur(carte, &positionJoueurVilain, BAS);
                break;

                case SDLK_LEFT:
                vilainActuel=vilain[GAUCHE];
                deplacerJoueur(carte, &positionJoueurVilain, GAUCHE);
                break;

                case SDLK_RIGHT:
                vilainActuel=vilain[DROITE];
                deplacerJoueur(carte, &positionJoueurVilain, DROITE);
                break;

                default:
                break;

            }
            break;

            default:
            break;
        }

        // On passe l'écran en blanc
        SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));

        // On positionne le fond
        positionFond.x=0;
        positionFond.y=0;

        SDL_BlitSurface(fond,NULL,ecran,&positionFond);

        for ( i=0; i<11; i++){
        for ( j=0; j<22; j++){

            position.x = j*TAILLE_BLOC;
            position.y = i*TAILLE_BLOC;

            switch(carte[i][j]) {
                case MUR:
                SDL_BlitSurface(mur, NULL, ecran, &position);
                break;

                case ROCHER:
                SDL_BlitSurface(rocher, NULL, ecran, &position);
                break;
            }

        }
        }
        // Position en taille de bloc et non pas en pixel
        position.x=positionJoueur.x*TAILLE_BLOC;
        position.y=positionJoueur.y*TAILLE_BLOC;
        SDL_BlitSurface(sachaActuel, NULL,ecran, &position);

        positionVilain.x=positionJoueurVilain.x*TAILLE_BLOC;
        positionVilain.y=positionJoueurVilain.y*TAILLE_BLOC;
        SDL_BlitSurface(vilainActuel, NULL,ecran, &positionVilain);

        // On rafraichit l'ecran
        SDL_Flip(ecran);
    }

    SDL_EnableKeyRepeat(0,0);
    SDL_FreeSurface(mur);
    SDL_FreeSurface(rocher);

    // On arrête d'aficher les images pour les 4 positions
    for(i=0; i<4; i++){
        SDL_FreeSurface(sacha[i]);
        SDL_FreeSurface(vilain[i]);
    }
}

// Fonction pour faire déplacer le joueur
void deplacerJoueur(int **carte, SDL_Rect *pos, int direction){

    switch(direction){
        case HAUT:
        if (carte[pos->y-1][pos->x]==MUR)
        break;
        if (carte[pos->y-1][pos->x]==ROCHER)
        break;
        pos->y--;
        break;

        case BAS:
        if (carte[pos->y+1][pos->x]==MUR)
        break;
        if (carte[pos->y+1][pos->x]==ROCHER)
        break;
        pos->y++;
        break;

        case GAUCHE:
        // Joueur 1 colision roché
        if(positionJoueur.x==2 && positionJoueur.y==6 && carte[5][20]==3){
            break;
        }
        // Joueur 2 colision roché
        if(positionJoueurVilain.x==2 && positionJoueurVilain.y==6 && carte[5][20]==3){
            break;
        }
        // Joueur 1 tp gauche
        if(positionJoueur.x == 2 && positionJoueur.y == 6) {
            positionJoueur.x = 20;
            positionJoueur.y = 5;
            break;
        }
        // Joueur 2 tp gauche
        if(positionJoueurVilain.x == 2 && positionJoueurVilain.y == 6) {
            positionJoueurVilain.x = 20;
            positionJoueurVilain.y = 5;
            break;
        }
        if (carte[pos->y][pos->x-1]==MUR)
        break;
        if (carte[pos->y][pos->x-1]==ROCHER)
        break;
        pos->x--;
        break;

        case DROITE:
        // Joueur 1 colision roché
        if(positionJoueur.x==20 && positionJoueur.y==5 && carte[6][2]==3){
           break;
        }
        // Joueur 2 colision roché
        if(positionJoueurVilain.x==20 && positionJoueurVilain.y==5 && carte[6][2]==3){
           break;
        }
        // Joueur 1 tp droite
        if(positionJoueur.x == 20 && positionJoueur.y == 5) {
            positionJoueur.x = 2;
            positionJoueur.y = 6;
            break;
        }
        // Joueur 2 tp droite
        if(positionJoueurVilain.x == 20 && positionJoueurVilain.y == 5) {
            positionJoueurVilain.x = 2;
            positionJoueurVilain.y = 6;
            break;
        }

        if (carte[pos->y][pos->x+1]==MUR)
        break;
        if (carte[pos->y][pos->x+1]==ROCHER)
        break;
        pos->x++;
        break;
    }
}

void placementAleatoireMur(int **carte){
    int a=0;
    int b=0;

    // On place les éléments dans le tableau centrale
    for(a=1; a<11; a++) {

    // // On évite les erreurs liées à l'aléatoire
    // srand(time(NULL));

    for(b=2; b<21; b++){

        if (carte[a][b] == 0 && carte[a][b] != SACHA){
            // Possibilité de rajouter de la difficulté
            int v = rand()%2;
            if(v==0){
                carte[a][b]=ROCHER;
            }
        }
    }
    }
    for(a=2; a<11; a++){
    for(b=3; b<21; b++){

        if (carte[a][b] == SACHA){
                if(carte[a+1][b]==3){
                    carte[a+1][b]=0;
                }
                if(carte[a][b+1]==3){
                    carte[a][b+1]=0;
                }
        }
    }
    }
}
