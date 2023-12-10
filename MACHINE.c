#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "bilb.h"
#include "PLAYER.h"
#include <stdbool.h>
#include <time.h>

///THE GAME//////////////////////////////////
void GameOn(SDL_Window *window , SDL_Renderer *renderer , int N,int pn,listeSy premierecombinaison,listeSy dernierecombinaison )
{   ///DECLARATION
    SDL_Surface *img = NULL,*A= NULL ,*mkach = NULL,*menu= NULL , *menu2;
    liste t = NULL ;
    A = IMG_Load("A.jpg") ;
    ajouter_tete(&t,A,1) ;
    rempli(t) ;
    img = IMG_Load("background3.jpg") ;
    SDL_Texture *text = NULL;
    SDL_CreateImageAndTexture(img,text,renderer,window , 0 , 0);
    listeP all = NULL;
    long int res;
    listeSy cambin = NULL;
    res = combinaisonTransformEnNombre(premierecombinaison,N);
    ajouter_tetenor(&all,premierecombinaison,res,0,-1);
    listeP avancer,test,insere;
    listeSy crt = NULL;
    int sc;
    avancer = all;
    insere = all;
    int e;
    TTF_Font * font = TTF_OpenFont("Gameplay.ttf", 36);
    SDL_Color colorTitle = { 250, 250, 250  };
    SDL_Color colorTitle2 = { 250, 179, 39  };
    mkach = TTF_RenderText_Solid(font , "cette combinaison n exsite pas !!",colorTitle) ;
    menu = TTF_RenderText_Solid( font , "doner une nouvelle comb",colorTitle) ;
    menu2 = TTF_RenderText_Solid( font , "doner une nouvelle comb",colorTitle2) ;
    int pile = 1;
    int prpile = 0;
    if((nbr_paire(N)==0) && pn == N / 2){ pn = pn + 1;}

printf("%d",N) ;
printf("%d",pn) ;
int xc =295 ;
switch(N)
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
/// LES COMB POSSIBLE
    while (avancer != NULL)
    {

     e = 1 ;
     while (e<=(N-pn+1)){
        test = all;
        crt = NULL;
        crt = nouvListe((avancer->info));
        res = 0;
        sc = 0;
        cambin = NULL;
        cambin = play(crt,e,pn,N);
        res = combinaisonTransformEnNombre(cambin,N);

        while (test != NULL && sc == 0){
            if ((test->somme) == res){ sc = sc+1;}
            test = (test->suiv);
        }
        if (sc == 0){
            ajouter_apresnor(&insere,cambin,res,pile,prpile);
            pile = pile + 1;
            }
        e = e + 1;

        }
     avancer = avancer->suiv ;
     prpile = prpile + 1;

}
    ///CHEMIN + AFFICHAGE
    listef affmachine = NULL;
    affiche_listefin(affmachine,t,renderer,100) ;
    long int smcmbfin = combinaisonTransformEnNombre(dernierecombinaison,N);
    listeP parcour = NULL;
    int save;
    int restart3 = combfinalexiste2(all,dernierecombinaison,N);
    if (restart3 == 0){
       // printf("mkach!");
       CreateLettre(renderer,mkach,15,250,0,0) ;
    }
    else { printf("CECI EST UNE COMBINAISON FINALE !\n\n");

      parcour = all;
      while (parcour->somme != smcmbfin){
        parcour = parcour ->suiv;
      }
      while ((parcour->prdindice) >= 0){
         ajouter_tetefin(&affmachine,parcour->info,0);
         save = parcour->prdindice;
         while ((parcour -> indice) != save ){
            parcour = parcour ->pred;
         }
    }


     affiche_listefinE(affmachine);
         affiche(premierecombinaison,t,renderer,xc,50) ;


    }

    parcour = all;
        while ((parcour->prdindice) >= 0){
         ajouter_tetefin(&affmachine,parcour->info,0);
         save = parcour->prdindice;
         while ((parcour -> indice) != save ){
            parcour = parcour ->pred;
         }
    }


     printf("\n");
    affiche_listefinPvsM(affmachine,t,renderer,xc,100) ;
    CreateLettre(renderer,menu,74,519,0,0) ;

      SDL_bool program_launched = SDL_TRUE;

        while(program_launched){
            SDL_Event event;

            while(SDL_PollEvent(&event)){
                switch(event.type){
              case SDL_MOUSEMOTION :


                if((event.motion.x <651 && event.motion.x>74)&&(event.motion.y<565 && event.motion.y>531))
                {
                    CreateLettre(renderer,menu2,74,519,0,0) ;
                }else {CreateLettre(renderer,menu,74,519,0,0) ;}
                break ;
                      case SDL_MOUSEBUTTONDOWN :


                if((event.motion.x <651 && event.motion.x>74)&&(event.motion.y<565 && event.motion.y>531))
                {
                    nbrN(window,renderer) ;
                }
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
























void CombFINALE(SDL_Window *window , SDL_Renderer *renderer , int N,int pn,listeSy premierecombinaison )
{
    SDL_Surface *img = NULL , *A = NULL , *rectangle = NULL,*text2 ,*text3;
    int compteur = 0 ;
    int i ;
    SDL_Texture *text = NULL;
    img = IMG_Load("background3.jpg") ;
    rectangle = IMG_Load("rect.png") ;
   TTF_Font * font = TTF_OpenFont("Gameplay.ttf", 60);
    TTF_Font * font2 = TTF_OpenFont("Gameplay.ttf", 48);
    SDL_Color colorTitle = { 255, 255, 255 };
   // DONNER = TTF_RenderText_Solid(font2,"DONNER LA COMB INITIAL" , colorTitle);
    SDL_CreateImageAndTexture(img,text,renderer,window , 0 , 0);
    text2 = TTF_RenderText_Solid(font2,"donner la comb finale" , colorTitle);
    text3 = TTF_RenderText_Solid(font,"OK" , colorTitle);
        int XClavier = 58 ,YClavier = 309 , c=0,jk = 0;
      CreateLettre(renderer,rectangle,132,25,0,0) ;
      CreateLettre(renderer,rectangle,132,213,0,0) ;
      CreateLettre(renderer,text2,39,138,0,0) ;
      CreateLettre(renderer,text3,330,640,0,0) ;
    liste t = NULL , ts = NULL  ;
  //  int screen = 50 ;
    A = IMG_Load("A.jpg") ;
    ajouter_tete(&t,A,1) ;
    rempli(t) ;
    SDL_bool program_launched = SDL_TRUE;
    affiche(premierecombinaison,t,renderer,201,42) ;
/// AFFICHAGE DE CLAVIER
    ts = t ;
    while(jk < 48)
    {
        CreateLettre(renderer,ts->img,XClavier,YClavier,0,0) ;
        XClavier = XClavier + 54 ;
        ts=ts->svt ;
        c++ ; jk++ ;
        if(c==12){YClavier = YClavier + 62 ; XClavier = 58 ; c = 0 ;}

    }
    XClavier = 275 ;
    for(i=1;i<=4;i++)
    {
        CreateLettre(renderer,ts->img,XClavier,558,0,0) ;
        XClavier = XClavier + 54 ;
        ts = ts->svt ;
    }
    listeSy dernierecombinaison = NULL, pcmbp = NULL;
    int xx = 187;
        while(program_launched){
            SDL_Event event;

            while(SDL_PollEvent(&event)){
                switch(event.type){
                    case SDL_MOUSEBUTTONDOWN :
                     if((event.motion.x <418 && event.motion.x>330)&&(event.motion.y<698 && event.motion.y>640) )
                     {
                         GameOn(window,renderer,N,pn, premierecombinaison ,  dernierecombinaison) ;
                     }
                       if((event.motion.x <(58+40) && event.motion.x>58)&&(event.motion.y<349 && event.motion.y>309))
                     {
                         CreateLettre(renderer,findC(t,1),xx,230,0,0) ;
                         xx = xx + 40 ;
                         if(dernierecombinaison == NULL) {ajouter_t(&dernierecombinaison,1);pcmbp = dernierecombinaison;}
                        else ajouter_p(&pcmbp,1);
                        compteur ++ ;

                     }
                       if((event.motion.x >(112) && event.motion.x<(112+40))&&(event.motion.y<349 && event.motion.y>309))
                     {
                         CreateLettre(renderer,findC(t,-1),xx,230,0,0) ;
                         xx = xx + 40 ;
                         if(dernierecombinaison == NULL) {ajouter_t(&dernierecombinaison,-1);pcmbp = dernierecombinaison;}
                        else ajouter_p(&pcmbp,-1);
                        compteur ++ ;

                     }
                      if((event.motion.x >(166) && event.motion.x<(166+40))&&(event.motion.y<349 && event.motion.y>309))
                     {
                         CreateLettre(renderer,findC(t,2),xx,230,0,0) ;
                         xx = xx + 40 ;
                         if(dernierecombinaison == NULL) {ajouter_t(&dernierecombinaison,2);pcmbp = dernierecombinaison;}
                        else ajouter_p(&pcmbp,2);
                        compteur ++ ;

                     }
                       if((event.motion.x >(220) && event.motion.x<(220+40))&&(event.motion.y<349 && event.motion.y>309))
                     {
                         CreateLettre(renderer,findC(t,-2),xx,230,0,0) ;
                         xx = xx + 40 ;
                         if(dernierecombinaison == NULL) {ajouter_t(&dernierecombinaison,-2);pcmbp = dernierecombinaison;}
                        else ajouter_p(&pcmbp,-2);
                        compteur ++ ;

                     }
                       if((event.motion.x >(274) && event.motion.x<(274+40))&&(event.motion.y<349 && event.motion.y>309))
                     {
                         CreateLettre(renderer,findC(t,3),xx,230,0,0) ;
                         xx = xx + 40 ;
                         if(dernierecombinaison == NULL) {ajouter_t(&dernierecombinaison,3);pcmbp = dernierecombinaison;}
                        else ajouter_p(&pcmbp,3);
                        compteur ++ ;

                     }
                       if((event.motion.x >(328) && event.motion.x<328+40)&&(event.motion.y<349 && event.motion.y>309))
                     {
                         CreateLettre(renderer,findC(t,-3),xx,230,0,0) ;
                         xx = xx + 40 ;
                         if(dernierecombinaison == NULL) {ajouter_t(&dernierecombinaison,-3);pcmbp = dernierecombinaison;}
                        else ajouter_p(&pcmbp,-3);
                        compteur ++ ;

                     }
                       if((event.motion.x >(382) && event.motion.x<382 + 40)&&(event.motion.y<349 && event.motion.y>309))
                     {
                         CreateLettre(renderer,findC(t,4),xx,230,0,0) ;
                         xx = xx + 40 ;
                         if(dernierecombinaison == NULL) {ajouter_t(&dernierecombinaison,4);pcmbp = dernierecombinaison;}
                        else ajouter_p(&pcmbp,4);
                        compteur ++ ;

                     }
                       if((event.motion.x >(436) && event.motion.x<436+40)&&(event.motion.y<349 && event.motion.y>309))
                     {
                         CreateLettre(renderer,findC(t,-4),xx,230,0,0) ;
                         xx = xx + 40 ;
                         if(dernierecombinaison == NULL) {ajouter_t(&dernierecombinaison,-4);pcmbp = dernierecombinaison;}
                        else ajouter_p(&pcmbp,-4);
                        compteur ++ ;

                     }
                        if((event.motion.x >(490) && event.motion.x<490+40)&&(event.motion.y<349 && event.motion.y>309))
                     {
                         CreateLettre(renderer,findC(t,5),xx,230,0,0) ;
                         xx = xx + 40 ;
                         if(dernierecombinaison == NULL) {ajouter_t(&dernierecombinaison,5);pcmbp = dernierecombinaison;}
                        else ajouter_p(&pcmbp,5);
                        compteur ++ ;

                     }
                        if((event.motion.x >(544) && event.motion.x<544+40)&&(event.motion.y<349 && event.motion.y>309))
                     {
                         CreateLettre(renderer,findC(t,-5),xx,230,0,0) ;
                         xx = xx + 40 ;
                         if(dernierecombinaison == NULL) {ajouter_t(&dernierecombinaison,-5);pcmbp = dernierecombinaison;}
                        else ajouter_p(&pcmbp,-5);
                        compteur ++ ;

                     }
                        if((event.motion.x >(598) && event.motion.x<598+40)&&(event.motion.y<349 && event.motion.y>309))
                     {
                         CreateLettre(renderer,findC(t,6),xx,230,0,0) ;
                         xx = xx + 40 ;
                         if(dernierecombinaison == NULL) {ajouter_t(&dernierecombinaison,6);pcmbp = dernierecombinaison;}
                        else ajouter_p(&pcmbp,6);
                        compteur ++ ;

                     }
                        if((event.motion.x >(652) && event.motion.x<652+40)&&(event.motion.y<349 && event.motion.y>309))
                     {
                         CreateLettre(renderer,findC(t,-6),xx,230,0,0) ;
                         xx = xx + 40 ;
                         if(dernierecombinaison == NULL) {ajouter_t(&dernierecombinaison,-6);pcmbp = dernierecombinaison;}
                        else ajouter_p(&pcmbp,-6);
                        compteur ++ ;

                     }

                     if((event.motion.x >(58) && event.motion.x<58+40)&&(event.motion.y<371+40 && event.motion.y>371))
                        {
                         CreateLettre(renderer,findC(t,7),xx,230,0,0) ;
                         xx = xx + 40 ;
                         if(dernierecombinaison == NULL) {ajouter_t(&dernierecombinaison,7);pcmbp = dernierecombinaison;}
                        else ajouter_p(&pcmbp,7);
                        compteur ++ ;

                            }
//////////////////////////
                    if((event.motion.x >(112) && event.motion.x<112+40)&&(event.motion.y<371+40 && event.motion.y>371))
                        {
                        CreateLettre(renderer,findC(t,-7),xx,230,0,0) ;
                         xx = xx + 40 ;
                         if(dernierecombinaison == NULL) {ajouter_t(&dernierecombinaison,-7);pcmbp = dernierecombinaison;}
                        else ajouter_p(&pcmbp,-7);
                        compteur ++ ;

                        }
/////////////////////////
                    if((event.motion.x >(166) && event.motion.x<166+40)&&(event.motion.y<371+40 && event.motion.y>371))
                    {
                         CreateLettre(renderer,findC(t,8),xx,230,0,0) ;
                         xx = xx + 40 ;
                         if(dernierecombinaison == NULL) {ajouter_t(&dernierecombinaison,8);pcmbp = dernierecombinaison;}
                        else ajouter_p(&pcmbp,8);
                        compteur ++ ;

                    }
/////////////////////////
                    if((event.motion.x >(220) && event.motion.x<220+40)&&(event.motion.y<371+40 && event.motion.y>371))
                    {
                         CreateLettre(renderer,findC(t,-8),xx,230,0,0) ;
                         xx = xx + 40 ;
                         if(dernierecombinaison == NULL) {ajouter_t(&dernierecombinaison,-8);pcmbp = dernierecombinaison;}
                        else ajouter_p(&pcmbp,-8);
                        compteur ++ ;

                    }
/////////////////////////
                    if((event.motion.x >(274) && event.motion.x<274+40)&&(event.motion.y<371+40 && event.motion.y>371))
                        {
                         CreateLettre(renderer,findC(t,9),xx,230,0,0) ;
                         xx = xx + 40 ;
                         if(dernierecombinaison == NULL) {ajouter_t(&dernierecombinaison,9);pcmbp = dernierecombinaison;}
                        else ajouter_p(&pcmbp,9);
                        compteur ++ ;

                        }
/////////////////////////
                    if((event.motion.x >(328) && event.motion.x<328+40)&&(event.motion.y<371+40 && event.motion.y>371))
                        {
                         CreateLettre(renderer,findC(t,-9),xx,230,0,0) ;
                         xx = xx + 40 ;
                         if(dernierecombinaison == NULL) {ajouter_t(&dernierecombinaison,-9);pcmbp = dernierecombinaison;}
                        else ajouter_p(&pcmbp,-9);
                        compteur ++ ;

                        }
/////////////////////////
                    if((event.motion.x >(382) && event.motion.x<382+40)&&(event.motion.y<371+40 && event.motion.y>371))
                        {
                         CreateLettre(renderer,findC(t,10),xx,230,0,0) ;
                         xx = xx + 40 ;
                         if(dernierecombinaison == NULL) {ajouter_t(&dernierecombinaison,10);pcmbp = dernierecombinaison;}
                        else ajouter_p(&pcmbp,10);
                        compteur ++ ;

                            }
/////////////////////////
                    if((event.motion.x >(436) && event.motion.x<436+40)&&(event.motion.y<371+40 && event.motion.y>371))
                                {
                                             CreateLettre(renderer,findC(t,-10),xx,230,0,0) ;
                                             xx = xx + 40 ;
                                             if(dernierecombinaison == NULL) {ajouter_t(&dernierecombinaison,-10);pcmbp = dernierecombinaison;}
                                            else ajouter_p(&pcmbp,-10);
                                            compteur ++ ;

                                }
                    /////////////////////////
                    if((event.motion.x >(490) && event.motion.x<490+40)&&(event.motion.y<371+40 && event.motion.y>371))
                                {
                                             CreateLettre(renderer,findC(t,11),xx,230,0,0) ;
                                             xx = xx + 40 ;
                                             if(dernierecombinaison == NULL) {ajouter_t(&dernierecombinaison,11);pcmbp = dernierecombinaison;}
                                            else ajouter_p(&pcmbp,11);
                                            compteur ++ ;

                                }
                    /////////////////////////
                    if((event.motion.x >(544) && event.motion.x<544+40)&&(event.motion.y<371+40 && event.motion.y>371))
                                {
                                             CreateLettre(renderer,findC(t,-11),xx,230,0,0) ;
                                             xx = xx + 40 ;
                                             if(dernierecombinaison == NULL) {ajouter_t(&dernierecombinaison,-11);pcmbp = dernierecombinaison;}
                                            else ajouter_p(&pcmbp,-11);
                                            compteur ++ ;

                                }
                    /////////////////////////
                    if((event.motion.x >(598) && event.motion.x<598+40)&&(event.motion.y<371+40 && event.motion.y>371))
                                {
                                             CreateLettre(renderer,findC(t,12),xx,230,0,0) ;
                                             xx = xx + 40 ;
                                             if(dernierecombinaison == NULL) {ajouter_t(&dernierecombinaison,12);pcmbp = dernierecombinaison;}
                                            else ajouter_p(&pcmbp,12);
                                            compteur ++ ;

                                }
                    /////////////////////////
                    if((event.motion.x >(652) && event.motion.x<652+40)&&(event.motion.y<371+40 && event.motion.y>371))
                                {
                                             CreateLettre(renderer,findC(t,-12),xx,230,0,0) ;
                                             xx = xx + 40 ;
                                             if(dernierecombinaison == NULL) {ajouter_t(&dernierecombinaison,-12);pcmbp = dernierecombinaison;}
                                            else ajouter_p(&pcmbp,-12);
                                            compteur ++ ;

                                }
/////////////////////////
                        if ((event.motion.x > (58) && event.motion.x < 58+40) && (event.motion.y < 433+40 && event.motion.y >433))
                          {
                            CreateLettre(renderer,findC(t,13),xx,230,0,0);
                            xx = xx + 40;
                            if (dernierecombinaison == NULL){
                                                             ajouter_t(&dernierecombinaison,13);
                                                             pcmbp = dernierecombinaison;
                                                            }
                            else ajouter_p(&pcmbp,13);
                            compteur ++ ;
                        }

                        if ((event.motion.x > (112) && event.motion.x < 112+40) && (event.motion.y < 433+40 && event.motion.y >433))
                          {
                            CreateLettre(renderer,findC(t,-13),xx,230,0,0);
                            xx = xx + 40;
                            if (dernierecombinaison == NULL){
                                                             ajouter_t(&dernierecombinaison,-13);
                                                             pcmbp = dernierecombinaison;
                                                            }
                            else ajouter_p(&pcmbp,-13);
                            compteur ++ ;
                        }

                        if ((event.motion.x > (166) && event.motion.x < 166+40) && (event.motion.y < 433+40 && event.motion.y >433))
                          {
                            CreateLettre(renderer,findC(t,14),xx,230,0,0);
                            xx = xx + 40;
                            if (dernierecombinaison == NULL){
                                                             ajouter_t(&dernierecombinaison,14);
                                                             pcmbp = dernierecombinaison;
                                                            }
                            else ajouter_p(&pcmbp,14);
                            compteur ++ ;
                        }

                        if ((event.motion.x > (220) && event.motion.x < 220+40) && (event.motion.y < 433+40 && event.motion.y >433))
                          {
                            CreateLettre(renderer,findC(t,-14),xx,230,0,0);
                            xx = xx + 40;
                            if (dernierecombinaison == NULL){
                                                             ajouter_t(&dernierecombinaison,-14);
                                                             pcmbp = dernierecombinaison;
                                                            }
                            else ajouter_p(&pcmbp,-14);
                            compteur ++ ;
                        }

                        if ((event.motion.x > (274) && event.motion.x < 274+40) && (event.motion.y < 433+40 && event.motion.y >433))
                          {
                            CreateLettre(renderer,findC(t,15),xx,230,0,0);
                            xx = xx + 40;
                            if (dernierecombinaison == NULL){
                                                             ajouter_t(&dernierecombinaison,15);
                                                             pcmbp = dernierecombinaison;
                                                            }
                            else ajouter_p(&pcmbp,15);
                            compteur ++ ;
                        }

                        if ((event.motion.x > (328) && event.motion.x < 328+40) && (event.motion.y < 433+40 && event.motion.y >433))
                          {
                            CreateLettre(renderer,findC(t,-15),xx,230,0,0);
                            xx = xx + 40;
                            if (dernierecombinaison == NULL){
                                                             ajouter_t(&dernierecombinaison,-15);
                                                             pcmbp = dernierecombinaison;
                                                            }
                            else ajouter_p(&pcmbp,-15);
                            compteur ++ ;
                        }

                        if ((event.motion.x > (382) && event.motion.x < 382+40) && (event.motion.y < 433+40 && event.motion.y >433))
                          {
                            CreateLettre(renderer,findC(t,16),xx,230,0,0);
                            xx = xx + 40;
                            if (dernierecombinaison == NULL){
                                                             ajouter_t(&dernierecombinaison,16);
                                                             pcmbp = dernierecombinaison;
                                                            }
                            else ajouter_p(&pcmbp,16);
                            compteur ++ ;
                        }

                        if ((event.motion.x > (436) && event.motion.x < 436+40) && (event.motion.y < 433+40 && event.motion.y >433))
                          {
                            CreateLettre(renderer,findC(t,-16),xx,230,0,0);
                            xx = xx + 40;
                            if (dernierecombinaison == NULL){
                                                             ajouter_t(&dernierecombinaison,-16);
                                                             pcmbp = dernierecombinaison;
                                                            }
                            else ajouter_p(&pcmbp,-16);
                            compteur ++ ;
                        }
                        if ((event.motion.x > (490) && event.motion.x < 490+40) && (event.motion.y < 433+40 && event.motion.y >433))
                          {
                            CreateLettre(renderer,findC(t,17),xx,230,0,0);
                            xx = xx + 40;
                            if (dernierecombinaison == NULL){
                                                             ajouter_t(&dernierecombinaison,17);
                                                             pcmbp = dernierecombinaison;
                                                            }
                            else ajouter_p(&pcmbp,17);
                            compteur ++ ;
                        }
                        if ((event.motion.x > (544) && event.motion.x < 544+40) && (event.motion.y < 433+40 && event.motion.y >433))
                          {
                            CreateLettre(renderer,findC(t,-17),xx,230,0,0);
                            xx = xx + 40;
                            if (dernierecombinaison == NULL){
                                                             ajouter_t(&dernierecombinaison,-17);
                                                             pcmbp = dernierecombinaison;
                                                            }
                            else ajouter_p(&pcmbp,-17);
                            compteur ++ ;
                        }
                        if ((event.motion.x > (598) && event.motion.x < 598+40) && (event.motion.y < 433+40 && event.motion.y >433))
                          {
                            CreateLettre(renderer,findC(t,18),xx,230,0,0);
                            xx = xx + 40;
                            if (dernierecombinaison == NULL){
                                                             ajouter_t(&dernierecombinaison,18);
                                                             pcmbp = dernierecombinaison;
                                                            }
                            else ajouter_p(&pcmbp,18);
                            compteur ++ ;
                        }
                         if ((event.motion.x > (652) && event.motion.x < 652+40) && (event.motion.y < 433+40 && event.motion.y >433))
                          {
                            CreateLettre(renderer,findC(t,-18),xx,230,0,0);
                            xx = xx + 40;
                            if (dernierecombinaison == NULL){
                                                             ajouter_t(&dernierecombinaison,-18);
                                                             pcmbp = dernierecombinaison;
                                                            }
                            else ajouter_p(&pcmbp,-18);
                            compteur ++ ;
                        }

    /////////////////////////////////////////////////
                    if ((event.motion.x > (58) && event.motion.x < 58+40) && (event.motion.y < 496+40 && event.motion.y >496))
                          {
                            CreateLettre(renderer,findC(t,19),xx,230,0,0);
                            xx = xx + 40;
                            if (dernierecombinaison == NULL){
                                                             ajouter_t(&dernierecombinaison,19);
                                                             pcmbp = dernierecombinaison;
                                                            }
                            else ajouter_p(&pcmbp,19);
                            compteur ++ ;
                        }
                        if ((event.motion.x > (112) && event.motion.x < 112+40) && (event.motion.y < 496+40 && event.motion.y >496))
                          {
                            CreateLettre(renderer,findC(t,-19),xx,230,0,0);
                            xx = xx + 40;
                            if (dernierecombinaison == NULL){
                                                             ajouter_t(&dernierecombinaison,-19);
                                                             pcmbp = dernierecombinaison;
                                                            }
                            else ajouter_p(&pcmbp,-19);
                            compteur ++ ;
                        }
                            if ((event.motion.x > (166) && event.motion.x < 166+40) && (event.motion.y < 496+40 && event.motion.y >496))
                          {
                            CreateLettre(renderer,findC(t,20),xx,230,0,0);
                            xx = xx + 40;
                            if (dernierecombinaison == NULL){
                                                             ajouter_t(&dernierecombinaison,20);
                                                             pcmbp = dernierecombinaison;
                                                            }
                            else ajouter_p(&pcmbp,20);
                            compteur ++ ;
                        }
                            if ((event.motion.x > (220) && event.motion.x < 220+40) && (event.motion.y < 496+40 && event.motion.y >496))
                          {
                            CreateLettre(renderer,findC(t,-20),xx,230,0,0);
                            xx = xx + 40;
                            if (dernierecombinaison == NULL){
                                                             ajouter_t(&dernierecombinaison,-20);
                                                             pcmbp = dernierecombinaison;
                                                            }
                            else ajouter_p(&pcmbp,-20);
                            compteur ++ ;
                        }
                            if ((event.motion.x > (274) && event.motion.x < 274+40) && (event.motion.y < 496+40 && event.motion.y >496))
                          {
                            CreateLettre(renderer,findC(t,21),xx,230,0,0);
                            xx = xx + 40;
                            if (dernierecombinaison == NULL){
                                                             ajouter_t(&dernierecombinaison,21);
                                                             pcmbp = dernierecombinaison;
                                                            }
                            else ajouter_p(&pcmbp,21);
                            compteur ++ ;
                        }
                            if ((event.motion.x > (328) && event.motion.x < 328+40) && (event.motion.y < 496+40 && event.motion.y >496))
                          {
                            CreateLettre(renderer,findC(t,-21),xx,230,0,0);
                            xx = xx + 40;
                            if (dernierecombinaison == NULL){
                                                             ajouter_t(&dernierecombinaison,-21);
                                                             pcmbp = dernierecombinaison;
                                                            }
                            else ajouter_p(&pcmbp,-21);
                            compteur ++ ;
                        }
                            if ((event.motion.x > (382) && event.motion.x < 382+40) && (event.motion.y < 496+40 && event.motion.y >496))
                          {
                            CreateLettre(renderer,findC(t,22),xx,230,0,0);
                            xx = xx + 40;
                            if (dernierecombinaison == NULL){
                                                             ajouter_t(&dernierecombinaison,22);
                                                             pcmbp = dernierecombinaison;
                                                            }
                            else ajouter_p(&pcmbp,22);
                            compteur ++ ;
                        }
                            if ((event.motion.x > (436) && event.motion.x < 436+40) && (event.motion.y < 496+40 && event.motion.y >496))
                          {
                            CreateLettre(renderer,findC(t,-22),xx,230,0,0);
                            xx = xx + 40;
                            if (dernierecombinaison == NULL){
                                                             ajouter_t(&dernierecombinaison,-22);
                                                             pcmbp = dernierecombinaison;
                                                            }
                            else ajouter_p(&pcmbp,-22);
                            compteur ++ ;
                        }
                            if ((event.motion.x > (490) && event.motion.x < 490+40) && (event.motion.y < 496+40 && event.motion.y >496))
                          {
                            CreateLettre(renderer,findC(t,23),xx,230,0,0);
                            xx = xx + 40;
                            if (dernierecombinaison == NULL){
                                                             ajouter_t(&dernierecombinaison,23);
                                                             pcmbp = dernierecombinaison;
                                                            }
                            else ajouter_p(&pcmbp,23);
                            compteur ++ ;
                        }
                            if ((event.motion.x > (544) && event.motion.x < 544+40) && (event.motion.y < 496+40 && event.motion.y >496))
                          {
                            CreateLettre(renderer,findC(t,-23),xx,230,0,0);
                            xx = xx + 40;
                            if (dernierecombinaison == NULL){
                                                             ajouter_t(&dernierecombinaison,-23);
                                                             pcmbp = dernierecombinaison;
                                                            }
                            else ajouter_p(&pcmbp,-23);
                            compteur ++ ;
                        }
                            if ((event.motion.x > (598) && event.motion.x < 598+40) && (event.motion.y < 496+40 && event.motion.y >496))
                          {
                            CreateLettre(renderer,findC(t,24),xx,230,0,0);
                            xx = xx + 40;
                            if (dernierecombinaison == NULL){
                                                             ajouter_t(&dernierecombinaison,24);
                                                             pcmbp = dernierecombinaison;
                                                            }
                            else ajouter_p(&pcmbp,24);
                            compteur ++ ;
                        }
                            if ((event.motion.x > (652) && event.motion.x < (652)+40) && (event.motion.y < 496+40 && event.motion.y >496))
                          {
                            CreateLettre(renderer,findC(t,-24),xx,230,0,0);
                            xx = xx + 40;
                            if (dernierecombinaison == NULL){
                                                             ajouter_t(&dernierecombinaison,-24);
                                                             pcmbp = dernierecombinaison;
                                                            }
                            else ajouter_p(&pcmbp,-24);
                            compteur ++ ;
                        }
                    if ((event.motion.x > (275) && event.motion.x < (275)+40) && (event.motion.y < 558+40 && event.motion.y >558))
                          {
                            CreateLettre(renderer,findC(t,25),xx,230,0,0);
                            xx = xx + 40;
                            if (dernierecombinaison == NULL){
                                                             ajouter_t(&dernierecombinaison,25);
                                                             pcmbp = dernierecombinaison;
                                                            }
                            else ajouter_p(&pcmbp,25);
                            compteur ++ ;
                        }
                         if ((event.motion.x > (329) && event.motion.x < (329)+40) && (event.motion.y < 558+40 && event.motion.y >558))
                          {
                            CreateLettre(renderer,findC(t,-25),xx,230,0,0);
                            xx = xx + 40;
                            if (dernierecombinaison == NULL){
                                                             ajouter_t(&dernierecombinaison,-25);
                                                             pcmbp = dernierecombinaison;
                                                            }
                            else ajouter_p(&pcmbp,-25);
                            compteur ++ ;
                        }
                        if ((event.motion.x > (383) && event.motion.x < (383)+40) && (event.motion.y < 558+40 && event.motion.y >558))
                          {
                            CreateLettre(renderer,findC(t,26),xx,230,0,0);
                            xx = xx + 40;
                            if (dernierecombinaison == NULL){
                                                             ajouter_t(&dernierecombinaison,26);
                                                             pcmbp = dernierecombinaison;
                                                            }
                            else ajouter_p(&pcmbp,26);
                            compteur ++ ;}
                         if ((event.motion.x > (437) && event.motion.x < (437)+40) && (event.motion.y < 558+40 && event.motion.y >558))
                          {
                            CreateLettre(renderer,findC(t,-26),xx,230,0,0);
                            xx = xx + 40;
                            if (dernierecombinaison == NULL){
                                                             ajouter_t(&dernierecombinaison,-26);
                                                             pcmbp = dernierecombinaison;
                                                            }
                            else ajouter_p(&pcmbp,-26);
                            compteur ++ ;
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




    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void CombI(SDL_Window *window , SDL_Renderer *renderer , int N,int pn )
{   ///DECLARATION
    SDL_RenderClear(renderer) ;
    SDL_Surface *img = NULL , *A = NULL,*ENTER,*DONNER,*rectangle;
    SDL_Texture *text = NULL;
    img = IMG_Load("background3.jpg") ;
    rectangle = IMG_Load("rect.png") ;
    SDL_CreateImageAndTexture(img,text,renderer,window , 0 , 0);
    liste t = NULL ,ts = NULL;
    int screen = 50 , compteur = 0 , XClavier = 58 , xx = 206;
    A = IMG_Load("A.jpg") ;
    ajouter_tete(&t,A,1) ;
    rempli(t) ;
    TTF_Font * font = TTF_OpenFont("Gameplay.ttf", 60);
    TTF_Font * font2 = TTF_OpenFont("Gameplay.ttf", 48);
    SDL_Color colorTitle = { 255, 255, 255 };
    DONNER = TTF_RenderText_Solid(font2,"DONNER LA COMB INITIAL" , colorTitle);
    ENTER = TTF_RenderText_Solid(font,"OK",colorTitle) ;

    /// CREATION DE CLAVIER
    CreateLettre(renderer,ENTER,330,592,0,0) ;
    CreateLettre(renderer,DONNER,45,35,0,0) ;
    CreateLettre(renderer,rectangle,139,244 ,0,0) ;
    /// CREATION DE CLAVIER
    ts = t ;
    for(int i=1;i<=12;i++)
    {
        CreateLettre(renderer,ts->img,XClavier,395,0,0) ;
        ts = (ts->svt) ;
        ts = (ts->svt) ;
        XClavier = XClavier + 54 ;
    }
    XClavier = 58 ;
     for(int i=1;i<=12;i++)
    {
        CreateLettre(renderer,ts->img,XClavier,463,0,0) ;
        ts = (ts->svt) ;
        ts = (ts->svt) ;
        XClavier = XClavier + 54 ;
    }
    XClavier = 328 ;
      for(int i=1;i<=2;i++)
    {
        CreateLettre(renderer,ts->img,XClavier,525,0,0) ;
        ts = (ts->svt) ;
        ts = (ts->svt) ;
        XClavier = XClavier + 54 ;
    }


    SDL_bool program_launched = SDL_TRUE;
    listeSy premierecombinaison = NULL;
    listeSy pcmbp = premierecombinaison;

        while(program_launched){
            SDL_Event event;

            while(SDL_PollEvent(&event)){
                switch(event.type){
                     case SDL_MOUSEBUTTONDOWN :
                     if((event.motion.x <418 && event.motion.x>330)&&(event.motion.y<650 && event.motion.y>592) && (compteur == N))
                     {  screen = 1 ;
                        while(screen == 1)
                        {
                           CombFINALE(window,renderer,N,pn,premierecombinaison) ;
                        }

                     }

                     if((event.motion.x <(58+40) && event.motion.x>58)&&(event.motion.y<435 && event.motion.y>395))
                     {
                         CreateLettre(renderer,findC(t,1),xx,261,0,0) ;
                         xx = xx + 40 ;
                         if(premierecombinaison == NULL) {ajouter_t(&premierecombinaison,1);pcmbp = premierecombinaison;}
                        else ajouter_p(&pcmbp,1);
                        compteur ++ ;

                     }
                       if((event.motion.x >(112) && event.motion.x<(112+40))&&(event.motion.y<435 && event.motion.y>395))
                     {
                         CreateLettre(renderer,findC(t,2),xx,261,0,0) ;
                         xx = xx + 40 ;
                         if(premierecombinaison == NULL) {ajouter_t(&premierecombinaison,2);pcmbp = premierecombinaison;}
                        else ajouter_p(&pcmbp,2);
                        compteur ++ ;

                     }
                      if((event.motion.x >(166) && event.motion.x<(166+40))&&(event.motion.y<435 && event.motion.y>395))
                     {
                         CreateLettre(renderer,findC(t,3),xx,261,0,0) ;
                         xx = xx + 40 ;
                         if(premierecombinaison == NULL) {ajouter_t(&premierecombinaison,3);pcmbp = premierecombinaison;}
                        else ajouter_p(&pcmbp,3);
                        compteur ++ ;

                     }
                       if((event.motion.x >(220) && event.motion.x<(220+40))&&(event.motion.y<435 && event.motion.y>395))
                     {
                         CreateLettre(renderer,findC(t,4),xx,261,0,0) ;
                         xx = xx + 40 ;
                         if(premierecombinaison == NULL) {ajouter_t(&premierecombinaison,4);pcmbp = premierecombinaison;}
                        else ajouter_p(&pcmbp,4);
                        compteur ++ ;

                     }
                       if((event.motion.x >(274) && event.motion.x<(274+40))&&(event.motion.y<435 && event.motion.y>395))
                     {
                         CreateLettre(renderer,findC(t,5),xx,261,0,0) ;
                         xx = xx + 40 ;
                         if(premierecombinaison == NULL) {ajouter_t(&premierecombinaison,5);pcmbp = premierecombinaison;}
                        else ajouter_p(&pcmbp,5);
                        compteur ++ ;

                     }
                       if((event.motion.x >(328) && event.motion.x<328+40)&&(event.motion.y<435 && event.motion.y>395))
                     {
                         CreateLettre(renderer,findC(t,6),xx,261,0,0) ;
                         xx = xx + 40 ;
                         if(premierecombinaison == NULL) {ajouter_t(&premierecombinaison,6);pcmbp = premierecombinaison;}
                        else ajouter_p(&pcmbp,6);
                        compteur ++ ;

                     }
                       if((event.motion.x >(382) && event.motion.x<382 + 40)&&(event.motion.y<435 && event.motion.y>395))
                     {
                         CreateLettre(renderer,findC(t,7),xx,261,0,0) ;
                         xx = xx + 40 ;
                         if(premierecombinaison == NULL) {ajouter_t(&premierecombinaison,7);pcmbp = premierecombinaison;}
                        else ajouter_p(&pcmbp,7);
                        compteur ++ ;

                     }
                       if((event.motion.x >(436) && event.motion.x<436+40)&&(event.motion.y<435 && event.motion.y>395))
                     {
                         CreateLettre(renderer,findC(t,8),xx,261,0,0) ;
                         xx = xx + 40 ;
                         if(premierecombinaison == NULL) {ajouter_t(&premierecombinaison,8);pcmbp = premierecombinaison;}
                        else ajouter_p(&pcmbp,8);
                        compteur ++ ;

                     }
                        if((event.motion.x >(490) && event.motion.x<490+40)&&(event.motion.y<435 && event.motion.y>395))
                     {
                         CreateLettre(renderer,findC(t,9),xx,261,0,0) ;
                         xx = xx + 40 ;
                         if(premierecombinaison == NULL) {ajouter_t(&premierecombinaison,8);pcmbp = premierecombinaison;}
                        else ajouter_p(&pcmbp,9);
                        compteur ++ ;

                     }
                        if((event.motion.x >(544) && event.motion.x<544+40)&&(event.motion.y<435 && event.motion.y>395))
                     {
                         CreateLettre(renderer,findC(t,10),xx,261,0,0) ;
                         xx = xx + 40 ;
                         if(premierecombinaison == NULL) {ajouter_t(&premierecombinaison,10);pcmbp = premierecombinaison;}
                        else ajouter_p(&pcmbp,10);
                        compteur ++ ;

                     }
                        if((event.motion.x >(598) && event.motion.x<598+40)&&(event.motion.y<435 && event.motion.y>395))
                     {
                         CreateLettre(renderer,findC(t,11),xx,261,0,0) ;
                         xx = xx + 40 ;
                         if(premierecombinaison == NULL) {ajouter_t(&premierecombinaison,11);pcmbp = premierecombinaison;}
                        else ajouter_p(&pcmbp,11);
                        compteur ++ ;

                     }
                        if((event.motion.x >(652) && event.motion.x<652+40)&&(event.motion.y<435 && event.motion.y>395))
                     {
                         CreateLettre(renderer,findC(t,12),xx,261,0,0) ;
                         xx = xx + 40 ;
                         if(premierecombinaison == NULL) {ajouter_t(&premierecombinaison,12);pcmbp = premierecombinaison;}
                        else ajouter_p(&pcmbp,12);
                        compteur ++ ;

                     }



                     if((event.motion.x >(58) && event.motion.x<58+40)&&(event.motion.y<503 && event.motion.y>463))
                     {
                         CreateLettre(renderer,findC(t,13),xx,261,0,0) ;
                         xx = xx + 40 ;
                         if(premierecombinaison == NULL) {ajouter_t(&premierecombinaison,13);pcmbp = premierecombinaison;}
                        else ajouter_p(&pcmbp,13);
                        compteur ++ ;

                     }

                    if((event.motion.x >(112) && event.motion.x<112+40)&&(event.motion.y<503 && event.motion.y>463))
                     {
                         CreateLettre(renderer,findC(t,14),xx,261,0,0) ;
                         xx = xx + 40 ;
                         if(premierecombinaison == NULL) {ajouter_t(&premierecombinaison,14);pcmbp = premierecombinaison;}
                        else ajouter_p(&pcmbp,14);
                        compteur ++ ;

                     }

                    if((event.motion.x >(166) && event.motion.x<166+40)&&(event.motion.y<503 && event.motion.y>463))
                     {
                         CreateLettre(renderer,findC(t,15),xx,261,0,0) ;
                         xx = xx + 40 ;
                         if(premierecombinaison == NULL) {ajouter_t(&premierecombinaison,15);pcmbp = premierecombinaison;}
                        else ajouter_p(&pcmbp,15);
                        compteur ++ ;

                     }
                    if((event.motion.x >(220) && event.motion.x<220+40)&&(event.motion.y<503 && event.motion.y>463))
                     {
                         CreateLettre(renderer,findC(t,16),xx,261,0,0) ;
                         xx = xx + 40 ;
                         if(premierecombinaison == NULL) {ajouter_t(&premierecombinaison,16);pcmbp = premierecombinaison;}
                        else ajouter_p(&pcmbp,16);
                        compteur ++ ;

                     }
                    if((event.motion.x >(274) && event.motion.x<274+40)&&(event.motion.y<503 && event.motion.y>463))
                     {
                         CreateLettre(renderer,findC(t,17),xx,261,0,0) ;
                         xx = xx + 40 ;
                         if(premierecombinaison == NULL) {ajouter_t(&premierecombinaison,17);pcmbp = premierecombinaison;}
                        else ajouter_p(&pcmbp,17);
                        compteur ++ ;

                     }
                    if((event.motion.x >(328) && event.motion.x<328+40)&&(event.motion.y<503 && event.motion.y>463))
                     {
                         CreateLettre(renderer,findC(t,18),xx,261,0,0) ;
                         xx = xx + 40 ;
                         if(premierecombinaison == NULL) {ajouter_t(&premierecombinaison,18);pcmbp = premierecombinaison;}
                        else ajouter_p(&pcmbp,18);
                        compteur ++ ;

                     }
                    if((event.motion.x >(382) && event.motion.x<382+40)&&(event.motion.y<503 && event.motion.y>463))
                     {
                         CreateLettre(renderer,findC(t,19),xx,261,0,0) ;
                         xx = xx + 40 ;
                         if(premierecombinaison == NULL) {ajouter_t(&premierecombinaison,19);pcmbp = premierecombinaison;}
                        else ajouter_p(&pcmbp,19);
                        compteur ++ ;

                     }
                    if((event.motion.x >(436) && event.motion.x<436+40)&&(event.motion.y<503 && event.motion.y>463))
                     {
                         CreateLettre(renderer,findC(t,20),xx,261,0,0) ;
                         xx = xx + 40 ;
                         if(premierecombinaison == NULL) {ajouter_t(&premierecombinaison,20);pcmbp = premierecombinaison;}
                        else ajouter_p(&pcmbp,20);
                        compteur ++ ;

                     }
                    if((event.motion.x >(490) && event.motion.x<490+40)&&(event.motion.y<503 && event.motion.y>463))
                     {
                         CreateLettre(renderer,findC(t,21),xx,261,0,0) ;
                         xx = xx + 40 ;
                         if(premierecombinaison == NULL) {ajouter_t(&premierecombinaison,21);pcmbp = premierecombinaison;}
                        else ajouter_p(&pcmbp,21);
                        compteur ++ ;

                     }
                    if((event.motion.x >(544) && event.motion.x<544+40)&&(event.motion.y<503 && event.motion.y>463))
                     {
                         CreateLettre(renderer,findC(t,22),xx,261,0,0) ;
                         xx = xx + 40 ;
                         if(premierecombinaison == NULL) {ajouter_t(&premierecombinaison,22);pcmbp = premierecombinaison;}
                        else ajouter_p(&pcmbp,22);
                        compteur ++ ;

                     }
                    if((event.motion.x >(598) && event.motion.x<598+40)&&(event.motion.y<503 && event.motion.y>463))
                     {
                         CreateLettre(renderer,findC(t,23),xx,261,0,0) ;
                         xx = xx + 40 ;
                         if(premierecombinaison == NULL) {ajouter_t(&premierecombinaison,23);pcmbp = premierecombinaison;}
                        else ajouter_p(&pcmbp,23);
                        compteur ++ ;

                     }
                    if((event.motion.x >(652) && event.motion.x<652+40)&&(event.motion.y<503 && event.motion.y>463))
                     {
                         CreateLettre(renderer,findC(t,24),xx,261,0,0) ;
                         xx = xx + 40 ;
                         if(premierecombinaison == NULL) {ajouter_t(&premierecombinaison,24);pcmbp = premierecombinaison;}
                        else ajouter_p(&pcmbp,24);
                        compteur ++ ;

                     }
                       if((event.motion.x >(328) && event.motion.x<328+40)&&(event.motion.y<525+40 && event.motion.y>525))
                     {
                         CreateLettre(renderer,findC(t,25),xx,261,0,0) ;
                         xx = xx + 40 ;
                         if(premierecombinaison == NULL) {ajouter_t(&premierecombinaison,25);pcmbp = premierecombinaison;}
                        else ajouter_p(&pcmbp,25);
                        compteur ++ ;

                     }
                        if((event.motion.x >(381) && event.motion.x<381+40)&&(event.motion.y<525+40 && event.motion.y>525))
                     {
                         CreateLettre(renderer,findC(t,26),xx,261,0,0) ;
                         xx = xx + 40 ;
                         if(premierecombinaison == NULL) {ajouter_t(&premierecombinaison,26);pcmbp = premierecombinaison;}
                        else ajouter_p(&pcmbp,26);
                        compteur ++ ;

                     }
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

void nbrP(SDL_Window *window , SDL_Renderer *renderer , int N)
{   int pn = N / 2 ,screen = 21;
    char int_str[20] ;
    SDL_Surface *img = NULL ,*LN = NULL ,*D,*OK ;
    SDL_Texture *text = NULL;
    img = IMG_Load("background3.jpg") ;
    SDL_CreateImageAndTexture(img,text,renderer,window , 0 , 0);
    TTF_Font * font = TTF_OpenFont("Gameplay.ttf", 60);
    TTF_Font * font2 = TTF_OpenFont("Gameplay.ttf", 30);
    SDL_Color colorTitle = { 255, 255, 255 };
    SDL_Color colorTitle2 = { 250, 179, 39 };
    OK = TTF_RenderText_Solid(font,"OK" , colorTitle);
    D = TTF_RenderText_Solid(font2,"donner nbre de lettre a permuter" , colorTitle);
    CreateLettre(renderer,D,46,205,0,0) ;
    CreateLettre(renderer,OK,330,592,0,0) ;

      SDL_bool program_launched = SDL_TRUE;

        while(program_launched){
            SDL_Event event;

            while(SDL_PollEvent(&event)){
                switch(event.type){
                         case SDL_MOUSEBUTTONDOWN :
                     if((event.motion.x <418 && event.motion.x>330)&&(event.motion.y<650 && event.motion.y>592))
                     {  screen = 1 ;
                        while(screen == 1)
                        {
                            CombI(window,renderer,N,pn);
                        }

                     }


                    break ;
                    case SDL_KEYDOWN :
                   switch(event.key.keysym.sym)
                   {
                    case SDLK_2 :
                    pn = 2 ;
                    sprintf(int_str, "%d", pn);
                    LN = TTF_RenderText_Solid(font,int_str , colorTitle);
                    CreateLettre(renderer ,LN, 354 , 345 , 0 , 0) ;
                    break ;
                    case SDLK_5 :
                    pn = 5 ;
                    sprintf(int_str, "%d", pn);
                    LN = TTF_RenderText_Solid(font,int_str , colorTitle);
                    CreateLettre(renderer ,LN, 354 , 345 , 0 , 0) ;
                    break ;

                   case SDLK_6 :
                    pn = 6 ;
                    sprintf(int_str, "%d", pn);
                    LN = TTF_RenderText_Solid(font,int_str , colorTitle);
                    CreateLettre(renderer ,LN, 354 , 345 , 0 , 0) ;
                    break ;
                    case SDLK_7 :
                    pn= 7 ;
                    sprintf(int_str, "%d", pn);
                    LN = TTF_RenderText_Solid(font,int_str , colorTitle);
                    CreateLettre(renderer ,LN, 354 , 345 , 0 , 0) ;
                    break ;
                    case SDLK_3 :
                    pn = 3 ;
                    sprintf(int_str, "%d", pn);
                    LN = TTF_RenderText_Solid(font,int_str , colorTitle);
                    CreateLettre(renderer ,LN, 354 , 345 , 0 , 0) ;
                    break ;
                     case SDLK_4 :
                    pn = 4 ;
                    sprintf(int_str, "%d", pn);
                    LN = TTF_RenderText_Solid(font,int_str , colorTitle);
                    CreateLettre(renderer ,LN, 354 , 345 , 0 , 0) ;
                    break ;
                   }


                  break ;
                case SDL_MOUSEMOTION:
                        if((event.motion.x <418 && event.motion.x>330)&&(event.motion.y<650 && event.motion.y>592))
                     {
                            OK = TTF_RenderText_Solid(font,"OK" , colorTitle2);
                            CreateLettre(renderer,OK,330,592,0,0) ;


                     }else {OK = TTF_RenderText_Solid(font,"OK" , colorTitle);CreateLettre(renderer,OK,330,592,0,0) ;}
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

void nbrN(SDL_Window *window , SDL_Renderer *renderer )
{   char int_str[20];
    int screen = 21 ;
    SDL_Surface *img = NULL , *A = NULL,*LN = NULL ,*D,*OK ;
    SDL_Texture *text = NULL;
    img = IMG_Load("background3.jpg") ;
    SDL_CreateImageAndTexture(img,text,renderer,window , 0 , 0);
    liste t = NULL ;
    int N = 4;
    TTF_Font * font = TTF_OpenFont("Gameplay.ttf", 60);
    TTF_Font * font2 = TTF_OpenFont("Gameplay.ttf", 36);
    SDL_Color colorTitle = { 255, 255, 255 };
    SDL_Color colorTitle2 = { 250, 179, 39 };
   //  LN = TTF_RenderText_Solid(font,"6" , colorTitle);
     OK = TTF_RenderText_Solid(font,"OK" , colorTitle);
     D = TTF_RenderText_Solid(font2,"DONNER LE NOMBRES DE LETTRES" , colorTitle);
     CreateLettre(renderer,D,27,213,0,0) ;
     CreateLettre(renderer,OK,330,592,0,0) ;
  //  CreateLettre(renderer,ENTER,315,324,0,0) ;
    A = IMG_Load("A.jpg") ;
    ajouter_tete(&t,A,1) ;
    rempli(t) ;
     SDL_bool program_launched = SDL_TRUE;

        while(program_launched){
            SDL_Event event;

            while(SDL_PollEvent(&event)){
                switch(event.type){

                case SDL_MOUSEBUTTONDOWN :
                     if((event.motion.x <418 && event.motion.x>330)&&(event.motion.y<650 && event.motion.y>592))
                     {  screen = 23 ;
                        while(screen == 23)
                        {
                            nbrP(window,renderer,N) ;
                        }

                     }


                    break ;
                    case SDL_KEYDOWN :
                   switch(event.key.keysym.sym)
                   {
                    case SDLK_4 :
                    N = 4 ;
                    sprintf(int_str, "%d", N);
                    LN = TTF_RenderText_Solid(font,int_str , colorTitle);
                    CreateLettre(renderer ,LN, 354 , 345 , 0 , 0) ;
                    break ;
                    case SDLK_5 :
                    N = 5 ;
                    sprintf(int_str, "%d", N);
                    LN = TTF_RenderText_Solid(font,int_str , colorTitle);
                    CreateLettre(renderer ,LN, 354 , 345 , 0 , 0) ;
                    break ;

                   case SDLK_6 :
                    N = 6 ;
                    sprintf(int_str, "%d", N);
                    LN = TTF_RenderText_Solid(font,int_str , colorTitle);
                    CreateLettre(renderer ,LN, 354 , 345 , 0 , 0) ;
                    break ;
                    case SDLK_7 :
                    N = 7 ;
                    sprintf(int_str, "%d", N);
                    LN = TTF_RenderText_Solid(font,int_str , colorTitle);
                    CreateLettre(renderer ,LN, 354 , 345 , 0 , 0) ;
                    break ;
                    case SDLK_8 :
                    N = 8 ;
                    sprintf(int_str, "%d", N);
                    LN = TTF_RenderText_Solid(font,int_str , colorTitle);
                    CreateLettre(renderer ,LN, 354 , 345 , 0 , 0) ;
                    break ;
                   }


                  break ;
                    case SDL_MOUSEMOTION:
                        if((event.motion.x <418 && event.motion.x>330)&&(event.motion.y<650 && event.motion.y>592))
                     {
                            OK = TTF_RenderText_Solid(font,"OK" , colorTitle2);
                            CreateLettre(renderer,OK,330,592,0,0) ;


                     }else {OK = TTF_RenderText_Solid(font,"OK" , colorTitle);CreateLettre(renderer,OK,330,592,0,0) ;}
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


