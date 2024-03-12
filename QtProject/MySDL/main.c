#include <stdio.h>
#include <SDL.h>

#undef main
#define YUV_WIDTH 320
#define YUV_HEIGHT 240
#define YUV_FORMAT SDL_PIXELFORMAT_IYUV
#define REFRESH_EVENT   (SDL_USEREVENT + 1)
int main()
{
//    if(SDL_Init(SDL_INIT_AUDIO)) {
//        //
//        return -1;
//    }


//    int video_width=YUV_WIDTH;
//    int video_height=YUV_HEIGHT;

//    int win_width=YUV_WIDTH;
//    int win_height=YUV_HEIGHT;
//    SDL_Window *window=SDL_CreateWindow("SDL显示视频",
//                                        SDL_WINDOWPOS_UNDEFINED,
//                                        SDL_WINDOWPOS_UNDEFINED,
//                                        win_width,
//                                        win_height,
//                                        SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE
//                                        );
//    SDL_Renderer *renderer=SDL_CreateRenderer(window,
//                                              -1,
//                                              0
//                                              );
//    uint32_t pixfomrat=YUV_FORMAT;
//    SDL_Texture *texture=SDL_CreateTexture(render,
//                                           pixfomrat,
//                                           SDL_TEXTUREACCESS_STREAMING,
//                                           video_width,
//                                           video_height
//                                           );
//    SDL_Event event;
//    while(1) {
//        SDL_WaitEvent(&event);
//        if(event.type==REFRESH_EVENT) {

//        }
//    }
    return 0;
}
