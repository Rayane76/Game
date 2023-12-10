#ifndef BILB_H_INCLUDED
#define BILB_H_INCLUDED
#include <stdbool.h>
#include <SDL_image.h>

typedef struct cel *liste ;
typedef struct cel
{
    int i ;
    SDL_Surface *img ;
    liste svt ;
}ne ;
typedef struct cel7 *arbre ;
typedef struct cel7
{
    int info;
    arbre svt ;
}ne6 ;
typedef struct cel3 *listeC ;
typedef struct cel3
{
    int info ;
    listeC svt ;
}ne2 ;

typedef struct cil *listeSy;
typedef struct cil {
  int val;
  listeSy svt;
  listeSy pred;
}ne3;

typedef struct celd *listeP;
typedef struct celd {
   listeSy info;
   listeP suiv;
   long int somme;
   listeP pred;
   int indice;
   int prdindice;
}noeud;

typedef struct cvl *listef;
typedef struct cvl {
  listeSy val;
  listef svt;
  listef pred;
  long int somme;
}nre;

struct top_time {
    int timer;
    char date[20];
} top_times[5];


void CreateLettre(SDL_Renderer *r ,SDL_Surface *s_lettre,int x , int y , int w , int h) ;
void SDL_ExitWithError (const char *message);
void SDL_CreateImageAndTexture(SDL_Surface *image, SDL_Texture *texture,SDL_Renderer *renderer,SDL_Window *window , int x , int y) ;
liste creer_noued() ;
void ajouter_tete (liste *t , SDL_Surface *img , int i) ;
void ajouter_apres (liste *prd , SDL_Surface *img , int i ) ;
void rempli (liste t  ) ;
SDL_Surface * (findC (liste t , int i )) ;
int findint (liste t , SDL_Surface * x) ;
bool Found(listeC t , int x) ;
void AJOUTER (listeC *t , int x) ;
void imp_tab(SDL_Surface **t, int nb_elem ,int x ,int y , SDL_Renderer *r) ;
void combInit(SDL_Surface **T4,SDL_Surface **T4F, int n , listeC *p , liste t) ;
void change2 (int e , SDL_Surface **T4 , liste t) ;
void permuter(int *x , int *y) ;
void combF ( SDL_Surface **T4,SDL_Surface **T , int n , listeC *p , liste t , int pn) ;
int same (SDL_Surface **t1 , SDL_Surface **t2, int n,liste t) ;
void imp_tabFINL(SDL_Surface **t, int nb_elem , int y , SDL_Renderer *r) ;
//void YOUWON (SDL_Window *window , SDL_Renderer *renderer , int v) ;
void YOULOST (SDL_Window *window , SDL_Renderer *renderer) ;
void change3 (int e , SDL_Surface **T4 , liste t) ;
void change4 (int e , SDL_Surface **T4 , liste t) ;
void change5 (int e , SDL_Surface **T4 , liste t) ;

void ajouter_t(listeSy *t , int x);
void ajouter_p(listeSy *prd, int x) ;
void affiche(listeSy p,liste t,SDL_Renderer *r,int x,int y) ;
listeSy creer_ne () ;
int combinaisonTransformEnNombre (listeSy h, int N) ;
int puissance (int x , int p) ;
void ajouter_tetenor(listeP *t , listeSy s , long int x, int ind , int prind) ;
listeSy nouvListe (listeSy h) ;

void ajouter_tetefin(listef *t , listeSy x , long int s) ;
listeSy play(listeSy t,int e,int x,int N);
listeP creer_noeudnor() ;
listef creer_noeudfin () ;
int verifiCombinaisonFinale(listeSy comb) ;
void ajouter_apresfin(listef *prd, listeSy x, long int s) ;
void ajouter_apresnor(listeP *prd, listeSy s , long int x,int ind,int prind) ;
int combinaisonvalide(listeSy combinit, listeSy combutil) ;
int verifiCombinaisonFinale(listeSy comb) ;
int combfinalexiste (listef x , listeSy v , int N ) ;
void affiche_listefin(listef p , liste t , SDL_Renderer *r,int y)  ;
void affiche_listefinE(listef t) ;
 void affiche_listeE(listeSy t)  ;
 int nbr_paire(int n) ;
 char* int_to_string(int n) ;
 void Draw_Timer(SDL_Renderer *renderer, int tiempo) ;
 SDL_Texture *initialize_texture_from_TTF(const char* name, SDL_Renderer *renderer) ;
  void Blit(SDL_Renderer *renderer, SDL_Texture *texture,SDL_Rect dest) ;
    void affiche_listefinPvsM(listef p , liste t , SDL_Renderer *r,int x,int y) ;
void save_timer_and_date(int timer)  ;
 int combfinalexiste2 (listeP x , listeSy v , int N ) ;
void LEADERBOARD(SDL_Window *window , SDL_Renderer *renderer,liste t);
void handle_ok_button_click(void *data, SDL_Event *event) ;
void save_surfaces(SDL_Surface* screen) ;
SDL_Texture *Conti(SDL_Renderer *renderer , SDL_Surface *img , int x , int y , int h , int w);
void Menu(SDL_Window *window ,SDL_Renderer *r, liste t) ;
void ajouter_teteentier(arbre *a , int x) ;
void suppListe(arbre *a) ;
void savefile(arbre a , int xc , int y , int min , int max) ;
void youwon(SDL_Window *window ,SDL_Renderer* renderer, TTF_Font* font, int v , liste t) ;
void Load2(SDL_Window *window , SDL_Renderer *renderer , liste t) ;
#endif // BILB_H_INCLUDED
