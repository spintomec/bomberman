#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

typedef struct(
    int key(SDL_LAST);
)
Touches;

void jouer(SDL_Surface* ecran);
void deplacerJoueur(int **carte, SDL_Rect *pos, int direction);
void placementAleatoireMur(int **carte);

#endif // JEU_H_INCLUDED
