#include "game.h" 
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>



void afficher_entite_secondaire (ent *E, SDL_Surface *ecran) 
{

SDL_BlitSurface(E->image_entite,NULL,ecran,&E->dst);

SDL_Flip(ecran) ;

	
	

}


