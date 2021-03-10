#include"fichier.h"
void menu(SDL_Surface *screen,int *continuer,Mix_Music *music,Mix_Chunk *effect)
{
TTF_Init();
int continuer2=1;
SDL_Surface *opt;
TTF_Font *police = NULL;
SDL_Surface *image1 = NULL;
SDL_Rect playerrect;
SDL_Surface *exite2 = NULL;
SDL_Surface *play2 = NULL;
SDL_Surface *option2 = NULL;
SDL_Surface *foption = NULL;
SDL_Event event;
SDL_Color couleur= {255,0,0};
SDL_Surface *play = NULL;
SDL_Surface *options = NULL;
SDL_Surface *exite = NULL;
SDL_Surface *texte = NULL;
SDL_Rect positionecran , positionClic;
image1 =IMG_Load("image1.png");
play =IMG_Load("play.png");
options =IMG_Load("options.png");
exite =IMG_Load("exit.png");
exite2 =IMG_Load("buttonexit.png");
play2 =IMG_Load("buttonplay.png");
option2=IMG_Load("buttonoptions.png");
police = TTF_OpenFont("Takota.ttf",50);
texte =TTF_RenderText_Blended(police,"SWORD",couleur);
while(*continuer)
{
while (SDL_PollEvent(&event))
{
switch (event.type)
{
case SDL_QUIT:
    continuer=0;
    break ;
case SDL_KEYDOWN:
switch (event.key.keysym.sym)
{
case SDLK_ESCAPE:
continuer=0;
SDL_Quit();
break;
}
case SDL_MOUSEBUTTONUP:
if (event.button.button == SDL_BUTTON_LEFT)
{
positionClic.x=event.button.x;
positionClic.y=event.button.y;
if(event.button.x>425&&event.button.x<575&&event.button.y>300&&event.button.y<375)
{continuer=0;
SDL_Quit();
}
while(continuer2)
{
 if (event.button.x>425&&event.button.x<575&&event.button.y>220&&event.button.y<250)
{
option(opt,&continuer2);
}

}

case SDL_MOUSEMOTION:
if(event.motion.x>425&&event.motion.x<575&&event.motion.y>300&&event.motion.y<375)
{
Mix_PlayChannel(1,effect,3);

positionecran.x=200;
positionecran.y=180;
SDL_BlitSurface(exite2,NULL,screen,&positionecran);
SDL_Flip(screen);

Mix_Pause(1);
}
else if(event.motion.x>425&&event.motion.x<575&&event.motion.y>150&&event.motion.y<200)
{
Mix_PlayChannel(1,effect,3);

positionecran.x=200;
positionecran.y=38;
SDL_BlitSurface(play2,NULL,screen,&positionecran);
SDL_Flip(screen);

Mix_Pause(1);
}
else if(event.motion.x>425&&event.motion.x<575&&event.motion.y>220&&event.motion.y<250)
{
Mix_PlayChannel(1,effect,3);

positionecran.x=180;
positionecran.y=120;
SDL_BlitSurface(option2,NULL,screen,&positionecran);

SDL_Flip(screen);
//SDL_Delay(1);
Mix_Pause(1);
}
}
}
}

positionecran.x=0;
positionecran.y=0;
SDL_BlitSurface(image1,NULL,screen,&positionecran);
positionecran.x=210;
positionecran.y=50;
SDL_BlitSurface(play,NULL,screen,&positionecran);
positionecran.x=200;
positionecran.y=100;
SDL_BlitSurface(options,NULL,screen,&positionecran);
positionecran.x=200;
positionecran.y=190;
SDL_BlitSurface(exite,NULL,screen,&positionecran);
positionecran.x=50;
positionecran.y=50;
SDL_BlitSurface(texte,NULL,screen,&positionecran);
SDL_Flip(screen);
Mix_PlayMusic(music,-1);
SDL_Flip(screen);
continuer2=1;
}
Mix_FreeMusic(music);
Mix_FreeChunk(effect);
Mix_Quit();
SDL_FreeSurface(texte);
TTF_CloseFont(police);
SDL_FreeSurface(opt);
SDL_FreeSurface(screen);
}

void option(SDL_Surface* opt,int *continuer2)
{
TTF_Init();

    SDL_Surface *background= NULL;
     SDL_Surface *textback=NULL;
	SDL_Surface *imagesound=NULL;
	SDL_Rect positionClic;
    SDL_Rect positionFond, posback,possound;
 TTF_Font *police = NULL;
    SDL_Color couleur ={226,206,206};
    SDL_Event event;
opt= SDL_SetVideoMode(1400,1400,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_Flip(opt);
 
    while (*continuer2)
    {
        while (SDL_PollEvent(&event))
        {
	switch(event.type)
        {
        case SDL_QUIT:
            *continuer2 = 0;
            break;
	case SDL_MOUSEBUTTONUP:
	if (event.button.button == SDL_BUTTON_LEFT)
	{
	positionClic.x=event.button.x;
	positionClic.y=event.button.y;
if(event.button.x>120&&event.button.x<200&&event.button.y>200&&event.button.y<250)
*continuer2=0;
break;
	}
	}
	}
        SDL_FillRect(opt, NULL, SDL_MapRGB(opt->format, 0, 0, 0));
	positionFond.x = 0;
        positionFond.y =0;
        background = IMG_Load("b.opt.png");
        SDL_BlitSurface(background, NULL, opt, &positionFond);
	posback.x=120;
	posback.y=320;
        possound.x=120;
        possound.y=200;
        police = TTF_OpenFont("Takota.ttf", 70);
        textback = TTF_RenderText_Blended(police, "2:Back", couleur);
	SDL_BlitSurface(textback, NULL, opt, &posback);
	imagesound = TTF_RenderText_Blended(police, "1:son up  down", couleur);
	SDL_BlitSurface(imagesound, NULL, opt, &possound);
        SDL_Flip(opt);
}
SDL_FreeSurface(textback);
SDL_FreeSurface(imagesound);
SDL_FreeSurface(background);
TTF_CloseFont(police);
SDL_FreeSurface(opt);
 TTF_Quit();

}
