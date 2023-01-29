#include "SDL2/SDL.h"


int main(int argc, const char *argv[]){
    
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(
        "Test",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640, 480,
        0
    );
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 0, 225, 255, 255);
    //clear the screen to blue
    SDL_RenderClear(renderer);
    // Present what's drawn so far
    SDL_RenderPresent(renderer);
    SDL_Delay(5000);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    return (0);
}