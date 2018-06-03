#include "image.h"
namespace img{
    void image::loadimage(int width, int height, std::string path){
      if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        std::cout << "ERROR INIT SDL" << SDL_GetError() << std::endl;
      }
      SDL_Window *window = SDL_CreateWindow("LAND", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
      SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,  SDL_RENDERER_ACCELERATED);

      SDL_Texture *img = IMG_LoadTexture(renderer, path.c_str());
      SDL_Rect rect;
      rect.x = 0;
      rect.y = 0;
      rect.h = height;
      rect.w = width;
      while(true){
        SDL_Event event;
        if(SDL_PollEvent(&event)){
          if (event.type == SDL_QUIT){
            break;
          }
        }
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, img, NULL, &rect);
        SDL_RenderPresent(renderer);
      }
      SDL_DestroyTexture(img);
      SDL_DestroyRenderer(renderer);
      SDL_DestroyWindow(window);
  }

}
