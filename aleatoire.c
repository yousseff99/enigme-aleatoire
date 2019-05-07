#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include "aleatoire.h"

image initialisation(char nameofpicure[70],int x,int y)
{
    image image;
    image.img=IMG_Load(nameofpicure);
    image.posimg.x=x;
    image.posimg.y=y;
    return image;
}

void affichage(SDL_Surface *ecran,image image)
{
    SDL_BlitSurface(image.img,NULL,ecran,&image.posimg);
}

void free_pictures(image image)
{
    SDL_FreeSurface(image.img);
}

int random_nbr(int nbr1)
{
    srand(time(NULL));
    nbr1=rand() % 4 + 1;
    return nbr1;
}

int verifier_reponse(char *phrase,char correctanswer[18][20],int nbr1)
{
    int verif=0;
    //printf("question %d\n",nbr1);

  if(nbr1==1)
  {
    if (strcmp(phrase,correctanswer[1])==0)
    {
        verif=1;
    }
    else
    {
        verif=-1;
    }
   }

  if(nbr1==2)
  {
    if (strcmp(phrase,correctanswer[2])==0)
    {
        verif=1;
    }
    else
    {
        verif=-1;
    }
   }

  if(nbr1==3)
  {
    if (strcmp(phrase,correctanswer[3])==0)
    {
        verif=1;
    }
    else
    {
        verif=-1;
    }
   }

  if(nbr1==4)
  {
    if (strcmp(phrase,correctanswer[4])==0)
    {
        verif=1;
    }
    else
    {
        verif=-1;
    }
   }
   
    //printf("verif= %d\n",verif);
    return verif;
}

void sound_True()
{
    Mix_Chunk *truee; 
    truee = Mix_LoadWAV("sound/true.wav");
    Mix_PlayChannel(1, truee, 0);
}

void sound_False()
{
    Mix_Chunk *falsee; 
    falsee = Mix_LoadWAV("sound/false.wav");
    Mix_PlayChannel(1, falsee, 0);
}

void sound_win()
{
    Mix_Chunk *win; 
    win = Mix_LoadWAV("sound/win.wav");
    Mix_PlayChannel(1, win, 0);
}

