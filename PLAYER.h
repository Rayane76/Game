#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
Uint32 incTIME(Uint32 intervalle , void  *parametre) ;
void showN (SDL_Window *window , SDL_Renderer *renderer) ;
void jouer (SDL_Window *window , SDL_Renderer *renderer , int n , int pn) ;
void jouer2 (SDL_Window *window , SDL_Renderer *renderer , int n , int pn ,SDL_Surface *(T4[8]) , SDL_Surface *(T4F[8])) ;
#endif // PLAYER_H_INCLUDED
