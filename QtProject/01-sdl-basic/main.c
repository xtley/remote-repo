#include <stdio.h>

#include <SDL.h>
#undef main
int main()
{
    printf("Hello World!\n");

    SDL_Window *window = NULL;
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Basic Window",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              640,
                              480,
                              SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
                              );
    if(!window) {
        printf("Can't create window, err:%s\n",SDL_GetError());
        return 1;
    }
    SDL_Delay(5000);
    SDL_DestroyWindow(window);

    SDL_Quit();  //释放资源

    return 0;
}
