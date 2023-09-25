#include<iostream>
#include"stb_image_write.h"
#include<complex>
#include"imageLib.hpp"
#include<string>

using namespace std;



/*
 * The layout of memory expected by stb:
 * Start-> r g b r g b r g b r g b <- end
 * it's all one dimensional, but treated as 2d
 * first divide into rgb chunks, each takes 3 bytes
 * then it's chunked as colums so [rgb][rgb][rgb][rgb]
 * gets chunked as [[rgb][rgb][rgb][rgb]][[rgb][rgb][rgb][rgb]]
 * to access x, y use array[(width * y + x) * channels]
 * I believe that should give proper indexing
 */



int main()
{
  int imageWidth = 1920;
  int imageHeight = 1080;

  const int CHANNEL_NUM = 3;

  Image brot(imageWidth, imageHeight, CHANNEL_NUM);
  RGB color;

  int width = brot.getWidth();
  int height = brot.getHeight();
  int channels = brot.getChannels();

  int index = 0;
  for(int j = 0; j < height; ++j)
  {
    for(int i = 0; i < width; ++i)
    {
      float r = (float)i / (float)width;
      float g = (float)j / (float)height;
      float b = 0.2f;

      color.r = uint8_t(255.9 * r);
      color.g = uint8_t(255.9 * g);
      color.b = uint8_t(255.9 * b);
  
      brot.setPixel(i,j,color);
    }
  }

  //brot.printData();

  const char *name = "images/brottest.png";
  brot.writeImage(name);

  return 0;
}
