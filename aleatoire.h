#ifndef ALEATOIRE_H_
#define ALEATOIRE_H_

typedef struct image
{
	SDL_Surface *img;
	SDL_Rect posimg;
}image;


image initialisation(char nomimage[100],int x,int y);
void affichage(SDL_Surface *ecran,image img);
int random_nbr(int nbr1);
int random_nbr2(int nbr1);
int random_nbr3(int nbr1);
int random_nbr4(int nbr1);
int verifier_reponse(char *phrase,char correctanswer[18][20],int nbr1);
void sound_True();
void sound_False();
void sound_win();
void free_pictures(image img);



#endif
