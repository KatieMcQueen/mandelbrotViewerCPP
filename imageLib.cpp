#include"imageLib.hpp"
#include<cstdint>
#include<iostream>
#include"stb_image_write.h"

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


Image::Image(int w, int h, int c)
{
  width = w;
  height = h;
  channels = c;
  imageData = new uint8_t[h * w * c];
}

Image::~Image()
{
  delete [] imageData;
}

//the image data is flipped vertically by the image write library, we fix that flip here
int Image::pixelIndex(int x, int y)
{
  //this is the flip
  y = height - y - 1;
  return ((width * y + x) * channels);
}

RGB Image::getPixel(int x, int y)
{
  RGB colors;
  int baseAddr = pixelIndex(x,y);
  colors.r = imageData[baseAddr];
  colors.g = imageData[baseAddr + 1];
  colors.b = imageData[baseAddr + 2];
  return colors;
}

void Image::setPixel(int x, int y, RGB color)
{
  int baseAddr = pixelIndex(x,y);
  imageData[baseAddr + 0] = color.r;
  imageData[baseAddr + 1] = color.g;
  imageData[baseAddr + 2] = color.b;
}

void Image::printData()
{
  RGB color;
  for(int i = 0; i < width; i++)
  {
    for(int j = 0; j < height; j++)
    {
      color = getPixel(i, j);
      cout << "Pixel (" << i << ',' << j << ") is: (" 
           << (int)color.r << ',' << (int)color.g << ',' << (int)color.b << ")" << endl;
    }
  }
}

void Image::writeImage(const char* name)
{
  stbi_write_png(name, width, height, 
                channels, imageData, width * channels);
}


