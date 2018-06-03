#ifndef IMAGE_H
#define IMAGE_H
#include "SDL2/SDL.h"
#include <iostream>
#include <string>
#include "SDL2/SDL_image.h"

namespace img{
  class image{
  public:
    void loadimage(int width, int height, std::string path);
  private:

  };
}

#endif
