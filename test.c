#include "SDL2/SDL.h"



int process_events(SDL_Window *window){
    int done = 0;
    SDL_Event event;

    while (SDL_PollEvent(&event))
        {
        switch (event.type)
        {
            case SDL_WINDOWEVENT_CLOSE:{
                if (window){
                    SDL_DestroyWindow(window);
                    window = NULL;
                    done = 1;
                }                }
            case SDL_KEYDOWN:{
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:{
                        done = 1;
                    }
                    break;
                }
            }
            case SDL_QUIT:{
                done = 1;
            }
            break;
        }
    }
    return done;
}


int main(int argc, const char *argv[]){
    
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(
        "Test",
        SDL_WINDOWPOS_UNDEFINED_DISPLAY(0),
        SDL_WINDOWPOS_UNDEFINED,
        640, 480,
        0
    );
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    int done = 0;
    
    while(!done){
        if (process_events(window) == 1){
            done = 1;
        }
        done = process_events(window);
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
        SDL_Delay(100);
    }
    return (0);
}