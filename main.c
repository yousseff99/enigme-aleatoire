#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include "aleatoire.h"
int main()
{
    srand(time(NULL));
    int nbr1,continuer=1,win=0,verif;
    SDL_Surface *zoneSaisie=NULL;
    SDL_Event event;
    TTF_Font *police=NULL;
    SDL_Color noire={33, 33, 33},blanche={255, 255, 255};
    TTF_Init();
    police = TTF_OpenFont("font.ttf", 50);
    char *phrase,* mot;
    phrase=calloc(20,sizeof(char));
    mot=calloc(6,sizeof(char));
    char rand1[500]="";
    char correctanswer[18][20]= {{"cc"},{"4,5"},{"344"},{"11231"},{"silence"}};
    SDL_Rect poszoneSaisie;
    poszoneSaisie.x=160;
    poszoneSaisie.y=300;
    SDL_Surface *ecran =NULL;
    ecran = SDL_SetVideoMode(735,441, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1){printf("%s",Mix_GetError());}
    image background,question1,question2,question3,question4;
    background=initialisation("images/bg.png",0,0);
    question1=initialisation("images/1.png",0,0);
    question2=initialisation("images/2.png",0,0);
    question3=initialisation("images/3.png",0,0);
    question4=initialisation("images/4.png",0,0);

    nbr1=random_nbr(nbr1);
    printf("question %d\n",nbr1);
    while (continuer&&win!=1)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)// win teta9ra l click
            {
            case SDLK_RETURN:
            if(win==0)
            {   
                printf("Entrer\n");
                verif=verifier_reponse(phrase,correctanswer,nbr1);
                if(verif==1)
                {
                sound_True();
                printf("True \n");
                win=1;
                sound_win();
                SDL_Delay(2500);
                }
                if(verif==-1)
                {
                sound_False();
                printf("False \n");
                nbr1=random_nbr(nbr1);
                printf("question %d\n",nbr1);
                }
                
            }break;
            case SDLK_BACKSPACE:
                printf("Effacer\n");
                int x = 0,longeur;
                longeur=strlen(phrase);
                longeur--;
                while(phrase[x] != '\0')
                {
                    if(x >=longeur)
                    {
                        phrase[x] = phrase[x+1];
                    }
                    x++;
                }
                break;
            case SDLK_MINUS:
                strcpy(mot,",");
                if(strlen(phrase)<7){strcat(phrase,mot);printf(",\n");}
                break;
            case SDLK_COMMA:
                strcpy(mot,",");
                if(strlen(phrase)<7){strcat(phrase,mot);printf(",\n");}
                break;
            case SDLK_KP0:
                strcpy(mot,"0");
                if(strlen(phrase)<7){strcat(phrase,mot);printf("0\n");}
                break;
            case SDLK_KP1:
                strcpy(mot,"1");
                if(strlen(phrase)<7){strcat(phrase,mot);printf("1\n");}
                break;
            case SDLK_KP2:
                strcpy(mot,"2");
                if(strlen(phrase)<7){strcat(phrase,mot);printf("2\n");}
                break;
            case SDLK_KP3:
                strcpy(mot,"3");
                if(strlen(phrase)<7){strcat(phrase,mot);printf("3\n");}
                break;
            case SDLK_KP4:
                strcpy(mot,"4");
                if(strlen(phrase)<7){strcat(phrase,mot);printf("4\n");}
                break;
            case SDLK_KP5:
                strcpy(mot,"5");
                if(strlen(phrase)<7){strcat(phrase,mot);printf("5\n");}
                break;
            case SDLK_KP6:
                strcpy(mot,"6");
                if(strlen(phrase)<7){strcat(phrase,mot);printf("6\n");}
                break;
            case SDLK_KP7:
                strcpy(mot,"7");
                if(strlen(phrase)<7){strcat(phrase,mot);printf("7\n");}
                break;
            case SDLK_KP8:
                strcpy(mot,"8");
                if(strlen(phrase)<7){strcat(phrase,mot);printf("8\n");}
                break;
            case SDLK_KP9:
                strcpy(mot,"9");
                if(strlen(phrase)<7){strcat(phrase,mot);printf("9\n");}
                break;
                //////////alphabet//////////
            case SDLK_a:
                strcpy(mot,"a");
                if(strlen(phrase)<7){strcat(phrase,mot);printf("a\n");}
                break;
            case SDLK_b:
                strcpy(mot,"b");
                if(strlen(phrase)<7){strcat(phrase,mot);printf("b\n");}
                break;
            case SDLK_c:
                strcpy(mot,"c");
                if(strlen(phrase)<7){strcat(phrase,mot);printf("c\n");}
                break;
            case SDLK_d:
                strcpy(mot,"d");
                if(strlen(phrase)<7){strcat(phrase,mot);printf("d\n");}
                break;
            case SDLK_e:
                strcpy(mot,"e");
                if(strlen(phrase)<7){strcat(phrase,mot);printf("e\n");}
                break;
            case SDLK_f:
                strcpy(mot,"f");
                if(strlen(phrase)<7){strcat(phrase,mot);printf("f\n");}
                break;
            case SDLK_g:
                strcpy(mot,"g");
                if(strlen(phrase)<7){strcat(phrase,mot);printf("g\n");}
                break;
            case SDLK_h:
                strcpy(mot,"h");
                if(strlen(phrase)<7){strcat(phrase,mot);printf("h\n");}
                break;
            case SDLK_i:
                strcpy(mot,"i");
                if(strlen(phrase)<7){strcat(phrase,mot);printf("i\n");}
                break;
            case SDLK_j:
                strcpy(mot,"j");
                if(strlen(phrase)<7){strcat(phrase,mot);printf("j\n");}
                break;
            case SDLK_k:
                strcpy(mot,"k");
                if(strlen(phrase)<7){strcat(phrase,mot);printf("k\n");}
                break;
            case SDLK_l:
                strcpy(mot,"l");
                if(strlen(phrase)<7){strcat(phrase,mot);printf("l\n");}
                break;
            case SDLK_m:
                strcpy(mot,"m");
                if(strlen(phrase)<7){strcat(phrase,mot);printf("m\n");}
                break;
            case SDLK_n:
                strcpy(mot,"n");
                if(strlen(phrase)<7){strcat(phrase,mot);printf("n\n");}
                break;
            case SDLK_o:
                strcpy(mot,"o");
                if(strlen(phrase)<7){strcat(phrase,mot);printf("o\n");}
                break;
            case SDLK_p:
                strcpy(mot,"p");
                if(strlen(phrase)<7){strcat(phrase,mot);printf("p\n");}
                break;
            case SDLK_q:
                strcpy(mot,"q");
                if(strlen(phrase)<7){strcat(phrase,mot);printf("q\n");}
                break;
            case SDLK_r:
                strcpy(mot,"r");
                if(strlen(phrase)<7){strcat(phrase,mot);printf("r\n");}
                break;
        case SDLK_s:
                strcpy(mot,"s");
                if(strlen(phrase)<7){strcat(phrase,mot);printf("s\n");}
                break;
            case SDLK_t:
                strcpy(mot,"t");
                if(strlen(phrase)<7){strcat(phrase,mot);printf("t\n");}
                break;
            case SDLK_u:
                strcpy(mot,"u");
                if(strlen(phrase)<7){strcat(phrase,mot);printf("u\n");}
                break;
            case SDLK_v:
                strcpy(mot,"v");
                if(strlen(phrase)<7){strcat(phrase,mot);printf("v\n");}
                break;
            case SDLK_w:
                strcpy(mot,"w");
                if(strlen(phrase)<7){strcat(phrase,mot);printf("w\n");}
                break;
            case SDLK_x:
                strcpy(mot,"x");
                if(strlen(phrase)<7){strcat(phrase,mot);printf("x\n");}
                break;
            case SDLK_y:
                strcpy(mot,"y");
                if(strlen(phrase)<7){strcat(phrase,mot);printf("y\n");}
                break;
            case SDLK_z:
                strcpy(mot,"z");
                if(strlen(phrase)<7){strcat(phrase,mot);printf("z\n");}
                break;
         }
     }
     affichage(ecran,background);
     if(nbr1==1)
     {
     affichage(ecran,question1);
     }
     if(nbr1==2)
     {
     affichage(ecran,question2);
     }
     if(nbr1==3)
     {
     affichage(ecran,question3);
     }
     if(nbr1==4)
     {
     affichage(ecran,question4);
     }
    if(win==0)
     {
      zoneSaisie=TTF_RenderText_Blended(police,phrase,blanche);
      SDL_BlitSurface(zoneSaisie,NULL,ecran,&poszoneSaisie);
     }
     SDL_Flip(ecran);               
    } 
    TTF_CloseFont(police);

    free_pictures(background);
    free_pictures(question1);
    free_pictures(question2);
    free_pictures(question3);
    free_pictures(question4);
TTF_Quit();
    SDL_Quit();
    return win;
}
