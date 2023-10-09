#pragma once
#include"colorLib.hpp"


class Image
{
  //image class to hold and manipulate image data
  //the big one is a 3d array of color data
  //
  private:
    int width;
    int height;
    int channels;
    uint8_t *imageData = nullptr; //image is a 3d array of pixel data. this pointer goes to the start
  public:
    Image(int width, int height, int channels);
    ~Image();
    void setPixel(int x, int y, RGB color);
    RGB getPixel(int x, int y);
    int pixelIndex(int x, int y);
    void printData();
    void writeImage(const char* name);

    int getWidth()
    {return width;}

    int getHeight()
    {return height;}

    int getChannels()
    {return channels;}

    uint8_t* getImageData()
    {return imageData;}
};


