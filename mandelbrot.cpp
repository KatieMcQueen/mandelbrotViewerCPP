#include<iostream>
#include"stb_image_write.h"
#include<complex>
#include"imageLib.hpp"
#include<string>

using namespace std;


//this function evaluates whether the point is in the mandelbrot set under a certain number of iterations
int evaluate(complex<long double> c, int iterations)
{
  complex<long double> z = 0;
  for(int i = 0; i < iterations; i++)
  {
    //this is the definition of the mandelbrot any number that stays bounded to less than 2 is in the set
    z = (z*z) + c;
    if(abs(z) > 2)
    {
      //if it's greater than 2 it's value will explode and we don't care.
      //it's said to not be in the mandelbrot set
      //all we need is the number of iterations before it escapes, we can use this to color our picture
      return i;
    }
  }
  return 0;
}

const char* makeName(string name)
{
  //begin time and date fuckery
  //credit to the cppreference.com page explaining strftime() this would have sucked way more to figure out without it
  //we'll get an epoch from time()
  //then we create a character array, we include the format of our date string but blank and get the size of that
  //that size initializes the size of the character array 
  //then we use strftime() which is a doozy
  //arg 1: a pointer to the first character in a character array to store our date and time value
  //we use std::data() which happens to work for our purposes
  //arg 2 is the number of bytes to write, we use the size of out conviniently prexisting array
  //arg 3 is a formatting string. this looks like "%F_%T" 
  //the %F and %T conviniently expand into a date and time format that conviniently sorts things by how new they are
  //arg 4 is weird, we need a pointer to a tp object. tp objects are structs 
  //that hold information about the current time and date we generate this with std::gmtime()
  //conviniently this provides a pointer to an appropriate struct. weirdly it needs a pointer to the epoch time
  //so we just prefix our time with &
  //end time and date fuckery
  time_t myTime = time(nullptr); //I forgot. this sometimes takes a time object, the null pointer to keeps it happy
  char timeString[size("yyyy-mm-dd_hh:mm:ss")];
  strftime(data(timeString), size(timeString), "%F_%T", gmtime(&myTime));

  name = "images/" + name + '_' + timeString + ".png";
  return name.c_str();
}



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

  string baseName = "brotest";

  brot.writeImage(makeName(baseName));

  return 0;
}
