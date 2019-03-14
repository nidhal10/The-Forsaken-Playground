#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include <time.h>
#include "enig.h"



int main(int argc, char *argv[])
{
srand(time(NULL));
int nbalea=0;
char image[20],categorie1[20]="j",categorie2[20]="s";

SDL_Surface *ecran = NULL, *imagefond=NULL, *enigme=NULL;

SDL_Rect positionFond;
    SDL_Event event;
    int continuer = 1;

    positionFond.x = 0;
    positionFond.y = 0;

SDL_Init(SDL_INIT_VIDEO);

ecran = SDL_SetVideoMode(1024, 600, 32, SDL_HWSURFACE); 

SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

SDL_WM_SetCaption("affichage et initialisation enigme", NULL);

imagefond = IMG_Load("int.jpg");

SDL_BlitSurface(imagefond, NULL, ecran, &positionFond);
SDL_Flip(ecran);
while (continuer)

{

    SDL_WaitEvent(&event);

    switch(event.type)

    {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)

            {
                case SDLK_ESCAPE: 
                   
ecran = SDL_SetVideoMode(1024, 600, 32, SDL_HWSURFACE); 

SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
                    SDL_BlitSurface(imagefond, NULL, ecran, &positionFond);
SDL_Flip(ecran);
                    break;
            }

            break;
            case SDL_QUIT: 
            continuer = 0; 
            break;
case SDL_MOUSEBUTTONDOWN:
switch(event.button.button)
{
case SDL_BUTTON_LEFT:
if((event.button.x<1000)&&(event.button.x>550)&&(event.button.y>1)&&(event.button.y<599))
            {
            strcpy(image,"");
            strcpy(categorie1,"j");
            nbalea=1+rand()%2;
            sprintf(image,"%d",nbalea);
            strcat(image,".jpg");
            strcat(categorie1,image);
            strcpy(image,categorie1);
            afficher_enigme(image);
            SDL_Flip(ecran);
            }
else if((event.button.x<500)&&(event.button.x>1)&&(event.button.y>1)&&(event.button.y<599))
 
            {
            strcpy(image,"");
            strcpy(categorie2,"s");
            nbalea=1+rand()%3;
            sprintf(image,"%d",nbalea); 
            strcat(image,".jpg");
            strcat(categorie2,image);
            strcpy(image,categorie2);
            afficher_enigme(image);
            SDL_Flip(ecran);
            }

break;
}
    }
}
SDL_Flip(ecran);

    SDL_FreeSurface(imagefond);
    SDL_FreeSurface(enigme);
    SDL_Quit(); 
    return EXIT_SUCCESS; 
}
