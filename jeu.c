
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL_image.h>
#include "jeu.h"
#include "constantes.h"

// Position de objets et du joueur
SDL_Rect position, positionJoueur;

void jouer(SDL_Surface* ecran){

    // On crée un tableau pour les 4 position du joueur
    SDL_Surface *sacha[4]={NULL};
    SDL_Surface *sachaActuel=NULL;

    SDL_Surface *mur=NULL;
    SDL_Surface *rocher=NULL;


    SDL_Event event;

    int continuer=1;
    int i=0, j=0;

    // On alloue de la mémoire dynamiquement pour nos colonnes et rangées
    int **carte=(int**)malloc(11*sizeof(int*));
    for(i=0; i<11; i++){
        carte[i] = (int*)malloc(21*sizeof(int));
    }

    carte[0][0]=0;
    carte[0][1]=0;
    carte[0][2]=0;
    carte[0][3]=0;
    carte[0][4]=0;
    carte[0][5]=0;
    carte[0][6]=0;
    carte[0][7]=0;
    carte[0][8]=0;
    carte[0][9]=0;
    carte[0][10]=0;
    carte[0][11]=0;
    carte[0][12]=0;
    carte[0][13]=0;
    carte[0][14]=0;
    carte[0][15]=0;
    carte[0][16]=0;
    carte[0][17]=0;
    carte[0][18]=0;
    carte[0][19]=0;
    carte[0][20]=0;
    carte[0][21]=0;

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
    carte[1][20]=1;
    carte[1][21]=0;

    // carte[2][0]=0;
    // carte[2][1]=0;
    // carte[2][2]=1;
    carte[2][2]=1;
    // carte[2][4]=0;
    // carte[2][5]=0;
    // carte[2][6]=0;
    // carte[2][7]=0;
    // carte[2][8]=0;
    // carte[2][9]=0;
    // carte[2][10]=0;
    // carte[2][11]=1;
    // carte[2][12]=0;
    // carte[2][13]=0;
    // carte[2][14]=0;
    // carte[2][15]=0;
    // carte[2][16]=0;
    // carte[2][17]=0;
    // carte[2][18]=0;
    // carte[2][19]=0;
    carte[2][20]=1;
    // carte[2][21]=0;


    carte[3][0]=0;
    carte[3][1]=0;
    carte[3][2]=1;
    carte[3][3]=1;
    carte[3][4]=0;
    carte[3][5]=0;
    carte[3][6]=0;
    carte[3][7]=0;
    carte[3][8]=0;
    carte[3][9]=0;
    carte[3][10]=0;
    carte[3][11]=1;
    carte[3][12]=0;
    carte[3][13]=0;
    carte[3][14]=0;
    carte[3][15]=0;
    carte[3][16]=0;
    carte[3][17]=0;
    carte[3][18]=0;
    carte[3][19]=0;
    carte[3][20]=1;
    carte[3][21]=0;
    carte[4][0]=0;
    carte[4][1]=0;
    carte[4][2]=1;
    carte[4][3]=0;
    carte[4][4]=0;
    carte[4][5]=0;
    carte[4][6]=0;
    carte[4][7]=0;
    carte[4][8]=0;
    carte[4][9]=0;
    carte[4][10]=0;
    carte[4][11]=1;
    carte[4][12]=0;
    carte[4][13]=0;
    carte[4][14]=0;
    carte[4][15]=0;
    carte[4][16]=0;
    carte[4][17]=0;
    carte[4][18]=0;
    carte[4][19]=0;
    carte[4][20]=1;
    carte[4][21]=0;
    carte[5][0]=0;
    carte[5][1]=0;
    carte[5][2]=1;
    carte[5][3]=0;
    carte[5][4]=0;
    carte[5][5]=0;
    carte[5][6]=1;
    carte[5][7]=1;
    carte[5][8]=1;
    carte[5][9]=1;
    carte[5][10]=1;
    carte[5][11]=1;
    carte[5][12]=0;
    carte[5][13]=0;
    carte[5][14]=0;
    carte[5][15]=0;
    carte[5][16]=0;
    carte[5][17]=0;
    carte[5][18]=0;
    carte[5][19]=0;
    carte[5][20]=0;
    carte[5][21]=0;
    carte[6][0]=0;
    carte[6][1]=999;
    carte[6][2]=0;
    carte[6][3]=0;
    carte[6][4]=0;
    carte[6][5]=0;
    carte[6][6]=0;
    carte[6][7]=0;
    carte[6][8]=0;
    carte[6][9]=0;
    carte[6][10]=0;
    carte[6][11]=1;
    carte[6][12]=1;
    carte[6][13]=1;
    carte[6][14]=1;
    carte[6][15]=1;
    carte[6][16]=1;
    carte[6][17]=0;
    carte[6][18]=0;
    carte[6][19]=0;
    carte[6][20]=1;
    carte[6][21]=0;
    carte[7][0]=0;
    carte[7][1]=0;
    carte[7][2]=1;
    carte[7][3]=0;
    carte[7][4]=0;
    carte[7][5]=0;
    carte[7][6]=0;
    carte[7][7]=0;
    carte[7][8]=0;
    carte[7][9]=0;
    carte[7][10]=0;
    carte[7][11]=1;
    carte[7][12]=0;
    carte[7][13]=0;
    carte[7][14]=0;
    carte[7][15]=0;
    carte[7][16]=0;
    carte[7][17]=0;
    carte[7][18]=0;
    carte[7][19]=0;
    carte[7][20]=1;
    carte[7][21]=0;
    carte[8][0]=0;
    carte[8][1]=0;
    carte[8][2]=1;
    carte[8][3]=0;
    carte[8][4]=0;
    carte[8][5]=0;
    carte[8][6]=0;
    carte[8][7]=0;
    carte[8][8]=0;
    carte[8][9]=0;
    carte[8][10]=0;
    carte[8][11]=1;
    carte[8][12]=0;
    carte[8][13]=0;
    carte[8][14]=0;
    carte[8][15]=0;
    carte[8][16]=0;
    carte[8][17]=0;
    carte[8][18]=0;
    carte[8][19]=0;
    carte[8][20]=1;
    carte[8][21]=0;
    carte[9][0]=0;
    carte[9][1]=0;
    carte[9][2]=1;
    carte[9][3]=0;
    carte[9][4]=0;
    carte[9][5]=0;
    carte[9][6]=0;
    carte[9][7]=0;
    carte[9][8]=0;
    carte[9][9]=0;
    carte[9][10]=0;
    carte[9][11]=0;
    carte[9][12]=0;
    carte[9][13]=0;
    carte[9][14]=0;
    carte[9][15]=0;
    carte[9][16]=0;
    carte[9][17]=0;
    carte[9][18]=0;
    carte[9][19]=0;
    carte[9][20]=1;
    carte[9][21]=0;
    carte[9][22]=0;
    carte[10][0]=0;
    carte[10][1]=0;
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
    carte[10][21]=0;

    mur=IMG_Load("arbre.bmp");
    rocher=IMG_Load("obstacle.bmp");
    sacha[BAS]=IMG_Load("bas.bmp");
    sacha[HAUT]=IMG_Load("haut.bmp");
    sacha[GAUCHE]=IMG_Load("gauche.bmp");
    sacha[DROITE]=IMG_Load("droite.bmp");

    // On affiche sacha en position "BAS" au lancement de la partie
    sachaActuel=sacha[BAS];
    positionJoueur.x=3;
    positionJoueur.y=3;
    carte[3][3]=SACHA;

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

                case SDLK_UP:
                sachaActuel=sacha[HAUT];
                deplacerJoueur(carte, &positionJoueur, HAUT);
                break;

                case SDLK_DOWN:
                sachaActuel=sacha[BAS];
                deplacerJoueur(carte, &positionJoueur, BAS);
                break;

                case SDLK_LEFT:
                sachaActuel=sacha[GAUCHE];
                deplacerJoueur(carte, &positionJoueur, GAUCHE);
                break;

                case SDLK_RIGHT:
                sachaActuel=sacha[DROITE];
                deplacerJoueur(carte, &positionJoueur, DROITE);
                break;

            }
            break;
        }

        // On passe l'écran en blanc
        SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));

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

        // On rafraichit l'ecran
        SDL_Flip(ecran);
    }
    SDL_EnableKeyRepeat(0,0);
    SDL_FreeSurface(mur);
    SDL_FreeSurface(rocher);

    // On arrête d'aficher les images pour les 4 positions
    for(i=0; i<4; i++){
        SDL_FreeSurface(sacha[i]);
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
        if(positionJoueur.x == 2 && positionJoueur.y == 6) {
            positionJoueur.x = 20;
            positionJoueur.y = 5;
            break;
        }
        if (carte[pos->y][pos->x-1]==MUR)
        break;
        if (carte[pos->y][pos->x-1]==ROCHER)
        break;
        pos->x--;
        break;

        case DROITE:
        if(positionJoueur.x == 20 && positionJoueur.y == 5) {
            positionJoueur.x = 2;
            positionJoueur.y = 6;
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

    // On évite les erreurs liées à l'aléatoire
    srand(time(NULL));

    for(b=2; b<21; b++){


        if (carte[a][b] == 0 && carte[a][b] != SACHA){
            // Possibilité de rajouter de la difficulté
            int v = rand()%1;
            if(v==0){
                carte[a][b]=ROCHER;
            }
        }
    }
    }
    for(a=1; a<11; a++){
    for(b=2; b<21; b++){

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
