#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include<SDL_image.h>
#include "bilb.h"
#include "PLAYER.h"
#include <stdbool.h>
#include "MACHINE.h"
#include "MachineVsPlayer.h"



int main(int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *r = NULL ;
    SDL_Surface *img = NULL ,*A;
    SDL_Texture *texture = NULL;
    TTF_Init();
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
    int screen = 0  ;

    liste t= NULL ;
     A = IMG_Load("A.jpg") ;
    ajouter_tete(&t,A,1) ;
    rempli(t) ;
  // TTF_Font * font = TTF_OpenFont("SF Atarian System.ttf", 30);
    img =IMG_Load("background3.jpg");
    r = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

    window = SDL_CreateWindow("Premiere fenetre SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 750, 750, 0);
    r =  SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    SDL_CreateImageAndTexture(img,texture,r,window , 0 , 0 );

    //   CreateLettre(r ,img,100 , 100 , 100 , 100) ;

       TTF_Font * font = TTF_OpenFont("Gameplay.ttf", 60);
        SDL_Color colorTitle = { 255, 255, 255 };
     //   SDL_Color colorTitle2 = { 23, 44, 188 };
        SDL_Surface * surfacew1 = TTF_RenderText_Solid(font,"PLAYER" , colorTitle);
       CreateLettre(r ,surfacew1, 242 , 208 , 0 , 0) ;
         SDL_Color colorTitle2 = { 250, 179, 39  };
        SDL_Surface *surfacew2 = TTF_RenderText_Solid(font,"PLAYER" , colorTitle2);

        SDL_Surface * surfacew4 = TTF_RenderText_Solid(font,"MACHINE " , colorTitle);
       CreateLettre(r ,surfacew4, 235 , 346 , 0 , 0) ;
       SDL_Surface * surfacew5 = TTF_RenderText_Solid(font,"MACHINE " , colorTitle2);



        SDL_Surface * surfacew3 = TTF_RenderText_Solid(font,"P vs M " , colorTitle);
        SDL_Surface * surfacew6 = TTF_RenderText_Solid(font,"P vs M " , colorTitle2);
       CreateLettre(r ,surfacew3, 267 , 483 , 0 , 0) ;


        SDL_Surface *lead ,*lead2,*load,*load2 ;
        lead = IMG_Load("lead.png") ;
        lead2 = IMG_Load("lead2.png") ;
        load = IMG_Load("load.png") ;
        load2 = IMG_Load("load2.png") ;

        CreateLettre(r,lead,311 ,619,0,0) ;
        CreateLettre(r,load,384 ,619,0,0) ;
    SDL_bool program_launched = SDL_TRUE;

        while(program_launched){
            SDL_Event event;


            while(SDL_PollEvent(&event)){
                switch(event.type){
                    case SDL_MOUSEMOTION:
                        if((event.motion.x <503 && event.motion.x>242)&&(event.motion.y<266&& event.motion.y>175))
                        {

                            CreateLettre(r ,surfacew2, 242 , 208 , 0 , 0) ;

                        }
                         else if((event.motion.x <519 && event.motion.x>228)&&(event.motion.y<403&& event.motion.y>345))
                        {
                            CreateLettre(r ,surfacew5, 235 , 346 , 0 , 0) ;

                        }

                         else if((event.motion.x <490 && event.motion.x>267)&&(event.motion.y<543&& event.motion.y>483))
                        {
                              CreateLettre(r ,surfacew6, 267 , 483 , 0 , 0) ;
                        }
                        else if((event.motion.x <(311+60) && event.motion.x>311)&&(event.motion.y<(619+60)&& event.motion.y>619))
                        {
                               CreateLettre(r,lead2,311 ,619,0,0) ;
                        }
                        else if((event.motion.x <(384+60) && event.motion.x>384)&&(event.motion.y<(619+60)&& event.motion.y>619))
                        {
                               CreateLettre(r,load2,384 ,619,0,0) ;
                        }
                        else {CreateLettre(r ,surfacew1, 242 , 208 , 0 , 0) ;
                            CreateLettre(r ,surfacew4, 235 , 346 , 0 , 0) ;
                             CreateLettre(r,lead,311 ,619,0,0) ;
                             CreateLettre(r,load,384 ,619,0,0) ;
                            CreateLettre(r ,surfacew3, 267 , 483 , 0 , 0) ;
                            }
                    break ;
                    case SDL_MOUSEBUTTONDOWN:

                        if((event.motion.x <503 && event.motion.x>242)&&(event.motion.y<266&& event.motion.y>175))
                        {
                            showN(window,r) ;
                            screen= 2 ;
                            while(screen == 2)
                            {
                                SDL_DestroyRenderer(r);
                            }



                        }
                        else if((event.motion.x <519 && event.motion.x>228)&&(event.motion.y<403&& event.motion.y>345))
                        {
                            nbrN(window,r) ;
                            screen = 3 ;
                            while(screen == 3)
                            {
                                SDL_DestroyRenderer(r);
                            }

                        }
                        else if((event.motion.x <490 && event.motion.x>267)&&(event.motion.y<543&& event.motion.y>483))
                        {
                              MvsP(window,r) ;
                            screen = 999 ;
                            while(screen == 999)
                            {
                                SDL_DestroyRenderer(r);
                            }
                        }
                        else if((event.motion.x <(311+40) && event.motion.x>311)&&(event.motion.y<(619+60)&& event.motion.y>619))
                        {
                            LEADERBOARD(window,r , t) ;
                            screen = 12 ;
                            while(screen == 12)
                            {
                                SDL_DestroyRenderer(r);
                            }
                        }
                        else if((event.motion.x <(384+60) && event.motion.x>384)&&(event.motion.y<(619+60)&& event.motion.y>619))
                        {
                            Load(window,r,t) ;
                            screen = 1200 ;
                            while(screen == 1200)
                            {
                                SDL_DestroyRenderer(r);
                            }
                        }

                     break;


                      case SDL_QUIT:
                           program_launched = SDL_FALSE;
                           break;

                      default:
                          break;
                }
                }
            }




    SDL_DestroyRenderer(r);
    SDL_DestroyWindow(window);
    SDL_Quit();



        return 0;
}
