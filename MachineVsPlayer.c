#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include<SDL_image.h>
#include "bilb.h"
#include "PLAYER.h"
#include <stdbool.h>
#include "MACHINE.h"

void MvsP(SDL_Window *window , SDL_Renderer *renderer)
{
    SDL_Surface *img = NULL ,*A ,*Half;
    SDL_Texture *text = NULL;
    img = IMG_Load("background3.jpg") ;
    Half = IMG_Load("half.jpg") ;
    SDL_CreateImageAndTexture(img,text,renderer,window , 0 , 0);
    CreateLettre(renderer,Half,371,21,0,0) ;
    int N,x,i;
    int tab[26] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
    listeSy t,prd;
    liste alphab = NULL ;
    A = IMG_Load("A.jpg") ;
    ajouter_tete(&alphab,A,1) ;
    rempli(alphab) ;
    listeP tout;
    t = NULL;
    tout = NULL;
    time_t t1;
    srand ( (unsigned) time (&t1));

    N = (rand()%5)+4;

    do {
            srand(time(NULL));

            x = rand()%N;


    }

     while (((nbr_paire(N) == 1) && x<N/2) || ((nbr_paire(N)== 0) && x<=N/2));

     int o;
     o = rand()%26;
     ajouter_t(&t,tab[o]);

     i=0;
     int l;
     prd = t;
     for (i=1;i<N;i++){
        do {
        l = rand()%26;
        }
        while (prd->val == l);
        ajouter_p(&prd,tab[l]);

     }
     affiche(t,alphab,renderer,20,42) ;

    long int total;
     listeSy comb = NULL;
     total = combinaisonTransformEnNombre(t,N);
     ajouter_tetenor(&tout,t,total,0,0);
     listeP combin,verif,prec;
     listeSy crea = NULL;
     int vf;
     combin = tout;
     prec = tout;
     int c;
     int compter = 0;
     listef cmbfnl = NULL;
     ajouter_tetefin(&cmbfnl,t,total);
     listef prcdf = cmbfnl;
     int rmp = 0;
     int ind = 1;
     int prdind = 0;

     while (combin != NULL){
     c = 1;
     while (c<=(N-x+1)){
        verif = tout;
        crea = NULL;
        crea = nouvListe((combin->info));
        total = 0;
        vf = 0;
        comb = NULL;
        comb = play(crea,c,x,N);
        total = combinaisonTransformEnNombre(comb,N);

        while (verif != NULL && vf == 0){
            if ((verif->somme) == total){ vf = vf+1;}
            verif = (verif->suiv);
        }
        if (vf == 0){
            compter = verifiCombinaisonFinale (comb);
            if (compter == 0){
            ajouter_apresfin(&prcdf,comb,total);

            rmp = rmp + 1;
            }
                ajouter_apresnor(&prec,comb,total,ind,prdind);
                ind = ind + 1;
            }
        c = c + 1;

        }
     combin = combin->suiv ;
     prdind = prdind + 1;
     }
      printf("\n");
    printf("\n");
    verif = NULL;
    prec = NULL;
    free(verif);
    free(combin);
    free(prec);


    int m;
    listef combinaisonfinale = cmbfnl;

    if (N == 7 && x == 5){
        srand(time(NULL));
        m = rand() % (rmp-4) ;
    }
    else if (N == 8 && x == 6){
        srand(time(NULL));
        m = rand() % (rmp/15) ;
    }
    else if (N == 8 && x == 5){
        srand(time(NULL));
        m = rand() % (rmp-50) ;
    }
    else {
    srand(time(NULL));
    m = rand() % rmp ;  // normalement m=rand() % rmp f gae les cas bssh ndiro hka bach ma ymedelnach combinaison b3ida bzef
    }

    int ar = 0;
     while (ar <= m){
        combinaisonfinale = combinaisonfinale -> svt;
        ar = ar +1;
     }
     int xc ;
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

     affiche(combinaisonfinale->val,alphab,renderer,xc,699) ;

    int save;
    listeP trouv = tout;
    while (trouv->somme != combinaisonfinale->somme){
        trouv = trouv ->suiv;
    }
    listef casmachine = NULL;
    while ((trouv->prdindice) >= 0 && trouv != tout){
         ajouter_tetefin(&casmachine,trouv->info,0);
         save = trouv->prdindice;
         while ((trouv -> indice) != save ){
            trouv = trouv ->pred;
         }
    }
    printf("%d",N) ;

    affiche(t,alphab,renderer,391,42) ;
   affiche_listefinPvsM(casmachine,alphab,renderer,391,100) ;
    int y = 100 ;



   // long int vrf;
    listeSy cvb;
    int min = 42 , max = 82 ;
    Uint32 start_time;
    int ymax = 92 ;
    SDL_bool program_launched = SDL_TRUE;
     while(program_launched){
            SDL_Event event;



            while(SDL_PollEvent(&event) ){
                switch(event.type){

                case SDL_MOUSEBUTTONDOWN :
                if((event.motion.x <60 && event.motion.x>20)&&(event.motion.y<max && event.motion.y>min))
                {
                    cvb = NULL;
                    cvb = play(t,1,x,N);
                    affiche(cvb , alphab,renderer,20,ymax) ;
                    ymax = ymax + 50 ;
                    max = max + 50 ;
                    min = min + 50 ;
                }
                  if((event.motion.x <100 && event.motion.x>60)&&(event.motion.y<max && event.motion.y>min))
                {
                    cvb = NULL;
                    cvb = play(t,2,x,N);
                    affiche(cvb , alphab,renderer,20,ymax) ;
                    ymax = ymax + 50 ;
                    max = max + 50 ;
                    min = min + 50 ;
                }
                  if((event.motion.x <140 && event.motion.x>100)&&(event.motion.y<max && event.motion.y>min))
                {
                    cvb = NULL;
                    cvb = play(t,3,x,N);
                    affiche(cvb , alphab,renderer,20,ymax) ;
                    ymax = ymax + 50 ;
                    max = max + 50 ;
                    min = min + 50 ;
                }
                  if((event.motion.x <180 && event.motion.x>140)&&(event.motion.y<max && event.motion.y>min) &&(N-x+1 > 4))
                {
                    cvb = NULL;
                    cvb = play(t,4,x,N);
                    affiche(cvb , alphab,renderer,20,ymax) ;
                    ymax = ymax + 50 ;
                    max = max + 50 ;
                    min = min + 50 ;
                }
                  if((event.motion.x <220 && event.motion.x>180)&&(event.motion.y<max && event.motion.y>min)&&(N-x+1 > 5))
                {
                    cvb = NULL;
                    cvb = play(t,5,x,N);
                    affiche(cvb , alphab,renderer,20,ymax) ;
                    ymax = ymax + 50 ;
                    max = max + 50 ;
                    min = min + 50 ;
                }
                  if((event.motion.x <260 && event.motion.x>220)&&(event.motion.y<max && event.motion.y>min)&&(N-x+1 > 6))
                {
                    cvb = NULL;
                    cvb = play(t,6,x,N);
                    affiche(cvb , alphab,renderer,20,ymax) ;
                    ymax = ymax + 50 ;
                    max = max + 50 ;
                    min = min + 50 ;
                }
                  if((event.motion.x <300 && event.motion.x>260)&&(event.motion.y<max && event.motion.y>min)&&(N-x+1 > 7))
                {
                    cvb = NULL;
                    cvb = play(t,7,x,N);
                    affiche(cvb , alphab,renderer,20,ymax) ;
                    ymax = ymax + 50 ;
                    max = max + 50 ;
                    min = min + 50 ;
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
