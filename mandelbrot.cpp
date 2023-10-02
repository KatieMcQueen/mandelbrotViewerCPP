#include<iostream>
#include"stb_image_write.h"
#include<complex>
#include"imageLib.hpp"
#include<string>
#include"complexLib.hpp"
#include"colormaps.hpp"

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
  return -1;
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

RGB normalToRGB(double *value)
{
  RGB color;

  color.r = (uint8_t)(255.9 * value[0]);
  color.g = (uint8_t)(255.9 * value[1]);
  color.b = (uint8_t)(255.9 * value[2]);

  return color;
}


RGB getColor(int iterations)
{
  RGB color;
  if(iterations >= 0)
  {
    iterations = (iterations + 260) % 510; //510 is how many elements are in twilight by defalult
    color = normalToRGB(twilight[iterations]);
  } 
  else 
  {
    color.r = 0;
    color.g = 0;
    color.b = 0;
  } 

  return color;
}

void getCorners(long double x, long double y, long double r, int width, int height, complex<long double> &corner1, complex<long double> &corner2)
{
  // get the imaginary/y component by adding and subtracting the radius from the y coordinate. 
  // then scale the x component based on the ratio of the height and width
  // the formula for the width in the complex plane is 2rw/h to get the ammount to add and subtract we divide by 2 so rw/h
  long double corner1Imaginary = y - r;
  long double corner2Imaginary = y + r;
  long double imaginaryWidth = (r * width) / height;
  long double corner1Real = x - imaginaryWidth;
  long double corner2Real = x + imaginaryWidth;
  corner1.real(corner1Real);
  corner1.imag(corner1Imaginary);
  corner2.real(corner2Real);
  corner2.imag(corner2Imaginary);
}

int main()
{
  int imageWidth = 2560;
  int imageHeight = 1440;

  const int CHANNEL_NUM = 3;

  complex<long double> corner1;
  complex<long double> corner2;

  cout << "Enteer the x, y, and r values seaparated by spaces: ";
  long double coordinateX, coordinateY, viewRadius;
  cin >> coordinateX >> coordinateY >> viewRadius;
  cout << endl << coordinateX << " " << coordinateY << " " << viewRadius << endl;

  getCorners(coordinateX, coordinateY, viewRadius, imageWidth, imageHeight, corner1, corner2);

  const int MAX_ITERATIONS = 2000;

  ComplexField plane(imageWidth, imageHeight, corner1, corner2);

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
      complex<long double> point = plane.getValue(i,j);
      int value = evaluate(point, MAX_ITERATIONS);
      color = getColor(value);

      /*
      cout << "The complex point " << point << " at (" << i << ',' << j << ") iterates " << value;
      cout << " times. it has a color of (" << (int)color.r << ',' << (int)color.g << ',' << (int)color.b << ")" << endl;
      */
  
      brot.setPixel(i,j,color);
    }
  }

  string baseName = "brotest";

  brot.writeImage(makeName(baseName));

  return 0;
}
