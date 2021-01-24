
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "constants.h"
#include <iostream>

//globals
SDL_Window* g_window = nullptr;
//functions
bool InitSDL();
int ExitSDL();

int main(int argc, char* args[])
{
    if (InitSDL()) {
        SDL_Delay(5000);
    }
    ExitSDL();
    return 0;
}
bool InitSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize. Error: " << SDL_GetError();
        return false;
    }
    else {
        g_window = SDL_CreateWindow("Mario SDL",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN);
        if (g_window == nullptr) {
            std::cout << "SDL window was not created. Error: " << SDL_GetError();
            return false;
        }
    }
    return true;
}
int ExitSDL()
{
    SDL_DestroyWindow(g_window);
    g_window = nullptr;
    IMG_Quit();
    SDL_Quit();
    return 0;
}
