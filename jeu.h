#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

//typedef struct()

void *gestion_bombe(void *arg);
void creationBombe(int **carte, SDL_Surface* ecran);
void jouer(SDL_Surface* ecran);
void deplacerJoueur(int **carte, SDL_Rect *pos, int direction);
void placementAleatoireMur(int **carte);

#endif // JEU_H_INCLUDED
