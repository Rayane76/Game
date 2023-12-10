#ifndef MACHINE_H_INCLUDED
#define MACHINE_H_INCLUDED

void CombI(SDL_Window *window , SDL_Renderer *renderer , int N,int pn ) ;
void nbrN(SDL_Window *window , SDL_Renderer *renderer  );
void nbrP(SDL_Window *window , SDL_Renderer *renderer , int N);
void CombFINALE(SDL_Window *window , SDL_Renderer *renderer , int N,int pn,listeSy premierecombinaison ) ;

void GameOn(SDL_Window *window , SDL_Renderer *renderer , int N,int pn,listeSy premierecombinaison,listeSy dernierecombinaison ) ;

#endif // MACHINE_H_INCLUDED
