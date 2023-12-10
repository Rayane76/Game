#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "bilb.h"
#include "PLAYER.h"
#include <stdbool.h>
#include <time.h>


void jouer (SDL_Window *window , SDL_Renderer *renderer , int n , int pn)
{

    SDL_RenderClear(renderer) ;

///------DECLARATION
    int   y = 106 , min = 48 , max = 88 , test = 0 , x = 0,j,screen = 21,xc = 297;
    SDL_Surface *img = NULL, *A = NULL ,*(T4[8]) ,*(T4F[8]),*pause,*cont ,*menu,*pauseC,*menuC;
    SDL_Texture *text = NULL ;
    TTF_Font * font = TTF_OpenFont("Gameplay.ttf", 36);
    TTF_Font * font2 = TTF_OpenFont("Gameplay.ttf", 60);
    SDL_Color comf = {255,255,255} ;
    SDL_Surface * surfacew1 = TTF_RenderText_Solid(font,"LA COMB FINALE" , comf);
    SDL_Surface * save = TTF_RenderText_Solid(font2,"save and quit" , comf);
    cont = TTF_RenderText_Solid(font2,"continue" , comf);
    SDL_Init(SDL_INIT_TIMER) ;
    int start = SDL_GetTicks();
    SDL_Surface *timer_surface;
    int timer = 0;
    listeC P = NULL ;
    liste t = NULL ;
    img = IMG_Load("background3.jpg") ;
    time_t t1;
    pause = IMG_Load("pause.png") ;
    pauseC = IMG_Load("pauseC.png") ;
    menu = IMG_Load("menu.png") ;
    menuC = IMG_Load("menuC.png") ;
    srand ( (unsigned) time (&t1));
    SDL_CreateImageAndTexture(img,text,renderer,window , 0 , 0);
    CreateLettre(renderer ,surfacew1, 209 , 602 , 333 , 40) ;
    CreateLettre(renderer ,pause, 615 , 28 , 333 , 40) ;
    CreateLettre(renderer ,menu, 674 , 28 , 333 , 40) ;
    A = IMG_Load("A.jpg") ;
    ajouter_tete(&t,A,1) ;
    rempli(t) ;
    start = SDL_GetTicks() ;
    SDL_bool program_launched = SDL_TRUE;
    SDL_Surface *screen_surface = NULL;
    screen_surface = SDL_GetWindowSurface(window);
    SDL_Surface * quit = TTF_RenderText_Solid(font2,"Quit " , comf);


j = n-pn+1 ;
switch(n)
{
    case 4:
    xc = 295 ;
    break ;
    case 5:
    xc = 295-20 ;
    break ;
    case 6:
    xc = 295-20-20 ;
    break ;
    case 7:
    xc = 295-20-20-20 ;
    break ;
    case 8:
    xc = 295-80;
    break ;
    default :
        break ;
}
SDL_Rect c_rect = {150, 208, 800, 800};
///CREATION DE LA COMB INITAL
combInit(&(T4[0]) , &(T4F[0]) , n , &P , t) ;

///AFICHAGE DE LA COMB INITIAL
    imp_tab(&(T4[0]), n,xc ,48, renderer) ;
///CREATION DE LA COMB FINALE
    P = NULL ;
    combF(&(T4F[0]),&(T4[0]),n,&P,t,pn) ;
///AFICHAGE DE LA COM FINALE
    imp_tab(&(T4F[0]), n,xc ,662, renderer) ;
    SDL_Texture *pause_text = NULL ;
    int paused = 0 , ptime = 0;
SDL_Texture *cont_text = NULL;
SDL_Surface *image ;
arbre a = NULL ;
int supp = 1 ;
/// GAME ON
        while(program_launched){
            for(int i = 0 ; i<n;i++)
            {
                ajouter_teteentier(&a,findint(t,T4F[i])) ;
            }
            if(supp == 1) suppListe(&a) ;



            SDL_Event event;

            while(SDL_PollEvent(&event)){

                image = SDL_GetWindowSurface(window);
                switch(event.type){

            case SDL_MOUSEBUTTONDOWN :
                    if((event.motion.x <674+40 && event.motion.x>674)&&(event.motion.y<28+40 && event.motion.y>28))
                    {   Menu(window,renderer,t) ;
                        screen = 984 ;
                        while(screen == 984)
                        {
                            SDL_DestroyRenderer(renderer) ;
                        }
                    }
                  if((event.motion.x <615+40 && event.motion.x>615)&&(event.motion.y<28+40 && event.motion.y>28))
        {
            paused = 1;
            save_surfaces(image) ;
            ptime = SDL_GetTicks();
            // create the rectangle surface
            SDL_Surface *rect_surface = SDL_CreateRGBSurface(0, 750, 750, 32, 0, 0, 0, 0);
            SDL_FillRect(rect_surface, NULL, SDL_MapRGB(rect_surface->format, 31, 31, 31));
            //create the rectangle texture
            SDL_Texture *rect_texture = SDL_CreateTextureFromSurface(renderer, rect_surface);
            //draw the rectangle texture on top of the screen
            SDL_RenderCopy(renderer, rect_texture, NULL, NULL);
            // render the continue button
            CreateLettre(renderer ,cont, 212 , 208 , 0 , 0) ;
            CreateLettre(renderer,save, 150 , 346 , 0 , 0) ;
            CreateLettre(renderer ,quit, 300 , 483 , 0 , 0) ;


            while(paused == 1)
            {
                SDL_Event event2;
                while(SDL_PollEvent(&event2)){
                    switch(event2.type){
                        case SDL_MOUSEBUTTONDOWN:
                            if((event2.motion.x <538 && event2.motion.x>212)&&(event2.motion.y<208+60 && event2.motion.y>208))
                            {

                                paused = 0;
                                start += SDL_GetTicks() - ptime; //
                                //destroy the rectangle texture to make it invisible
                                SDL_DestroyTexture(rect_texture);
                                SDL_FreeSurface(rect_surface);
                                SDL_FillRect(screen_surface, &c_rect, SDL_MapRGB(screen_surface->format, 31, 31, 31));
                                imp_tab(&(T4[0]), n,xc ,y-50, renderer) ;
                                imp_tab(&(T4F[0]), n,xc ,662, renderer) ;
                                CreateLettre(renderer ,surfacew1, 209 , 602 , 333 , 40) ;
                                CreateLettre(renderer ,pause, 615 , 28 , 333 , 40) ;
                                CreateLettre(renderer ,menu, 674 , 26 , 333 , 40) ;


                            }
                            if((event2.motion.x <550 && event2.motion.x>150)&&(event2.motion.y<346+60 && event2.motion.y>346))
                            {
                                int supp = 0 ;
                                FILE* xf = fopen("x.txt", "w") ;
                                FILE* fp = fopen("tab.txt", "w") ;
                                FILE* fpfinale = fopen("tabfinale.txt", "w") ;
                                for(int i = 0 ; i < n ; i++)
                                {
                                    fprintf(fp,"%d " , findint(t,T4[i])) ;
                                    fprintf(fpfinale,"%d " , findint(t,T4F[i]) );
                                }

                                fprintf(xf, "%d %d %d %d %d %d %d %d", xc, y, min, max , pn , n , x , ptime);
                                paused = 0 ;
                                program_launched = SDL_FALSE;
                                fclose(xf) ;
                                fclose(fp) ;
                                fclose(fpfinale) ;
                            }
                            if((event2.motion.x <400 && event2.motion.x>300)&&(event2.motion.y<483+60 && event2.motion.y>483))
                            {   paused = 0 ;
                                program_launched = SDL_FALSE;
                            }
                            break;
                    }
                }
                SDL_RenderPresent(renderer);
            }
        }

/// IF CLICK ON 1
                if((event.motion.x <xc+40 && event.motion.x>xc)&&(event.motion.y<max && event.motion.y>min))
                {   switch(pn)
                {
                    case 2 :
                         change2(1,&(T4[0]),t) ;
                    break ;
                    case 3 :
                         change3(1,&(T4[0]),t) ;
                    break ;
                    case 4 :
                         change4(1,&(T4[0]),t) ;
                    break ;
                    case 5 :
                        change5(1,&(T4[0]),t) ;
                    break ;
                }

                    imp_tab(&(T4[0]), n ,xc,y, renderer) ;
                    y = y + 50;
                    x++ ;
                     min  = min + 50 ;
                     max  = max + 50 ;


                }
/// IF CLICK ON 2
                else if((event.motion.x <xc+80 && event.motion.x>xc+40)&&(event.motion.y<max && event.motion.y>min))
                {
                  switch(pn)
                {
                    case 2 :
                         change2(2,&(T4[0]),t) ;
                    break ;
                    case 3 :
                         change3(2,&(T4[0]),t) ;
                    break ;
                    case 4 :
                         change4(2,&(T4[0]),t) ;
                    break ;
                    case 5 :
                        change5(2,&(T4[0]),t) ;
                    break ;

                }

                    imp_tab(&(T4[0]), n ,xc,y, renderer) ;
                    y = y + 50;
                    x++ ;
                     min  = min + 50 ;
                     max  = max + 50 ;


                }

/// IF CLICK ON 3
                else if((event.motion.x <xc+120 && event.motion.x>xc+80)&&(event.motion.y<max && event.motion.y>min) && (j>2))
                {
                    switch(pn)
                {
                    case 2 :
                         change2(3,&(T4[0]),t) ;
                    break ;
                    case 3 :
                         change3(3,&(T4[0]),t) ;
                    break ;
                    case 4 :
                         change4(3,&(T4[0]),t) ;
                    break ;
                     case 5 :
                        change5(3,&(T4[0]),t) ;
                    break;

                }


                    imp_tab(&(T4[0]), n ,xc,y, renderer) ;
                    y = y + 50;
                    x++ ;
                     min  = min + 50 ;
                     max  = max + 50 ;


                }
/// IF CLICK ON 4
               else if((event.motion.x <xc+160 && event.motion.x>xc+120)&&(event.motion.y<max && event.motion.y>min) && (n>4) && (j>3))
               {
                     switch(pn)
                {   case 2 :
                        change2(4,&(T4[0]),t) ;
                    break ;
                    case 3 :
                         change3(4,&(T4[0]),t) ;
                    break ;
                    case 4 :
                         change4(4,&(T4[0]),t) ;

                    break ;
                    case 5 :
                        change5(4,&(T4[0]),t) ;
                }


                    imp_tab(&(T4[0]), n ,xc,y, renderer) ;
                    y = y + 50;
                    x++ ;
                     min  = min + 50 ;
                     max  = max + 50 ;
               }
/// IF CLICK ON 5

                else if(((event.motion.x <(xc+200)) && (event.motion.x>xc+160))&&((event.motion.y<max) && (event.motion.y>min)) && (n>5) && (j>4))
               {
                     switch(pn)
                {
                    case 3 :
                         change3(5,&(T4[0]),t) ;
                    break ;
                    case 4 :
                         change4(5,&(T4[0]),t) ;
                    break ;
                }


                    imp_tab(&(T4[0]), n ,xc,y, renderer) ;
                    y = y + 50;
                    x++ ;
                     min  = min + 50 ;
                     max  = max + 50 ;
               }
 {printf("ELSE");}


                test = same(&(T4[0]),&(T4F[0]),4,t) ;
                if(test == 1)
                {
               // save_timer_and_date(timer) ;
                // YOUWON(window,renderer , timer) ;
                youwon(window,renderer,font,timer,t) ;
                 screen = 100 ;

                            while(screen == 100)
                            {
                                SDL_DestroyRenderer(renderer);
                            }
                }

                if(x==10) YOULOST(window ,renderer) ;


                break ;




                case SDL_QUIT:
                           program_launched = SDL_FALSE;
                           break;

                      default:
                          break;
                }
                }

  // update timer
   if(paused == 0) timer = (SDL_GetTicks() - start) / 1000;

    // clear the timer rect area on the screen surface
    SDL_Rect timer_rect = {100, 100, 40, 40};
    SDL_Rect page_rect = {100, 100, 60, 60};
    SDL_FillRect(screen_surface, &page_rect, SDL_MapRGB(screen_surface->format, 31, 31, 31));

    // render timer as text
    timer_surface = TTF_RenderText_Solid(font, int_to_string(timer), comf);
    SDL_BlitSurface(timer_surface, NULL, screen_surface, &timer_rect);

    // update the screen
    SDL_UpdateWindowSurface(window);
    SDL_FreeSurface(timer_surface);

            }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

}



void showN (SDL_Window *window , SDL_Renderer *renderer)
{
     SDL_RenderClear(renderer) ;
     SDL_Surface *img = NULL,*tn,*tpn,*grandN,*petitN,*start,*start2 ;
     img = IMG_Load("background3.jpg") ;
     SDL_Texture *text = NULL;
     SDL_CreateImageAndTexture(img,text,renderer,window , 0 , 0);
     int n , pn ;
     SDL_Color comf = {255,255,255} ;
     SDL_Color colorTitle2 = { 250, 179, 39  };

    /// GRAND N
    do
    {
        n = 1 + rand() ;
    }while(n < 4 || n > 8) ;
    /// PETIT N
    do
    {
        pn = 1 + rand() ;
    }while(pn < (n/2) || pn >= (n-1) ) ;
    printf("N = %d\n",n) ;
    printf("n = %d",pn) ;
   // n = 8 ; pn = 6 ;
    if(n==8 && pn ==6 ) pn = 5 ;
    TTF_Font * font = TTF_OpenFont("Gameplay.ttf", 60);
    tn = TTF_RenderText_Solid(font, int_to_string(n), comf);
    grandN = TTF_RenderText_Solid(font, "Grand N", comf);
    petitN = TTF_RenderText_Solid(font, "Petit N", comf);
    tpn = TTF_RenderText_Solid(font, int_to_string(pn), comf);
    start = TTF_RenderText_Solid(font, "START", comf);
    start2 = TTF_RenderText_Solid(font, "START", colorTitle2);
    SDL_bool program_launched = SDL_TRUE;
    int screen = 21 ;
    CreateLettre(renderer,tn,354,182,0,0) ;
    CreateLettre(renderer,grandN,233,85,0,0) ;
    CreateLettre(renderer,petitN,240,288,0,0) ;
    CreateLettre(renderer,tpn,354,385,0,0) ;
    CreateLettre(renderer,start,264,609,0,0) ;
 while(program_launched){
            SDL_Event event;

            while(SDL_PollEvent(&event)){
                switch(event.type){
                    case SDL_MOUSEBUTTONDOWN :
                        if((event.motion.x <485 && event.motion.x>264)&&(event.motion.y<667&& event.motion.y>609))
                        {      screen = 40 ;
                        while(screen == 40)
                        {
                            jouer(window,renderer,n,pn) ;
                        }



                        }
                    break ;
                    case SDL_MOUSEMOTION :
                         if((event.motion.x <485 && event.motion.x>264)&&(event.motion.y<667&& event.motion.y>609))
                        {
                                    CreateLettre(renderer,start2,264,609,0,0) ;


                        }else {CreateLettre(renderer,start,264,609,0,0) ;}
                    break ;

                      case SDL_QUIT:
                           program_launched = SDL_FALSE;
                           break;

                      default:
                          break;
                }
                }
            }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

