#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include<SDL_image.h>
#include "bilb.h"
#include "PLAYER.h"
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

void CreateLettre(SDL_Renderer *r ,SDL_Surface *s_lettre,int x , int y , int w , int h)
{
    SDL_Texture *t_lettre = NULL;
   // SDL_Surface *s_lettre = NULL;

    SDL_Rect rectangle;
    rectangle.x = x;
    rectangle.y = y;
    rectangle.w = w;
    rectangle.h = h;

  //  s_lettre = IMG_Load("src/A.png");
    t_lettre = SDL_CreateTextureFromSurface(r, s_lettre);
  //  SDL_FreeSurface(s_lettre);

    SDL_QueryTexture(t_lettre, NULL, NULL, &rectangle.w, &rectangle.h);
    SDL_RenderCopy(r, t_lettre, NULL, &rectangle);
    SDL_RenderPresent(r);
}

void SDL_ExitWithError (const char *message)
{
    SDL_Log("ERREUR : %s > %s\n",message,SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}




void SDL_CreateImageAndTexture(SDL_Surface *image, SDL_Texture *texture,SDL_Renderer *renderer,SDL_Window *window , int x , int y){

            if(image == NULL){
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
                SDL_ExitWithError("IMPOSSIBLE DE CHARGER L IMAGE");
            }

            texture = SDL_CreateTextureFromSurface(renderer,image);
            SDL_FreeSurface(image);

            if(texture == NULL){
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
                SDL_ExitWithError("IMPOSSIBLE DE creer La texture");
            }
            SDL_Rect rectangle;

            if(SDL_QueryTexture(texture,NULL,NULL,&rectangle.w,&rectangle.h)!=0){
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
                SDL_ExitWithError("IMPOSSIBLE DE charger La texture");
            }

            rectangle.x = x ;
            rectangle.y = y ;

            if(SDL_RenderCopy(renderer,texture,NULL,&rectangle)!=0){
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
                SDL_ExitWithError("IMPOSSIBLE DE afficher la texture");
            }

            SDL_RenderPresent(renderer);

}


liste creer_noued(){
    liste nouv = malloc(sizeof(ne)) ;

    if(nouv == NULL){
            printf("MEMOIRE SATUREE !! ") ;
            exit(-1) ; // ARRETER LE PROGRAMME
    }

    return nouv ;

}
void ajouter_tete (liste *t , SDL_Surface *img , int i){

    liste nouv = creer_noued();

    nouv -> img  = img ;
    nouv -> i = i ;
    nouv -> svt = *t;
    *t = nouv ;

}
void ajouter_apres (liste *prd , SDL_Surface *img , int i ){

    liste nouv = creer_noued();

    nouv -> img = img ;
    nouv -> i = i ;
    nouv -> svt = NULL ;
    (*prd) -> svt = nouv ;
    *prd = (*prd)->svt ;
}
void rempli (liste t  )
{
    liste p  = NULL ;
    p = t ;

    SDL_Surface *iA = NULL , *B ,*iB ,*iC , *C , *D,*iD ,*E,*iE,*F,*iF,*G,*iG,*H;
    SDL_Surface *I, *iI , *J,*iJ,*K,*iK,*L,*iL,*M,*iM,*N,*iN,*O,*iO,*P,*iP,*Q,*iQ,*R,*iR,*S,*iS,*T,*iT,*U,*iU,*V,*iV;
    SDL_Surface *W,*iW,*X,*iX,*Y,*iY,*Z,*iZ ;
    iA = IMG_Load("iA.jpg") ;
    B = IMG_Load("B.jpg") ;
    iB = IMG_Load("iB.jpg") ;
    C = IMG_Load("C.jpg") ;
    iC = IMG_Load("iC.jpg") ;
    D = IMG_Load("D.jpg") ;
    iD = IMG_Load("iD.jpg") ;
    E = IMG_Load("E.jpg") ;
    iE = IMG_Load("iE.jpg") ;
    F = IMG_Load("F.jpg") ;
    iF = IMG_Load("iF.jpg") ;
    H = IMG_Load("H.jpg") ;
    G = IMG_Load("G.jpg") ;
    iG = IMG_Load("iG.jpg") ;
    I= IMG_Load("I.jpg") ;
    iI = IMG_Load("iI.jpg") ;
    J = IMG_Load("J.jpg") ;
    iJ = IMG_Load("iJ.jpg") ;
    K = IMG_Load("K.jpg") ;
    iK = IMG_Load("iK.jpg") ;
    L = IMG_Load("L.jpg") ;
    iL = IMG_Load("iL.jpg") ;
    M = IMG_Load("M.jpg");
    iM = IMG_Load("iM.jpg");
    N = IMG_Load("N.jpg");
    iN = IMG_Load("iN.jpg");
    O = IMG_Load("O.jpg");
    iO = IMG_Load("iO.jpg");
    P = IMG_Load("P.jpg");
    iP = IMG_Load("iP.jpg");
    Q = IMG_Load("Q.jpg");
    iQ = IMG_Load("iQ.jpg");
    R = IMG_Load("R.jpg");
    iR = IMG_Load("iR.jpg");
    S = IMG_Load("S.jpg");
    iS = IMG_Load("iS.jpg");
    T = IMG_Load("T.jpg");
    iT = IMG_Load("iT.jpg");
    U = IMG_Load("U.jpg");
    iU = IMG_Load("iU.jpg");
    V = IMG_Load("V.jpg");
    iV = IMG_Load("iV.jpg");
    W = IMG_Load("W.jpg");
    iW = IMG_Load("iW.jpg");
    X = IMG_Load("X.jpg");
    iX = IMG_Load("iX.jpg");
    Y = IMG_Load("Y.jpg");
    iY = IMG_Load("iY.jpg");
    Z = IMG_Load("Z.jpg");
    iZ = IMG_Load("iZ.jpg");


       // ajouter_tete(&t , A , 1 ) ;
        ajouter_apres(&p , iA , -1 ) ;
        ajouter_apres(&p , B , 2 ) ;
        ajouter_apres(&p , iB , -2 ) ;
        ajouter_apres(&p , C , 3 ) ;
        ajouter_apres(&p , iC , -3 ) ;
        ajouter_apres(&p , D , 4 ) ;
        ajouter_apres(&p , iD , -4 ) ;
        ajouter_apres(&p , E , 5 ) ;
        ajouter_apres(&p , iE , -5 ) ;
        ajouter_apres(&p , F , 6 ) ;
        ajouter_apres(&p , iF , -6 ) ;
        ajouter_apres(&p , G , 7 ) ;
        ajouter_apres(&p , iG , -7 ) ;
        ajouter_apres(&p , H , 8 ) ;
        ajouter_apres(&p , H , -8 ) ;
        ajouter_apres(&p , I , 9 ) ;
        ajouter_apres(&p , iI , -9 ) ;
        ajouter_apres(&p , J , 10 ) ;
        ajouter_apres(&p , iJ , -10 ) ;
        ajouter_apres(&p , K , 11 ) ;
        ajouter_apres(&p , iK , -11 ) ;
        ajouter_apres(&p , L , 12 ) ;
        ajouter_apres(&p , iL , -12 ) ;
        ajouter_apres(&p , M , 13);
        ajouter_apres(&p , iM , -13);
        ajouter_apres(&p , N , 14);
        ajouter_apres(&p , iN , -14);
        ajouter_apres(&p , O , 15);
        ajouter_apres(&p , iO , -15);
        ajouter_apres(&p , P , 16);
        ajouter_apres(&p , iP , -16);
        ajouter_apres(&p , Q , 17);
        ajouter_apres(&p , iQ , -17);
        ajouter_apres(&p , R , 18);
        ajouter_apres(&p , iR , -18);
        ajouter_apres(&p , S , 19);
        ajouter_apres(&p , iS , -19);
        ajouter_apres(&p , T , 20);
        ajouter_apres(&p , iT , -20);
        ajouter_apres(&p , U , 21);
        ajouter_apres(&p , iU , -21);
        ajouter_apres(&p , V , 22);
        ajouter_apres(&p , iV , -22);
        ajouter_apres(&p , W , 23);
        ajouter_apres(&p , iW , -23);
        ajouter_apres(&p , X , 24);
        ajouter_apres(&p , iX , -24);
        ajouter_apres(&p , Y , 25);
        ajouter_apres(&p , iY , -25);
        ajouter_apres(&p , Z , 26);
        ajouter_apres(&p , iZ , -26);



}


SDL_Surface * findC (liste t , int i )
{
    liste p = NULL ;
    p = t ;
    while (p != NULL && p->i != i )
    {
        p = p->svt ;
    }
    return p->img ;
}




bool Found(listeC t , int x)
{

    if(t == NULL){return false ;}
    else
    {
        while ((t != NULL )&& (t->info != x))
        {
           t = t->svt ;
        }

        if(t == NULL) {return false ; }
        else {return true ;}

    }
}
void AJOUTER (listeC *t , int x){

    listeC nouv = malloc(sizeof(ne2)) ;

    nouv ->info = x ;
    nouv -> svt = *t;

    *t = nouv ;
}

void imp_tab(SDL_Surface **t, int nb_elem ,int x ,int y , SDL_Renderer *r)
{
int i;
//int x = 297 ;

for (i = 0; i < nb_elem; i++)
{
    CreateLettre(r ,*(t + i), x , y , 40 , 40) ;
    x = x + 40 ;
}
}

 void permuter(int *x , int *y)
 {
     int temp ;
     temp = *x * -1;
     *x = *y * -1;
     *y = temp ;
 }
 int findint (liste t , SDL_Surface *x)
{
    liste p = NULL ;
    p = t ;
     while (p != NULL && (p->img != x) )
    {
        p = p->svt ;
    }
    return p->i ;
}


void change2 (int e , SDL_Surface **T4 , liste t)
{
    if (e == 0){printf("WE CANT") ;}
    int l1,l2 ;
     l1 = findint(t,*(T4 +(e-1))) ;
     l2 = findint(t,*(T4 +(e))) ;
    permuter(&l1,&l2) ;

    *(T4 +(e-1)) = findC(t,l1) ;
    *(T4 +(e)) = findC(t,l2) ;
}
void change3 (int e , SDL_Surface **T4 , liste t)
{

    int l1,l2,l3 ;

     l1 = findint(t,*(T4 +(e-1))) ;
     l2 = findint(t,*(T4 +(e+1))) ;
     l3 = findint(t,*(T4 + e)) ;
     l3 = l3 * -1 ;
    permuter(&l1,&l2) ;

    *(T4 +(e-1)) = findC(t,l1) ;
    *(T4 +(e+1)) = findC(t,l2) ;
    *(T4 +(e)) = findC(t,l3) ;
}
void change4 (int e , SDL_Surface **T4 , liste t)
{

    int l1 , l2, l3, l4 ;
    l1 = findint(t,*(T4 + (e-1))) ;
    l2 = findint(t,*(T4 + (e))) ;
    l3 = findint(t,*(T4 + (e+1))) ;
    l4 = findint(t,*(T4 + (e+2))) ;
    permuter(&l1,&l4) ;
    permuter(&l2,&l3) ;

    *(T4 +(e-1)) = findC(t,l1) ;
    *(T4 +(e)) = findC(t,l2) ;
    *(T4 +(e+1)) = findC(t,l3) ;
    *(T4 +(e+2)) = findC(t,l4) ;


}

void change5 (int e , SDL_Surface **T4 , liste t)
{

    int l1 , l2, l3, l4,l5 ;
    l1 = findint(t,*(T4 + (e-1))) ;
    l2 = findint(t,*(T4 + (e))) ;
    l3 = findint(t,*(T4 + (e+1))) ;
    l4 = findint(t,*(T4 + (e+2))) ;
    l5 = findint(t,*(T4 + (e+3))) ;
    permuter(&l1,&l5) ;
    permuter(&l2,&l4) ;
    l3 = l3 * -1 ;
    *(T4 +(e-1)) = findC(t,l1) ;
    *(T4 +(e)) = findC(t,l2) ;
    *(T4 +(e+1)) = findC(t,l3) ;
    *(T4 +(e+2)) = findC(t,l4) ;
    *(T4 +(e+3)) = findC(t,l5) ;


}

void combF ( SDL_Surface **T4,SDL_Surface **T , int n , listeC *p , liste t,int pn)
{
int x=0 ;
int e = 0 ;
int y = 10 ;

while(x<10)
    {

        {
             do{
            e = 1 + rand() % (n - pn + 1);

            }while(e == y);

          if(n != (pn + 1))  y=e ;

        }

        printf("%d\t",e) ;
        switch(pn)
        {
        case 2 :
            change2(e ,&(*(T4 + 0)), t) ;
        break ;
        case 3 :
            change3(e ,&(*(T4 + 0)), t) ;
        break ;
        case 4 :
            change4(e ,&(*(T4 + 0)), t) ;
        break ;
        case 5 :
            change5(e ,&(*(T4 + 0)), t) ;
        break ;

        }

      //  change2(e ,&(*(T4 + 0)), t) ;
        x++ ;
       if(same(&(*T4),&(*T),n,t) == 1) x = 0 ;
    }
}

void combInit(SDL_Surface **T4,SDL_Surface **T4F, int n , listeC *p , liste t)
{
    int i,x ;
    bool s ;
       for(i=0;i<n;i++)
    {
          do
            {
             x = 1 + rand() %26;
             s = Found(*p,x);
            }while(s == true);
        *(T4 + i ) = findC(t,x) ;
        *(T4F + i ) = findC(t,x) ;


         AJOUTER(&(*p),x) ;

    }
}


int same (SDL_Surface **t1 , SDL_Surface **t2, int n,liste t)
{   int i = 0 , x = 1 ;
    while((i<n) & (x!= 0))
     {
      if((*(t1 + i)) != (*(t2 + i)) ){x = 0 ;}
        i++ ;
    }

    return x ;
}


void imp_tabFINL(SDL_Surface **t, int nb_elem , int y , SDL_Renderer *r)
{
int i;
int x = 297  ;

for (i = 0; i < nb_elem; i++)
{
    CreateLettre(r ,*(t + i), x , y , 40 , 40) ;
    x = x + 40 ;
}
}

/*
void YOUWON (SDL_Window *window , SDL_Renderer *renderer , int v)

{
    SDL_RenderClear(renderer) ;
    SDL_Surface *img = NULL ;
    SDL_Texture *text = NULL;
    img = IMG_Load("background3.jpg") ;
    char time_in_string[20] = "TIME = " ;
    strcat(time_in_string , int_to_string(v) ) ;
    SDL_CreateImageAndTexture(img,text,renderer,window , 0 , 0);
    printf("\n%d",v) ;
     TTF_Font * font = TTF_OpenFont("Gameplay.ttf", 72);
     TTF_Font * font2 = TTF_OpenFont("Gameplay.ttf", 60);
        SDL_Color colorTitle = { 255, 255, 255 };
        SDL_Surface * surfacew1 = TTF_RenderText_Solid(font,"YOU WON" , colorTitle);
        SDL_Surface * temp = TTF_RenderText_Solid(font2,time_in_string , colorTitle);
       CreateLettre(renderer ,surfacew1, 198.12   , 232.13   , 0 , 0) ;
       CreateLettre(renderer,temp,224,361,0,0) ;


       SDL_bool program_launched = SDL_TRUE;
/// GAME ON
        while(program_launched){
            SDL_Event event;

            while(SDL_PollEvent(&event)){




                switch(event.type){



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
}*/
struct Person {
  char name[100];
  int time;
  char date[100] ;
};

void insertData(char name[100] , int time , char date[20]) {
    FILE *file = fopen("highscores.txt", "r+");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    struct Person buffer[100];
    int count = 0;

    //read data from file
    while (fscanf(file, "%s %d %s", buffer[count].name, &buffer[count].time , buffer[count].date) != EOF) {
        count++;
    }

    int i;
    for (i = 0; i < count; i++) {
        if (time < buffer[i].time) {
            break;
        }
    }

    int j;
    for (j = count; j > i; j--) {
        buffer[j] = buffer[j - 1];
    }

    strcpy(buffer[i].name, name );


    buffer[i].time = time ;
    strcpy(buffer[i].date, date );


    rewind(file);
    for (i = 0; i <= count; i++) {
        fprintf(file, "%s %d %s\n", buffer[i].name, buffer[i].time , buffer[i].date);
    }
    fclose(file);
}


void youwon(SDL_Window *window ,SDL_Renderer* renderer, TTF_Font* font, int v , liste t)
{
    // code for when the user wins the game

    // get the current time
    time_t current_time = time(NULL);
    struct tm *time_info = localtime(&current_time);
    char time_string[100];
    strftime(time_string, sizeof(time_string), "%d %b %Y %X", time_info); // format the time string in the desired format
    char v_int[10];
    sprintf(v_int, "%d", v);
    SDL_Color comf = {255,255,255} ;
    SDL_Surface *img = NULL , *start;

    SDL_Surface *rectangle = IMG_Load("rect.png") ;
    rectangle = IMG_Load("rect.png") ;
    SDL_Texture *text = NULL;
    img = IMG_Load("background3.jpg") ;
    SDL_CreateImageAndTexture(img,text,renderer,window , 0 , 0);
    // create a text box asking for user's name
    SDL_Color color = {255, 255, 255};
     TTF_Font * font2 = TTF_OpenFont("Gameplay.ttf", 48);
     TTF_Font * font3 = TTF_OpenFont("Gameplay.ttf", 36);
     start = TTF_RenderText_Solid(font2, "save", comf);
    SDL_Surface* prompt = TTF_RenderText_Blended(font2, "Enter your name", color);
    SDL_Texture* prompt_texture = SDL_CreateTextureFromSurface(renderer, prompt);
    //CreateLettre(renderer,prompt,107,64,0,0) ;
    SDL_Rect prompt_rect = {107, 64, prompt->w, prompt->h};
    SDL_FreeSurface(prompt);
    // display the text box
    SDL_RenderCopy(renderer, prompt_texture, NULL, &prompt_rect);
    SDL_RenderPresent(renderer);
    //CreateLettre(renderer,rectangle,90,275,0,0) ;
    CreateLettre(renderer,rectangle,139,338,0,0) ;
    CreateLettre(renderer,start,301,647,0,0) ;
    time_t currentTime;
    struct tm *localTime;
    char dateString[20];

    time(&currentTime);
    localTime = localtime(&currentTime);

    strftime(dateString, 20, "%Y-%m-%d", localTime);
    // handle user input
    char name[100] = "";
    SDL_StartTextInput();
    while(1) {
        SDL_Event e;
        while(SDL_PollEvent(&e)) {
            if(e.type == SDL_TEXTINPUT) {
                strcat(name, e.text.text);
                SDL_Surface* name_surface = TTF_RenderText_Blended(font3, name, color);
                SDL_Texture* name_texture = SDL_CreateTextureFromSurface(renderer, name_surface);
                SDL_Rect name_rect = {161, 357, name_surface->w, name_surface->h};
                SDL_FreeSurface(name_surface);
                SDL_RenderCopy(renderer, name_texture, NULL, &name_rect);
                SDL_RenderPresent(renderer);
            } else if(e.type == SDL_MOUSEBUTTONDOWN && (e.motion.x <452 && e.motion.x>341)&&(e.motion.y<693&& e.motion.y>647))
             {

                insertData(name , v , dateString);
                LEADERBOARD(window,renderer,t) ;
// stop text input
SDL_StopTextInput();
}

        }
    }
}



void YOULOST (SDL_Window *window , SDL_Renderer *renderer)

{
    SDL_RenderClear(renderer) ;
    SDL_Surface *img = NULL ;
    SDL_Texture *text = NULL;
    img = IMG_Load("background3.jpg") ;
    SDL_CreateImageAndTexture(img,text,renderer,window , 0 , 0);

     TTF_Font * font = TTF_OpenFont("Gameplay.ttf", 72);
     TTF_Font * font2 = TTF_OpenFont("Gameplay.ttf", 48);
        SDL_Color colorTitle = { 255, 255, 255 };
        SDL_Color colorTitle2 = { 250, 179, 39  };
        SDL_Surface * surfacew1 = TTF_RenderText_Solid(font,"YOU LOST" , colorTitle);
        SDL_Surface * back = TTF_RenderText_Solid(font2,"play again" , colorTitle);
        SDL_Surface * back2 = TTF_RenderText_Solid(font2,"play again" , colorTitle2);
       CreateLettre(renderer ,surfacew1, 164  , 200   , 0 , 0) ;
       CreateLettre(renderer ,back, 208  , 514   , 0 , 0) ;

        int screen = 94;
       SDL_bool program_launched = SDL_TRUE;
/// GAME ON
        while(program_launched){
            SDL_Event event;

            while(SDL_PollEvent(&event)){




                switch(event.type){
                case SDL_MOUSEMOTION :
                    if((event.motion.x <542&& event.motion.x>208)&&(event.motion.y<560 && event.motion.y>514))
                    {

                               CreateLettre(renderer ,back2, 208  , 514   , 0 , 0) ;


                    }else {       CreateLettre(renderer ,back, 208  , 514   , 0 , 0) ;}
                break ;

                case SDL_MOUSEBUTTONDOWN :
                    if((event.motion.x <542&& event.motion.x>208)&&(event.motion.y<560 && event.motion.y>514))
                    {
                            showN(window,renderer) ;
                            screen = 10 ;
                            while(screen == 10)
                            {
                                SDL_DestroyRenderer(renderer) ;
                            }


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

///
listeSy creer_ne (){
  listeSy nouv = malloc(sizeof(ne));

  if (nouv==NULL){
    printf("memoire pleine!");
    exit(-1);
  }
  return nouv;
}
void ajouter_t(listeSy *t , int x)
{

   listeSy nouv = creer_ne();
   nouv-> val = x;
   nouv-> svt = *t;
   nouv-> pred =NULL;
   if(*t!=NULL){(*t)->pred = nouv;}
   *t=nouv;

 }
void ajouter_p(listeSy *prd, int x){

  listeSy p;
  p = (*prd)->svt;
  listeSy nouv = creer_ne();
  nouv->val = x;
  (*prd)->svt = nouv;
  nouv->pred = *prd;
  nouv->svt = p;
  if(p!=NULL){p->pred = nouv;}
  *prd=nouv;

}

void affiche(listeSy p,liste t,SDL_Renderer *r,int x,int y)
{   SDL_Surface *v = NULL ;

    while(p != NULL)
    {
        v = findC(t,p->val) ;
        CreateLettre(r,v,x,y,0,0) ;
        x = x + 40 ;
        p = p->svt ;
    }
}
int combinaisonTransformEnNombre (listeSy h, int N){
  int x;
  int i;
  listeSy v;
  v = h;
  while (v->svt != NULL){v=v->svt;}
  x=0;
  for(i=0;i<N;i++){
    x = x + (v->val) * puissance(10,i);
    v = v->pred;
  }
  return x;
}

 int puissance (int x , int p)
 {
  int n ;
  int i ;
  n = 1;
  for (i=0;i<p;i++){
    n = n * x;
  }
  return n;
}
 void ajouter_tetenor(listeP *t , listeSy s , long int x, int ind , int prind){

   listeP nouv = creer_noeudnor();
   nouv->info = s;
   nouv->somme = x;
   nouv->indice = ind;
   nouv->prdindice = prind;
   nouv->suiv = *t;
   nouv-> pred =NULL;
   if(*t!=NULL){(*t)->pred = nouv;}
   *t=nouv;

 }
  void ajouter_tetefin(listef *t , listeSy x , long int s)
  {

   listef nouv = creer_noeudfin();
   nouv-> val = x;
   nouv->somme = s;
   nouv-> svt = *t;
   nouv-> pred =NULL;
   if(*t!=NULL){(*t)->pred = nouv;}
   *t=nouv;

 }

 listeSy nouvListe (listeSy h)
 {
   listeSy c,r ;
   c = NULL;
   listeSy b;
   b = h;
   ajouter_t(&c,b->val);
   r = c;
   b = b->svt;
   while (b!=NULL){
     ajouter_p(&c,b->val);
     b = b->svt;
   }
   return r;
}
listeSy play(listeSy t,int e,int x,int N)
{

    listeSy q;
    q=t;
    int j;
    j=1;
    while (j<e){
        q = q->svt ;
        j = j+1;
    }
    listeSy s,w;
    s=q; w=q->svt;
    int y;
    int r;
    r = q->val;
    int f;
    f=1;
    while(f<x){q=q->svt; f=f+1;}
    s->val = (q->val)*(-1);
    q->val = r * (-1);

    while((w!=q) && ((q->svt) != w)){
        if(w->svt == q){w->val = (w->val) * (-1);}
        else {
            y = w->val;
            w->val = ((q->pred)->val) * (-1);
            (q->pred)->val = y * (-1);
        }
        w = w->svt;
        q = q->pred;
    }
   return t;
}


listeP creer_noeudnor()
{

  listeP nouv = malloc(sizeof(noeud));

   if (nouv==NULL) {
    printf("MEMOIRE PLEINE !");
    exit(-1);
   }
   return nouv;
}
listef creer_noeudfin ()
{
  listef nouv = malloc(sizeof(nre));

  if (nouv==NULL){
    printf("memoire pleine!");
    exit(-1);
  }
  return nouv;
}

int verifiCombinaisonFinale(listeSy comb)
{
   listeSy h;
   listeSy svh;
   int x;
   x=0;
   h = comb;
   svh = h->svt;
   while (svh != NULL){
     if ((h->val)*(svh->val)<0){
        x = x+1;
     }
     h = h->svt;
     svh = svh->svt;
   }
   return x;
}
void ajouter_apresfin(listef *prd, listeSy x, long int s)
{

  listef p;
  p = (*prd)->svt;
  listef nouv = creer_noeudfin();
  nouv->val = x;
  nouv->somme = s;
  (*prd)->svt = nouv;
  nouv->pred = *prd;
  nouv->svt = p;
  if(p!=NULL){p->pred = nouv;}
  *prd=nouv;

}

 void ajouter_apresnor(listeP *prd, listeSy s , long int x,int ind,int prind)
 {

   listeP p;
  p = (*prd)->suiv;
  listeP nouv = creer_noeudnor();
  nouv->info = s;
  nouv->somme = x;
  nouv->indice = ind;
  nouv->prdindice = prind;
  (*prd)->suiv = nouv;
  nouv->pred = *prd;
  nouv->suiv = p;
  if(p!=NULL){p->pred = nouv;}
  *prd=nouv;

 }
int combinaisonvalide(listeSy combinit, listeSy combutil)
{
  listeSy r = combutil;
  listeSy v;
  int x = 0;
  int ret = 0;
  while (r != NULL){
    v = combinit;
    while (v != NULL){
        if (r->val == v->val || r->val == (v->val)*(-1)){
            x = x + 1;
        }
        v = v->svt;
    }
    ret = ret + x;
    r = r->svt;
  }
  return ret;
  //if ret == N t existi
  //if ret < N  n existe pas
}

int combfinalexiste (listef x , listeSy v , int N )
{
  int t = 0;
  int m = combinaisonTransformEnNombre(v,N);
  listef u = x->svt;
  while (u != NULL){
    if (u->somme == m){
        t = t + 1;
    }
    u = u->svt;
  }
  return t;
  //if t == 0 tssma combinaison ma t existich
}
 void affiche_listefin(listef p , liste t , SDL_Renderer *r,int y)
{
    int x = 325 ;
   while(p!=NULL){
    SDL_Delay(3000) ;
    // affiche_liste(t->val);
    affiche(p->val,t,r,x,y) ;

    // printf("\n");
     p=p->svt;
     y = y + 50 ;
   }

 }


int input_thread(void *data) {
  // Handle user input here
  return 0;
}

void affiche_listefinPvsM(listef p, liste t, SDL_Renderer *r, int x, int y) {

  SDL_Thread *input_thread_id = SDL_CreateThread(input_thread, "input_thread", NULL);
  while (p != NULL) {
    affiche(p->val, t, r, x, y);
    p = p->svt;
    y = y + 50;
    SDL_Delay(3000);
  }
  SDL_WaitThread(input_thread_id, NULL);
}






void affiche_listefinE(listef t)
 {

   while(t!=NULL){
     affiche_listeE(t->val);

     printf("\n");
     t=t->svt;
   }

 }

 void affiche_listeE(listeSy t)
 {

   while(t!=NULL){
     printf("%d\t", t->val);
     t=t->svt;
   }
   printf("\n");
 }
 int nbr_paire(int n){
  if(n%2==0){return 1;}
  else {return 0;}
}



char* int_to_string(int n)
{
    int len = snprintf(NULL, 0, "%d", n);
    char* str = malloc(len+1);
    sprintf(str, "%d", n);
    return str;
}


void Draw_Timer(SDL_Renderer *renderer, int tiempo)
{

        int ms , s ;
      SDL_Rect timerpos;
        ms = tiempo % 1000;//miliseconde
        s = tiempo / 1000 ;  // seconde



      timerpos.x=10;
      timerpos.y=10;
      timerpos.w=30;
      timerpos.h=45;
      char temps[20];
      SDL_Texture *timer;
      sprintf(temps,"%d:%d", s,ms); // on sauvgarde les secondes dans le tompant temps
      timer=initialize_texture_from_TTF(temps,renderer);
      Blit(renderer,timer,timerpos);
      SDL_DestroyTexture(timer);

}
SDL_Texture *initialize_texture_from_TTF(const char* name, SDL_Renderer *renderer)
{
    TTF_Font * font = TTF_OpenFont("Gameplay.ttf",60);
    SDL_Color color = { 255,255,255 };
    SDL_Surface * surface = TTF_RenderText_Solid(font,name, color);
    SDL_Texture * text = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return text;
}
 void Blit(SDL_Renderer *renderer, SDL_Texture *texture,SDL_Rect dest)
 {
      SDL_RenderCopy(renderer, texture, NULL, &dest);
 }

 int combfinalexiste2 (listeP x , listeSy v , int N )
 {
  int t = 0;
  int m = combinaisonTransformEnNombre(v,N);
  listeP u = x->suiv;
  while (u != NULL){
    if (u->somme == m){
        t = t + 1;
    }
    u = u->suiv;
  }
  return t;
  //if t == 0 tssma combinaison ma t existich
}

void save_timer_and_date(int timer)
{
    // Open a file for reading
    FILE *file = fopen("timer_and_date.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    int i,n=0;
    int timers[100] = {0};
    char dates[100][20];
    while(fscanf(file, "Timer: %d\nDate: %s\n", &timers[n], dates[n]) == 2) {
        n++;
    }
    fclose(file);

    // Get the current date and time
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char curr_date[20];
    strftime(curr_date, sizeof(curr_date), "%Y-%m-%d %H:%M:%S", tm);

    // Insert the new timer and date in the correct position
    for (i = 0; i < n; i++) {
        if (timer < timers[i]) {
            // Shift the existing data to make room for the new timer
            int j;
            for (j = n; j > i; j--) {
                timers[j] = timers[j - 1];
                strcpy(dates[j],dates[j-1]);
            }
            // Insert the new timer and date
            timers[i] = timer;
            strcpy(dates[i],curr_date);
            n++;
            break;
        }
    }
    if(n<100)
    {
        timers[n] = timer;
        strcpy(dates[n],curr_date);
        n++;
    }
    // Open the file for writing
    file = fopen("timer_and_date.txt", "w");
if (file == NULL) {
printf("Error opening file!\n");
return;
}

// Write the timers and dates to the file
for (i = 0; i < n; i++) {
    fprintf(file, "Timer: %d\nDate: %s\n", timers[i], dates[i]);
}

// Close the file
fclose(file);
}



void LEADERBOARD(SDL_Window *window , SDL_Renderer *renderer , liste t)
{
    SDL_Surface *img , *highscorename = NULL ,*highscoredate,*highscoretime;
    img = IMG_Load("leaderboad.jpg") ;
    SDL_Texture *text = NULL ;
    SDL_CreateImageAndTexture(img,text,renderer,window , 0 , 0);
    TTF_Font * font = TTF_OpenFont("Gameplay.ttf", 24);
    TTF_Font * font3 = TTF_OpenFont("Gameplay.ttf", 36);
    TTF_Font * font2 = TTF_OpenFont("Gameplay.ttf", 60);
    SDL_Color comf = {255,255,255} ;
    SDL_Color comf2 = {250, 179, 39} ;
     int y = 215 , x = 247 ;
    FILE *file = fopen("highscores.txt", "r");
    char name[100] ;
    char finalString[100] ;
    char date[20];
    int time ;
    int d = 5 ;
    SDL_Surface * back = TTF_RenderText_Solid(font3,"back" , comf);
    SDL_Surface * back2 = TTF_RenderText_Solid(font3,"back" , comf2);
    CreateLettre(renderer,back,301,641,0,0) ;

    while (fscanf(file, "%s %d %s", name, &time , date) != EOF && (d != 0)) {
       // sprintf(finalString, "%s           %s   %s", name, int_to_string(time), date);

        highscorename = TTF_RenderText_Solid(font, name, comf);
        highscoretime = TTF_RenderText_Solid(font, int_to_string(time), comf);
        highscoredate = TTF_RenderText_Solid(font, date, comf);
        CreateLettre(renderer,highscorename,x,y,0,0) ;
        CreateLettre(renderer,highscoretime,435,y,0,0) ;
        CreateLettre(renderer,highscoredate,517,y,0,0) ;
        y = y + 85 ;
        d-- ;
  }
    int screen = 98 ;
    fclose(file) ;
     SDL_bool program_launched = SDL_TRUE;

        while(program_launched){
            SDL_Event event;


            while(SDL_PollEvent(&event)){
                switch(event.type){
            case SDL_MOUSEMOTION :
                 if((event.motion.x <452 && event.motion.x>301)&&(event.motion.y<687 && event.motion.y>641))
                 {
                     CreateLettre(renderer,back2,301,641,0,0) ; ;

                 }else{
                         CreateLettre(renderer,back,301,641,0,0) ;

                 }
                break ;
                case SDL_MOUSEBUTTONDOWN :
                     if((event.motion.x <452 && event.motion.x>301)&&(event.motion.y<687 && event.motion.y>641))
                     {
                         Menu(window,renderer , t);
                         screen = 11 ;
                         while(screen == 11)
                         {
                             SDL_DestroyRenderer(renderer) ;
                         }
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
void save_surfaces(SDL_Surface* screen)
{
    SDL_SaveBMP(screen, "current.jpg");
}

void Load(SDL_Window *window , SDL_Renderer *renderer , liste t)
{
    SDL_Surface *img , *highscorename = NULL ,*highscoredate,*highscoretime,*(T4[8]),*cont,*(T4F[8]) , *menu , *pause;
    img = IMG_Load("background3.jpg") ;
    SDL_Texture *text = NULL ;
    SDL_CreateImageAndTexture(img,text,renderer,window , 0 , 0);
    TTF_Font * font = TTF_OpenFont("Gameplay.ttf", 36);
    TTF_Font * font2 = TTF_OpenFont("Gameplay.ttf", 60);
    SDL_Color comf = {255,255,255} ;
    SDL_Surface *timer_surface;
        SDL_Surface * quit = TTF_RenderText_Solid(font2,"Quit " , comf);
    SDL_Surface * save = TTF_RenderText_Solid(font2,"save and quit" , comf);

    cont = TTF_RenderText_Solid(font2,"continue" , comf);
int test = 0 ;
    int i = 0 ;
    int n = 0 ;
    FILE* fp = fopen("tab.txt", "r");
    FILE* fpfinale = fopen("tabfinale.txt", "r");
    FILE* xfile = fopen("x.txt", "r");
    int value , dvalue;
     fscanf(xfile,"%d",&value) ;
   int xc = value ;
    fscanf(xfile,"%d",&value) ;
   int y = value ;
    fscanf(xfile,"%d",&value) ;
   int min = value ;
 int start = SDL_GetTicks();
     fscanf(xfile,"%d",&value) ;
   int max = value ;
   fscanf(xfile,"%d",&value) ;
   int pn = value ;
    fscanf(xfile,"%d",&value) ;
    n = value ;
    fscanf(xfile,"%d",&value) ;
    int x = value ;
    fscanf(xfile,"%d",&value) ;
    int ptime = value ;
    for(int i = 0 ; i<n;i++)
    {   fscanf(fp,"%d",&value) ;
       fscanf(fpfinale,"%d",&dvalue) ;
        T4[i] = findC(t,value) ;
        T4F[i] = findC(t,dvalue) ;


    }

fclose(fp);
fclose(fpfinale);
fclose(xfile);
imp_tab(&(T4[0]), n,xc ,y-50, renderer) ;
imp_tab(&(T4F[0]), n,xc ,662, renderer) ;
int screen = -9 , paused = 0 ;
int j = n-pn+1 ;
int timer = 0;
SDL_Rect c_rect = {150, 208, 800, 800};
start += SDL_GetTicks() - ptime;
    SDL_Surface * surfacew1 = TTF_RenderText_Solid(font,"LA COMB FINALE" , comf);
CreateLettre(renderer ,surfacew1, 209 , 602 , 333 , 40) ;

SDL_Surface *screen_surface = NULL;
    screen_surface = SDL_GetWindowSurface(window);
SDL_Surface *image ;
     SDL_bool program_launched = SDL_TRUE;
menu = IMG_Load("menu.png") ;
 pause = IMG_Load("pause.png") ;
  CreateLettre(renderer ,pause, 615 , 28 , 333 , 40) ;
    CreateLettre(renderer ,menu, 674 , 28 , 333 , 40) ;
        while(program_launched){
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
                                FILE* x = fopen("x.txt", "w") ;
                                FILE* fp = fopen("tab.txt", "w") ;
                                FILE* fpfinale = fopen("tabfinale.txt", "w") ;
                                for(int i = 0 ; i < n ; i++)
                                {
                                    fprintf(fp,"%d " , findint(t,T4[i])) ;
                                    fprintf(fpfinale,"%d " , findint(t,T4F[i]) );
                                }
                                fprintf(x, "%d %d %d %d %d %d %d %d", xc, y, min, max , pn , n , x , ptime);
                                paused = 0 ;
                                program_launched = SDL_FALSE;
                                fclose(x) ;
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





void Menu(SDL_Window *window ,SDL_Renderer *r, liste t)
{

    SDL_Surface *img = NULL ;
    SDL_Texture *texture = NULL;
    int screen = 0  ;


  // TTF_Font * font = TTF_OpenFont("SF Atarian System.ttf", 30);
    img =IMG_Load("background3.jpg");

   // window = SDL_CreateWindow("Premiere fenetre SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 750, 750, 0);
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
                            LEADERBOARD(window,r,t) ;
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


}


void ajouter_teteentier(arbre *a , int x)
{
    arbre nouv = malloc(sizeof(ne6)) ;
    nouv->svt = NULL ;
    nouv->info = x ;
    if(a==NULL) *a = nouv ;
        else
        {
            nouv->svt = *a;
            *a = nouv ;


        }
}

void suppListe(arbre *a)
{
    arbre p = *a ;
    while(*a != NULL)
    {    p = *a ;
        (*a) = (*a)->svt ;
        free(p) ; p = NULL ;
    }
}



