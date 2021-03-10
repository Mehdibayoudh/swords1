#include"fichier.h"
int main(int argc ,char argv[])
{
int continuer=1;

SDL_Surface *screen;
SDL_Rect positionecran;
Mix_Music*music;
Mix_Chunk *effect ;
Mix_Chunk *effect2 ;
SDL_Rect positionClic ;
SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
printf("Erreur :%s \n",SDL_GetError());
}
if(SDL_Init(SDL_INIT_VIDEO) != 0)
{
printf("Erreur :%s \n",SDL_GetError());
return 1;
}
screen= SDL_SetVideoMode(1400,1400,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
if(screen==NULL)
{
printf("Erreur :%s \n",SDL_GetError());
return 1;
}

music=Mix_LoadMUS("horror.mp3");
effect=Mix_LoadWAV("boutonn.wav");

while(continuer)
{
SDL_FillRect(screen,NULL, SDL_MapRGB(screen->format, 0, 0, 0));
menu(screen,&continuer,music,effect);
}
SDL_Quit();
return 0;
}

